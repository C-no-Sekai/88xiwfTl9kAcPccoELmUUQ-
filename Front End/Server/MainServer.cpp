#include "MainServer.h"
#include <iostream>
using namespace std;

MainServer::MainServer(char *IP, int Port, int Max) : MainSocket(IP, Port) {
    BindSock();
    StartListener(Max);
}

void MainServer::BindSock() {
    if (bind(ListenSocket,(SOCKADDR *) & service, sizeof (service)) == SOCKET_ERROR) {
        cout << "bind failed with error: " << WSAGetLastError() << endl;
        closesocket(ListenSocket);
        WSACleanup();
        exit(1);
    }
}

void MainServer::StartListener(int Max) {
    if (listen(ListenSocket, Max) == SOCKET_ERROR) {
        cout << "listen failed with error: " << WSAGetLastError() << endl;
        closesocket(ListenSocket);
        WSACleanup();
        exit(1);
    }
}

SOCKET MainServer::AcceptConn() {
    SOCKET AcceptSocket = INVALID_SOCKET;
    AcceptSocket = accept(ListenSocket, NULL, NULL);
    while (AcceptSocket == INVALID_SOCKET) {
        cout << "accept failed with error: " << WSAGetLastError();
        AcceptSocket = accept(ListenSocket, NULL, NULL);
    }
    return AcceptSocket;
}