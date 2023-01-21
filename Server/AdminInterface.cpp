#include "Accounts.h"
#include <iostream>
#include <string>
#include <conio.h>

int callback(void*, int results, char** values, char** columns){
    for (int i = 0; i < results; i++){
        std::cout << columns[i] << ": " << values[i] << std::endl;
    }
    return 0;
}
int main(){
    std::string username, enteredPass;
    std::cout << "\t\t\t\t\tWELCOME!" << std::endl;
    std::cout << "Verify your IDENTITY: ";
    std::cin >> username;
    std::cout << "Enter Password: ";
    enteredPass = "";
    char a;
    do {
        a = getch();
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) {
            enteredPass += a;
            std::cout << '*';
        }
    }while (a != 13);

    if (username != "admin" && enteredPass != "admin"){
        std::cout << "Invalid IDENTITY!" << std::endl;
        return 0;
    }
    std::cout << "\nWelcome, " << username << "!" << std::endl;

    Accounts *accounts = Accounts::adminPanel();
    bool quit;
    do{
        std::cout << "Type the Query to run: ";
        std::string query;
        std::getline(std::cin, query);
        std::getline(std::cin, query);
        accounts->runCustomQuery(query.c_str(), callback);

        std::cout << "Type '0' to exit or '1' to continue: ";
        std::cin >> quit;
    } while (quit);
}
