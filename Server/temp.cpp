#include "temp.h"

ClientConn::ClientConn(char *ip, int port) {
    connectionEstablished = true;
    Sock = &BaseSocket::MainSocket();
    Sock->setSockAdr(ip, port);
    if (connect(Sock->ListenSocket, (SOCKADDR*) &(Sock->service), sizeof(Sock->service)) == SOCKET_ERROR) {
        std::cout << "[-] Connect failed with error: " << WSAGetLastError() << std::endl;
        connectionEstablished = false;
    }
    // Receive the key
    std::string key = getKey(), lenString, temp;
    do{
        Encryptor = new EncDec(key);
        lenString = std::to_string(key.length());
        for (int i = lenString.length(); i < 4; i++) lenString = "0" + lenString;
        send(Sock->ListenSocket, Encryptor->runEncDec(lenString).c_str(), 4, 0);
        temp = getKey();
    }while (Encryptor->runEncDec(temp) != key);
}

std::string ClientConn::getKey(int len) {
    char* key = new char[len];
    do {
        recv(Sock->ListenSocket, key, len, 0);
    } while (len == 32 || ((std::string)key).length() < len);
    return (std::string)key;
}

void ClientConn::sendMsg(char * msg, int LenMsg) {
    std::string lenString = std::to_string(LenMsg);
    for (int i = lenString.length(); i < 4; i++) lenString = "0" + lenString;
    do {
        send(Sock->ListenSocket, Encryptor->runEncDec(lenString).c_str(), 4, 0);
    } while(Encryptor->runEncDec(getKey(13)).substr(3, 9) == "RECVERROR");
    send(Sock->ListenSocket, Encryptor->runEncDec(msg).c_str(), LenMsg, 0);
}

std::string ClientConn::recvMsg() {
    bool lenReceived = false;
    std::string temp, msg;
    int len;

    while (!lenReceived){
        lenReceived = true;
        do {
            recv(Sock->ListenSocket, (char*)temp.c_str(), 4, 0);
        } while (((std::string)temp).length() < 4);
        try{
            len = std::stoi(Encryptor->runEncDec(temp));
        } catch(std::invalid_argument){
            lenReceived = false;
            send(Sock->ListenSocket, Encryptor->runEncDec("^^RECVERROR^^").c_str(), 13, 0);
        }
    }
    send(Sock->ListenSocket, Encryptor->runEncDec("^^OKKKKKKKK^^").c_str(), 13, 0);

    do {
        recv(Sock->ListenSocket, (char*)msg.c_str(), len, 0);
    } while (((std::string)msg).length() < len);
    return Encryptor->runEncDec((std::string)msg);
}
