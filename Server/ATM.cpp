#include "dbHandler.h"
#include "iostream"
#include <string>
#include <conio.h>

int main(){
    dbHandler DBHandle((char*)((std::string)"..\\VRBankDB.db").c_str(), false);
    std::string username, password;
    while (true){
        std::cout << "\t\t\t\t\tWELCOME TO ATM!" << std::endl;
        std::cout << "Enter Your UserName: ";
        std::getline(std::cin, username);
        std::cout << "Enter Your Password: ";
        password = "";
        char a;
        do {
            a = getch();
            if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) {
                password += a;
                std::cout << '*';
            }
        }while (a != 13);
        if (!DBHandle.UserPassInDB(username, password)){
            std::cout << "\nInvalid UserName or Password! ACCESS DENIED" << std::endl;
            system("PAUSE");
            system("CLS");
            continue;
        }

        std::cout << "\nWelcome " << username << "!" << std::endl;
        char makeTransaction = 'Y';
        std::string temp;
        double amount;
        do {
            std::cout << "Enter the Amount You Wish to Withdraw: ";
            std::cin >> temp;
            try{
                amount = std::stod(temp);
                if (amount < 0 || !DBHandle.withDraw(username, temp)){
                    throw std::invalid_argument("Amount Cannot be Negative");
                }
                std::cout << "Withdrawal Successful!" << std::endl;
                std::cout << "Do you Wish to Make Another Transaction? (Y/N): ";
                std::cin >> makeTransaction;
            }catch(std::invalid_argument){
                std::cout << "Invalid Amount Entered! Transaction Not Processed" << std::endl;
            }
        } while (makeTransaction != 'N' && makeTransaction != 'n');
        system("CLS");
        std::cin.get();
    }
}