//
//  decorator.h
//  cs100final
//
//  Created by Crystal on 7/17/20.
//  Copyright © 2020 Crystal. All rights reserved.
//
#include "composite.h"
#ifndef decorator_h
#define decorator_h

/*
class Decorator: public Quiz{
protected:
    Quiz* b;
public:
    Decorator() {};
        
    virtual void takeQuiz() = 0;
    virtual double getScore() = 0;
};


class AllCaps: public Decorator{
public:
    AllCaps(Quiz* q): Decorator(){
        b = q;
    }
    
    virtual void takeQuiz(){
        string input;
        
        for(auto &i : b->question)
            for(auto &j: i)
                j = toupper(j);
        
        for(int i = 0; i < b->question.size(); i++){
            cout << b->question[i];
            cout << b->mcqChoices[i];
            cin >> input;
            b->answer.push_back(input);
            cout << endl;
        }
        
    }
    
    virtual double getScore(){
        return b->getScore();
    }
    
};


*/
#endif /* decorator_h */
