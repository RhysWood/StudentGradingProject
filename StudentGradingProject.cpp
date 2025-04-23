#include "pch.h"
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm> //for std::short

int main()
{
    struct Student {
        std::string name;
        int score;
    };

    double totalScore = 0;
    int highScore = 0;
    int fails = 0;
    int pass = 0;
    std::string winner;


    //Ask for number of students
    std::cout << "Please Specify number of students: ";
    int numberOfStudents;

    //save that input as an int
    std::cin >> numberOfStudents;

    //Ignore everything in the input buffer until we hit a newline character.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    //loop for that many times, asking for a student name and grade each time
    for (int i = 0; i < numberOfStudents; i++) {
        std::cout << "Please enter student name: ";
        std::string studentName;
        std::getline(std::cin, studentName);

        std::cout << "Please enter " << studentName << "'s score: ";
        int score;
        std::cin >> score;
        totalScore += score;
        if (score > highScore) {
            highScore = score;
            winner = studentName;
        }
        //print Pass or Failif over or under 50
        if (score < 50) {
            std::cout << studentName << " failed.\n";
            fails += 1;
        }
        else if (score < 60) {
            std::cout << studentName << " got a C.\n";
            pass += 1;
        }
        else if (score < 70) {
            std::cout << studentName << " got a B.\n";
            pass += 1;
        }
        else if (score < 80) {
            std::cout << studentName << " got an A.\n";
            pass += 1;
        }
        else {
            std::cout << studentName << " got an A*.\n";
            pass += 1;
        }
        // Clear newline after entering score, in case we use getline again
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }
    std::cout << "The class average is " << (totalScore / numberOfStudents) << "\n";
    std::cout << fails << " people failed, while " << pass << " people passed.\n";
    std::cout << "The highest score was " << highScore << " from " << winner << "!";
    return 0;
}
