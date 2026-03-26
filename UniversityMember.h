#ifndef UNIVERSITYMEMBER_H
#define UNIVERSITYMEMBER_H
#include <iostream>
#include <string>
using namespace std;
class UniversityMember
{
private:
   string name;
	int memberID;
public:
   virtual ~UniversityMember();
    UniversityMember(string name, int memberID);
	string getName();
	int getMemberID();
	virtual void displayRole() = 0;
};

#endif