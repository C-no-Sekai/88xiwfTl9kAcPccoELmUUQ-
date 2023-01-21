#include "dbHandler.h"
#include <iostream>
#include <thread>
#include <chrono>
#include "ClientsHandler.h"

bool doesExist = false;
std::vector<std::string> interestReceivers;
std::string transactions, homePageUserDetails, transactionDetails;
double totalInventory, Balance, loaned;
std::string getCurrentDT(){
    tm* currTM;
    char dateString[100];
    time_t currTime;
    time(&currTime);
    currTM = localtime(&currTime);
    strftime(dateString, 50, "%c", currTM);
    return (std::string)dateString;
}
int getLoan(void *, int, char** values, char**){
    loaned = std::stod(values[0]);
    return 0;
}
int checkCall(void *, int results, char** values, char** columns){
    doesExist = true;
}
int getVisibleBalance(void *, int, char** values, char**){
    Balance = std::stod(values[0]);
    return 0;
}
int calcInventory(void *, int results, char** values, char**){
    for (int i = 0; i < results; i++) totalInventory += std::stod(values[i]);
    return 0;
}
int checkTransactions(void*, int results, char** values, char**){
    for (int i = 0; i < results; i++){
        transactions += (std::string)values[i];
        transactions += "\r\r";
    }
    transactions += "\t\t";
    return 0;
}
int checkHomePageDetails(void* , int results, char** values, char**){
    for (int i = 0; i < results; i++){
        homePageUserDetails += values[i];
        homePageUserDetails += "\n\n";
    }
    return 0;
}
int checkTransactionDetails(void*, int results, char** values, char** columns){
    for (int i = 0; i < results; i++){
        transactionDetails += (std::string)values[i];
        transactionDetails += "\n\n";
    }
    return 0;
}
dbHandler::dbHandler(char * Name, bool verbose) {
    this -> verbose = verbose;
    int response;
    response = sqlite3_open(Name, &dbHandle);
    if (response == SQLITE_NULL){
        std::cerr << "[-] UNABLE TO CREATE ERROR: " << sqlite3_errmsg(dbHandle) << "\n";
        delete this;
    }else if (verbose){
        std::cout << "[+] DataBase Connection Successfully Created\n";
    }
}
dbHandler::~dbHandler() {
    int response;
    response = sqlite3_close(dbHandle);
    if (response == SQLITE_OK){
        verbose && (std::cout << "[+] Successfully Closed DataBase Connection");
    }else{
        std::cerr << "[-] Resource Allocation Failed " << sqlite3_errmsg(dbHandle) << "\n";
    }
}
void dbHandler::dbRunSQL(const char * Command, int(*callback)(void *, int, char**, char**), void* store) {
    char* messageError;
    if (sqlite3_exec(dbHandle, Command, callback, store, &messageError) != SQLITE_OK){std::cerr << "[-] Failed to run Command. ERROR: " << messageError << "\n";
        sqlite3_free(messageError);
    }else if (verbose){
        std::cout << "[+] Command Run Successful\n";
    }
}
bool dbHandler::UserPassInDB(std::string userName, std::string password) {
    doesExist = false;
    std::string SQLCommand = "SELECT username FROM ACCOUNTS WHERE username = '" + userName + "' AND password = '" + password + "';";
    dbRunSQL(SQLCommand.c_str(), checkCall);
    return doesExist;
}
void dbHandler::addDefaultAccount(std::string params[4]) {
    std::string SQLCommand = "INSERT INTO ACCOUNTS (name, qalamID, username, password, dob, type, Balance, interest, doc) VALUES("
                             "'" + params[0] + "', '" + params[1] + "', '" + params[2] + "', '" + params[3] + "', '" + params[4] + "', 'C', 0, 0, '" + getCurrentDT() + "');";
    dbRunSQL(SQLCommand.c_str());
}
std::string dbHandler::getTransactions(std::string UserName) {
    transactions = "";
    std::string SQLCommand = "SELECT sender, receiver, amount FROM TRANSACTIONS WHERE sender = '" + UserName + "' OR receiver = '" + UserName + "' ORDER BY time DESC LIMIT 10;";
    dbRunSQL(SQLCommand.c_str(), checkTransactions);
    int numTransactions = std::count_if(transactions.begin(), transactions.end(), [=](char item) {return (int)item == 9;}) / 2;
    for (; numTransactions < 10; numTransactions++){
        transactions += " \r\r \r\r \t\t";
    }
    transactions += "\n\n";
    return transactions;
}
std::string dbHandler::homePageDetails(std::string UserName) {
    homePageUserDetails = "^DATA^";
    std::string SQLCommand = "SELECT name, Balance + loan FROM ACCOUNTS WHERE username = '" + UserName + "';";
    dbRunSQL(SQLCommand.c_str(), checkHomePageDetails);
    std:: cout << "ljsdafkjalk" << "\n";
    homePageUserDetails.append(getTransactions(UserName));
    std:: cout << "ljsdafkjalk1" << "\n";
    return homePageUserDetails;
}
std::string dbHandler::getTransactionDetails(std::string id){
    transactionDetails = "^MDET^"; // More Details
    std::string SQLCommand = "SELECT name, username, qalamID FROM ACCOUNTS WHERE qalamID = '" + id + "';";
    dbRunSQL(SQLCommand.c_str(), checkTransactionDetails);
    if (transactionDetails == "^MDET^") transactionDetails += "^INVALID^";
    return transactionDetails;
}
bool dbHandler::makeTransaction(std::string Sender, std::string receiver, std::string amount) {
    try{
        std::stod(amount);
    }catch(std::invalid_argument){
        return false;
    }
    std::string SQLCommand;
    // Remove Amount From Sender and Add to Transactions after recording time
    SQLCommand = "UPDATE ACCOUNTS SET Balance = Balance - " + amount + " WHERE username = '" + Sender + "';";
    dbRunSQL(SQLCommand.c_str());
    std::cout << "APPENDING TRANSACTIONS" << std::endl;
    SQLCommand = "INSERT INTO TRANSACTIONS VALUES('" + Sender + "', '" + receiver + "', " + amount + " ,'" + getCurrentDT() + "');";
    dbRunSQL(SQLCommand.c_str());
    std::cout << "APPENDING TRANSACTION FINISHEDS" << std::endl;

    // Remove Tax of 2% for bank
    double tax = 0;
    (std::stod(amount) > 10000) && (tax += 0.02 * std::stod(amount));
    // Check if Savings Account Affected
    double savingsChange = 0;
    doesExist = false;
    SQLCommand = "SELECT type FROM ACCOUNTS WHERE username = '" + Sender + "' AND type = 'S';";
    dbRunSQL(SQLCommand.c_str(), checkCall);
    (doesExist) && (savingsChange -= std::stod(amount));
    amount = std::to_string(std::stod(amount) - tax);
    doesExist = false;
    SQLCommand = "SELECT type FROM ACCOUNTS WHERE username = '" + receiver + "' AND type = 'S';";
    dbRunSQL(SQLCommand.c_str(), checkCall);
    if (doesExist){
        savingsChange += std::stod(amount);
    }

    SQLCommand = "UPDATE ACCOUNTS SET outstanding = Balance WHERE username = '" + receiver + "';";
    dbRunSQL(SQLCommand.c_str());

    // Update Inventory & receiver
    SQLCommand = "UPDATE ACCOUNTS SET Balance = Balance + " + amount + " WHERE username = '" + receiver + "';";
    dbRunSQL(SQLCommand.c_str());
    SQLCommand = "UPDATE INVENTORY SET ownSavings = ownSavings + " + std::to_string(tax) + ", clientSavings = clientSavings + " + std::to_string(savingsChange) + ";";
    dbRunSQL(SQLCommand.c_str());
    return true;
}
void dbHandler::addDailyInterest() {
    std::string SQLCommand = "UPDATE ACCOUNTS SET interest = interest + outstanding * 0.0002739726 WHERE type = 'S' AND outstanding > 1000 AND outstanding < 50000;"; // 10% for between 1000 to 50000 balance
    dbRunSQL(SQLCommand.c_str());
    SQLCommand = "UPDATE ACCOUNTS SET interest = interest + outstanding * 0.0004109589 WHERE type = 'S' AND outstanding >= 50000;"; // 15% for above 50,000
    dbRunSQL(SQLCommand.c_str());
    SQLCommand = "UPDATE ACCOUNTS SET outstanding = Balance WHERE type = 'S';";
    dbRunSQL(SQLCommand.c_str());
}
std::vector<std::string> dbHandler::addMonthlyInterest() {
    interestReceivers.clear();
    std::string SQLCommand = "UPDATE ACCOUNTS SET Balance = Balance + interest, Balance = Balance + interest WHERE type = 'S';";
    dbRunSQL(SQLCommand.c_str());
    SQLCommand = "INSERT INTO TRANSACTIONS (sender, receiver, amount, time) SELECT 'BankInterest', username, interest, '" + getCurrentDT() + "' FROM ACCOUNTS WHERE type = 'S';";
    dbRunSQL(SQLCommand.c_str());
    SQLCommand = "UPDATE ACCOUNTS SET interest = 0";
    dbRunSQL(SQLCommand.c_str());
    return interestReceivers;
}
void dbHandler::giveLoan(std::string option, std::string client, std::string amount){
    std::string SQLCommand = "UPDATE ACCOUNTS SET loan = loan + " + amount + " WHERE username = '" + client + "';";
    dbRunSQL(SQLCommand.c_str());
    SQLCommand = "UPDATE INVENTORY SET ownSavings = ownSavings - " + amount + ";";
    dbRunSQL(SQLCommand.c_str());
    SQLCommand = "INSERT INTO TRANSACTIONS VALUES ('BankInterest', '" + client + "', " + amount + ", '" + getCurrentDT() + "');";
    dbRunSQL(SQLCommand.c_str());

    if (option == "1"){
        std::thread loanInterest([&](){
            int counter = 0;
            std::string SQLCommand = "UPDATE ACCOUNTS SET loanInterest = loanInterest + loan * 0.0022222222 WHERE username = '" + client + "';";
            while(true) {
                std::this_thread::sleep_for(std::chrono::days(1));
                dbRunSQL(SQLCommand.c_str());
                if (++counter == 90) break;
            }
            SQLCommand = "UPDATE ACCOUNTS SET Balance = Balance - (loanInterest + loan) WHERE username = '" + client + "';";
            dbRunSQL(SQLCommand.c_str());
        });
        loanInterest.detach();
    } else if (option == "2"){
        std::thread loanInterest([&](){
            int counter = 0;
            std::string SQLCommand = "UPDATE ACCOUNTS SET loanInterest = loanInterest * 0.0013888888 WHERE username = '" + client + "';";
            while(true) {
                std::this_thread::sleep_for(std::chrono::days(1));
                dbRunSQL(SQLCommand.c_str());
                if (++counter == 180) break;
            }
            SQLCommand = "UPDATE ACCOUNTS SET Balance = Balance - (loanInterest + loan) WHERE username = '" + client + "';";
            dbRunSQL(SQLCommand.c_str());
        });
        loanInterest.detach();
    } else if (option == "3"){
        std::thread loanInterest([&](){
            int counter = 0;
            std::string SQLCommand = "UPDATE ACCOUNTS SET loanInterest = loanInterest * 0.000821917 WHERE username = '" + client + "';";
            while(true) {
                std::this_thread::sleep_for(std::chrono::days(1));
                dbRunSQL(SQLCommand.c_str());
                if (++counter == 365) break;
            }
            SQLCommand = "UPDATE ACCOUNTS SET Balance = Balance - (loanInterest + loan) WHERE username = '" + client + "';";
            dbRunSQL(SQLCommand.c_str());
        });
        loanInterest.detach();
    }
}
bool dbHandler::loanApplicable(std::string option, std::string client, std::string amount){
    double requestedAmount;
    try{
        requestedAmount = std::stod(amount);
    }catch (std::invalid_argument){
        return false;
    }
    totalInventory = 0;
    std::string SQLCommand = "SELECT SUM(ownSavings + clientSavings) FROM INVENTORY;";
    dbRunSQL(SQLCommand.c_str(), calcInventory);
    loaned = 0;
    SQLCommand = "SELECT loan + loanInterest FROM ACCOUNTS WHERE username = '" + client + "';";
    dbRunSQL(SQLCommand.c_str(), getLoan);
    doesExist = false; // Determining Account type is Savings or not
    SQLCommand = "SELECT username FROM ACCOUNTS WHERE username = '" + client + "' type = 'S';";
    dbRunSQL(SQLCommand.c_str(), checkCall);
    Balance = 0;
    dbRunSQL(SQLCommand.c_str(), getVisibleBalance);
    double bankLimit, clientLimit;
    if (doesExist){
        bankLimit = 0.40;
        clientLimit = 1.20;
    } else{
        bankLimit = 0.30;
        clientLimit = 0.70;
    }
    if ((requestedAmount + loaned) > bankLimit * totalInventory || (requestedAmount + loaned) > clientLimit * Balance){
        return false;
    }

    std::thread startLoanProcess([&](){
        std::this_thread::sleep_for(std::chrono::seconds(300));
        giveLoan(option, client, amount);
        ClientsHandler* temp = &ClientsHandler::getHandle();
        temp ->sendMsg(client, homePageDetails(client));
    });
    startLoanProcess.detach();
    return true;
};

