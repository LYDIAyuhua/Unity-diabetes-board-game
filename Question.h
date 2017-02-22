//
//  Question.h
//  BashTheBeast
//
//  Created by yuhualiu on 2/21/17.
//  Copyright © 2017 yuhualiu. All rights reserved.
//

#ifndef Question_h
#define Question_h

#include <string.h>
#include <iostream>
using namespace std;



class Questions
{
public:
    string title;
    string choice1;
    string choice2;
    string choice3;
    int penalty;
    int answer;
    
    Questions(){};
    void setTitle(string);
    void setChoice1(string);
    void setChoice2(string);
    void setChoice3(string);
    void setCorrectAnswer(int);
    bool checkAnswer(int);
    void setPenalty(int);
    
};
void Questions::setPenalty(int p)
{
    penalty = p;
}
void Questions::setCorrectAnswer(int a)
{
    answer = a;
}
void Questions::setTitle(string t)
{
    title = t;
}
void Questions::setChoice1(string choice)
{
    choice1 = choice;
}
void Questions::setChoice2(string choice)
{
    choice2 = choice;
}
void Questions::setChoice3(string choice)
{
    choice3 = choice;
}
bool Questions::checkAnswer(int check)
{
    if (answer == check) return true;
    return false;
}
#endif /* Question_h */
