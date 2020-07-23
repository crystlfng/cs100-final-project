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

**Input/Output**
* Input: user input and imported quizzes (.txt files)
* Output: exported quizzes, quiz to be displayed, display user score depending on correct answers.



# Class Diagram UML

![alt tag](https://github.com/crystlfng/cs100-final-project/blob/master/CS100%20Final%20Project2.png)
# I/O Examples 
>The program will firs prompt the user to enter the directory paths to the .txt files containing the quiz information.
The program will read those .txt files and push the appropriate information to the corresponding string vectors.
Those string vectors will then be passed into our **Factory Pattern** to make the quiz. (in the factory pattern we use one of our **decorators** to number the questions)
![alt tag](https://github.com/crystlfng/cs100-final-project/blob/master/io1.png)


>The user can now enter the heading information for the quiz. This will be printed out everytime they take the test so that they can remind themselves of necessary information. This information is passed into the **Heading Decorator** to be implemeted.
![alt tag](https://github.com/crystlfng/cs100-final-project/blob/master/io2.png)

>With the information provideed from the user the program will now print the quiz. The quiz allows for the user to answer their own questions; a mix of MCQ, FRQ, and TF (depends on what they provided in the txt files).
![alt tag](https://github.com/crystlfng/cs100-final-project/blob/master/io3.png)

>When answering the questions, the program keeps track of whther or not you answered correctly and will print the users score according to those answers.
![alt tag](https://github.com/crystlfng/cs100-final-project/blob/master/io4.png)

>The user can now choose to retake the quiz for a better score, in which the program will reprint the quiz and allow for a retake.
![alt tag](https://github.com/crystlfng/cs100-final-project/blob/master/io5.png)

>If the user decides that they are satisfied, they can opt not to retake in which the program will close.
![alt tag](https://github.com/crystlfng/cs100-final-project/blob/master/io6.png)



