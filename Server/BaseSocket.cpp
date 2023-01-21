#include "BaseSocket.h"

BaseSocket &BaseSocket::MainSocket() {
    static BaseSocket MainSock;
    return MainSock;
}

BaseSocket::BaseSocket() { // Initialize WinSock here
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        std::cout << "WSAStartup failed with error: " << iResult << std::endl;
        exit(1);
    }
}

SOCKET BaseSocket::CreateListener() {
    SOCKET tempSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (tempSocket == INVALID_SOCKET) {
        std::cout << "Error at socket(): " << WSAGetLastError() << std::endl;
        WSACleanup();
        exit(1);
    }
    return tempSocket;
}

void BaseSocket::setSockAdr(char *IP, int Port) {
    ListenSocket  = CreateListener();
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr(IP);
    service.sin_port = htons(Port);
}

