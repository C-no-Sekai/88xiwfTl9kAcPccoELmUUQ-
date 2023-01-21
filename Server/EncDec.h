#pragma once
#include <string>
class EncDec {
private:
    std::string key;
    char runEnc(char&, int);
public:
    EncDec(std::string);
    std::string runEncDec(std::string);
};