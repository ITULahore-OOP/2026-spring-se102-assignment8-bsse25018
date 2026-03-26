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
    cout << "=============================="<<endl;
    cout << "   SMART UNIVERSITY SYSTEM\n"<<endl;
    cout << "==============================\n"<<endl;

    // ---------- BUILD DEPARTMENT ----------

    string deptName;

    cout << "Build a Department First\n";
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
        cout << "\n=================================\n";
        cout << "            MENU\n";
        cout << "=================================\n";

        cout << "1. Create Student\n";
        cout << "2. Create Staff\n";
        cout << "3. Create Teaching Assistant\n";
        cout << "4. Add Member to Department\n";
        cout << "5. Display All Roles\n";
        cout << "6. Grade Assignment\n";
        cout << "7. Create Tutoring Session\n";
        cout << "8. Merge Two Sessions (+)\n";
        cout << "9. Compare Two Sessions (>)\n";
        cout << "0. Exit\n";

        cout << "---------------------------------\n";
        cout << "Enter Choice: ";
        cin >> choice;

        // ===============================
        // CREATE STUDENT
        // ===============================

        if (choice == 1)
        {
            string name;
            int id;
            double cgpa;

            cout << "\nEnter Name: ";
            cin >> name;

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter CGPA: ";
            cin >> cgpa;

            students[studentCount] =
                new Student(name, id, cgpa);

            studentCount++;

            cout << "Student Created\n";
        }

        // ===============================
        // CREATE STAFF
        // ===============================

        else if (choice == 2)
        {
            string name, cardID;
            int id, level;
            double salary;

            cout << "\nEnter Name: ";
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

            cout << "Staff Created\n";
        }

        // ===============================
        // CREATE TA
        // ===============================

        else if (choice == 3)
        {
            string name, cardID;
            int id, level, hours;
            double cgpa, salary;

            cout << "\nEnter Name: ";
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

            cout << "Teaching Assistant Created\n";
        }

        // ===============================
        // ADD TO DEPARTMENT
        // ===============================

        else if (choice == 4)
        {
            int type;

            cout << "\n1 Student\n";
            cout << "2 Staff\n";
            cout << "3 TA\n";

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
                cout << "Create Member First\n";
            }
        }

        // ===============================
        // DISPLAY ROLES
        // ===============================

        else if (choice == 5)
        {
            cout << "\nDepartment Members:\n";
            dept.displayAllRoles();
        }

        // ===============================
        // GRADE ASSIGNMENT
        // ===============================

        else if (choice == 6)
        {
            if (taCount == 0)
            {
                cout << "No TA Available\n";
            }
            else
            {
                int index;
                int type;

                cout << "Enter TA Index (0-"
                     << taCount - 1
                     << "): ";
                cin >> index;

                cout << "1 Numeric\n";
                cout << "2 Letter\n";

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

        // ===============================
        // CREATE SESSION
        // ===============================

        else if (choice == 7)
        {
            if (taCount == 0 ||
                studentCount == 0)
            {
                cout << "Need Student and TA\n";
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

                cout << "Session Created\n";
            }
        }

        // ===============================
        // MERGE SESSIONS
        // ===============================

        else if (choice == 8)
        {
            if (sessionCount < 2)
            {
                cout << "Need 2 sessions\n";
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

        // ===============================
        // COMPARE SESSIONS
        // ===============================

        else if (choice == 9)
        {
            if (sessionCount < 2)
            {
                cout << "Need 2 sessions\n";
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
                    cout << "First Longer\n";
                }
                else
                {
                    cout << "Second Longer\n";
                }
            }
        }

    } while (choice != 0);

    cout << "\nProgram Ended\n";

    return 0;
}