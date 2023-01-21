// Singleton Class Initialize Socket Listeners Works as template for both Client and Server
#pragma once
#include <winsock2.h>
#include <iostream>

class BaseSocket {
private:
    BaseSocket();
    BaseSocket(const BaseSocket&);
    BaseSocket& operator=(const BaseSocket&);
    SOCKET CreateListener();
public:
    SOCKET ListenSocket;
    void setSockAdr(char*, int);
    sockaddr_in service;
    static BaseSocket& MainSocket();
};

