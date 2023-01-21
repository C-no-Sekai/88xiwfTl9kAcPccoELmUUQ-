#include "Communicator.h"
#include <iostream>
#include <thread>
using namespace std;
Communicator::Communicator(SOCKET foreignSocket){
    sock = foreignSocket;
//    RecvData();
}
void Communicator::SendData(char* data){
    if (send( sock, data, (int)strlen(data), 0 ) == SOCKET_ERROR){
        cout << "send failed with error: " << WSAGetLastError() << endl;
        closesocket(sock);
    }
}

void Communicator::RecvData() {
    int iResult;
    char recvbuf[4096];
    int recvbuflen = 4096;
    do {
        iResult = recv(sock, recvbuf, recvbuflen, 0);
    } while (iResult > 0);
    cout << recvbuf << endl;
}
