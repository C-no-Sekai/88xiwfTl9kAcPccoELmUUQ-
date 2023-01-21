#include "Linker.h"
#include <iostream>
Linker::Linker(SOCKET Sock, std::string key) {
    this->Sock = Sock;
    Encryptor = new EncDec(key);
}

void Linker::sendKey(std::string msg, bool last){
    if (last) msg = Encryptor->runEncDec(msg);
    std::cout << msg << std::endl;
    if (send(Sock, msg.c_str(), msg.length(), 0) == SOCKET_ERROR){
        std::cout << "[-] Send Failed with Error: " << WSAGetLastError() << std::endl;
    }
}
void Linker::sendData(std::string msg) {
    std::string tempString = std::to_string(msg.length());
    for (int i = tempString.length(); i < 4; i++) tempString = "0" + tempString;
    std::cout << "SENDING: " << msg << std::endl;
    msg = Encryptor->runEncDec(msg);
    tempString = Encryptor->runEncDec(tempString);
    char temp[13];
    do {
        std::cout << "[-] Sending w8" << std::endl;
        if (send(Sock, tempString.c_str(), 4, 0) == SOCKET_ERROR) {
            std::cout << "[-] Send Failed with Error: " << WSAGetLastError() << std::endl;
        }
        recv(Sock, temp, 13, 0);
        std::cout << "Received: " << Encryptor->runEncDec((std::string)temp).substr(2, 9) << std::endl;
    }while (Encryptor->runEncDec(std::string(temp)).find("RECVERROR") != std::string::npos);

    if (send(Sock, msg.c_str(), msg.length(), 0) == SOCKET_ERROR){
        std::cout << "[-] Send Failed with Error: " << WSAGetLastError() << std::endl;
    }
}
std::string Linker::recvDataSize(){
    char temp[4];
    recv(Sock, temp, 4, 0);
    std::string returnedLen(temp);
    std::cout << "RECEIVED is " << Encryptor->runEncDec(returnedLen) << std::endl;
    std::cout << returnedLen.substr(0, 4);
    return Encryptor->runEncDec(returnedLen);
}
std::string Linker::recvData() {
    int LenMsg;
    char LenBuf[4];
    bool lenReceived = false;
    while (!lenReceived) {
        lenReceived = true;
        do {
            recv(Sock, LenBuf, 4, 0);
        } while (((std::string) LenBuf).length() < 4);
        try {
            LenMsg = std::stoi(Encryptor->runEncDec((std::string) LenBuf));
        } catch(std::invalid_argument) {
            lenReceived = false;
            std::cout << "Invalid Len; " << Encryptor->runEncDec((std::string) LenBuf) << std::endl;
            sendKey("^^RECVERROR^^", true);
        }
    }
    sendKey("^^OKKKKKKKK^^", true);

    char *recvbuf = new char[LenMsg];
    do {
        recv(Sock, recvbuf, LenMsg, 0);
    } while (((std::string) recvbuf).length() < LenMsg);
    std::string cipher(recvbuf);
    delete[] recvbuf;
    return Encryptor->runEncDec(cipher.substr(0, LenMsg));
}