#include "MainSocket.h"
#include <iostream>
using namespace std;
SOCKET MainSocket::CreateListener() {
    SOCKET tempSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (tempSocket == INVALID_SOCKET) {
        cout << "Error at socket(): " << WSAGetLastError() << endl;
        WSACleanup();
        exit(1);
    }
    return tempSocket;
}
MainSocket::MainSocket(char* IP, int Port) {
    ListenSocket  = CreateListener();
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr(IP);
    service.sin_port = htons(Port);
}

