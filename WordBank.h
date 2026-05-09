#ifndef WORDBANK_H
#define WORDBANK_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class WordBank {
private:
    vector<string> categories;
    vector<string> words;
    vector<string> meanings;
    string answer;
    string maskedWord;
    string meaning;
    string category;

    void loadFromFile();

public:
    WordBank();
    void generateQuestion();
    string getAnswer() { return answer; }
    string getMaskedWord() { return maskedWord; }
    string getMeaning() { return meaning; }
    string getCategory() { return category; }
};

#endif
