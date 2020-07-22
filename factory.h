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
        string q1 ="what color is a clear afternoon sky? \n",
                                          q2 ="what is 2+2? \n",
                                          q3 ="what class is this project for? \n",
                                          q4 ="who made this project? \n" ;
          
       string c1 ="a.blue\nb.pink\nc.white\nd.red\n",
            c2 = "a.5\nb.8\nc.4\nd.10\n",
            c3 = "a.CS014\nb.CS100\nc.PHIL001\nd.ENG001\n",
            c4 = "a.Sebastian L\nb.Brayan M\nc.Crystal F\nd.all of those above :) \n";
          
       string a1 = "a",a2= "c",a3 ="b",a4 ="d";
        string fa1 = "blue",fa2 = "4",fa3 = "cs100", fa4 = "everyone";

        //Questions for True/False
        string tf1 = "A slug's blood is green."/*true*/,
                tf2 = "Approximately one quarter of human bones are in the feet."/*true*/,
                tf3 = "The total surface area of two human lungs is approximately 70 square metres."/*true*/,
                tf4 = "In West Virginia, USA, if you accidentally hit an animal with your car, you are free to take it home to eat."/*true*/,
                tf5 = "In London, UK, if you happen to die in the House of Parliament, you are technically entitled to a state funeral, "
                      "because the building is considered too sacred a place."/*false*/,
                tf6 =  "It is illegal to pee in the Ocean in Portugal."/*true*/,
                tf7 = "You can lead a cow down stairs but not up stairs."/*false*/,
                tf8 = "Google was originally called 'Backrub'"/*true*/;

        string ta1 = "t" ,ta2 = "t",ta3 = "t", ta4 = "t", ta5 = "f", ta6 = "t", ta7 = "f", ta8 = "t";
        
        Quiz* tester = new Quiz();
        
        
        // ALL-CAPS
        if(decorator == "1"){
            if(qtype == "1&2"){
                FRQ* temp1 = new FRQ(q1,fa1);
                Caps* test1 = new Caps(temp1);
                tester->addQuestion(test1);
                    
                MCQ* temp2= new MCQ(q2, c2, a2);
                Caps* test2 = new Caps(temp2);
                tester->addQuestion(test2);
                    
                FRQ* temp3 = new FRQ(q3, fa3);
                Caps* test3 = new Caps(temp3);
                tester->addQuestion(test3);
                
                MCQ* temp4 = new MCQ(q4, c4, a4);
                Caps* test4 = new Caps(temp4);
                tester->addQuestion(test4);
            }
            //else if(qtype = "23"
            //else
            if(qtype == "1&3") {
                FRQ* temp1 = new FRQ(q1,fa1);
                Caps* test1 = new Caps(temp1);
                tester->addQuestion(test1);

                TF* temp2 = new TF(tf1,ta1);
                Caps* test2 = new Caps(temp2);
                tester->addQuestion(test2);
            }
        }
        else{
            if(qtype == "1&2"){
                FRQ* temp1 = new FRQ(q1,fa1);
                tester->addQuestion(temp1);
                    
                MCQ* temp2= new MCQ(q2, c2, a2);
                tester->addQuestion(temp2);
                    
                FRQ* temp3 = new FRQ(q3, fa3);
                tester->addQuestion(temp3);
                
                MCQ* temp4 = new MCQ(q4, c4, a4);
                tester->addQuestion(temp4);
            }
            //else if(qtype = "23"
            //else
        }
        
        
        return tester;
    }
};

#endif /* factory_h */

