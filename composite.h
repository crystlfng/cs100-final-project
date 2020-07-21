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
    virtual string print() = 0;
    virtual int getScore(string input) = 0;
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
    
    virtual int getScore(string input){
        if(a == input)
            score +=1;
    
        return score;
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

    virtual int getScore(string input){
        if(a == input)
            score +=1;

        return score;
    }

};

