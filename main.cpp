#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>
#include "WordBank.h"
#include "GameManager.h"
#include "ScoreBoard.h"
using namespace std;
int main() {
    srand(time(0));
    char playAgain;
    int streak = 0;
    int lastDifficulty = 0;   
    ScoreBoard scoreBoard;
    do {
        int difficulty;
        cout << "==============================" << endl;
        cout << "   請選擇遊戲難度 (1-3): " << endl;
        cout << "   1. 簡單 (Easy)" << endl;
        cout << "   2. 中等 (Normal)" << endl;
        cout << "   3. 困難 (Hard)" << endl;
        scoreBoard.display();
        cout << "==============================" << endl;
        cout << ">> ";
        cin >> difficulty;

        while (difficulty < 1 || difficulty > 3) {
            cout << "輸入錯誤，請重新選擇 (1-3): ";
            cin >> difficulty;
        }
        if (lastDifficulty != 0 && difficulty != lastDifficulty && streak > 0) {
            cout << "(難度切換,連勝歸零)" << endl;
            streak = 0;
        }

        WordBank bank;
        bank.generateQuestion(difficulty);

        string ans = bank.getAnswer();
        string masked = bank.getMaskedWord();
        string chi = bank.getMeaning();

        GameManager game(ans, masked, chi, streak);
        game.startGame();

        bool won = game.isWon();
        int oldBest = scoreBoard.getBestStreak(difficulty);

        if (won) {
            streak++;
            cout << "\n連勝 +1！目前 " << streak << " 連勝中" << endl;
            if (streak > oldBest) {
                cout << "★ 打破此難度最高連勝紀錄!★" << endl;
            }
        }
        else {
            if (streak >= 3) {
                cout << "\n你的 " << streak << " 連勝在這裡斷掉了！" << endl;
            }
            streak = 0;
        }

        scoreBoard.recordResult(difficulty, won, streak);
        lastDifficulty = difficulty;   

        cout << "\n再玩一局? (Y/N): ";
        cin >> playAgain;
        playAgain = toupper(playAgain);

    } while (playAgain == 'Y');

    cout << "\n========= 最終戰績 =========" << endl;
    scoreBoard.display();
    cout << "\n感謝您的遊玩！" << endl;

    return 0;
}
