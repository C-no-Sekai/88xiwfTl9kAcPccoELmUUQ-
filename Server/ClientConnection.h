#ifndef CLIENTCONNECTION_H
#define CLIENTCONNECTION_H
#include <QTcpSocket>
#include "EncDec.h"

class ClientConn{
private:
    QTcpSocket *Socket; //create a new socket
    EncDec *Encryptor; //create a new EncDec object
public:
    ClientConn(char*, int); //constructor
    void sendMsg(char*, int, bool sendLenOnly = false); //send a message to the server
    std::string getKey(); //get the key from the server
    std::string recvMsg(bool secure = true); //recieve a message from the server
    bool connectionEstablished; //create a boolean to store whether or not the connection is established
};

#endif // CLIENTCONNECTION_H
