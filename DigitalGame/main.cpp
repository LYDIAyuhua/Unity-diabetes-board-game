//
//  main.cpp
//  BashTheBeast
//
//  Created by yuhualiu on 2/21/17.
//  Copyright © 2017 yuhualiu. All rights reserved.
//

#include <iostream>
#include <string>
#include "Players.h"
#include "Characters.h"
#include "Question.h"
#include <vector>
#include <random>
using namespace std;



vector<Character> setCharacters()
{
    //set the characters
    vector<Character> characters;
    Character a;
    a.setName("Dora Drop Dose");
    a.setNum(0);
    a.setEnable(false);
    Character b;
    b.setName("Sid the Snackman");
    b.setNum(1);
    b.setEnable(false);
    Character c;
    c.setName("Sugar Ray Raise Dose");
    c.setNum(2);
    c.setEnable(false);
    Character d;
    d.setName("Stan Stable Dose");
    d.setNum(3);
    d.setEnable(false);
    characters.push_back(a);
    characters.push_back(b);
    characters.push_back(c);
    characters.push_back(d);
    return characters;
    
}

vector<Questions> setQuestions()
{
    vector<Questions> questions;
    Questions a;
    a.setTitle("What snack is the healthiest?");
    a.setChoice1("1) Piece of fruit");
    a.setChoice2("2) Animal crackers");
    a.setChoice3("3) Snickers bar");
    a.setCorrectAnswer(1);
    Questions b;
    b.setTitle("Which food you can eat?");
    b.setChoice1("1) Orange");
    b.setChoice2("2) Chocalate");
    b.setChoice3("3) Jelly");
    b.setCorrectAnswer(1);
    questions.push_back(a);
    questions.push_back(b);
    return questions;
}


//change characters.
vector<Player> setPlayers(int numPlayers,vector<Character> &characters)
{
    vector<Player> players;
    for (int i = 0; i < numPlayers;i++)
    {
        string name;
        Player p;
        p.setCurrentState(0);
        p.setPlayerNum(i+1);
        printf("Player %d: What's your name? ",i+1);
        cin >> name;
        p.setName(name);
        printf("Player %d: Here are your character choices: ",i+1);
        cout<<endl;
        int count = 1;
        for (vector<Character>::size_type j = 0; j != characters.size(); j++)
        {
            if (characters[j].enable == false)
            {
                printf("    %d) %s",count,characters[j].name.c_str());
                cout<<endl;
                count++;
            }
        }
        cout <<"Enter your selection: ";
        int charSelect;
        cin >> charSelect;
        cout<<endl;
        int numfalse = 1;
        for(std::vector<Character>::size_type n = 0; n!= characters.size(); n++)
        {
            if(characters[n].enable == false)
            {
                if(charSelect == numfalse)
                {
                    p.setCharacter(characters[n].name);
                    characters[n].enable = true;
                   // cout<<characters[n].name<<endl;  check the character names;
                }
                numfalse++;
            }
        }
        players.push_back(p);
    }
    return players;
}

int rollDice()
{
    return rand()%6+1;
}
int rollQuestions(vector<Questions> questions)
{
    return rand() % (questions.size()-1);
    
    //random_device random_device;
    //mt19937 engine{random_device()};
    //uniform_int_distribution<int> dist(0, questions.size() - 1);
    
    //int random_element = questions[dist(engine)];
    //return random_element;
}

int printMain()

//This function print the main menu
{
    int select;
    cout <<"    1) Start Game\n";
    cout <<"    2) Load Saved Game\n";
    cout <<"    3) Tutorial\n";
    cout <<"    4) About\n";
    cout <<"    5) Quit\n";
    cout << "Enter your selection: ";
    cin >> select;
    return select;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Welcome to the Bash the Beast! Please make the selection below: "<<endl;
    while (true)
    {
        int select = printMain();
        cout << "################################################################"<<endl;
        cout << "Let's get set up! Enter the number of players (1-4): ";
        int numPlayers;
        cin>>numPlayers;
        vector<Character> characters = setCharacters();
        vector<Player> players = setPlayers(numPlayers, characters);
        vector<Questions> questions = setQuestions();
        cout << "Setting up the game ...."<<endl;
        cout << "################################################################"<<endl;
        if (select == 1)
        {
            for (vector<Player>::size_type i = 0; i!= players.size(); i++)
            {
                printf("Player %d's turn \n" ,i+1);
                int num = rollDice();
                players[i].addMoves(num);
                printf("Rolling dice...you got a %d. Your game piece is now %d spaces from the clinic. Drawing card...time for a question.\n",num,players[i].currentState);
                
                int randomQuestion = rollQuestions(questions);
                
                cout<<"Arrived\n"<<endl;
                cout<<questions[randomQuestion].title.c_str()<<endl;
                
                printf("Question: %s \n",questions[randomQuestion].title.c_str());
                printf("    %s\n",questions[randomQuestion].choice1.c_str());
                printf("    %s\n",questions[randomQuestion].choice2.c_str());
                printf("    %s\n",questions[randomQuestion].choice3.c_str());
                cout<<"Enter your response: "<<endl;
                int answer;
                cin >> answer;
                if (answer == questions[randomQuestion].answer)
                {
                    printf("That's correct! Your glucose has dropped to 45, great job!\n");
                }
                else
                {
                    printf("Oh, Sorry! you did it wrong. Have a try next time.\n");
                }
                printf("'y' to continues or 'm' to enter the menu: ");
                string Continue;
                cin >>Continue;
                if (Continue == "y") {cout<<endl;continue;}
                else if(Continue == "m") printMain(); //need consider how to jump to the mian menu
                else break;
            }
        }
        if(select == 2){}
        if(select == 3){}
        if(select == 4){}
        if(select == 5)
        {
            break;
        }
    }
    
    return 0;
}

