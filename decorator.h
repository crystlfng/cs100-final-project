
#ifndef decorator_h
#define decorator_h

#include "composite.h"

class Decorator : public Question {
    protected:
        /* Data */
        Question* b;
    public:
        /* Constructor */
        Decorator() {};
        /* Inherited Functions */
        virtual void print() = 0;
        virtual int takeQuestion() = 0;
        virtual void addQuestion(Question* q) = 0;
};

class Section : public Decorator {
    private:
        /* Data */
        string sectname = "";
    public:
        /* Constructor */
        Section(Question* q, string name) {
            b = q;
            sectname = name;
        }
        /* Inherited Functions */
        virtual void print() {
            cout << sectname << endl 
                 << "**************************" << endl;
            b->print();
            cout << "**************************\n" << endl;
        }
        virtual int takeQuestion() {
            cout << sectname << endl 
                 << "**************************" << endl;
            int score = b->takeQuestion();
            cout << "**************************\n" << endl;
            return score;
        }
        virtual void addQuestion(Question* q) {}


};

class Header : public Decorator {
    private:
        /* Data */
        string subject = "";
        string quizname = "";
        string quizdescription = "";
    public:
        /* Constructor */
        Header(Question* q, string sub, string name, string desc) {
            b = q;
            subject = sub;
            quizname = name;
            quizdescription = desc;
        }
        /* Inherited Functions */
        virtual void print() {
            cout << "Quiz Name: " << quizname << endl << "Subject: " << subject << endl
                 << "Description: " << quizdescription
                 << "\n__________________________\n" << endl;
            b->print();
            cout << "____________________________\n" << endl;
        }
        virtual int takeQuestion() {
            cout << "Quiz Name: " << quizname << endl << "Subject: " << subject << endl
                 << "Description: " << quizdescription
                 << "\n__________________________\n" << endl;
            int score = b->takeQuestion();
            cout << "____________________________\n" << endl;
            return score;
        }
        virtual void addQuestion(Question* q) {}


};

class Enum : public Decorator {
    private:
        /* Data */
        string enumer; 
    public:
        /* Constructor */
        Enum(Question* q, string num) {
            b = q;
            enumer = num;
        }
        /* Inherited Functions */
        virtual void print() {
            cout << enumer << ".) ";
            b->print();
        }
        virtual int takeQuestion() {
            cout << enumer << ".) ";
            int score = b->takeQuestion();
            return score;
        }
        virtual void addQuestion(Question* q) {}


};
#endif /* decorator_h */
