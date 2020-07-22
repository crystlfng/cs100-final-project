#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <stdio.h>
#include <ctype.h>
#include "composite.h"
#include "decorator.h"
#include "factory.h"
#include "parse.h"



using namespace std;


int main()
{
    double score = 0;
    double count = 0;
    double percent;
    vector<string> questions;
    vector<string> choices;
    vector<string> answers;
    vector<string> types;

    // TYPES SPECIFICATION
    //  MCQ = "MCQ"
    //  FRQ = "FRQ"
    //  TF = "TF"


    //this will read the files in order to get the questions, adjust your file path accordingly.
    //Choices.txt will only be taking in MCQ in the order they appear on Questions.txt
    ifstream qfile("/Users/crystal/CS100/cs100-final-project/Questions.txt");
    if (!qfile) {
        cerr << "Cannot open file: " << "Questions.txt" << endl;
    } else {
        for (string line; getline(qfile, line); /**/) {
            questions.push_back(line);
        }
        cout << to_string(questions.size()) << " lines read from [" << "Questions.txt" << "]" << endl;
    }
    qfile.close();

    ifstream cfile("/Users/crystal/CS100/cs100-final-project/Choices.txt"); //adjust path
    if (!cfile) {
        cerr << "Cannot open file: " << "Choices.txt" << endl;
    } else {
        for (string line; getline(cfile, line); /**/) {
            choices.push_back(line);
        }
        cout << to_string(choices.size()) << " lines read from [" << "Choices.txt" << "]" << endl;
    }
    cfile.close();

    ifstream basicIfstream("/Users/crystal/CS100/cs100-final-project/Types.txt"); //adjust path
    if (!basicIfstream) {
        cerr << "Cannot open file: " << "Types.txt" << endl;
    } else {
        for (string line; getline(basicIfstream, line); /**/) {
            types.push_back(line);
        }
        cout << to_string(types.size()) << " lines read from [" << "Types.txt" << "]" << endl;
    }
    basicIfstream.close();

    ifstream afile("/Users/crystal/CS100/cs100-final-project/Answers.txt"); //adjust path
    if (!afile) {
        cerr << "Cannot open file: " << "Answers.txt" << endl;
    } else {
        for (string line; getline(afile, line); /**/) {
            answers.push_back(line);
        }
        cout << to_string(answers.size()) << " lines read from [" << "Answers.txt" << "]" << endl;
    }
    afile.close();
    cout << endl ;

    string input;
    string input2,input3;
    
    Factory* root = new Factory(questions,choices,answers,types);
     Question* test = root->getQuiz();
    cout << "Quiz Subject?\nsubject: ";
    getline(cin, input);
    cout << "Name of the Quiz?\nname: ";
    getline(cin, input2);
    cout << "Quiz Description?\ndescription: ";
    getline(cin, input3);
    
    
    Decorator* title = new Header(test, input, input2, input3);
    
    cout << endl << endl ;
    
    while (input != "no"){
        cout << "QUIZ START\n";
        cout << "==================\n\n";
        count = questions.size();
        score += title->takeQuestion();
        percent = (score/count)*100;
        cout << "Your score! : " << percent << "%" << endl;
        
        cout << "\nWould you like to retake this quiz?\n(yes/no):";
        cin >> input;
        cout << endl ;
        
    }     
    return 0;
}
