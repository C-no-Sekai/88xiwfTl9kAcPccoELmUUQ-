#pragma once
#include "ConnectionHandler.h"
#include <array>
#include <vector>
extern std::vector<ConnectionHandler*> tempStore;

struct ClientHandler{
    std::string ID;
    ConnectionHandler *receiver;
    ConnectionHandler *sender;
};

class ClientsHandler { // Declaring as Singleton
private:
    ClientsHandler();
    ClientsHandler(const ClientsHandler&);
    ClientsHandler& operator=(const ClientsHandler&);

    std::array<ClientHandler, 30> store;
    int calcIndex(const std::string);
    int spaceLeft = 30;
public:
    static ClientsHandler& getHandle();
    void addRecord(ClientHandler&);
    ConnectionHandler* getReceiver(std::string);
    void removeRecord(const std::string);
    void addReceiver(ConnectionHandler&, std::string);
    int spacesLeft();
    bool isPresent(const std::string);
    void sendMsg(std::string, std::string);
};
