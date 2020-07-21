//
//  composite.h
//  cs100final
//
//  Created by Crystal on 7/17/20.
//  Copyright © 2020 Crystal. All rights reserved.
//

#ifndef composite_h
#define composite_h

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <stdio.h>
#include <ctype.h>

using namespace std;

struct node
{
    string question;
    string answer;
    node *next;
};

class Question{
public:
    node* head;
    node* last;
    node* n;
    int score = 0;
    Question(){};
    virtual void printQuiz(node *current) = 0;
    //virtual int getScore() = 0;
    virtual void addQuestion(node *&head, node *&tail, string q, string a) = 0;
};

class MCQ: public Question{
public:
    MCQ(): Question(){
        head = NULL;
        last = NULL;
        string question = q;
        string answer  = a;
    }

    virtual void addQuestion(node *&head, node *&tail, string q, string a){ //this will add questions to a new linked list;
        if(head == NULL){ //checks if list is empty.
            node *temp = new node;
            temp->question = q;
            temp->answer = a;
            temp->next = NULL;
            head = temp;
            tail = temp;
        }
        else{
            node *temp = new node;
            temp->question = q;
            temp->answer = a;
            temp->next = NULL;
            last->next = temp;
            tail  = temp;
        }
    }

    virtual void printQuiz(node *current){ //will test that the quiz is working
        int count = 0;
        if(head == NULL){ //checks if list is empty.
            cout << "No questions in this quiz." << endl;
        }
        else{
            while(current != NULL){
                count++;
                cout << "question #" << count << " " << current->question << endl;
                cout << "answer: " << current->answer << endl << endl;
                current = current->next;
            }

        }

    }

};

class TFQuiz: public Question{
public:
    TFQuiz(): Question(){
        head = NULL;
        last = NULL;
        string question = q;
        string answer  = a;
    }

    virtual void addQuestion(node *&head, node *&tail, string q, string a){ //this will add questions to a new linked list;
        if(head == NULL){ //checks if list is empty.
            node *temp = new node;
            temp->question = q;
            temp->answer = a;
            temp->next = NULL;
            head = temp;
            tail = temp;
        }
        else{
            node *temp = new node;
            temp->question = q;
            temp->answer = a;
            temp->next = NULL;
            last->next = temp;
            tail  = temp;
        }
    }

    virtual void printQuiz(node *current){ //will test that the quiz is working
        int count = 0;
        if(head == NULL){ //checks if list is empty.
            cout << "No questions in this quiz." << endl;
        }
        else{
            while(current != NULL){
                count++;
                cout << "question #" << count << " " << current->question << endl;
                cout << "answer: " << current->answer << endl << endl;
                current = current->next;
            }

        }

    }

};


/*
class FRQ: public Quiz{
private :
    vector<string> question;

public:
    FRQ(vector<string>q):Quiz(){
        question = q;
    }
    
    virtual void takeQuiz(){
        for(int i = 0; i < question.size(); i++){
            cout << question[i];
            cout << endl;
        }
    }
    
};
*/

#endif /* composite_h */
