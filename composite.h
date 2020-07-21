//
//  composite.h
//  cs100final
//
//  Created by Crystal on 7/17/20.
//  Copyright © 2020 Crystal. All rights reserved.
//

#ifndef composite_h
#define composite_h

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <ctype.h>

using namespace std;



class Question{
public:
    string q;
    string c;
    string a;
    int score = 0;
    Question(){};
    virtual void print() = 0;
    virtual int getScore() = 0;
};

class MCQ: public Question{
public:
    MCQ(vector<string>qn, vector<string>ch,vector<string>ans, int i): Question(){
        q = qn[i];
        c = ch[i];
        a = ans[i];
    }
    
    virtual void print(){
        cout << q ;
        cout << c << endl;
    }
    
    virtual int getScore(string input){
        if(a == input)
            score +=1;
    
        return score;
    }
    
};
/*
class FRQ: public Quiz{
private :
    vector<string> question;

public:
    FRQ(vector<string>q):Quiz(){
        question = q;
    }
    
    virtual void takeQuiz(){
        for(int i = 0; i < question.size(); i++){
            cout << question[i];
            cout << endl;
        }
    }
    
};
*/

#endif /* composite_h */
