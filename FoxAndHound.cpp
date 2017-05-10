//
// Created by tumig on 9.5.2017.
//

#include <list>
#include <iostream>
#include "FoxAndHound.h"

using namespace std;

void FoxAndHound::gameStart(){
    generateGrid();
    pawns["h"] = 2;
    pawns["F"] = 1;
}

void FoxAndHound::playTurn(int player){

}

void FoxAndHound::legal(){
    /*vector<pair<int,int>> tempList;
    if(getCurrPlayer() == 1){
        //Finna allar staðsetningur hjá playerinum
        for (int i = 0; i < size_; ++i) {
            for (int j = 0; j < size_; ++j) {
                if(grid[index(i,j)] == 'F'){
                    tempList.push_back(make_pair(i,j));
                }
            }
        }
        for(auto j : tempList){
            isLegal(j.first,j.second);
        }

    }
    else{

    }*/
}

bool FoxAndHound::checkForWin(){
    return false;
}

bool FoxAndHound::isLegal(string from, string to){
    int fRow = (int)from[0] - 97, fCol = (int)from[1]-48;
    int tRow = (int)to[0] - 97, tCol = (int)to[1]-48;
    if(tRow < 0 || tRow > 7 || tCol < 0 || tRow > 7) //Checka hvort out of bounds
        return false;
    if(tRow == (fRow+1) || tRow == (fRow-1)){
        if(tCol == (fCol+1) || tCol == (fCol-1)){
            return true;
        }
    }
    return false;
}

void FoxAndHound::generateGrid() {
    size_ = 8;
    grid = new char[size_*size_];
    for (int i = 0; i < size_; ++i) {
        for (int j = 0; j < size_; ++j) {
            grid[index(i,j)] = '.';
        }
    }
    pawns["h"] = 2;
    pawns["F"] = 1;
    for (int k = 0; k < size_; ++k) {
        if(k%2 == 1){
            grid[index(0,k)] = 'h';
        }
    }
    grid[index(size_-1,0)] = 'F';
}