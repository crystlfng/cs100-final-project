#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include "composite.h"
#include "decorator.h"
#include "factory.h"


using namespace std;


int main()
{
    vector<string> question = { "what color is a clear afternoon sky? \n",
                                   "what is 2+2? \n",
                                   "what class is this project for? \n",
                                   "who made this project? \n" };
       
    vector<string> mcqChoices = {   "a.blue \nb.pink \nc.white \nd.red\n",
                                       "a.5 \nb.8 \nc.4 \nd.10 \n",
                                       "a.CS014 \nb.CS100 \nc.PHIL001 \nd.ENG001 \n",
                                       "a.Sebastian L \nb.Brayan M \nc.Crystal F \nd.all of those above :) \n"};
       
    vector<string> mcqAnswers = {"a","c","b","d"};
    
    string answer;
    
    string qtype;
    string decorator;
    int choice1, choice2;
    
    cout << "Choose quiz type:\n(1)MCQ\n(2)FRQ\nEnter \"1\" or \"2\": ";
    cin >>choice1;
    cout <<endl;
    cout << "Choose decorator type:\n(1)All Caps\n(2)No Caps\nEnter \"1\" or \"2\": ";
    cin >>choice2;
    cout <<endl;
    
    if(choice1 == 1)
        qtype = "mcq";
    else
        qtype = "frq";
    
    if(choice2 == 1)
        decorator = "allcaps";
    else
        decorator = "nocaps";
    
    
    for(int i = 0; i < question.size(); i++){
        Factory* f = new Factory();
        Question* test = f->parse(qtype, decorator,i,question);
        
        cout << test->print();
        
        cout << "answer: ";
        cin >> answer;
        cout << endl;
        //test->getScore(answer);
        //cout << endl << test->printScore() << endl;
    }
    
    
    return 0;
}
