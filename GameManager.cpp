#include "GameManager.h"
#include <string>
#include< cctype >
GameManager::GameManager(string ans, string masked, string chiMeaning) {
    answer = ans;
    currentWord = masked;
    meaning = chiMeaning; 
    hp = 3;
}

void GameManager::startGame() {
    string guessWord;

    while (hp > 0 && currentWord != answer) {
        cout << "\n=============================" << endl;
        cout << "【中文提示】 " << meaning << endl;
        cout << "【英文單字】 " << currentWord << endl;
        cout << "剩餘血量: " << hp << " 滴" << endl;
        cout << "請輸入完整單字來填空: ";
        cin >> guessWord;
        cin.ignore(10000, '\n');
        for (int i = 0; i < guessWord.length(); i++) {
            guessWord[i] = tolower(guessWord[i]);
        }
        cout << "你的答案: " << guessWord << endl;
        if (guessWord.length() != answer.length()) {
            cout << ">> 提醒：字數不對喔！這題單字有 " << answer.length() << " 個字母，請重新輸入。" << endl;
            continue;
        }

        bool hasMistake = false;
        string wrongFeedback = ""; 
        for (int i = 0; i < answer.length(); i++) {
            if (currentWord[i] == '_') {
                if (guessWord[i] == answer[i]) {
                    currentWord[i] = guessWord[i];
                }
                else {
                    hasMistake = true;
                    wrongFeedback += "- 第 " + to_string(i + 1) + " 格錯了 (你輸入 '" + guessWord[i] + "')\n";
                }
            }
            else {
                if (guessWord[i] != answer[i]) {
                    hasMistake = true;
                    wrongFeedback += "- 第 " + to_string(i + 1) + " 格原本是 '" + string(1, answer[i]) + "'，你打成了 '" + guessWord[i] + "'\n";
                }
            }
        }
        if (hasMistake) {
            hp--;
            cout << ">> 答錯囉！扣 1 滴血。" << endl;
            cout << "【錯誤細節】：" << endl;
            cout << wrongFeedback; 
        }
        else {
            cout << ">> 太棒了！拼寫完全正確！" << endl;
        }
    }
    cout << "\n========= 遊戲結束 =========" << endl;
    if (hp == 0) {
        cout << "遊戲失敗！正確解答是: " << answer << endl;
    }
    else {
        cout << "恭喜獲勝！你成功猜出單字: " << answer << endl;
    }
}