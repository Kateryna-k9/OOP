
#include <iostream>
#include "Expert.h"

using namespace std;

int main()
{
    Expert expert1("Development", "Website",
        "Ivanenko", "Petrenko Petro",
        "Programming", "Consulting");

    Expert expert2("Testing", "Mobile App",
        "Shevchenko", "Kovalenko Anna",
        "Programming", "Data Analysis");

    Expert expert3;

    cout << "=== ORIGINAL EXPERTS ===" << endl;

    cout << "\nExpert 1:" << endl;
    expert1.showInfo();

    cout << "\nExpert 2:" << endl;
    expert2.showInfo();

    cout << "\n=== ASSIGNMENT OPERATOR ===" << endl;

    expert3 = expert1;

    cout << "Expert 3 after assignment:" << endl;
    expert3.showInfo();

    cout << "\n=== OPERATOR == ===" << endl;

    if (expert1 == expert2)
        cout << "Experts have the same specialization!" << endl;
    else
        cout << "Experts have different specializations!" << endl;

    cout << "\n=== OPERATOR () ===" << endl;

    if (expert1("Programming"))
        cout << "Expert with Programming found!" << endl;
    else
        cout << "Expert not found!" << endl;

    if (expert2("Databases"))
        cout << "Expert with Databases found!" << endl;
    else
        cout << "Expert not found!" << endl;

    cout << "\n=== CHANGE SPECIALIZATION ===" << endl;

    expert2.setSpecialization("Databases");

    cout << "Expert 1: "
        << expert1.getSpecialization() << endl;

    cout << "Expert 2: "
        << expert2.getSpecialization() << endl;

    cout << "\n=== COMPARE AGAIN ===" << endl;

    if (expert1 == expert2)
        cout << "Experts have the same specialization!" << endl;
    else
        cout << "Experts have different specializations!" << endl;

    cout << "\n=== SEARCH AGAIN ===" << endl;

    if (expert2("Databases"))
        cout << "Expert with Databases found!" << endl;
    else
        cout << "Expert not found!" << endl;

    return 0;
}
