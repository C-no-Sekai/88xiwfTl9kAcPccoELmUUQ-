#include "MainSocket.h"
#include <iostream>
using namespace std;
SOCKET MainSocket::CreateListener() {
    return socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}
MainSocket::MainSocket(char* IP, int Port) {
    ListenSocket  = CreateListener();
    if (ListenSocket == INVALID_SOCKET) {
        cout << "socket failed with error: " << WSAGetLastError() << endl;
        WSACleanup();
        exit(1);
    }
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr(IP);
    service.sin_port = htons(Port);
}

