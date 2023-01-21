#include "MainServer.h"
#include "Communicator.h"
#include <iostream>
#include <thread>
#include <vector>
using namespace std;
int main(){
    // Initialize WinSock
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        cout << "WSAStartup failed with error: " << iResult << endl;
        return 1;
    }

    // Initialize Object handler
    vector<Communicator> Sockets;
    vector<thread> Threads;
    // Initialize Socket Class Object
    MainServer sock1("10.7.93.74", 21337, 10);

    thread th1([&](){
        while (true) {
            cout << "[-] Waiting" << endl;
            Communicator com1(sock1.AcceptConn());
            Sockets.push_back(com1);
            Threads.push_back(thread([&](){
             while (true){
                 com1.RecvData();
             }
            }
                    ));
            cout << "[+] Connection Received" << endl;
        }
    });

    th1.join();
    Threads[0].join();
}