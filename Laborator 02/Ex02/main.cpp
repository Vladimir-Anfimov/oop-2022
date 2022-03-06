#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include "GlobalFunctions.h"
#include <iostream>

int main()
{
    Student studentOne = Student();
    Student studentTwo = Student();

    studentOne.setName("Vladimir");
    studentTwo.setName("Andrei");

    studentOne.setGradeMath(10);
    studentTwo.setGradeMath(5);

    studentOne.setGradeEnglish(6);
    studentTwo.setGradeEnglish(8);

    studentOne.setGradeHistory(9);
    studentTwo.setGradeHistory(9);

    std::cout << "Grades math: \n";
    std::cout << studentOne.getName() << " : " << studentOne.getGradeMath() << "\n";
    std::cout << studentTwo.getName() << " : " << studentTwo.getGradeMath() << "\n\n";

    std::cout << "Grades english: \n";
    std::cout << studentOne.getName() << " : " << studentOne.getGradeEnglish() << "\n";
    std::cout << studentTwo.getName() << " : " << studentTwo.getGradeEnglish() << "\n\n";

    std::cout << "Grades history: \n";
    std::cout << studentOne.getName() << " : " << studentOne.getGradeHistory() << "\n";
    std::cout << studentTwo.getName() << " : " << studentTwo.getGradeHistory() << "\n\n";

    std::cout << "Grades average: \n";
    std::cout << studentOne.getName() << " : " << studentOne.getAverageGrade() << "\n";
    std::cout << studentTwo.getName() << " : " << studentTwo.getAverageGrade() << "\n\n";

    std::cout << "Compare names result: " << compareNames(studentOne, studentTwo) << "\n\n";

    std::cout << "Compare math grade result: " << compareMathGrade(studentOne, studentTwo) << "\n\n";

    std::cout << "Compare english grade result: " << compareEnglishGrade(studentOne, studentTwo) << "\n\n";
    
    std::cout << "Compare history grade result: " << compareHistoryGrade(studentOne, studentTwo) << "\n\n";

    std::cout << "Compare average grade result: " << compareAverageGrade(studentOne, studentTwo) << "\n\n";



}