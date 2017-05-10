//
// Created by tumig on 8.5.2017.
//

#ifndef ASSIGNMENT_2_BASE_H
#define ASSIGNMENT_2_BASE_H


#include <utility>
#include <string>
#include <map>
#include <vector>

class Base {
public:
    Base();
    void win();
    void move(std::string from,std::string to); //implemented
    void start();
    void turn();
    void go();
    int commands(); //nánast implemented
    void display(); //implemented
    void level(std::string s); //
    void retract();
    bool checkGameList(int n);
    int index(int row,int col) {return row*size_+col;};
    bool getRunning(){return running;};
    int getCurrPlayer(){return player;};
private:
    virtual void gameStart() = 0; //Initializar allt sem leikurin þarf
    virtual void playTurn(int player) = 0; //Sér um að gera turns fyrir hvern leik
    virtual void legal() = 0; //Sér um að checka hvaða legal moves spilandi hefur
    virtual bool isLegal(std::string from, std::string to) = 0; //Sér um að kíkja hvort move sem er að fara gerast er legal
    virtual bool checkForWin() = 0; //Kíkir hvort win state er náð
    virtual void generateGrid() = 0;
private:
    int player = 1, diff = 0;
    bool running = true;
    std::map<int,std::string> games;
    std::map<std::string,int> difficultyList;
    std::map<std::string,int> commandList;
    enum difficulty {random = 0, easy = 1, medium = 2, hard = 3};
    enum command {LIST = 0, GAME = 1, START = 2, LEGAL = 3, MOVE = 4, RETRACT = 5, DISPLAY =6, EVALUATE = 7, GO = 8, LEVEL = 9, DEBUG = 10, QUIT = 11};
public:
    int size_ = 0;
    char *grid;
    std::map<std::string,int> pawns;
};


#endif //ASSIGNMENT_2_BASE_H
