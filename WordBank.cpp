#include "WordBank.h"
#include <ctime>
#include <cstdlib>

WordBank::WordBank() {
    loadFromFile();
}

void WordBank::loadFromFile() {
    ifstream file("words.txt");
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string cat, eng, chi;
            if (getline(ss, cat, '|') && getline(ss, eng, '|') && getline(ss, chi)) {
                categories.push_back(cat);
                words.push_back(eng);
                meanings.push_back(chi);
            }
        }
        file.close();
    } else {
        categories.push_back("default");
        words.push_back("error");
        meanings.push_back("讀檔失敗");
    }
}

void WordBank::generateQuestion() {
    if (words.empty()) return;

    int index = rand() % words.size();
    answer = words[index];
    meaning = meanings[index];
    category = categories[index];
    maskedWord = answer;

    int len = answer.length();
    
    if (len < 5) {
        int numHoles = (rand() % 2) + 1;
        for(int i = 0; i < numHoles; i++) {
            maskedWord[rand() % len] = '_';
        }
    } 
    else if (len % 2 != 0) {
        maskedWord[0] = '_';
        maskedWord[3] = '_';
    } 
    else {
        maskedWord[1] = '_';
        maskedWord[4] = '_';
    }
}
