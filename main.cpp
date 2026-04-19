#include <iostream>
#include <cstdlib>
#include <ctime>
#include "WordBank.h"
#include "GameManager.h"
using namespace std;
int main() {
    srand(time(0));
    WordBank bank;
    bank.generateQuestion();
    string ans = bank.getAnswer();
    string masked = bank.getMaskedWord();
    string chi = bank.getMeaning(); 
    GameManager game(ans, masked, chi);

    game.startGame();

    return 0;
}