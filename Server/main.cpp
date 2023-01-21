//#include "ConnectionHandler.h"
#include "dbHandler.h"
#include "Server.h"
#include <vector>
#include "Accounts.h"
#include "ClientsHandler.h"

int main() {
    Accounts::adminPanel();
    Server S1((char *)((std::string)"127.0.0.1").c_str(), 8080, 30); // Create a new Server on IP
    dbHandler* test = new dbHandler((char*)((std::string)"..\\VRBankDB.db").c_str());
    ClientsHandler* store = &ClientsHandler::getHandle();
    while (true){
        SOCKET temp1 = S1.AcceptConn();
        SOCKET temp2 = S1.AcceptConn();
        if (store->spacesLeft() <= 0){
            std::cout << "[-] Connection Limit Reached" << std::endl;
            while (store->spacesLeft() <= 0){}
        }
        std::thread t([&](){
            std::cout << "[+] Started. Conn" << std::endl;
            new ConnectionHandler(temp1, temp2, test);
        });
        t.detach();
    }
}
