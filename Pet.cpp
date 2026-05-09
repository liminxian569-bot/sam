#include "Pet.h"
#include <iostream>
#include <cstdlib>
Pet::Pet(const string& petName) {
    name = petName;
}
void Pet::drawBody(Mood mood) const {
    switch (mood) {
    case IDLE:
        // 半閉眼悠閒貓
        cout << "       /\\_/\\" << endl;
        cout << "      ( -.- )" << endl;
        cout << "       >   <" << endl;
        cout << "       /   \\" << endl;
        cout << "      (_____)~" << endl;
        break;

    case HAPPY:
        // 瞇眼開心貓 + 音符
        cout << "       /\\_/\\   " << endl;
        cout << "      ( ^.^ )" << endl;
        cout << "       >   <" << endl;
        cout << "       /   \\" << endl;
        cout << "      (_____)~" << endl;
        break;
    case LOW_HP:
        // 大眼警戒、毛炸開、爪舉起
        cout << "    !  /\\_/\\  !" << endl;
        cout << "      ( O.O )" << endl;
        cout << "       >   <" << endl;
        cout << "      _/| |\\_" << endl;
        cout << "      (_____)" << endl;
        break;
        case WORRIED:
            // 哭眼擔心貓
            cout << "       /\\_/\\" << endl;
            cout << "      ( ;.; )" << endl;
            cout << "       > _ <" << endl;
            cout << "       /   \\" << endl;
            cout << "      (_____)~" << endl;
            break;
    case WIN:
        // 張嘴大笑、舉爪、星星圍繞
        cout << "    *  /\\_/\\  *" << endl;
        cout << "      ( ^o^ )" << endl;
        cout << "       >   <" << endl;
        cout << "      _/| |\\_" << endl;
        cout << "      (_____)" << endl;
        break;

    case LOSE:
        // 流淚貓
        cout << "       /\\_/\\" << endl;
        cout << "      ( T_T )" << endl;
        cout << "       >   <" << endl;
        cout << "       /   \\" << endl;
        cout << "      (_____)" << endl;
        cout << "         ' '" << endl;
        break;
    }
}

// ====================================================
//   貓咪台詞庫（傲嬌個性）
//   設計重點：嘴硬心軟、自稱「本喵」、用括號描述動作
// ====================================================
string Pet::pickReaction(Mood mood) const {
    vector<string> lines;

    switch (mood) {
    case IDLE:
        lines = {
            "開始吧。"
        };
        break;
    case HAPPY:
        lines = {
            "算你厲害啦！",
        };
        break;
    case LOW_HP:
        lines = {
            "拜託認真一點...",
        };
        break;
    case WORRIED:
        lines = {
            "下一個再加油!"
        };
        break;
    case WIN:
        lines = {
            "你最棒！",
        };
        break;

    case LOSE:
        lines = {
            "沒事啦，下次再來。",
        };
        break;
    }

    if (lines.empty()) return "";
    return lines[rand() % lines.size()];
}

// ====================================================
//   主介面：顯示貓咪 + 對話框
// ====================================================
void Pet::show(Mood mood) const {
    drawBody(mood);
    cout << "  " << name << "：「" << pickReaction(mood) << "」" << endl;
}
