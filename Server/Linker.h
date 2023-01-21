#pragma once
#include <winsock2.h>
#include <string>
#include <thread>
#include "EncDec.h"

#include <iostream>
class Linker {
private:
    SOCKET Sock;
public:
    Linker(SOCKET, std::string);
    EncDec *Encryptor;
    void sendData(std::string);
    std::string recvDataSize();
    std::string recvData();
    void sendKey(std::string, bool last = false);
    ~Linker(){std::cout << "ERROR" << std::endl;}
};
