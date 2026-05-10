#include "Pet.h"
#include <iostream>
#include <cstdlib>
Pet::Pet(const string& petName) {
    name = petName;
}
void Pet::drawBody(Mood mood) const {
    switch (mood) {
    case IDLE:
        cout << "       /\\_/\\" << endl;
        cout << "      ( -.- )" << endl;
        cout << "       >   <" << endl;
        cout << "       /   \\" << endl;
        cout << "      (_____)~" << endl;
        break;

    case HAPPY:
        cout << "       /\\_/\\   " << endl;
        cout << "      ( ^.^ )" << endl;
        cout << "       >   <" << endl;
        cout << "       /   \\" << endl;
        cout << "      (_____)~" << endl;
        break;
    case LOW_HP:
        cout << "    !  /\\_/\\  !" << endl;
        cout << "      ( O.O )" << endl;
        cout << "       >   <" << endl;
        cout << "      _/| |\\_" << endl;
        cout << "      (_____)" << endl;
        break;
        case WORRIED:
            cout << "       /\\_/\\" << endl;
            cout << "      ( ;.; )" << endl;
            cout << "       > _ <" << endl;
            cout << "       /   \\" << endl;
            cout << "      (_____)~" << endl;
            break;
    case WIN:
        cout << "    *  /\\_/\\  *" << endl;
        cout << "      ( ^o^ )" << endl;
        cout << "       >   <" << endl;
        cout << "      _/| |\\_" << endl;
        cout << "      (_____)" << endl;
        break;

    case LOSE:
        cout << "       /\\_/\\" << endl;
        cout << "      ( T_T )" << endl;
        cout << "       >   <" << endl;
        cout << "       /   \\" << endl;
        cout << "      (_____)" << endl;
        cout << "         ' '" << endl;
        break;
    }
}
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
void Pet::show(Mood mood) const {
    drawBody(mood);
    cout << "  " << name << "：「" << pickReaction(mood) << "」" << endl;
}
