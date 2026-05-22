#include "ScoreBoard.h"
ScoreBoard::ScoreBoard(string file) {
    fileName = file;
    bestEasy = 0;
    bestNormal = 0;
    bestHard = 0;
    totalGames = 0;
    totalWins = 0;
    load();
}
void ScoreBoard::load() {
    ifstream in(fileName);
    if (!in.is_open()) 
        return;   
    string line;
    while (getline(in, line)) {
        if (line.empty()) 
            continue;
        size_t pos = line.find('=');
        if (pos == string::npos) 
            continue;
        string key = line.substr(0, pos);
        int val = atoi(line.substr(pos + 1).c_str());
        if (key == "easy_best")
            bestEasy = val;
        else if (key == "normal_best") 
            bestNormal = val;
        else if (key == "hard_best")
            bestHard = val;
        else if (key == "total_games")
            totalGames = val;
        else if (key == "total_wins")
            totalWins = val;
    }
    in.close();
}
void ScoreBoard::save() {
    ofstream out(fileName);
    if (!out.is_open()) {
        cout << "[警告] 無法寫入紀錄檔" << endl;
        return;
    }
    out << "easy_best=" << bestEasy << endl;
    out << "normal_best=" << bestNormal << endl;
    out << "hard_best=" << bestHard << endl;
    out << "total_games=" << totalGames << endl;
    out << "total_wins=" << totalWins << endl;
    out.close();
}
void ScoreBoard::recordResult(int difficulty, bool won, int streak) {
    totalGames++;
    if (won) {
        totalWins++;
        if (difficulty == 1 && streak > bestEasy)
            bestEasy = streak;
        else if (difficulty == 2 && streak > bestNormal)
            bestNormal = streak;
        else if (difficulty == 3 && streak > bestHard)
            bestHard = streak;
    }
    save();  
}
void ScoreBoard::display() const {
    cout << "------------------------------" << endl;
    cout << "   歷史紀錄" << endl;
    if (totalGames == 0) {
        cout << "   (尚無紀錄,快來玩第一場!)" << endl;
    }
    else {
        int winRate = totalWins * 100 / totalGames;
        cout << "   總場次: " << totalGames
            << "  勝場: " << totalWins
            << "  勝率: " << winRate << "%" << endl;
        cout << "   最高連勝 - 簡單:" << bestEasy
            << " / 中等:" << bestNormal
            << " / 困難:" << bestHard << endl;
    }
}
int ScoreBoard::getBestStreak(int difficulty) const {
    if (difficulty == 1) 
        return bestEasy;
    if (difficulty == 2)
        return bestNormal;
    if (difficulty == 3) 
        return bestHard;
    return 0;
}
