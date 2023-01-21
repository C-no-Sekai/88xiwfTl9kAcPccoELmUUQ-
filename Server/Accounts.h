#pragma once
#include "dbHandler.h"
#include "ClientsHandler.h"

class Accounts {
private:
    // Preventing Creation of Objects Creating Singleton Class
    Accounts(const Accounts&); // No Definition
    Accounts& operator = (const Accounts&); // No Definition
    Accounts(){}; // No Definition
public:
    static dbHandler* dbHandle;
    static ClientsHandler *ClientSub;
    void runCustomQuery(const char *, int (*)(void *, int, char**, char**) = NULL);
    static Accounts* adminPanel();
};
