#include <iostream>
#include "FoxAndHound.h"
using namespace std;

int gameLoop(Base* b);

int main() {
    Base *b = new FoxAndHound();
    while(true){
        b->start();
        int i = gameLoop(b);
        if(i == -2) {
            return 0;
        }
        else{
            switch(i){
                case 1:{
                    break;//Fox and hounds
                }
                case 2:{
                    break;//Breakthrough
                }
                case 3:{
                    break;//Mega-Breakthrough
                }
            }
        }
    }
}

int gameLoop(Base *b)
{
    int newGame = 0;
    while(b->getRunning())
    {
        newGame = b->commands();
        if(newGame > 0) {
            return newGame;
        }
        else if(newGame == -1){
            cout << "Illegal command, please try again" << endl;
        }
    }
    return -2;
}