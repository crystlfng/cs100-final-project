
#ifndef decorator_h
#define decorator_h
#include "composite.h"

class Decorator : public Question
{
protected:
    Question* b;
    public:
        Decorator() {};
        
        virtual string print() = 0;
        virtual int getScore(string input) = 0;
};

class Caps: public Decorator{
public:
    Caps(Question* input):Decorator(){
        b = input;
    }
    
    virtual string print(){
        string s = b->print();
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        return s;
    }
    
    virtual int getScore(string input){
        if(a == input)
            score +=1;
        return score;
    }
};


#endif /* decorator_h */
