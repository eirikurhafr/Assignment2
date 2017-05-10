//
// Created by tumig on 8.5.2017.
//

#include <iostream>
#include "Base.h"

using namespace std;

Base::Base() {
    //Filla games map
    games[1] = "Fox and hounds";
    games[2] = "Breakthrough";
    games[3] = "Mega-Breakthrough";
    //Filla difficulty map
    difficultyList["random"] = 0;
    difficultyList["easy"] = 1;
    difficultyList["medium"] = 2;
    difficultyList["hard"] = 3;
    //Filla command map
    commandList["list"] = 0;
    commandList["game"] = 1;
    commandList["start"] = 2;
    commandList["legal"] = 3;
    commandList["move"] = 4;
    commandList["retract"] = 5;
    commandList["display"] = 6;
    commandList["evaluate"] = 7;
    commandList["go"] = 8;
    commandList["level"] = 9;
    commandList["debug"] = 10;
    commandList["quit"] = 11;
}

void Base::win(){
    cout << "Player " << player << " has won the game!" << endl;
    running = false;
}

void Base::move(string from,string to){
    int fRow = (int)from[0] - 97, fCol = (int)from[1]-48;
    int tRow = (int)to[0] - 97, tCol = (int)to[1]-48;
    grid[index(tRow,tCol)] = grid[index(fRow,fCol)];
    grid[index(fRow,fCol)] = '.';
}

void Base::start(){
    gameStart();
    cout << "This is the current game state: " << endl;
    display();
}
void Base::turn(){
    if(checkForWin()) {
        win();
        return;
    }
    else {
        if (player == 1)
            player++;
        else
            player--;
    }
}

bool Base::checkGameList(int n) {
    if((games.find(n) != games.end()))
        return true;
    else {
        cout << "This game doesn't exist" << endl;
        return false;
    }
}

void Base::go() {

}

int Base::commands(){
    cout << "Player " << player << "'s turn to move" << endl;
    cout << "List of commands: list, game, start, legal, move, retract"
            "display, evaluate, go, level, debug, quit" << endl;
    string input;
    int command;
    cin >> input;
    if(commandList.find(input) != commandList.end()){
        command = commandList[input];
    }
    else{
        return -1; //illegal command
    }
    switch(command) {
        case LIST: {
            cout << "List of games: " << endl;
            for (auto e : games) {
                cout << e.first << " : " << e.second << endl;
            }
            break;
        }
        case GAME: {
            int n;
            cin >> n;
            if(checkGameList(n)) {
                return n;
            }
            break;
        }
        case START: {
            start();
            break;
        }
        case LEGAL: {
            legal();
            break;
        }
        case MOVE: {
            string m1, m2;
            cin >> m1;
            cin >> m2;
            if(isLegal(m1,m2)) {
                move(m1, m2);
                turn();
            }
            else{
                cout << "This move is illegal, please input a new move" << endl;
            }
            break;
        }
        case RETRACT: {
            break;
        }
        case DISPLAY: {
            display();
            break;
        }
        case EVALUATE: {
            break;
        }
        case GO: {
            go();
            turn();
            break;
        }
        case LEVEL: {
            string s;
            cin >> s;
            level(s);
            break;
        }
        case DEBUG: {
            break;
        }
        case QUIT: {
            running = false;
            return 0;
        }
    }
    cout << endl;
    return 0;
}

void Base::display() {
    for (int i = 0; i < size_; ++i) {
        cout << (char)'a'+i << "|";
        for (int j = 0; j < size_; ++j) {
            cout << grid[index(i,j)] << "|";
        }
        cout << endl;
    }
}

void Base::level(string s){
        if(difficultyList.find(s) != difficultyList.end()){
            diff = difficultyList[s];
            cout << "Difficulty set to: " << s << endl;
        }
        else {
            cout << "Illega input, please type in a valid difficulty level." << endl;
        }
}

void Base::retract(){

}
