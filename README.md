# CS100 - Final-Project

**Group Members:**

Crystal Feng            cfeng017@ucr.edu\
Brayan Montiel          bmont032@ucr.edu\
Sebastian Flores Leon   sflor032@ucr.edu

# Quiz Maker
**Uses of application**

The app will allow users to create a quiz using uploaded .txt files.
The Quiz Maker will need .txt files of a list of Questions, Choice, Question Types, and Answers.
The program will then compile this information to create a quiz with a mix of MCQs, FRQs, or TF questions depending on the Question Types that the user requested. With this, the user will be able to continually retake the quiz for their studying needs. They can also easily add, edit or remove questions in the quiz through the .txt file.

**Why are we developing this?**

As students ourselves, we are always looking for new ways to improve our learning. While there are many quiz makers online, we plan to make one that is simplistic and easy to use. As customizable as we make it, it'll become a great studying tool.

**Tools**

* Project is developed in C++ 
* Github is used for collaboration
> Will add any tools that are implemented into project

**Input/Output**
* Input: user input and imported quizzes (.txt files)
* Output: exported quizzes, quiz to be displayed, display user score depending on correct answers.



# Class Diagram UML

![alt tag](https://github.com/crystlfng/cs100-final-project/blob/master/CS100%20Final%20Project2.png)
# I/O Examples 
The program will firs prompt the user to enter the directory paths to the .txt files containing the quiz information.
The program will read those .txt files and push the appropriate information to the corresponding string vectors.
Those string vectors will then be passed into our **Factory Pattern** to make the quiz. (in the factory pattern we use one of our **decorators** to number the questions)
>Enter Question.txt directory path: \
>/Users/crystal/Desktop/test/test/Questions.txt\
>10 lines read from [Questions.txt]\
>Enter Choice.txt path: \
>/Users/crystal/Desktop/test/test/Choices.txt\
>3 lines read from [Choices.txt]\
>Enter Types.txt directory path:\
>/Users/crystal/Desktop/test/test/Types.txt\
>10 lines read from [Types.txt]\
>Enter Answer.txt directory path\
>/Users/crystal/Desktop/test/test/Answers.txt\
>10 lines read from [Answers.txt]


The user can now enter the heading information for the quiz. This will be printed out everytime they take the test so that they can remind themselves of necessary information.
>![alt tag](https://github.com/crystlfng/cs100-final-project/blob/master/io2.png)


