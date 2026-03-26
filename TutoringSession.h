#ifndef TUTORINGSESSION_H
#define TUTORINGSESSION_H

#include "TeachingAssistant.h"
#include "Student.h"

class TutoringSession
{
private:
    int sessionID;
    double duration;
    TeachingAssistant* ta;
    Student* student;

public:
    TutoringSession(int id, double d,
                    TeachingAssistant* ta,
                    Student* student);

    double getDuration();

    void displaySession();

    TutoringSession operator+(const TutoringSession& other);
};

bool operator>(TutoringSession s1, TutoringSession s2);

#endif