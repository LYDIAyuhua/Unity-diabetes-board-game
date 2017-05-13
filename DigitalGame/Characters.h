//
//  Character.h
//  BashTheBeast
//
//  Created by yuhualiu on 2/21/17.
//  Copyright © 2017 yuhualiu. All rights reserved.
//

#ifndef Characters_h
#define Characters_h
#include <string>
using namespace std;


class Character
{
public:
    string name;
    bool enable;
    int characterNum;
    
    Character(){}
    void setName(string);
    void setNum(int);
    void setEnable(bool);
    void setCharacter(string,int,bool);
};
void Character::setCharacter(string characterName,int num,bool choice)
{
    name = characterName;
    enable = choice;
    characterNum = num;
}

void Character::setName(string characterName)
{
    name = characterName;
}
void Character::setNum(int num)
{
    characterNum = num;
}
void Character::setEnable(bool choice)
{
    enable = choice;
}

#endif /* Characters_h */
