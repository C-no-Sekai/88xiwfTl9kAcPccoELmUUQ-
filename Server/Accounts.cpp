#include "Accounts.h"
#include <string>
#include <thread>
#include <chrono>

ClientsHandler *Accounts::ClientSub = &ClientsHandler::getHandle();

dbHandler* Accounts::dbHandle = new dbHandler((char*)((std::string)"..\\VRBankDB.db").c_str());
Accounts* Accounts::adminPanel(){
     // Creating Database Connection
    static Accounts adminInterface;
    std::thread dailyInterest([&](){
        while(true) {
            std::this_thread::sleep_for(std::chrono::days(1));
            dbHandle->addDailyInterest();
        }
    });
    dailyInterest.detach();

    std::thread monthlyAddInterest([&](){
        std::vector<std::string> receiverStore;
        while(true) {
            receiverStore.clear();
            std::this_thread::sleep_for(std::chrono::months(1));
            receiverStore = dbHandle->addMonthlyInterest();
            for (std::string receiver: receiverStore){
                if (ClientSub->isPresent(receiver)){
                    ClientSub->sendMsg(receiver, dbHandle->homePageDetails(receiver));
                }
            }
        }
    });
    monthlyAddInterest.detach();

    return &adminInterface; // Returning Reference to Class
}
void Accounts::runCustomQuery(const char * Command, int (callback)(void *, int, char **, char **)) { // Run Custom Query
    dbHandle -> dbRunSQL(Command, callback);
}
