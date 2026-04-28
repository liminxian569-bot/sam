#include "WordBank.h"

WordBank::WordBank() {
    
    words = { "computer", "science", "apple", "banana", "keyboard", "system", "coding" };


    meanings = { "電腦", "科學", "蘋果", "香蕉", "鍵盤", "系統", "程式設計" };

    srand(time(0));
}

void WordBank::generateQuestion() {
    int index = rand() % words.size();
    answer = words[index];
    currentMeaning = meanings[index]; 
    maskedWord = answer;

    int len = answer.length();

   
    if (len < 5) {
        int holes = (rand() % 2) + 1;
        for (int i = 0; i < holes; i++) {
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
