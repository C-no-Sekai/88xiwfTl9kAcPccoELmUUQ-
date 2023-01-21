//#include "ConnectionHandler.h"
#include "ClientsHandler.h"
#include <random>
#include <iostream>

ClientsHandler *ClientSub = &ClientsHandler::getHandle();

std::string generateRandString(){
    std::string tempString = "";
    std::uniform_int_distribution<int> lengthString(25, 25);
    std::uniform_int_distribution<int> CharString(0, 255);
    std::random_device rd;
    std::mt19937 gen(rd());

    int sizeString = lengthString(gen);
    for (int i = 0; i < sizeString; i++){
        tempString += (char)CharString(gen);
    }
    return tempString;
};
ConnectionHandler::ConnectionHandler(SOCKET sock, SOCKET sock2, dbHandler* dbHandle){
    this->sock = sock;
    UniqueID = "";
    DBHandler = dbHandle;

    std::cout << "[+] Connection Received" << std::endl;
    std::string key = generateRandString();
    std::cout << "[+] Chosen is  " << key << std::endl;
    Conn = new Linker(sock, key); // For Receiving
    ConnSender = new Linker(sock2, key); // For Sending
    int count = 0;
    std::string tempString = std::to_string(key.length());
    for (int i = tempString.length(); i < 4; i++) tempString = "0" + tempString;
    do {
        if (count >= 10){
            closesocket(sock);
            delete this;
            break;
        }
        ConnSender->sendKey(key);
        std::cout << "Sent: " << ++count << std::endl << "SIZE WAS: " << tempString << std::endl;
    } while (Conn->recvDataSize() != tempString);
    ConnSender->sendKey( key, true);
    std::cout << "[+] Key Generated and sent" << std::endl;

    handleConn();

}
void ConnectionHandler::sendData(std::string msg) {ConnSender->sendData(msg);}
void ConnectionHandler::handleConn() {
    std::string ClientMsg = "";
    while (true){
        ClientMsg = Conn->recvData();
        if (ClientMsg == "!!QUIT!!"){ // For Quitting
            if (UniqueID != "") {
                ClientSub->removeRecord(UniqueID);
            }
            std::cout << "[-] Client Logged out" << std::endl;
            delete this;
            break;

        }else if(ClientMsg.substr(0, 3) == "^L^"){ // For Login
            std::cout << "MESSAGE RECEIVED: " << ClientMsg << std::endl;
            int breakPoint = ClientMsg.find("\n\n");
            std::cout << "MY index is: " << breakPoint << std::endl;
            if (DBHandler->UserPassInDB(ClientMsg.substr(3, breakPoint - 3), ClientMsg.substr(breakPoint + 2, ClientMsg.length() - breakPoint - 2))){
                UniqueID = (char *)ClientMsg.substr(3, breakPoint - 3).c_str();
                std::cout << UniqueID << std::endl;
                ClientHandler temp = {UniqueID, nullptr, this};
                ClientSub->addRecord(temp);
                ConnSender->sendData("^LOGINSUCCESS^");
                ConnSender->sendData(DBHandler->homePageDetails(ClientMsg.substr(3, breakPoint - 3)));
            }else{
                std::cout << "BAD" << std::endl;
                ConnSender->sendData("^LGNINVALID^");
            }
        }else if (ClientMsg.substr(0, 13) == "^GetHomePage^"){
            std::cout << "WONDERFUL ELEGANT" << std::endl;
            ConnSender->sendData(DBHandler->homePageDetails(ClientMsg.substr(13, ClientMsg.length() - 13)));
//            UniqueID = ClientMsg.substr(5, ClientMsg.length() - 5);
//            std::cout << (std::string)UniqueID << std::endl;
//            std::cout << "ID in " << ClientSub->isPresent(UniqueID) << std::endl;
//            ClientSub->addReceiver(*this, UniqueID);
//            std::cout << "WONDERFUL ELEGANT" << std::endl;
//            break;
        }else if(ClientMsg.substr(0, 3) == "^S^"){ // For SignUp name username password dob
            int start = 3, breakpoint = 0, index = 0;
            std::string params[5];
            do{
                breakpoint = ClientMsg.find("\n\n", breakpoint + 1);
                std::cout << ClientMsg.substr(start, breakpoint - start) << std::endl;
                params[index++] = ClientMsg.substr(start, breakpoint - start);
                start = breakpoint + 2;
            } while (breakpoint != std::string::npos);

//            DBHandler->addDefaultAccount(params);
            DBHandler->addUser(params[0], params[1], params[2], params[3], "S", params[4],"0");
        }else if(ClientMsg.substr(0, 5) == "^VID^"){ //ID verification in Transfer
            ConnSender->sendData(DBHandler->getTransactionDetails(ClientMsg.substr(5, ClientMsg.length() - 5)));
        }else if(ClientMsg.substr(0, 6) == "^MTRS^") { // Make Transactions Sender, Receiver, amount
            int start = 6, breakpoint = 0, index = 0;
            std::string params[3];
            do{
                breakpoint = ClientMsg.find("\n\n", breakpoint + 1);
                std::cout << ClientMsg.substr(start, breakpoint - start) << std::endl;
                params[index++] = ClientMsg.substr(start, breakpoint - start);
                start = breakpoint + 2;
            } while (breakpoint != std::string::npos);

            if (!DBHandler->makeTransaction(params[0], params[1], params[2])) {
                ConnSender->sendData("^MTRS^INVALID");
            } else {
                ConnSender->sendData("^MTRS^VALID");
            }
            ClientSub->sendMsg(params[1], DBHandler->homePageDetails(params[1]));
        }else if(ClientMsg.substr(0, 6) == "^LOAN^") {
            std::string params[3];
            int start = 6, breakpoint = 0, index = 0;
            do{
                breakpoint = ClientMsg.find("\n\n", breakpoint + 1);
                std::cout << ClientMsg.substr(start, breakpoint - start) << std::endl;
                params[index++] = ClientMsg.substr(start, breakpoint - start);
                start = breakpoint + 2;
            } while (breakpoint != std::string::npos);
            if (DBHandler->loanApplicable(params[0], params[1], params[2])) {
                ConnSender->sendData((char*)((std::string)"^LOANACCEPT^").c_str());
            }
            ConnSender->sendData((char*)((std::string)"^LOANREJECTED^").c_str());

        }else std::cout << "Message: " << ClientMsg << std::endl;
    }
}
