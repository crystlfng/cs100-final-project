#ifndef factory_h
#define factory_h
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include "composite.h"
#include "decorator.h"

class Question;

class Factory{
public:
    Factory(){};
    
    Question* parse(string qtype, string decorator){
        vector<string> question = { "what color is a clear afternoon sky? \n",
                                          "what is 2+2? \n",
                                          "what class is this project for? \n",
                                          "who made this project? \n" };
          
       vector<string> mcqChoices = {   "a.blue \nb.pink \nc.white \nd.red\n",
                                          "a.5 \nb.8 \nc.4 \nd.10 \n",
                                          "a.CS014 \nb.CS100 \nc.PHIL001 \nd.ENG001 \n",
                                          "a.Sebastian L \nb.Brayan M \nc.Crystal F \nd.all of those above :) \n"};
          
       vector<string> mcqAnswers = {"a","c","b","d"};
        
        
        
        Quiz* tester = new Quiz();
        
        for (int i =0; i < question.size(); i++){
            
        if (qtype == "frq" && decorator == "nocaps" ){
                FRQ* test = new FRQ(question,mcqAnswers, i);
                
            tester->addQuestion(test);
        }
        if (qtype == "mcq" && decorator == "nocaps" ){
                MCQ* test= new MCQ(question, mcqChoices,mcqAnswers, i);
            
            tester->addQuestion(test);
        }
        
        
        if (qtype == "frq" && decorator == "allcaps" ){
                FRQ* temp = new FRQ(question,mcqAnswers, i);
                Caps* test = new Caps(temp);
           tester->addQuestion(test);
        }
        
        if (qtype == "mcq" && decorator == "allcaps" ){

                MCQ* temp = new MCQ(question, mcqChoices,mcqAnswers, i);
                Caps* test = new Caps(temp);
             tester->addQuestion(test);
            
        }
        }
        
        return tester;
    }
};

#endif /* factory_h */

