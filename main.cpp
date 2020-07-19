//
//  main.cpp
//  cs100final
//
//  Created by Crystal on 7/17/20.
//  Copyright © 2020 Crystal. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include "composite.h"
#include "decorator.h"

using namespace std;

int main() {
    vector<string> question = { "what color is a clear afternoon sky? \n",
                                "what is 2+2? \n",
                                "what class is this project for? \n",
                                "who made this project? \n" };
    
    vector<string> mcqChoices = {   "a.blue \nb.pink \nc.white \nd.red\n",
                                    "a.5 \nb.8 \nc.4 \nd.10 \n",
                                    "a.CS014 \nb.CS100 \nc.PHIL001 \nd.ENG001 \n",
                                    "a.Sebastian L \nb.Brayan M \nc.Crystal F \nd.all of those above :) \n"};
    
    vector<string> mcqAnswers = {"a","c","b","d"};
    
    
    /*
    for(auto &i : question) {
        for(auto &j: i)
            j = toupper(j);
    }*/

    MCQ* quiz = new MCQ(question,mcqChoices, mcqAnswers);
    
    AllCaps* caps = new AllCaps(quiz);
    
    caps->takeQuiz();
    
    cout <<"Score: " << caps->getScore() << "%" << endl;
    
    return 0;
}
