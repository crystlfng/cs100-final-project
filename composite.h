#ifndef composite_h
#define composite_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;



class Question{
    public:
        /* Constructor */
        Question(){};
        /* Virtual Functions */
        virtual void print() = 0;
        virtual int takeQuestion() = 0;
        virtual void addQuestion(Question* q) = 0;
};

class MCQ : public Question {
    private:
        /* Data */ 
        string q;
        string c;
        string a;
    public:
        /* Constructor */
        MCQ(string qn, string ch, string ans) : Question() {
            q = qn;
            c = ch;
            a = ans;
        }
        /* Inherited Functions */
        virtual void print(){
            cout << q << endl << c << endl << "Answer: ";
        }

        virtual int takeQuestion() {
            string answer;
            this->print();
            cin >> answer;
            if (answer == a)
                return 1;
            else
                return 0;
        }
        virtual void addQuestion(Question* q) {}
    
};

class FRQ: public Question {
    private:
        /* Data */
        string q;
        string a;
    public:
        /* Constructor */
        FRQ(string qn, string ans): Question() {
           q = qn;
           a = ans;
        }
        /* Inherited Functions */
        virtual void print(){
          cout << q << endl<< "Free Response: ";
        }
        virtual int takeQuestion() {
            string answer;
            this->print();
            cin >> answer;
            if (answer == a) return 1;
            else return 0;
        }
        virtual void addQuestion(Question* q) {}

};

class TF: public Question {
    private:
        /* Data */
        string q;
        string a;
    public:
        /* Constructor */
        TF(string qn, string ans): Question() {
           q = qn;
           a = ans;
        }
        /* Inherited Functions */
        virtual void print(){
          cout << q << endl << "True (t)/False (f): " ;
        }
        virtual int takeQuestion() {
            string answer;
            this->print();
            cin >> answer;
            if (answer == a) return 1;
            else return 0;
        }
        virtual void addQuestion(Question* q) {}
};

class Quiz: public Question {
    private:
        vector<Question*> quiz;
    public:
        /* Constructor */
        Quiz():Question(){};

        /* Inherited Functions */
        virtual void print() {
            for(int i=0; i < quiz.size();i++){
                quiz[i]->print();
                cout << endl;
            }
        }
        virtual int takeQuestion() {
            int score = 0;
            for(int i=0; i < quiz.size();i++){
                score += quiz[i]->takeQuestion();
                cout << endl;
            }
            return score;
        }
        /* Member Functions */
        void addQuestion(Question* q){
            quiz.push_back(q);
        }
};

#endif /* composite_h */
