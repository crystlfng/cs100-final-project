#ifndef __COMPOSITE_TEST_H__
#define __COMPOSITE_TEST_H__

#include "gtest/gtest.h"
#include "composite.h"

using namespace std;

TEST(MCQTest, TestAlone) {
    string question = "What year is it (answer:2020)?\n";
    string choices = "a.2020\nb.2019\nc.1989\nd.3005\n";
    string answer = "a";

    Question* test = new MCQ(question,choices, answer);
    EXPECT_EQ(test->takeQuestion(), 1);
}

TEST(FRQTest, TestAlone) {
    string question = "What year is it (answer:2020)?\n";
    string answer = "2020";

    Question* test = new FRQ(question, answer);
    EXPECT_EQ(test->takeQuestion(), 1);
}

TEST(TFTest, TestAlone) {
    string question = "It is the year 2020 (answer:t)?\n";
    string answer = "t";

    Question* test = new TF(question, answer);
    EXPECT_EQ(test->takeQuestion(), 1);
}

TEST(QuizTest, TestAll) {
    string question = "What year is it (answer:2020)?\n";
    string choices = "a.2020\nb.2019\nc.1989\nd.3005\n";
    string answer = "a";
    Question* testmcq = new MCQ(question,choices, answer);
    
    answer = "2020";
    Question* testfrq = new FRQ(question, answer);
    
    answer = "t";
    Question* testtf = new TF(question, answer);

    Question* testquiz = new Quiz();
    testquiz->addQuestion(testmcq);
    testquiz->addQuestion(testfrq);
    testquiz->addQuestion(testtf);

    EXPECT_EQ(testquiz->takeQuestion(), 3);
}

TEST(QuizTest, Recursive) {
    string question = "What year is it (answer:2020)?\n";
    string choices = "a.2020\nb.2019\nc.1989\nd.3005\n";
    string answer = "a";
    Question* testmcq = new MCQ(question,choices, answer);
    answer = "2020";
    Question* testfrq = new FRQ(question, answer);
    answer = "t";
    Question* testtf = new TF(question, answer);
    Question* testquiz = new Quiz();
    testquiz->addQuestion(testmcq);
    testquiz->addQuestion(testfrq);
    Question* testroot = new Quiz();
    testroot->addQuestion(testquiz);
    testroot->addQuestion(testtf);

    EXPECT_EQ(testroot->takeQuestion(), 3);
}

#endif //__COMPOSITE_TEST_H__
