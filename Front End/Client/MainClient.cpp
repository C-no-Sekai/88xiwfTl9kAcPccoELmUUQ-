#include "MainClient.h"
#include <iostream>
using namespace std;
MainClient::MainClient(char *IP, int Port) : MainSocket(IP, Port){}

SOCKET MainClient::Connect(){
    int iResult;
    if (ListenSocket == INVALID_SOCKET) {
        cout << "socket failed with error: " << WSAGetLastError() << endl;
        WSACleanup();
        exit(1);
    }

    iResult = connect(ListenSocket, (SOCKADDR*) &service, sizeof(service) );
    if ( iResult == SOCKET_ERROR) {
        closesocket (ListenSocket);
        cout << "Unable to connect to server: " << WSAGetLastError() << endl;
        WSACleanup();
        exit(1);
    }
    return ListenSocket;
}