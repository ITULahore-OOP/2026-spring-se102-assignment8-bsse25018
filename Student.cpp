#include "Student.h"

Student::Student(string name, int id, double cgpa)
    : UniversityMember(name, id)
{
    this->cgpa = cgpa;
}

double Student::getCGPA()
{
    return cgpa;
}

void Student::updateCGPA(double newCGPA)
{
    cgpa = newCGPA;
}

void Student::displayRole()
{
    cout << "Role: Student" << endl;
}