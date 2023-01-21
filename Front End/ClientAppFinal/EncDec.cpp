#include "EncDec.h"
EncDec::EncDec(std::string key) {this->key = key;} //constructor
char EncDec::runEnc(char &test, int mode) { //create a function to run the encryption
    if (mode & 1){ //if the mode is 1
        test ^= key[3]; //xor the test with the last character of the key
    } else { //if the mode is 0
        test ^= key[0]; //xor the test with the first character of the key
    }
    for (int i = 1; i < 3; i++){ //loop through the key
        test ^= key[i]; //xor the test with the next character of the key
    }
    return test; //return the test
}
std::string EncDec::runEncDec(std::string base) { //create a function to run the encryption and decryption
    std::string output = ""; //create a string to store the output
    int index = 0; //create a variable to store the index
    for (char i: base){ //loop through the base
        output += EncDec::runEnc(i, index); //run the encryption on the character
        index++; //increment the index
    }
    return output; //return the output
}
