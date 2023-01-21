#pragma once
#include "BaseSocket.h"
class Server {
private:
    BaseSocket *Sock;
    std::string key;
public:
    Server(char*, int, int);
    void BindSock();
    void StartListener(int);
    SOCKET AcceptConn();
};
