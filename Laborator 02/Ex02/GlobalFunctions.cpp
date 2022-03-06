#include "GlobalFunctions.h"
#include "Student.h"
#include <cstring>

int compareNames(const Student& studentOne, const Student& studentTwo) {
    int result = strcmp(studentOne.getName(), studentTwo.getName());
    if (result == 0)
        return 0;
    else if (result < 0)
        return -1;
    return 1;
}

int compareMathGrade(const Student& studentOne, const Student& studentTwo) {
    if (studentOne.getGradeMath() == studentTwo.getGradeMath())
        return 0;
    else if (studentOne.getGradeMath() > studentTwo.getGradeMath())
        return 1;
    else
        return -1;
}

int compareEnglishGrade(const Student& studentOne, const Student& studentTwo) {
    if (studentOne.getGradeEnglish() == studentTwo.getGradeEnglish())
        return 0;
    else if (studentOne.getGradeEnglish() > studentTwo.getGradeEnglish())
        return 1;
    else
        return -1;
}

int compareHistoryGrade(const Student& studentOne, const Student& studentTwo) {
    if (studentOne.getGradeHistory() == studentTwo.getGradeHistory())
        return 0;
    else if (studentOne.getGradeHistory() > studentTwo.getGradeHistory())
        return 1;
    else
        return -1;
}

int compareAverageGrade(const Student& studentOne, const Student& studentTwo) {
    if (studentOne.getAverageGrade() == studentTwo.getAverageGrade())
        return 0;
    else if (studentOne.getAverageGrade() > studentTwo.getAverageGrade())
        return 1;
    else
        return -1;
}
