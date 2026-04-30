// Lab 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
    int seconds;
    int hours = 0, minutes = 0;
    int choice;

    cout << "Enter seconds: ";
    cin >> seconds;

    cout << "\nChoose method:\n";
    cout << "1 - pointers\n";
    cout << "2 - references\n";
    cout << "Your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        convertPointer(&seconds, &hours, &minutes);
        break;

    case 2:
        convertReference(seconds, hours, minutes);
        break;

    default:
        cout << "Wrong choice!" << endl;
        return 0;
    }

    cout << "\nResult:\n";
    cout << "Hours: " << hours << endl;
    cout << "Minutes: " << minutes << endl;

    return 0;
}