bool dbHandler::withDraw(std::string client, std::string amount) {
    Balance = 0;
    std::string SQLCommand = "SELECT Balance FROM ACCOUNTS WHERE username = '" + client + "';";
    dbRunSQL(SQLCommand.c_str(), getVisibleBalance);
    loaned = 0;
    SQLCommand = "SELECT loan + loanInterest FROM ACCOUNTS WHERE username = '" + client + "';";
    dbRunSQL(SQLCommand.c_str(), getLoan);

    if (Balance + loaned < std::stod(amount)){
        return false;
    }

    SQLCommand = "UPDATE ACCOUNTS SET Balance = Balance - " + amount + " WHERE username = '" + client + "';";
    dbRunSQL(SQLCommand.c_str());

    SQLCommand = "INSERT INTO TRANSACTIONS VALUES ('" + client + "', 'WithDrawn', " + amount + ", '" + getCurrentDT() + "');";
    dbRunSQL(SQLCommand.c_str());

    doesExist = false;
    SQLCommand = "SELECT username FROM ACCOUNTS WHERE username = '" + client + "' AND type = 'S';";
    dbRunSQL(SQLCommand.c_str(), checkCall);
    if (doesExist){
        SQLCommand = "UPDATE INVENTORY SET clientSavings = clientSavings - " + amount + ";";
        dbRunSQL(SQLCommand.c_str());
    }
    ClientsHandler* temp = &ClientsHandler::getHandle();
    temp->sendMsg(client, homePageDetails(client));
    return true;
}

