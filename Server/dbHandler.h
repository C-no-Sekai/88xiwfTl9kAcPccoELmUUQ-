#ifndef DATABASECPP_WRAPPER_DBHANDLER_H
#define DATABASECPP_WRAPPER_DBHANDLER_H
#pragma comment(lib, "sqlite3.h")
#include <string>
#include <sqlite3.h>
#include <vector>
#include <cstddef>

class dbHandler {
    friend class Accounts;

private:
    sqlite3 *dbHandle;
    bool verbose;
protected:
//    void dbRunSQL(const char *, int (*)(void *, int, char **, char **) = NULL,
//                  void *store = NULL); // Run DDL Commands All Can be Run With No OutPut
public:
                      void dbRunSQL(const char *, int (*)(void *, int, char **, char **) = NULL,
                                    void *store = NULL); // Run DDL Commands All Can be Run With No OutPut
    dbHandler(char *, bool verbose = false); // Open a Connection
    ~dbHandler(); // Close the Connection
    bool UserPassInDB(std::string, std::string);
    void addDefaultAccount(std::string[4]);
    std::string getTransactions(std::string);
    std::string homePageDetails(std::string);
    std::string getTransactionDetails(std::string); // Allow for Information from Qalam ID
    bool makeTransaction(std::string, std::string, std::string); //Sender Receiver Amount
    bool loanApplicable(std::string, std::string, std::string); //Option Client Amount
    void giveLoan(std::string, std::string, std::string); //Option Client Amount
    bool withDraw(std::string, std::string); // User Amount
    void addDailyInterest();
    bool qalamExists(std::string);
    bool userExists(std::string);
    bool depositLoan(std::string, std::string);
    bool depositAccount(std::string, std::string);
    bool addUser(std::string, std::string, std::string, std::string, std::string, std::string, std::string);
    std::vector<std::string> addMonthlyInterest();
};


#endif //DATABASECPP_WRAPPER_DBHANDLER_H
