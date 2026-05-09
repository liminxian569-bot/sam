#ifndef PET_H
#define PET_H
#include <string>
#include <vector>
using namespace std;

class Pet {
public:
    enum Mood {
        IDLE,       
        HAPPY,       
        WORRIED,     
        LOW_HP,     
        WIN,       
        LOSE       
    };

    Pet(const string& name = "Coddy");

   
    void show(Mood mood) const;

    string getName() const { return name; }

private:
    string name;

  
    void drawBody(Mood mood) const;           
    string pickReaction(Mood mood) const;       
};

#endif
