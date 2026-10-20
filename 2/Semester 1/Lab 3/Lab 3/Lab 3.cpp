// Lab 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "Header.h"

int main()
{
    B1 obj1(10);
    B2 obj2(20);
    B3 obj3(30);

    D1 obj4(100, 200, 300, 400);
    D2 obj5(1000, 2000, 3000, 4000, 5000);

    int choice;

    do
    {
        cout << "\n========== LAB 3 MENU ==========" << endl;
        cout << "1. Show base classes (B1, B2, B3)" << endl;
        cout << "2. Show derived class D1" << endl;
        cout << "3. Show derived class D2" << endl;
        cout << "4. Test operator <<" << endl;
        cout << "5. Test polymorphism" << endl;
        cout << "6. Show values using get()" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n=== BASE CLASSES ===" << endl;
            obj1.show();
            obj2.show();
            obj3.show();
            break;

        case 2:
            cout << "\n=== CLASS D1 ===" << endl;
            obj4.show();
            break;

        case 3:
            cout << "\n=== CLASS D2 ===" << endl;
            obj5.show();
            break;

        case 4:
            cout << "\n=== OPERATOR << ===" << endl;

            cout << obj1 << endl;
            cout << obj2 << endl;
            cout << obj3 << endl;

            cout << "\nD1:" << endl;
            cout << obj4 << endl;

            cout << "\nD2:" << endl;
            cout << obj5 << endl;
            break;

        case 5:
        {
            cout << "\n=== POLYMORPHISM ===" << endl;

            B1* ptrB1 = &obj5;
            B2* ptrB2 = &obj5;
            D1* ptrD1 = &obj5;

            cout << "\nB1 pointer -> D2:" << endl;
            ptrB1->show();

            cout << "\nB2 pointer -> D2:" << endl;
            ptrB2->show();

            cout << "\nD1 pointer -> D2:" << endl;
            ptrD1->show();

            cout << "\nB1 pointer -> D1:" << endl;
            B1* ptrB1D1 = &obj4;
            ptrB1D1->show();

            break;
        }

        case 6:
            cout << "\n=== GET METHODS ===" << endl;

            cout << "\nBase classes:" << endl;
            cout << "B1: " << obj1.getValueB1() << endl;
            cout << "B2: " << obj2.getValueB2() << endl;
            cout << "B3: " << obj3.getValueB3() << endl;

            cout << "\nD1:" << endl;
            cout << "B1: " << obj4.getValueB1() << endl;
            cout << "B2: " << obj4.getValueB2() << endl;
            cout << "B3: " << obj4.getB3Value() << endl;
            cout << "D1: " << obj4.getValueD1() << endl;

            cout << "\nD2:" << endl;
            cout << "B1: " << obj5.getValueB1() << endl;
            cout << "B2: " << obj5.getValueB2() << endl;
            cout << "B3: " << obj5.getB3Value() << endl;
            cout << "D1: " << obj5.getValueD1() << endl;
            cout << "D2: " << obj5.getValueD2() << endl;
            break;

        case 0:
            cout << "\nExiting program..." << endl;
            break;

        default:
            cout << "\nInvalid option! Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
