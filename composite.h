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
    int count = 0;
    Question(){};
    virtual string print()=0;
    virtual void printScore() =0;
    virtual void increaseScore() =0;
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

    virtual void printScore(){
        cout << count << " "<< score ;
        double percent = (score/count) * 100;
        cout << "\nYour scored a " << percent << "% " << endl;
    }

    virtual void increaseScore(){
        score++;
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
        cout << "Free response : " ; //will make it easier to distinguish
        return s;
    }

    virtual void increaseScore() {
        score++;
    }

    virtual void printScore(){
        cout << count << " "<< score ;
        double percent = (score/count) * 100;
        cout << "\nYour scored a " << percent << "% " << endl;
    }
};

class TF: public Question{
public:
    TF(string qn,string ans): Question(){
        q = qn;
        a = ans;
    }

    virtual string print(){
        string s = q;
        cout << "(t) for True/(f) for False: " ;
        return s;
    }

    virtual void increaseScore(){
        score++;
    }

    virtual void printScore(){
        cout << count << " "<< score ;
        double percent = (score/count) * 100;
        cout << "\nYour scored a " << percent << "% " << endl;
    }
};

class Quiz: public Question{
public:
    vector<Question*> quiz;
    string answer;
    Quiz():Question(){};
    
    virtual string print(){
        string s= "";
        for(int i=0; i < quiz.size();i++){
            count++;
            cout << quiz[i]->print();
            cin >> answer;
            if (answer == quiz[i]->a)
                quiz[i]->increaseScore();
        }
        return s;
    }
    
    void addQuestion(Question* q){
        quiz.push_back(q);
    }

    virtual void increaseScore(){
        score++;
    }

    virtual void printScore(){
        cout << count << " "<< score ;
        double percent = (score/count) * 100;
        cout << "\nYour scored a " << percent << "% " << endl;
    }
};

#endif /* composite_h */
