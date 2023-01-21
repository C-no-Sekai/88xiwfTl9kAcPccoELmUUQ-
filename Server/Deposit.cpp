#include "dbHandler.h"
#include "iostream"
#include <string>
#include <conio.h>

int main() {
    dbHandler DBHandle((char *) ((std::string) "..\\VRBankDB.db").c_str(), false);
    std::string username, password;
    while (true) {
        std::cout << "\t\t\t\t\tWELCOME TO Deposit Center" << std::endl;
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
        } while (a != 13);
        if (!DBHandle.UserPassInDB(username, password)) {
            std::cout << "\nInvalid UserName or Password! ACCESS DENIED" << std::endl;
            system("PAUSE");
            system("CLS");
            continue;
        }
        std::cout << "\nWelcome " << username << "!" << std::endl;

        char choice;
        std::string amount;

        do {
            std::cout << "Do you wish to deposit for:\n1) Loan\n2)Account Deposit\n3) Exit\nEnter your choice: ";
            std::cin >> choice;

            std::cout << "Enter the amount you wish to deposit: ";
            std::cin >> amount;

            try {
                std::stod(amount);
                if (std::stod(amount) < 0) {
                    throw std::invalid_argument("Amount Cannot be Negative");
                }
            } catch (std::invalid_argument) {
                std::cout << "Invalid Amount Entered! Transaction Not Processed" << std::endl;
                system("PAUSE");
                continue;
            }

            if (choice == '1') {
                if (DBHandle.depositLoan(username, amount)){
                    std::cout << "Deposit Successful!" << std::endl;
                }
            } else if (choice == '2'){
                if (DBHandle.depositAccount(username, amount)){
                    std::cout << "Deposit Successful!" << std::endl;
                }
            } else {
                std::cout << "Invalid Choice Entered! Transaction Not Processed" << std::endl;
            }
        } while (choice != '3');

        system("PAUSE");
        system("CLS");
    }
}