#ifndef SERVER_MAINSERVER_H
#define SERVER_MAINSERVER_H
#include "MainSocket.h"
using namespace std;
class MainServer: public MainSocket{
public:
    MainServer(char*, int, int);
    void BindSock();
    void StartListener(int);
    SOCKET AcceptConn();
};
#endif //SERVER_MAINSERVER_H
