Math Game - C++

Overview

Math Game is a console-based application developed using C++. It allows players to answer randomly generated mathematical questions based on their selected difficulty level and operation type.

The game checks the player's answers, tracks the results, and displays a final summary showing the number of correct and incorrect answers.

Features

Select the number of questions, from 1 to 10.

Choose a difficulty level: Easy, Medium, Hard, or Mixed.

Choose a mathematical operation: Addition, Subtraction, Multiplication, Division, or Mixed.

Generate random numbers for each question.

Check answers automatically.

Display the correct answer when the player answers incorrectly.

Change the console screen color based on the answer result.

Display the final quiz results and pass/fail status.

Play again without restarting the application manually.

Difficulty Levels

Easy: Numbers between 1 and 10.

Medium: Numbers between 10 and 50.

Hard: Numbers between 50 and 100.

Mixed: Randomly selects a difficulty level for each question.

Technologies Used

C++

Visual Studio

Standard C++ Libraries

C++ Concepts Applied

Enumerations (enum) to define question difficulty levels and mathematical operations.

Structures (struct) to organize question and quiz data.

Functions to divide the program into reusable, organized tasks.

Arrays to store quiz questions.

Loops to validate user input, process questions, and allow replaying the game.

Conditional statements and switch statements to control program logic.

References to update quiz data across functions.

Random number generation using rand(), srand(), and time().

Input and output using cin and cout.

Basic arithmetic operations and answer validation.

How to Run

Clone or download this repository.

Open the project or solution file in Visual Studio.

Build the project.

Run the application.

Follow the on-screen instructions to configure and play the game.

Learning Objectives

This project was developed as part of my journey in learning C++ programming. It helped me practice programming fundamentals, organize data using structures, work with functions and references, and apply problem-solving skills through a practical application.

Future Improvements

Improve input validation to handle invalid non-numeric input.

Handle division by zero and support more suitable division questions.

Improve the scoring system and quiz statistics.

Refactor the question storage to use a dynamic container instead of a fixed-size array.

Author

Developed as a personal C++ learning project.
