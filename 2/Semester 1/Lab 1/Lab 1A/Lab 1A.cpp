// Lab 1A.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Figure.h"
#include <iostream>

using namespace std;

int main()
{
    Figure kr(10);
    Figure tr(10, 20);

    int choice;

    while (true)
    {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Show circle" << endl;
        cout << "2. Show triangle" << endl;
        cout << "3. Change circle radius" << endl;
        cout << "4. Change triangle dimensions" << endl;
        cout << "5. Show circle area using get()" << endl;
        cout << "6. Show triangle area using get()" << endl;
        cout << "0. Exit" << endl;
        cout << "==========================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            kr.show();
        }
        else if (choice == 2)
        {
            tr.show();
        }
        else if (choice == 3)
        {
            double newRadius;

            cout << "Enter new radius: ";
            cin >> newRadius;

            kr.setRadius(newRadius);
        }
        else if (choice == 4)
        {
            double newHeight;
            double newBase;

            cout << "Enter new height: ";
            cin >> newHeight;

            cout << "Enter new base: ";
            cin >> newBase;

            tr.setHeight(newHeight);
            tr.setBase(newBase);
        }
        else if (choice == 5)
        {
            cout << "Circle area: "
                << kr.getCircleArea() << endl;
        }
        else if (choice == 6)
        {
            cout << "Triangle area: "
                << tr.getTriangleArea() << endl;
        }
        else if (choice == 0)
        {
            cout << "Program finished." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}