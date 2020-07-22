#ifndef factory_h
#define factory_h
#include <iostream>
#include <string>
#include <vector>

#include "composite.h"
#include "decorator.h"
#include "parse.h"

class Question;

// Input wil be asked for in main and sent to Factory as vectors

// Factory will take in several vectors 
// One for Question
// Two for Choices
// Three for Answer 
// Four for QuestionType

class Factory {
    private:
        /* Data */
        Question* root;
    public:
        /* Constructor */
        Factory(vector<string> questions, vector<string> 
                choices, vector<string> answers, vector<string> types) {
            root = parse(questions,choices,answers,types);
        }
        /* Member Function */
        Question* getQuiz() {return root;}
};

#endif /* factory_h */
