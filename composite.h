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
};

class MCQ: public Question{
public:
    MCQ(): Question(){
        head = NULL;
        last = NULL;
        string question = q;
        string answer  = a;
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


class FRQ: public Question{
public:
    FRQ(vector<string>qn,vector<string>ans, int i): Question(){
        q = qn[i];
        a = ans[i];
    }

    virtual string print(){
        string s = q;
        return s;
    }

    virtual int getScore(string input){
        if(a == input)
            score +=1;

        return score;
    }

};

