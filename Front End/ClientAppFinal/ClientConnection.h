#pragma once
#include "BaseSocket.h"
#include "EncDec.h"
class ClientConn {
private:
    BaseSocket *Sock;
    EncDec* Encryptor;
    SOCKET SockReceiver;
public:
    ClientConn(char*, int); // Create Connection get Key and Start Listener
    void sendMsg(char*, int);
    std::string getKey(int len = 25, bool sender = false);
    std::string recvMsg();
    bool connectionEstablished;
};

