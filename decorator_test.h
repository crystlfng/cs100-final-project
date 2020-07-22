#ifndef __DECORATOR_TEST_H__
#define __DECORATOR_TEST_H__

#include "gtest/gtest.h"
#include "decorator.h"
#include <string>
#include "composite.h"

using namespace std;

TEST(DECORATOR, SECTION) {
    string question = "What year is it (answer:2020)?\n";
    string choices = "a.2020\nb.2019\nc.1989\nd.3005\n";
    string answer = "a";

    Question* test = new MCQ(question,choices, answer);

    Question* sect = new Section(test, "Multiple Choice Questions");
	
    EXPECT_EQ(sect->takeQuestion(), 1);
}

TEST(DECORATOR, MultiSections){

	//prove how we can use sections and that you can make multiple sections in one quiz

	string q1 = "what year is it?\n", q2 = "what is 2+2?\n";
	string c1 = "a.2020\nb.2019\nc.1989\nd.3005\n";
	string a1 = "a", a2 ="4";

	Question* one = new MCQ(q1, c1, a1);
	Question* two  = new FRQ(q2, a2);

	Question* sect = new Section(one, "Random Question:");
	Question* sect2 = new Section(two, "Math Question:");

	Question* test = new Quiz();
	test->addQuestion(sect);
	test->addQuestion(sect2);

	EXPECT_EQ(test->takeQuestion(), 2);


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
