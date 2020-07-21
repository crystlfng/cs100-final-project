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
    
    
   
        Factory* f = new Factory();
        Question* test = f->parse(qtype, decorator);
        
        cout << test->print();
        
    return 0;
}
