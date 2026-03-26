#include "Staff.h"

Staff::Staff(string name, int id, double salary, AccessCard card)
    : UniversityMember(name, id), card(card)
{
    this->salary = salary;
}

double Staff::getSalary()
{
    return salary;
}

void Staff::displayRole()
{
    cout << "Role: Staff: " << endl;
}

void Staff::displayCard()
{
    card.displayCardInfo();
}