#include "ClientConnection.h"

ClientConn::ClientConn(char *ip, int port) {
    connectionEstablished = true;
    Sock = &BaseSocket::MainSocket();
    Sock->setSockAdr(ip, port);
//    unsigned long iMode = -1;
//    ioctlsocket(Sock->ListenSocket, FIONBIO, &iMode);
    if (connect(Sock->ListenSocket, (SOCKADDR*) &(Sock->service), sizeof(Sock->service)) == SOCKET_ERROR) {
        std::cout << "[-] Connect failed with error: " << WSAGetLastError() << std::endl;
        connectionEstablished = false;
        return;
    }
    SockReceiver = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    connect(SockReceiver, (SOCKADDR*) &(Sock->service), sizeof(Sock->service));

//    iMode = 0;
//    ioctlsocket(Sock->ListenSocket, FIONBIO, &iMode);
    // Receive the key
    std::string key = getKey(25, true);
    std::string temp = key, lenString;
    do{
        key = temp;
        Encryptor = new EncDec(key);
        std::cout << "Received length was: " << key.length() << std::endl;
        std::cout << "Key was: " << key << std::endl;
        lenString = std::to_string(key.length());
        for (int i = lenString.length(); i < 4; i++) lenString = "0" + lenString;
        send(Sock->ListenSocket, Encryptor->runEncDec(lenString).c_str(), 4, 0);
        temp.clear();
        temp = getKey(25, true);
        std::cout<<"Key was " << temp <<std::endl;
    }while (Encryptor->runEncDec(temp) != key);
}

std::string ClientConn::getKey(int len, bool sender) {
//    char* key = new char[len];
    char key[1024];
    int iResult;
    do{
    if  (sender){
        iResult = recv(SockReceiver, key, len, 0);
    }else{
        iResult = recv(Sock->ListenSocket, key, len, 0);
    }
    std::cout << "Yes u were right" << std::endl;
    }while(iResult > 0 && ((std::string)key).length() < len);
//    std::cout << ((std::string)key).length();
    std::cout<<"Key was " << ((std::string)key).substr(0, len) <<std::endl;
    return ((std::string)key).substr(0, len);
}

void ClientConn::sendMsg(char * msg, int LenMsg) {
    std::string lenString = std::to_string(LenMsg);
    for (int i = lenString.length(); i < 4; i++) lenString = "0" + lenString;
    do {
        send(Sock->ListenSocket, Encryptor->runEncDec(lenString).c_str(), 4, 0);
    } while(Encryptor->runEncDec(getKey(13)).substr(2, 9) == "RECVERROR");
        std::cout << "Test" << std::endl;
    send(Sock->ListenSocket, Encryptor->runEncDec(msg).c_str(), LenMsg, 0);
}

std::string ClientConn::recvMsg() {
    bool lenReceived = false;
    int len, iResult;
    while (!lenReceived){
        char *LenBuf = new char[4];
        lenReceived = true;
        do {
           iResult =  recv(SockReceiver, LenBuf, 4, 0);
        } while (((std::string)LenBuf).length() < 4 && iResult > 0);
        try{
            len = std::stoi(Encryptor->runEncDec((std::string)LenBuf));
            delete[] LenBuf;
        } catch(std::invalid_argument){
            lenReceived = false;
            delete[] LenBuf;
            std::cout << "Requesting Resend" << std::endl;
            send(SockReceiver, Encryptor->runEncDec("^^RECVERROR^^").c_str(), 13, 0);
        }
    }
    send(SockReceiver, Encryptor->runEncDec("^^OKKKKKKKK^^").c_str(), 13, 0);
    std::cout << "Received Size was " << len << std::endl;

    char *recvBuf = new char[len + 10];
    do {
        iResult = recv(SockReceiver, recvBuf, len, 0);
    } while (((std::string)recvBuf).length() < len && iResult > 0);
    std::cout << "Message was: " <<  Encryptor->runEncDec((std::string)recvBuf).substr(0, len) << std::endl;
    std::string msgReceived = ((std::string)recvBuf).substr(0, len);
    delete[] recvBuf;
    return Encryptor->runEncDec(msgReceived);
}
