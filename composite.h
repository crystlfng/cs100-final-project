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



class Quiz{
public:
    vector<string> question;
    vector<string> mcqChoices;
    vector<string> mcqAnswers;
    vector<string> answer;
    Quiz(){};
    virtual void takeQuiz() = 0;
    virtual double getScore() = 0;
};

class MCQ: public Quiz{
private :
    vector<string> question;
    vector<string> mcqChoices;
    vector<string> mcqAnswers;
    vector<string>answer;
public:
    MCQ(vector<string>q,vector<string>c, vector<string>a): Quiz(){
        question = q;
        mcqChoices = c;
        mcqAnswers = a;
    }
    
    virtual void takeQuiz(){
        string input;
        
        for(int i = 0; i < question.size(); i++){
            cout << question[i];
            cout << mcqChoices[i];
            cin >> input;
            answer.push_back(input);
            cout << endl;
        }
    }
    
    virtual double getScore(){
        double score = 0;
        for (int i = 0; i < question.size(); i++){
            if(mcqAnswers[i] == answer[i]){
                score += 1;
            }
        }
        score = score/question.size();
        
        score = score*100;
        
        return score;
    }

    
};

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


#endif /* composite_h */
