#pragma once
#include "Linker.h"
#include "dbHandler.h"
class ConnectionHandler {
private:
    dbHandler* DBHandler;
    SOCKET sock;
    Linker *Conn, *ConnSender;
    std::string UniqueID;

public:
    ConnectionHandler(SOCKET, SOCKET, dbHandler*); // Create a new Linker on the selected Socket
    void sendData(std::string); // Call Over Send from Linker
    void handleConn(); // Call over recv from Linker

};

