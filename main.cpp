#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include "WordBank.h"
#include "GameManager.h"

using namespace std;

int main() {
    srand(time(0));
    char playAgain;

    do {
        WordBank bank;
        bank.generateQuestion();

        string ans = bank.getAnswer();
        string masked = bank.getMaskedWord();
        string chi = bank.getMeaning();
        GameManager game(ans, masked, chi);
        game.startGame();
        cout << "\n=============================" << endl;
        cout << "要再來一局嗎？(y/n): ";
        cin >> playAgain;
        playAgain = tolower(playAgain);

    } while (playAgain == 'y');

    cout << "感謝遊玩！你的寵物小夥伴期待下次見面！" << endl;

    return 0;
}
