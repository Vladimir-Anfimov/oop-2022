#pragma once
class Student 
{
    const static int NAME_LENGTH = 30;

    char name[NAME_LENGTH];
    float gradeMath;
    float gradeEnglish;
    float gradeHistory;

  public:
    void setName(const char* name);
    const char* getName() const;

    void setGradeMath(float grade);
    float getGradeMath() const;
    
    void setGradeEnglish(float grade);
    float getGradeEnglish() const;
    
    void setGradeHistory(float grade);
    float getGradeHistory() const;

    float getAverageGrade() const;
};
