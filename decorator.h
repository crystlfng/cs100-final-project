
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
        virtual void printScore()= 0;
        virtual void increaseScore() =0;
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

    virtual void increaseScore(){
        score++;
    }

    virtual void printScore(){
        cout << count << " "<< score ;
        double percent = (score/count) * 100;
        cout << "\nYour scored a " << percent << "% " << endl;
    }
};


#endif /* decorator_h */
