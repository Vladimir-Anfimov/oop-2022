#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <cstring>
#include <iostream>

void Student::setName(const char* name) 
{
    if (strlen(name) <= NAME_LENGTH)
        strcpy(this->name, name);
    else
        std::cout << "Name must be maximum 30 characters long";
}

const char* Student::getName() const {
    return this->name;
}

void Student::setGradeMath(float grade) 
{
    if (grade >= 1 && grade <= 10)
        this->gradeMath = grade;
    else
        std::cout << "Grade must be between 1 and 10.";
}

float Student::getGradeMath() const {
    return this->gradeMath;
}

void Student::setGradeEnglish(float grade) {
    if (grade >= 1 && grade <= 10)
        this->gradeEnglish = grade;
    else
        std::cout << "Grade must be between 1 and 10.";
}

float Student::getGradeEnglish() const {
    return this->gradeEnglish;
}

void Student::setGradeHistory(float grade) {
    if (grade >= 1 && grade <= 10)
        this->gradeHistory = grade;
    else
        std::cout << "Grade must be between 1 and 10.";
}

float Student::getGradeHistory() const {
    return this->gradeHistory;
}

float Student::getAverageGrade() const {
    return (gradeMath + gradeEnglish + gradeHistory) / 3;
}