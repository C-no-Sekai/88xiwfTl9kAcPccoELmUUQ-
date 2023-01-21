#ifndef SERVER_MAINSOCKET_H
#define SERVER_MAINSOCKET_H
#include <winsock2.h>
#include <string>

using namespace std;


class MainSocket {
public:
    SOCKET ListenSocket;
    sockaddr_in service;
    SOCKET CreateListener();
    MainSocket(char*, int);
    // Features to be moved later
};


#endif //SERVER_MAINSOCKET_H
