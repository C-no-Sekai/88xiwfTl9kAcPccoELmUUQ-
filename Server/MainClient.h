#ifndef CLIENT_MAINCLIENT_H
#define CLIENT_MAINCLIENT_H
#include <winsock2.h>
#include "MainSocket.h"
class MainClient: public MainSocket{
public:
    MainClient(char*, int);
    SOCKET Connect();
};


#endif //CLIENT_MAINCLIENT_H
