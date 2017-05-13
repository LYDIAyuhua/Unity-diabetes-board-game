//
//  Players.h
//  BashTheBeast
//
//  Created by yuhualiu on 2/21/17.
//  Copyright © 2017 yuhualiu. All rights reserved.
//

#ifndef Players_h
#define Players_h

#include <iostream>
#include <string>
using namespace std;


class Player
{
public:
    string name;
    string character;
    int currentState;
    int playerNum;
    
    Player(){};
    void setCharacter(string);
    void setName(string);
    void setCurrentState(int);
    void setPlayerNum(int);
    void addMoves(int);
};


void Player::setCharacter(string c)
{
    character = c;
}
void Player::setName(string n)
{
    name = n;
}
void Player::setCurrentState(int state)
{
    currentState = state;
}
void Player::setPlayerNum(int num)
{
    playerNum = num;
}
void Player::addMoves(int num)
{
    currentState +=num;
}






#endif /* Players_h */
