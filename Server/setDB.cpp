#include "dbHandler.h"
#include <string>
#include <iostream>
//#include "Accounts.h"
#include <ctime>
int callback(void *, int argc, char** values, char** columns){
    for (int i = 0; i < argc; i++){
        std::cout << *(columns + i) << " : " << *(values + i) << std::endl;
    }
    return 0;
}
int main(){
    std::string DBName = "..\\VRBankDB.db";
    dbHandler DBHandle((char *)DBName.c_str(), true);
//    std::cout << DBHandle.UserPassInDB("test", "te") << std::endl;
    std::string SQLCommand;
//    std::cout << DBHandle.homePageDetails("admin1") << std::endl;
//    Accounts *DBHandle = Accounts::adminPanel();
//    std::string t[] = {"Administrator", "111111", "admin", "admin", "Fri Dec 31 1999"};
//    DBHandle.addDefaultAccount(t);
//    std::string t1[] = {"test", "222222", "test", "test", "Fri Dec 31 1999"};
//    DBHandle.addDefaultAccount(t1);
//
//    SQLCommand = "UPDATE ACCOUNTS SET Balance = 10000";
//    DBHandle.dbRunSQL(SQLCommand.c_str(), callback);
//    SQLCommand = "DROP TABLE IF EXISTS ACCOUNTS";
//    DBHandle.dbRunSQL(SQLCommand.c_str());
//    SQLCommand = "DROP TABLE IF EXISTS TRANSACTIONS";
//    DBHandle.dbRunSQL(SQLCommand.c_str());
//    SQLCommand = "DROP TABLE IF EXISTS INVENTORY";
//    DBHandle.dbRunSQL(SQLCommand.c_str());
//
//    SQLCommand = "CREATE TABLE IF NOT EXISTS ACCOUNTS("
//                 "name varchar(30),"
//                 "qalamID varchar(6),"
//                 "username varchar(30) UNIQUE,"
//                 "password varchar(30),"
//                 "type char(1),"
//                 "dob date,"
//                 "Balance money,"
//                 "outstanding money,"
//                 "interest money,"
//                 "doc datetime,"
//                 "PRIMARY KEY (qalamID));";
//    DBHandle.dbRunSQL(SQLCommand.c_str());
//
//    SQLCommand = "CREATE TABLE IF NOT EXISTS TRANSACTIONS("
//                 "sender varchar(30),"
//                 "receiver varchar(30),"
//                 "amount money,"
//                 "time datetime);";
//    DBHandle.dbRunSQL(SQLCommand.c_str());
//
//    SQLCommand = "CREATE TABLE IF NOT EXISTS INVENTORY("
//                 "ownSavings money,"
//                 "clientSavings money);";
//    DBHandle.dbRunSQL(SQLCommand.c_str());

//    SQLCommand = "INSERT INTO INVENTORY VALUES(0, 0);";
//    DBHandle->runCustomQuery(SQLCommand.c_str());
//    DBHandle->runCustomQuery(SQLCommand.c_str(), callback);


//    SQLCommand = "INSERT INTO ACCOUNTS VALUES('Abdul Rehman', '389777' , 'admin1', 'admin1', 'S', 'Fri Dec 31 1999', 10, 100000);";
//    DBHandle->runCustomQuery(SQLCommand.c_str());
//
//    SQLCommand = "INSERT INTO ACCOUNTS VALUES('Taha', '345671' , 'admin2', 'admin2', 'S', 'Fri Dec 31 1999', 9915.8, 990000);";
//    DBHandle->runCustomQuery(SQLCommand.c_str());
//    SQLCommand = "DROP TABLE IF EXISTS ACCOUNTS;";

//    SQLCommand = "SELECT * FROM ACCOUNTS;";
//    DBHandle->runCustomQuery(SQLCommand.c_str(), callback);
//
//    DBHandle2.makeTransaction("admin1", "admin2", "2");
//    DBHandle2.getTransactions("admin1");
//    std::cout << "Here" << std::endl;
//    SQLCommand = "SELECT * FROM ACCOUNTS;";
//    DBHandle->runCustomQuery(SQLCommand.c_str(), callback);
//    tm* currTM;
//    char dateString[100];
//    time_t currTime;
//    time(&currTime);
//    currTM = localtime(&currTime);
//    strftime(dateString, 50, "%c", currTM);
//    SQLCommand = "INSERT INTO TRANSACTIONS VALUES ('admin2', 'admin1', 19990, '" + (std::string)dateString +"')";
//    DBHandle->runCustomQuery(SQLCommand.c_str());
//
//    SQLCommand = "SELECT * FROM TRANSACTIONS;";
//    DBHandle->runCustomQuery(SQLCommand.c_str(), callback);

//    SQLCommand = "CREATE TABLE IF NOT EXISTS ACCOUNTS("
//                 "name varchar(30),"
//                 "qalamID varchar(6),"
//                 "username varchar(30) UNIQUE,"
//                 "password varchar(30),"
//                 "type char(1),"
//                 "dob date,"
//                 "actualBalance money,"
//                 "visibleBalance money,"
//                 "PRIMARY KEY (qalamID));";
//    DBHandle->runCustomQuery(SQLCommand.c_str());
//
//    SQLCommand = "INSERT INTO ACCOUNTS VALUES('Administrator V1.0', '333333' , 'A-kyun', 'B-kyuun', 'C', 2004-05-27, 10000, 1000000);";
//    DBHandle->runCustomQuery(SQLCommand.c_str());
//
//    SQLCommand = "DROP TABLE IF EXISTS TRANSACTIONS;";
//    DBHandle->runCustomQuery(SQLCommand.c_str());
//
//    SQLCommand = "CREATE TABLE IF NOT EXISTS TRANSACTIONS("
//                 "sender varchar(30),"
//                 "receiver varchar(30),"
//                 "amount money,"
//                 "time datetime);";
//    DBHandle->runCustomQuery(SQLCommand.c_str());
}

