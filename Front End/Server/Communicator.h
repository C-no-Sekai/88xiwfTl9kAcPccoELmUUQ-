#ifndef SERVER_COMMUNICATOR_H
#define SERVER_COMMUNICATOR_H
#include <winsock2.h>

class Communicator {
    SOCKET sock;
public:
    Communicator(SOCKET);
    void SendData(char*);
    void RecvData();
};


#endif //SERVER_COMMUNICATOR_H
