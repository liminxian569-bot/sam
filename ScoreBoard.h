#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
class ScoreBoard {
private:
    int bestEasy;
    int bestNormal;
    int bestHard;
    int totalGames;
    int totalWins;
    string fileName;
    void load();
    void save();
public:
    ScoreBoard(string file = "record.txt");
    void recordResult(int difficulty, bool won, int streak);
    void display() const;
    int getBestStreak(int difficulty) const;
};
#endif
