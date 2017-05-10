//
// Created by tumig on 9.5.2017.
//

#ifndef ASSIGNMENT_2_FOXANDHOUND_H
#define ASSIGNMENT_2_FOXANDHOUND_H
#include "Base.h"

class FoxAndHound : public Base {
public:
    FoxAndHound() : Base() {};
    virtual void gameStart();
    virtual void playTurn(int player);
    virtual void legal();
    virtual bool checkForWin();
    virtual bool isLegal(std::string from, std::string to);
    virtual void generateGrid();
};


#endif //ASSIGNMENT_2_FOXANDHOUND_H
