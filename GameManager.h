#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "Pet.h"
#include <iostream>
#include <string>

using namespace std;

class GameManager {
private:
    string answer;
    string currentWord;
    string meaning;
    int hp;
    int currentStreak;
    bool won;
    Pet companion;
public:
    GameManager(string ans, string masked, string chiMeaning, int streak = 0);
    void startGame();
    bool isWon() const {
        return won;
    }
};
#endif
