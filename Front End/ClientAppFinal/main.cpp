#define WM_MYCUSTOMMESSAGE (WM_USER + 1)
#include <winsock2.h>
#include "mainwindow.h" //include the mainwindow class
#include <QApplication> //include the QApplication class
#include "ClientConnection.h" //include the ClientConnection class
#include "connecttointernet.h" //include the connecttointernet class
#include "signup.h" //include the signup class
#include "test.h" //include the test class
#include "transfer.h" //include the transfer class
#include "loaning.h" //include the loaning class
#include "withdraw.h" //include the withdraw class
#include <thread> //include the thread class
#include "globalCalls.h" //include the globalCalls class

QWidget** finale;
MainWindow* loginScreen;
signup* signupWindow;
ConnecttoInternet* networkError;
test* HomePage;
Transfer* transactions;
loaning* LoanPage;
withdraw* Withdrawl;

bool programToRun = true;
std::string AuthNameVar, UserName, name, transactions1, balance, IP = "127.0.0.1";
int portNum = 8080;


void HandleConnection();

std::vector<std::string> tokenize(const std::string& s, const std::string& del){
    int starting_point = 0;
    int ending_point = s.find(del) ;
    std::vector<std::string> tokens;
    std::string temp;
    while (ending_point <= s.length()){
        temp = s.substr(starting_point, ending_point-starting_point);
        starting_point = ending_point + del.length();
        ending_point = s.find(del,starting_point);
        tokens.push_back(temp);
    }
    return tokens;
}
std::string test::get_name(){return name;}
std::string test::get_Transactions(){return transactions1;}
std::string test:: get_actual_balance(){return balance;}

void test::setName(std::string temp){name = temp;}
void test::setTransaction(std::string temp){transactions1 = temp;}
void test::setBalance(std::string temp){balance = temp;}

ClientConn *C1;

void Transfer:: change_to_main(){
        (*(finale + 3))->setVisible(true);
        (*(finale + 4))->setVisible(false);
}
void createConnection(char* IP, int Port){
    C1 = new ClientConn(IP, Port);
    if (C1->connectionEstablished){
        (*(finale + 2))->setVisible(false);
        (*(finale + 0))->setVisible(true);
        HandleConnection();
    }else{
        (*(finale + 2))->setVisible(true);
        C1 = nullptr;
    }
}

void ConnecttoInternet::on_Retry_clicked(){createConnection((char*)IP.c_str(), portNum);}
std::string test::getName(){return UserName;}
std::string MainWindow::getName(){return UserName;}
void MainWindow::setName(std::string name){UserName = name;}

void signup::test(){
    (*(finale + 2))->setVisible(true);
    (*(finale + 1))->setVisible(false);
}
void MainWindow::on_SignUp_clicked(){
    (*(finale + 0))->setVisible(false);
    (*(finale + 1))->setVisible(true);
};
void test::window_switching_to_transfer(){
    (*(finale + 4))->setVisible(true);
    (*(finale + 3))->setVisible(false);
}
void test::window_switching_to_withdraw(){
    (*(finale + 6))->setVisible(true);
    (*(finale + 3))->setVisible(false);
}
void test::window_switching_to_loaning(){
    (*(finale + 5))->setVisible(true);
    (*(finale + 3))->setVisible(false);
}
void MainWindow::authenticate(){

}
void loaning::func(){
    (*(finale + 5))->setVisible(false);
    (*(finale + 3))->setVisible(true);
}
void signup::Send_data(std::string name){
    C1->sendMsg((char *)name.c_str(),name.length());
    (*(finale + 1))->setVisible(false);
    (*(finale + 0))->setVisible(true);
    (*(finale+2))->setVisible(false);
}

void MainWindow::send_data(std::string LoginDetails){
    C1->sendMsg((char *)LoginDetails.c_str(), LoginDetails.length());
    std::cout << "[+] Login Details Sent" << std::endl;
}
std::string Transfer::auth(){return AuthNameVar;}
std::string Transfer::get_balance(){return balance;}
void Transfer::sendMoney(ClientConn* C1){
    std::string MsgToSend = reinterpret_cast<char*>(transactions -> moneyToSend);
    C1->sendMsg((char *)MsgToSend.c_str(), MsgToSend.length());
}

