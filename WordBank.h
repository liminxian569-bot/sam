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
    string answer;
    string maskedWord;

public:
    WordBank();
    void generateQuestion();
    string getAnswer() { return answer; }
    string getMaskedWord() { return maskedWord; }
};

#endif