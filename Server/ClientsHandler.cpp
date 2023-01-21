#include "ClientsHandler.h"
#include <algorithm>
#define totalSize 30

//std::array<ClientHandler, totalSize> ClientsHandler::store;
ConnectionHandler* ClientsHandler::getReceiver(std::string ID){
    int index = calcIndex(ID);
    return store[index].receiver;
}

ClientsHandler &ClientsHandler::getHandle() {
    static ClientsHandler Client;
    return Client;
}
ClientsHandler::ClientsHandler(){
    for (int i = 0; i < totalSize; i++) store[i] = {"", nullptr, nullptr};
}
void ClientsHandler::addRecord(ClientHandler& temp) {
    if (isPresent(temp.ID) and spaceLeft <= 0) return;
    int index = calcIndex(temp.ID);
    while (store[index].ID != "") {
        index++;
        (index == totalSize) && (index = 0);
    }
    spaceLeft--;
    store[index] = temp;
    std::cout << "ADDED RECORD AT " << index << std::endl;
    std::cout << "RECORD PRESENT " << isPresent(temp.ID) << std::endl;
}
bool ClientsHandler::isPresent(const std::string ID) {
    int index = calcIndex(ID), count = 0;
    while (store[index].ID != ID && ++count <= totalSize) (++index < totalSize) && (index = 0);
    if (count >= totalSize) return false;
    return true;
}
void ClientsHandler::removeRecord(const std::string ID) {
    if (!isPresent(ID)) return;
    int index = calcIndex(ID);
    while (store[index].ID != ID){
        index++;
        (index == totalSize) && (index = 0);
    }
    spaceLeft++;
    // Delete Socket
    store[index] = {"", nullptr, nullptr};
}
void ClientsHandler::addReceiver(ConnectionHandler& temp, std::string ID) {
    int index = calcIndex(ID);
    while (store[index].ID != ID) (++index <= totalSize) && (index = 0);
    store[index].receiver = &temp;
}
int ClientsHandler::spacesLeft() {return spaceLeft;}
int ClientsHandler::calcIndex(const std::string ID) {
    // Assigning weights 1 through 6 to ID each element
    int weight = 1, hash = 0;
    for (char i: (std::string)ID){
        hash += weight * int(i);
        weight++;
    }
    hash *= 13;
    return hash % totalSize;
}
void ClientsHandler::sendMsg(std::string id, std::string msg){
    int index = calcIndex(id), count = 0;
    while (store[index].ID != id && ++count <= totalSize) (++index < totalSize) && (index = 0);
    if (count >= totalSize) return;
    store[index].sender->sendData(msg);
}