void Transfer::on_pushButton_clicked()
{
    std::string Msg = "^VID^" + getEnteredID();
    C1->sendMsg((char*)Msg.c_str(), Msg.length());
}

// Add Receive feature for Home Page after ogin Uodating Q Objects using signals code for both Client And Server is to be added
void MainWindow::updateLogin(bool status){
    if (status){
        UserName = Username.toStdString();
        (*(finale + 0))->setVisible(false);
        (*(finale + 3))->setVisible(true);
    } else {
        this->Colorchange();
    }
}
void withdraw::on_pushButton_3_clicked()
{
    (*(finale + 6))->setVisible(false);
    (*(finale + 3))->setVisible(true);
}
void loaning::sendMsg(std::string msg){
    msg += UserName;
    msg += "\n\n";
    C1 -> sendMsg((char *)msg.c_str(), msg.length());
}
void Transfer::makeTransfer(){
    std::string msg = "^MTRS^" + UserName + "\n\n" + recepient + "\n\n" + std::to_string(moneyToSend);
    C1->sendMsg((char *)msg.c_str(), msg.length());
}
// Opening read Feature:
void HandleConnection(){
    std::cout << "[+] Connection Esablished! Started Listening" << std::endl;
    std::thread programReader([&](){
        QObject::connect(loginScreen, &MainWindow::LoginUpdate, loginScreen, &MainWindow::updateLogin);
        QObject::connect(HomePage, &test::UpdateHome, HomePage, &test::updateHomePage);
        QObject::connect(transactions, &Transfer::processTransaction, transactions, &Transfer::process);
        QObject::connect(transactions, &Transfer::transactionResults, transactions, &Transfer::displayTransactionResults);
        std::string serverCommand;
        while (programToRun){
            serverCommand = C1->recvMsg();
            std::cout << serverCommand << std::endl;
            if (serverCommand == "^LGNINVALID^"){
                emit loginScreen->LoginUpdate(false);
            } else if (serverCommand == "^LOGINSUCCESS^"){
                emit loginScreen->LoginUpdate(true);
            } else if (serverCommand.substr(0, 6) == "^DATA^"){
                    std::cout << "TEMO: " << serverCommand.length() << "\n" << serverCommand << std::endl << "TIll\n";
                    std::string x[3];
                    int index = 0, start = 6, breakpoint = 0;
                    do{
                        breakpoint = serverCommand.find("\n\n", breakpoint + 1);
                        x[index++] = serverCommand.substr(start, breakpoint - start);
                        std::cout << index << "  " << x[index - 1] << std::endl;
                        start = breakpoint + 2;
                    } while (serverCommand.find("\n\n", breakpoint + 1) != std::string::npos);
                    std::string* temp = new std::string[3]{x[0], x[1], x[2]};
                    emit HomePage->UpdateHome(temp);
                    std::cout << "HERE" << std::endl;
            } else if (serverCommand.substr(0, 6) == "^MDET^"){
                    std::string temp[1] = {serverCommand.substr(6, std::string::npos)};
                    emit transactions->processTransaction(temp);
            }else if (serverCommand.substr(0, 6) == "^MTRS^"){
                    std::string temp[1] = {serverCommand.substr(6, std::string::npos)};
                    emit transactions->transactionResults(temp);
            }
            else{
                std::cout << serverCommand<<std::endl;
                 }
        }
    });
    programReader.detach();
}

int main(int argc, char *argv[])
{
    QApplication test2(argc, argv);
    loginScreen = new MainWindow;
    signupWindow = new signup;
    networkError = new ConnecttoInternet;
    HomePage = new test;
    transactions = new Transfer;
    LoanPage = new loaning;
    Withdrawl = new withdraw;

    finale = new QWidget*[7]{loginScreen, signupWindow, networkError, HomePage, transactions, LoanPage, Withdrawl};
    createConnection((char*)IP.c_str(), portNum);
    return test2.exec();
}
