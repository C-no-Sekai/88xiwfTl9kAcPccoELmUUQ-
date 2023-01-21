#ifndef TOKENIZE_H
#define TOKENIZE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> tokenize(const string& s, const string& del){
    int starting_point = 0;
    int ending_point = s.find(del) ;
    vector<string> tokens;
    std::string temp;
    while (ending_point <= s.length()){
        temp = s.substr(starting_point, ending_point-starting_point);
        starting_point = ending_point + del.length();
        ending_point = s.find(del,starting_point);
        tokens.push_back(temp);
    }
    return tokens;
}

#endif // TOKENIZE_H
