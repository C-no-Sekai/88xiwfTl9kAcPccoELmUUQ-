#include <iostream>
#include <winsock2.h>

using namespace std;
int main() {
    //----------------------
    // Declare and initialize variables.
    WSADATA wsaData;
    int iResult;

    SOCKET ConnectSocket = INVALID_SOCKET;
    struct sockaddr_in clientService;

    char *sendbuf = "this is a test";
    char recvbuf[512];
    int recvbuflen = 512;

    //----------------------
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != NO_ERROR) {
        cout <<"WSAStartup failed " << iResult << endl;
        return 1;
    }
    //----------------------
    // Create a SOCKET for connecting to server
    ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ConnectSocket == INVALID_SOCKET) {
        cout << "Error at socket(): " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }
    //----------------------
    // The sockaddr_in structure specifies the address family,
    // IP address, and port of the server to be connected to.
    clientService.sin_family = AF_INET;
    clientService.sin_addr.s_addr = inet_addr( "127.0.0.1");
    clientService.sin_port = htons( 8080 );

    //----------------------
    // Connect to server.
    iResult = connect( ConnectSocket, (SOCKADDR*) &clientService, sizeof(clientService) );
    if ( iResult == SOCKET_ERROR) {
        closesocket (ConnectSocket);
        cout << "Unable to connect to server: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    // Send an initial buffer
//    iResult = send( ConnectSocket, sendbuf, (int)strlen(sendbuf), 0 );
//    if (iResult == SOCKET_ERROR) {
//        printf("send failed: %d\n", WSAGetLastError());
//        closesocket(ConnectSocket);
//        WSACleanup();
//        return 1;
//    }

    cout << "Bytes Sent: " << iResult << endl;
    // shutdown the connection since no more data will be sent
    iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        cout << "shutdown failed: " <<  WSAGetLastError() << endl;
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    // Receive until the peer closes the connection
    do {

        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if ( iResult > 0 )
            cout << "Bytes received: " << iResult << endl;
        else if ( iResult == 0 )
            cout << "Connection closed" << endl;
        else
            cout << "recv failed: " << WSAGetLastError() << endl;
            cout << recvbuf;
    } while( iResult > 0 );

    // cleanup
    closesocket(ConnectSocket);
    WSACleanup();
    cin.get();
    return 0;
}

































//#include <iostream>
//#include <thread>
//#include <ws2tcpip.h>
//#include <winsock2.h>
//using namespace std;
//
//int main(){
//    // Initialize Winsock
//    WSADATA wsaData;
//    int iResult = 0;
//
//    SOCKET ListenSocket = INVALID_SOCKET;
//    sockaddr_in service;
//
//    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
//    if (iResult != NO_ERROR) {
//        wprintf(L"WSAStartup() failed with error: %d\n", iResult);
//        return 1;
//    }
//
//
//
//    SOCKET ConnectSocket;
//    char buffer[1024] = { 0 };
//    ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
////    int sockFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
//    struct sockaddr_in saAdd{};
//    saAdd.sin_family = AF_INET;
//    saAdd.sin_port = 8080;
//    saAdd.sin_addr.s_addr = inet_addr("10.7.170.127");
//
//    connect(ConnectSocket, (SOCKADDR *) &saAdd, sizeof(saAdd));
//    recv(ConnectSocket, buffer, 1024, 0);
//    cout << buffer;
//}