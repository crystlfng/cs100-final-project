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
};

class MCQ: public Question{
public:
    MCQ(vector<string>qn, vector<string>ch,vector<string>ans, int i): Question(){
        q = qn[i];
        c = ch[i];
        a = ans[i];
    }
    
    virtual string print(){
        string s = q;
        s+=c;
        return s;
    }
    
};

class FRQ: public Question{
public:
    FRQ(vector<string>qn,vector<string>ans, int i): Question(){
        q = qn[i];
        a = ans[i];
    }

    virtual string print(){
        string s = q;
        return s;
    }

};

class Quiz: public Question{
public:
    vector<Question> quiz;
    int score=0;
    string answer;
    Quiz():Question(){};
    
    virtual void print(){
        for(int i; i < quiz.size();i++){
            cout << quiz[i]->print() <<endl;
            cin >> answer;
            if (answer == quiz[i].a)
                score +=1;
        }
        
    }
    
    void addQuestion(Question* q){
        quiz.add(q);
    }
    
};

#endif /* composite_h */
