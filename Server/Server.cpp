#include "Server.h"
Server::Server(char *IP, int Port, int MaxConn) {
    Sock = &BaseSocket::MainSocket();
    Sock->setSockAdr(IP, Port);
    BindSock();
    StartListener(MaxConn);
}

void Server::BindSock() {
    if (bind(Sock->ListenSocket,(SOCKADDR *) &(Sock->service), sizeof (Sock->service)) == SOCKET_ERROR) {
        std::cout << "bind failed with error: " << WSAGetLastError() << std::endl;
        closesocket(Sock->ListenSocket);
        WSACleanup();
        exit(1);
    }
}

void Server::StartListener(int Max) {
    if (listen(Sock->ListenSocket, Max) == SOCKET_ERROR) {
        std::cout << "listen failed with error: " << WSAGetLastError() << std::endl;
        closesocket(Sock->ListenSocket);
        WSACleanup();
        exit(1);
    }
}

SOCKET Server::AcceptConn() {
    SOCKET AcceptSocket = INVALID_SOCKET;
    AcceptSocket = accept(Sock->ListenSocket, NULL, NULL);
    while (AcceptSocket == INVALID_SOCKET) {
        std::cout << "accept failed with error: " << WSAGetLastError();
        AcceptSocket = accept(Sock->ListenSocket, NULL, NULL);
    }
    return AcceptSocket;
}