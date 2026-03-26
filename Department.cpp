#include "Department.h"

Department::Department(string name)
{
    this->name = name;
    count = 0;
}

void Department::addMember(UniversityMember* m)
{
    members[count++] = m;
}

void Department::displayAllRoles()
{
    for (int i = 0; i < count; i++)
    {
        members[i]->displayRole();
    }
}