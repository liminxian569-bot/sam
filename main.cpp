#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>
#include "WordBank.h"
#include "GameManager.h"

using namespace std;

int main() {
    srand(time(0));
    char playAgain;

    do {
        int difficulty;
        cout << "==============================" << endl;
        cout << "   請選擇遊戲難度 (1-3): " << endl;
        cout << "   1. 簡單 (Easy)" << endl;
        cout << "   2. 中等 (Normal)" << endl;
        cout << "   3. 困難 (Hard)" << endl;
        cout << "==============================" << endl;
        cout << ">> ";
        cin >> difficulty;

        while (difficulty < 1 || difficulty > 3) {
            cout << "輸入錯誤，請重新選擇 (1-3): ";
            cin >> difficulty;
        }

        WordBank bank;
        bank.generateQuestion(difficulty);

        string ans = bank.getAnswer();
        string masked = bank.getMaskedWord();
        string chi = bank.getMeaning();

        GameManager game(ans, masked, chi);
        game.startGame();

        cout << "\n再玩一局? (Y/N): ";
        cin >> playAgain;
        playAgain = toupper(playAgain);

    } while (playAgain == 'Y');

    cout << "感謝您的遊玩！" << endl;

    return 0;
}
