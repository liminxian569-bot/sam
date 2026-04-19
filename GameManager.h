#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <string>

using namespace std;

class GameManager {
private:
    string answer;
    string currentWord;
    string meaning;              
    int hp;

public:
   
    GameManager(string ans, string masked, string chiMeaning);

    void startGame();
};

#endif

