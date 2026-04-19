#ifndef WORDBANK_H
#define WORDBANK_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class WordBank {
private:
    vector<string> words;
    vector<string> meanings; 
    string answer;
    string maskedWord;
    string currentMeaning;   

public:
    WordBank();
    void generateQuestion();
    string getAnswer() { return answer; }
    string getMaskedWord() { return maskedWord; }
    string getMeaning() { return currentMeaning; }
};

#endif
