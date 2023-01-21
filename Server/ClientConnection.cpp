#include "ClientConnection.h"
#include <iostream>
#include <string>

ClientConn::ClientConn(char *IP, int PORT){ //constructor
    connectionEstablished = true; //set connectionEstablished to true
    Socket = new QTcpSocket(); //create a new socket
    Socket->connectToHost(IP, PORT); //connect to the host
    if (!Socket->waitForConnected(1000)){  //wait for the connection to be established
        std::cout << "[-] Connection Establishment Error" << std::endl; //if the connection is not established, print an error message
        connectionEstablished = false; //set connectionEstablished to false
        return; //return
    };
    std::string key = getKey(), temp; //get the key and store it in a string
    std::cout << "My length is " << key.length() << std::endl; //print the length of the key
    Encryptor = new EncDec(key); //create a new EncDec object with the key
    int count = 0; //create a counter
    while (true){ //loop forever
        if (++count >= 10){ //if the counter is greater than 10
            connectionEstablished = false; //set connectionEstablished to false
            return; //return
        }
        sendMsg((char*)key.c_str(), key.length(), true); //send the key to the server
        temp = getKey(); //get the key from the server
        std::cout << temp << std::endl; //print the key
        if (temp == Encryptor->runEncDec(key)){ //if the key is correct
            break; //break the loop
        }
        key = temp; //set the key to the new key
        delete Encryptor; //delete the EncDec object
        Encryptor = new EncDec(key); //create a new EncDec object with the new key
    }
}

std::string ClientConn::getKey(){ //get the key from the server
    Socket->waitForReadyRead(3000); //wait for the socket to be ready to read
    return (std::string)Socket->readAll(); //return the key
}
void ClientConn::sendMsg(char *msg, int lenStr, bool sendLenOnly){ //send a message to the server
    std::string tempString = std::to_string(lenStr); //convert the length of the message to a string
    for (int i = tempString.length(); i < 4; i++) tempString = "0" + tempString; //add 0's to the front of the string until it is 4 characters long
    do{
    std::cout << "WROTE: " << Socket->write((Encryptor->runEncDec(tempString)).c_str()) << std::endl;
    Socket->waitForBytesWritten(1000);
    Socket->flush();
    if (sendLenOnly) return;

    }while (Encryptor->runEncDec(getKey()).substr(3, 9) == "RECVERROR"); //if the server is not ready to receive the message, send the message again


    std::cout << "WROTE ACTUAL: " << Socket->write((Encryptor->runEncDec(msg)).c_str()) << std::endl; //send the message to the server
    Socket->waitForBytesWritten(1000); //wait for the message to be sent
}

std::string ClientConn::recvMsg(bool secure){
//    while (!){}
    Socket->waitForReadyRead(300); //wait for the socket to be ready to read
    char* buffer = new char[4]; //create a buffer to store the length of the message
    QDataStream Stream(Socket); //create a QDataStream object to read the length of the message
    Stream.setByteOrder(QDataStream::LittleEndian); //set the byte order to little endian

    bool lenReceived = false; //create a boolean to store if the length has been received
    int LenMsg; //create a variable to store the length of the message
    while (!lenReceived){
    lenReceived = true; //set lenReceived to true
    Stream.startTransaction(); //start a transaction
    uint temp = 4;
    do{
//        Stream.readBytes(buffer, temp);
    Stream.readRawData(buffer, 4); //read the length of the message
//        buffer = (char*)((std::string)Socket->read(4)).c_str();
    }while(((std::string)buffer).length() < 4); //if the length is not 4 characters long, read the length again
    Stream.commitTransaction(); //commit the transaction
    try { //try to convert the length of the message to an integer
        if (secure){ //if the message is secure=
            LenMsg = std::stoi(Encryptor->runEncDec((std::string) buffer)); //convert the length of the message to an integer
        }else{ //if the message is not secure
            LenMsg = std::stoi((std::string) buffer); //convert the length of the message to an integer
        } 
    } catch (std::invalid_argument){ //if the length of the message is not an integer
        try{ //try to convert the length of the message to an integer
            LenMsg = std::stoi((std::string) buffer); //convert the length of the message to an integer
        }catch (std::invalid_argument){ //if the length of the message is not an integer
            lenReceived = false; //set lenReceived to false
            std::cout << "RECV LEN ERROR was: " << Encryptor->runEncDec((std::string) buffer) << std::endl;
             std::cout << "RECV LEN ERROR was: " << ((std::string) buffer) << std::endl;//print the length of the message
            std::string ErrorMsg = "^^RECVERROR^^"; //create a string to store the error message
            Socket->write(ErrorMsg.c_str()); //send the error message to the server
            Socket->waitForBytesWritten(10000); //wait for the error message to be sent
        } //end of try-catch for the length of the message being not an integer
      }
}
    Socket->write(((std::string)("^^OKKKKKKKK^^")).c_str()); //send a message to the server to say that the length of the message has been received
    buffer = new char[LenMsg]; //create a buffer to store the message

    Socket->waitForReadyRead(3000); //wait for the socket to be ready to read
    Stream.startTransaction(); //start a transaction
    do{
    Stream.readRawData(buffer, LenMsg); //read the message
    }while(((std::string)buffer).length() < LenMsg); //if the length of the message is not the same as the length of the message, read the message again
    Stream.commitTransaction(); //commit the transaction
    if (secure){ //if the message is secure
        return Encryptor->runEncDec((std::string) buffer).substr(0, LenMsg); //return the message
    }
    std::cout << "SIZE = " << LenMsg << " and LenMsg was " << LenMsg << std::endl; //print the length of the message and the length of the message that was received
    std::cout << buffer << std::endl; //print the message
    return ((std::string)buffer).substr(0, LenMsg); //return the message
}
