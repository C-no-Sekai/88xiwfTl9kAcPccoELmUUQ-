#include "EncDec.h"
EncDec::EncDec(std::string key) {this->key = key;}
char EncDec::runEnc(char &test, int mode) {
    if (mode & 1){
        test ^= key[3];
    } else {
        test ^= key[0];
    }
    for (int i = 1; i < 3; i++){
        test ^= key[i];
    }
    return test;
}
std::string EncDec::runEncDec(std::string base) {
    std::string output = "";
    int index = 0;
    for (char i: base){
        output += EncDec::runEnc(i, index);
        index++;
    }
    return output;
}