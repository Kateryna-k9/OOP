// TermProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//




#include <iostream>
#include "Expert.h"

using namespace std;

int main()
{
    Expert expert("Development", "Website",
        "Ivanenko", "Petrenko Petro",
        "Programming", "Consulting");

    cout << "=== EXPERT INFORMATION ===" << endl;
    expert.showInfo();

    cout << "\n=== SEARCH BY SPECIALIZATION ===" << endl;

    if (expert.hasSpecialization("Programming"))
        cout << "Expert found!" << endl;
    else
        cout << "Expert not found!" << endl;

    cout << "\n=== CHANGE SPECIALIZATION ===" << endl;

    expert.setSpecialization("Databases");
    expert.setFunctions("Data Analysis");

    expert.showInfo();

    cout << "\n=== SEARCH AGAIN ===" << endl;

    if (expert.hasSpecialization("Programming"))
        cout << "Expert found!" << endl;
    else
        cout << "Expert not found!" << endl;

    cout << "\n=== GETTERS ===" << endl;
    cout << "Full name: " << expert.getFullName() << endl;
    cout << "Specialization: " << expert.getSpecialization() << endl;
    cout << "Functions: " << expert.getFunctions() << endl;

    return 0;
}
