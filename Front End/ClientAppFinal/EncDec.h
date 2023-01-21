#ifndef ENCDEC_H
#define ENCDEC_H
#include <string>
class EncDec {
private:
    std::string key; //create a string to store the key
    char runEnc(char&, int); //create a function to run the encryption
public:
    EncDec(std::string); //constructor
    std::string runEncDec(std::string); //create a function to run the encryption and decryption
};
#endif // ENCDEC_H
