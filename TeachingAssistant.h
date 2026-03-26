#ifndef TEACHINGASSISTANT_H
#define TEACHINGASSISTANT_H

#include "Student.h"
#include "Staff.h"

class TeachingAssistant : public Student, public Staff
{
private:
    int workingHours;

public:
    TeachingAssistant(string name, int id,
                      double cgpa,
                      double salary,
                      AccessCard card,
                      int hours);

    void displayRole() override;

    void gradeAssignment(int score);
    void gradeAssignment(string letter);
};

#endif