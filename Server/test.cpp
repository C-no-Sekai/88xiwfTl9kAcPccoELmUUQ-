#include "Server.h"
using namespace std;

int main() {
Server S1("10.7.171.152", 8080, 30);
SOCKET test = S1.AcceptConn();

}