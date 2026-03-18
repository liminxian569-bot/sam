#include "WordBank.h"

WordBank::WordBank() {
    words = {"computer", "science", "apple", "banana", "keyboard", "system", "coding"};    //題庫
    srand(time(0));
}

void WordBank::generateQuestion() {
    int index = rand() % words.size();
    answer = words[index];                         //正確答案
    maskedWord = answer;                           //答案暫存

    int len = answer.length();                     //答案長度
    
    if (len < 5) {                                //長度<5 隨機挖空1~2個字母
        int holes = (rand() % 2) + 1;
        for(int i = 0; i < holes; i++) {
            maskedWord[rand() % len] = '_';
        }
    } else if (len % 2 != 0) {                    //長度是奇數 挖空第1個和第4個字母
        maskedWord[0] = '_';
        maskedWord[3] = '_';
    } else {                                       //長度是偶數 挖空第2個和第5個字母
        maskedWord[1] = '_';
        maskedWord[4] = '_';
    }
}