bool dbHandler::qalamExists(std::string id) {
    doesExist = false;
    std::string SQLCommand = "SELECT username FROM ACCOUNTS WHERE qalamID = '" + id + "';";
    dbRunSQL(SQLCommand.c_str(), checkCall);
    return doesExist;
}

bool dbHandler::userExists(std::string name) {
    doesExist = false;
    std::string SQLCommand = "SELECT username FROM ACCOUNTS WHERE username = '" + name + "';";
    dbRunSQL(SQLCommand.c_str(), checkCall);
    return doesExist;
}

bool dbHandler::addUser(std::string name, std::string qalam, std::string username, std::string password, std::string type, std::string dob, std::string balance) {
    std::string SQLCommand = "INSERT INTO ACCOUNTS VALUES('" + name + "', '" + qalam + "', '" + username + "', '" + password + "', '" + type + "', '" + dob + "', " + balance + ", " + balance + ", 0, '" + getCurrentDT() + "', 0, 0);";
    dbRunSQL(SQLCommand.c_str());
}

bool dbHandler::depositLoan(std::string client, std::string amount){
    loaned = 0;
    std::string SQLCommand = "SELECT loan + loanInterest FROM ACCOUNTS WHERE username = '" + client + "';";
    dbRunSQL(SQLCommand.c_str(), getLoan);

    double deposit = std::stod(amount);
    if (deposit > loaned){
        std::cout << "You cannot deposit more than you have loaned" << std::endl;
        return false;
    }

    loaned = 0;
    SQLCommand = "SELECT loanInterest FROM ACCOUNTS WHERE username = '" + client + "';";
    dbRunSQL(SQLCommand.c_str(), getLoan);
    if (loaned < deposit){
        SQLCommand = "UPDATE ACCOUNTS SET loan = loan + loanInterest - " + amount + ", loanInterest = 0 WHERE username = '" + client + "';";
    }else{
        SQLCommand = "UPDATE ACCOUNTS SET loanInterest = loanInterest - " + amount + " WHERE username = '" + client + "';";
    }
    dbRunSQL(SQLCommand.c_str());

    SQLCommand = "INSERT INTO TRANSACTIONS VALUES ('" + client + "', 'LoanDeposit', " + amount + ", '" + getCurrentDT() + "');";
    dbRunSQL(SQLCommand.c_str());
    SQLCommand = "UPDATE INVENTORY SET ownSavings = ownSavings + " + amount + ";";
    dbRunSQL(SQLCommand.c_str());
    return true;
}
bool dbHandler::depositAccount(std::string client, std::string amount) {
    std::string SQLCommand = "UPDATE ACCOUNTS SET Balance = Balance + " + amount + " WHERE username = '" + client + "';";
    dbRunSQL(SQLCommand.c_str());
    SQLCommand = "UPDATE ACCOUNTS SET outstanding = Balance WHERE username = '" + client + "' AND outstanding < Balance;";
    dbRunSQL(SQLCommand.c_str());

    SQLCommand = "INSERT INTO TRANSACTIONS VALUES ('Deposit', '" + client + "', " + amount + ", '" + getCurrentDT() + "');";
    dbRunSQL(SQLCommand.c_str());

    doesExist = false;
    SQLCommand = "SELECT username FROM ACCOUNTS WHERE username = '" + client + "' AND type = 'S';";
    dbRunSQL(SQLCommand.c_str(), checkCall);

    if (doesExist){
        SQLCommand = "UPDATE INVENTORY SET clientSavings = clientSavings + " + amount + ";";
    }
    ClientsHandler* temp = &ClientsHandler::getHandle();
    temp ->sendMsg(client, homePageDetails(client));

    return true;
}