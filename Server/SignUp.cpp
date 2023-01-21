#include <iostream>
#include <algorithm>
#include "dbHandler.h"

int main(){
    dbHandler DBHandle((char*)((std::string)"..\\VRBankDB.db").c_str(), false);
    std::string name, qalamID, username, password, type, balance, dob;
    char ans = 'Y';
    while (ans != 'N' && ans != 'n'){
        std::cout << "\t\t\t\t\tWELCOME TO SignUp!" << std::endl;
        std::cout << "Enter Your Name: ";
        std::getline(std::cin, name);
        do {
            do {
                std::cout << "QALAM ID MUST BE A UNIQUE 6 DIGIT NUMBER\n";
                std::cout << "Enter Your QALAM ID: ";
                std::getline(std::cin, qalamID);
            } while (qalamID.length() != 6 && std::all_of(qalamID.begin(), qalamID.end(), ::isdigit));
        if (DBHandle.qalamExists(qalamID)) {
            std::cout << "QALAM ID Already Exists! Please Try Again" << std::endl;
            }
        } while (DBHandle.qalamExists(qalamID));

        do {
            std::cout << "Choose a Username for yourself: ";
            std::getline(std::cin, username);
            if (DBHandle.userExists(username)) {
                std::cout << "Username Already Exists! Please Try Again" << std::endl;
            }
        } while (DBHandle.userExists(username));

        std::cout << "Choose a Password for yourself: ";
        std::getline(std::cin, password);

        do {
            std::cout << "Choose Account Type (S/C): ";
            std::cin >> type;
        } while (type != "S" && type != "C");

        std::cout << "Enter Date of Birth: ";
        std::cin.get();
        std::getline(std::cin, dob);

        std::cout << "Enter Initial Balance: ";
        std::cin >> balance;

        DBHandle.addUser(name, qalamID, username, password, type, dob, balance);
        std::cout << "SignUp Successful!" << std::endl;
        std::cout << "Do you Wish to SignUp Another User? (Y/N): ";
        std::cin >> ans;
        system("CLS");
    }
}