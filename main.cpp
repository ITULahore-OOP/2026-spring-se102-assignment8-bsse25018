#include <iostream>
#include "AccessCard.h"
#include "Student.h"
#include "Staff.h"
#include "TeachingAssistant.h"
#include "TutoringSession.h"
#include "Department.h"
#include <string>
using namespace std;

int main()
{    
    cout << "==============================" << endl;
    cout << "  ASSIGNMENT 8 | BSSE-25018" << endl << endl;
    cout << "==============================" << endl << endl;

    cout << "==============================" << endl;
    cout << "   SMART UNIVERSITY SYSTEM" << endl << endl;
    cout << "==============================" << endl << endl;

    // ---------- BUILD DEPARTMENT ----------

    string deptName;

    cout << "Build a Department First" << endl;
    cout << "Enter Department Name: ";
    cin >> deptName;

    Department dept(deptName);

    // ---------- ARRAYS ----------

    Student* students[50];
    Staff* staffs[50];
    TeachingAssistant* tas[50];
    TutoringSession* sessions[50];

    int studentCount = 0;
    int staffCount = 0;
    int taCount = 0;
    int sessionCount = 0;

    int choice;

    do
    {
        cout << endl << "=================================" << endl;
        cout << "            MENU" << endl;
        cout << "=================================" << endl;

        cout << "1. Create Student" << endl;
        cout << "2. Create Staff" << endl;
        cout << "3. Create Teaching Assistant" << endl;
        cout << "4. Add Member to Department" << endl;
        cout << "5. Display All Roles" << endl;
        cout << "6. Grade Assignment" << endl;
        cout << "7. Create Tutoring Session" << endl;
        cout << "8. Merge Two Sessions (+)" << endl;
        cout << "9. Compare Two Sessions (>)" << endl;
        cout << "0. Exit" << endl;

        cout << "---------------------------------" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string name;
            int id;
            double cgpa;

            cout << endl << "Enter Name: ";
            cin >> name;

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter CGPA: ";
            cin >> cgpa;

            students[studentCount] =
                new Student(name, id, cgpa);

            studentCount++;

            cout << "Student Created" << endl;
        }

        else if (choice == 2)
        {
            string name, cardID;
            int id, level;
            double salary;

            cout << endl << "Enter Name: ";
            cin >> name;

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter Salary: ";
            cin >> salary;

            cout << "Enter Card ID: ";
            cin >> cardID;

            cout << "Enter Access Level: ";
            cin >> level;

            AccessCard card(cardID, level);

            staffs[staffCount] =
                new Staff(name, id, salary, card);

            staffCount++;

            cout << "Staff Created" << endl;
        }

        else if (choice == 3)
        {
            string name, cardID;
            int id, level, hours;
            double cgpa, salary;

            cout << endl << "Enter Name: ";
            cin >> name;

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter CGPA: ";
            cin >> cgpa;

            cout << "Enter Salary: ";
            cin >> salary;

            cout << "Enter Card ID: ";
            cin >> cardID;

            cout << "Enter Access Level: ";
            cin >> level;

            cout << "Enter Working Hours: ";
            cin >> hours;

            AccessCard card(cardID, level);

            tas[taCount] =
                new TeachingAssistant(
                    name,
                    id,
                    cgpa,
                    salary,
                    card,
                    hours);

            taCount++;

            cout << "Teaching Assistant Created" << endl;
        }

        else if (choice == 4)
        {
            int type;

            cout << endl << "1 Student" << endl;
            cout << "2 Staff" << endl;
            cout << "3 TA" << endl;

            cout << "Select Type: ";
            cin >> type;

            if (type == 1 && studentCount > 0)
            {
                dept.addMember(
                    students[studentCount - 1]);
            }
            else if (type == 2 && staffCount > 0)
            {
                dept.addMember(
                    staffs[staffCount - 1]);
            }
            else if (type == 3 && taCount > 0)
            {
                dept.addMember(
                    tas[taCount - 1]);
            }
            else
            {
                cout << "Create Member First" << endl;
            }
        }

        else if (choice == 5)
        {
            cout << endl << "Department Members:" << endl;
            dept.displayAllRoles();
        }

        else if (choice == 6)
        {
            if (taCount == 0)
            {
                cout << "No TA Available" << endl;
            }
            else
            {
                int index;
                int type;

                cout << "Enter TA Index (0-"
                     << taCount - 1
                     << "): ";
                cin >> index;

                cout << "1 Numeric" << endl;
                cout << "2 Letter" << endl;

                cout << "Choice: ";
                cin >> type;

                if (type == 1)
                {
                    int score;

                    cout << "Enter Score: ";
                    cin >> score;

                    tas[index]
                        ->gradeAssignment(score);
                }
                else
                {
                    string grade;

                    cout << "Enter Grade: ";
                    cin >> grade;

                    tas[index]
                        ->gradeAssignment(grade);
                }
            }
        }

        else if (choice == 7)
        {
            if (taCount == 0 ||
                studentCount == 0)
            {
                cout << "Need Student and TA" << endl;
            }
            else
            {
                int t, s;
                double d;

                cout << "TA Index: ";
                cin >> t;

                cout << "Student Index: ";
                cin >> s;

                cout << "Duration: ";
                cin >> d;

                sessions[sessionCount] =
                    new TutoringSession(
                        sessionCount + 1,
                        d,
                        tas[t],
                        students[s]);

                sessionCount++;

                cout << "Session Created" << endl;
            }
        }

        else if (choice == 8)
        {
            if (sessionCount < 2)
            {
                cout << "Need 2 sessions" << endl;
            }
            else
            {
                int a, b;

                cout << "First index: ";
                cin >> a;

                cout << "Second index: ";
                cin >> b;

                TutoringSession s =
                    *sessions[a] +
                    *sessions[b];

                s.displaySession();
            }
        }

        else if (choice == 9)
        {
            if (sessionCount < 2)
            {
                cout << "Need 2 sessions" << endl;
            }
            else
            {
                int a, b;

                cout << "First index: ";
                cin >> a;

                cout << "Second index: ";
                cin >> b;

                if (*sessions[a] >
                    *sessions[b])
                {
                    cout << "First Longer" << endl;
                }
                else
                {
                    cout << "Second Longer" << endl;
                }
            }
        }

    } while (choice != 0);

    cout << endl << "Program Ended" << endl;

    return 0;
}