// TermProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream>
#include "Manager.h"

using namespace std;

int main()
{
    Manager manager("Development", "Website",
        "Ivanenko", "Petrenko Petro",
        "Personnel Management", "Active");

    cout << "=== MANAGER INFORMATION ===" << endl;
    manager.showInfo();

    cout << "\n=== CHECK STATUS ===" << endl;

    if (manager.isActive())
        cout << "Manager is active!" << endl;
    else
        cout << "Manager is not active!" << endl;

    cout << "\n=== CHANGE STATUS ===" << endl;

    manager.setWorkStatus("Vacation");
    manager.showInfo();

    cout << "\n=== CHECK STATUS AGAIN ===" << endl;

    if (manager.isActive())
        cout << "Manager is active!" << endl;
    else
        cout << "Manager is not active!" << endl;

    cout << "\n=== GETTERS ===" << endl;
    cout << "Full name: " << manager.getFullName() << endl;
    cout << "Skills: " << manager.getSkills() << endl;
    cout << "Status: " << manager.getWorkStatus() << endl;

    return 0;
}
