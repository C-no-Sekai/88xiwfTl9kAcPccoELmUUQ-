//#include <thread>
//#include <winsock2.h>
//#include <iostream>
//using namespace std;
//int main()
//{
//    //----------------------
//    // Initialize Winsock.
//    WSADATA wsaData;
//    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
//    if (iResult != NO_ERROR) {
//        cout << "WSAStartup failed with error: " << iResult << endl;
//        return 1;
//    }
//    //----------------------
//    // Create a SOCKET for listening for
//    // incoming connection requests.
//    SOCKET ListenSocket;
//    ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//    if (ListenSocket == INVALID_SOCKET) {
//        cout << "socket failed with error: " << WSAGetLastError() << endl;
//        WSACleanup();
//        return 1;
//    }
//    //----------------------
//    // The sockaddr_in structure specifies the address family,
//    // IP address, and port for the socket that is being bound.
//    sockaddr_in service{};
//    service.sin_family = AF_INET;
//    char *a = "127.0.0.1";
//    service.sin_addr.s_addr = inet_addr(a);
//    service.sin_port = htons(8080);
//
//    if (bind(ListenSocket,(SOCKADDR *) & service, sizeof (service)) == SOCKET_ERROR) {
//        cout << "bind failed with error: " << WSAGetLastError() << endl;
//        closesocket(ListenSocket);
//        WSACleanup();
//        return 1;
//    }
//    //----------------------
//    // Listen for incoming connection requests.
//    // on the created socket
//    if (listen(ListenSocket, 3) == SOCKET_ERROR) {
//        cout << "listen failed with error: " << WSAGetLastError() << endl;
//        closesocket(ListenSocket);
//        WSACleanup();
//        return 1;
//    }
//    //----------------------
//    // Create a SOCKET for accepting incoming requests.
//    SOCKET AcceptSocket;
//
//
//    cout << "Waiting for client to connect...\n";
//
//    //----------------------
//    // Accept the connection.
//    AcceptSocket = accept(ListenSocket, NULL, NULL);
//    if (AcceptSocket == INVALID_SOCKET) {
//        cout << "accept failed with error: " << WSAGetLastError();
//        closesocket(ListenSocket);
//        WSACleanup();
//        return 1;
//    } else
//        cout << "Client connected.\n";
//
//    char *sendbuf = "Client: sending data test";
//
//
//    //----------------------
//    // Send an initial buffer
//    iResult = send( AcceptSocket, sendbuf, (int)strlen(sendbuf), 0 );
//    if (iResult == SOCKET_ERROR) {
//        cout << "send failed with error: " << WSAGetLastError() << endl;
//        closesocket(AcceptSocket);
//        WSACleanup();
//        return 1;
//    }
//    // No longer need server socket
//    closesocket(ListenSocket);
//    WSACleanup();
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////#include <iostream>
////#include <thread>
////#include <ws2tcpip.h>
////#include <winsock2.h>
////using namespace std;
////
////int main(){
//////    int sockfd = socket(domain, type, protocol);
//////    const struct sockaddr add = {"10.7.170.127", "8080"};
////
////    // Initialize Winsock
////    WSADATA wsaData;
////    int iResult = 0;
////
////    SOCKET ListenSocket = INVALID_SOCKET;
////    sockaddr_in service;
////
////    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
////    if (iResult != NO_ERROR) {
////        wprintf(L"WSAStartup() failed with error: %d\n", iResult);
////        return 1;
////    }
////
////    SOCKET sockFileDescriptor;
////    sockFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
////    if (sockFileDescriptor == INVALID_SOCKET){
////        cout << "INVALID!!!  " << WSAGetLastError() << endl;
////    }
////    struct sockaddr_in saAdd{};
////    saAdd.sin_family = AF_INET;
////    saAdd.sin_port = 8080;
////    saAdd.sin_addr.s_addr = inet_addr("10.7.170.127");
////    int ssbindSize = sizeof(saAdd);
////    bind(sockFileDescriptor, (SOCKADDR*) &saAdd, sizeof(saAdd));
////    if (listen(sockFileDescriptor, 3) == SOCKET_ERROR){
////        cout << "SOCK LISTEN ERROR" << endl;
////    }
////
////    int client_socket_fd;
////    client_socket_fd = accept(sockFileDescriptor, NULL, NULL);
////
//////    int new_sock = accept(sockFileDescriptor, NULL, NULL);
////    send(client_socket_fd, "HI", sizeof("HI"), 0);
////    cout << "Data Sent";
////    }