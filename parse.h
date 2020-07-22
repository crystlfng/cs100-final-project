#ifndef parse_h
#define parse_h

#include <iostream>
#include <string>
#include <vector>

#include "composite.h"
#include "decorator.h"

// TYPES SPECIFICATION
//  MCQ = "MCQ"
//  FRQ = "FRQ"
//  TF = "TF"

Question* parse(vector<string> questions, vector<string> 
                choices, vector<string> answers, vector<string> types) {
    // This is returned
    Question* root = new Quiz();
    // This is to use 
    Question* tmp;
    // Checking if all vectors have correct input.
    if(questions.size()<1 && answers.size()<1 && types.size()<1) return nullptr;
    if(types[0]=="MCQ" && choices.size()<1) return nullptr;
    if(!(questions.size()==answers.size() && types.size()==questions.size())) return nullptr;
    /* Parsing loop */
    // The counter for choices which MCQ only uses
    int j = 0;
    for(int i=0; i<questions.size(); i++) {
        if(types[i] == "MCQ") {
            tmp = new MCQ(questions[i],choices[j],answers[i]);
            j++;
            tmp = new Enum(tmp, to_string(i+1));
            root->addQuestion(tmp);

        }
        else if(types[i] == "FRQ") {
            tmp = new FRQ(questions[i],answers[i]);
            tmp = new Enum(tmp, to_string(i+1));
            root->addQuestion(tmp);
        }
        else if(types[i] == "TF") {
            tmp = new TF(questions[i],answers[i]);
            tmp = new Enum(tmp, to_string(i+1));
            root->addQuestion(tmp);
        }
        else return nullptr;
    }
    return root;

}

#endif // parse_h