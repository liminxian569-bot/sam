#include "WordBank.h"
#include <ctime>
#include <cstdlib>

WordBank::WordBank() {}

void WordBank::loadFromFile(string fileName) {
    categories.clear();
    words.clear();
    meanings.clear();

    ifstream file(fileName);
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.empty()) continue;
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
        cout << "[Error] Cannot open " << fileName << endl;
    }
}

void WordBank::generateQuestion(int difficulty) {
    string targetFile;
    if (difficulty == 1) targetFile = "easy.txt";
    else if (difficulty == 2) targetFile = "normal.txt";
    else targetFile = "hard.txt";

    loadFromFile(targetFile);

    if (words.empty()) {
        answer = "error";
        meaning = "無資料";
        return;
    }

    int index = rand() % words.size();
    answer = words[index];
    meaning = meanings[index];
    category = categories[index];
    maskedWord = answer;

    int len = answer.length();
    if (len < 5) {
        int numHoles = (rand() % 2) + 1;
        for(int i = 0; i < numHoles; i++) maskedWord[rand() % len] = '_';
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
