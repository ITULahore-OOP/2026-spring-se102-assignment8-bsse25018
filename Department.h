#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "UniversityMember.h"

class Department
{
private:
    string name;
    UniversityMember* members[50];
    int count;

public:
    Department(string name);

    void addMember(UniversityMember* m);

    void displayAllRoles();
};

#endif