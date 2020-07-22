#ifndef __DECORATOR_TEST_H__
#define __DECORATOR_TEST_H__

#include "gtest/gtest.h"
#include "decorator.h"
#include <string>

using namespace std;

TEST(DECORATOR, SECTION) {
    string question = "What year is it (answer:2020)?\n";
    string choices = "a.2020\nb.2019\nc.1989\nd.3005\n";
    string answer = "a";

    Question* test = new MCQ(question,choices, answer);

    Question* sect = new Section(test, "Multiple Choice Questions");

    EXPECT_EQ(sect->takeQuestion(), 1);
}

TEST(DECORATOR, HEADER) {
    string question = "What year is it (answer:2020)?\n";
    string choices = "a.2020\nb.2019\nc.1989\nd.3005\n";
    string answer = "a";

    Question* test = new MCQ(question,choices, answer);

    string desc = "This test is what we learned the past week. Please use lowercase for all answers.";
    Question* head = new Header(test, "Common Sense - 101", "Quiz 3", desc);

    EXPECT_EQ(head->takeQuestion(), 1);
}

TEST(DECORATOR, SectionHeaderNumbered) {
    string question = "What year is it (answer:2020)?\n";
    string choices = "a.2020\nb.2019\nc.1989\nd.3005\n";
    string answer = "a";

    Question* test = new MCQ(question,choices, answer);
    Question* num1 = new Enum(test, "1");

    Question* sect = new Section(num1, "Multiple Choice Questions");

    string desc = "This test is what we learned the past week. Please use lowercase for all answers.";
    Question* head = new Header(sect, "Common Sense - 101", "Quiz 3", desc);

    EXPECT_EQ(head->takeQuestion(), 1);
}

#endif //__DECORATOR_TEST_H__
