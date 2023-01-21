#include "MainClient.h"
#include "Communicator.h"
#include <iostream>
#include <string>
#include <thread>
using namespace std;
int main(){
    // Initialize WinSock
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        cout << "WSAStartup failed with error: " << iResult << endl;
        return 1;
    }

    // Initialize Socket Class Object
    MainClient sock1("10.7.93.74", 21337);
    Communicator comm1(sock1.Connect());

    // Start Receiver Thread
    thread t{[&](){
        while (true){
            comm1.RecvData();
        }
    }};
    string data = "Hello! Server";

    while (data != ""){
        char SenderData[data.length() + 1];
        strcpy(SenderData, data.c_str());
        comm1.SendData(SenderData);
        cout << "Next Message: ";
        getline(cin, data);
    }
    t.join();
}