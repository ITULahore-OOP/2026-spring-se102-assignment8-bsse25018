#include "TutoringSession.h"

TutoringSession::TutoringSession(int id, double d,
                                 TeachingAssistant* ta,
                                 Student* student)
{
    sessionID = id;
    duration = d;
    this->ta = ta;
    this->student = student;
}

double TutoringSession::getDuration()
{
    return duration;
}

void TutoringSession::displaySession()
{
    cout << "Session " << sessionID
         << " Duration: " << duration << endl;
}

TutoringSession TutoringSession::operator+(const TutoringSession& other)
{
    return TutoringSession(0,
                           duration + other.duration,
                           ta,
                           student);
}

bool operator>(TutoringSession s1, TutoringSession s2)
{
    return s1.getDuration() > s2.getDuration();
}