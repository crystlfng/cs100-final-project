#ifndef __FACTORY_TEST_H__
#define __FACTORY_TEST_H__

#include "gtest/gtest.h"
#include "factory.h"
#include "composite.h"

using namespace std;


TEST(FACTORY, Basic) {
    vector<string> question = {"What year is it?\n",
                                "What color is a clear afternoon sky? \n",
                                "What is 2+2? \n",
                                "This class is for CS100. \n",
                                "Who made this project? \n"
    };
    vector<string> choice = {"a.2020\nb.2019\nc.1989\nd.3005\n",
                                "a.blue\nb.pink\nc.white\nd.red\n",
                                "a.Sebastian L\nb.Brayan M\nc.Crystal F\nd.all of those above :) \n"
    };
    vector<string> answer = {"a",
                            "a",
                            "4",
                            "t",
                            "d"                            
    };
    vector<string> type = {"MCQ",
                            "MCQ",
                            "FRQ",
                            "TF",
                            "MCQ"
    };

    Factory* test1 = new Factory(question, choice, answer, type);
    Question* returned = test1->getQuiz();

    Question* sect = new Section(returned, "Section1");


    string desc = "This test is what we learned the past week. Please use lowercase for all answers.";
    Question* head = new Header(test, "Common Sense - 101", "Quiz 3", desc);



    // Taking quiz
    EXPECT_EQ(head->takeQuestion(), 15);
}

#endif //__FACTORY_TEST_H__
