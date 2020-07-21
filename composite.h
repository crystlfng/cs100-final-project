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
    virtual string print()=0;
};

class MCQ: public Question{
public:
    MCQ(string qn, string ch, string ans): Question(){
        q = qn;
        c = ch;
        a = ans;
    }
    
    virtual string print(){
        string s = q;
        s+=c;
        return s;
    }
    
};

class FRQ: public Question{
public:
    FRQ(string qn,string ans): Question(){
        q = qn;
        a = ans;
    }

    virtual string print(){
        string s = q;
        return s;
    }

};

class Quiz: public Question{
public:
    vector<Question*> quiz;
    int score=0;
    string answer;
    Quiz():Question(){};
    
    virtual string print(){
        string s= "";
        for(int i=0; i < quiz.size();i++){
            cout << quiz[i]->print();
            cin >> answer;
            if (answer == quiz[i]->a)
                score +=1;
        }
        return s;
    }
    
    void addQuestion(Question* q){
        quiz.push_back(q);
    }
    
};

#endif /* composite_h */
