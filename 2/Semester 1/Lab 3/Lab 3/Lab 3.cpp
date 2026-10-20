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

    cout << "=== BASE CLASSES ===" << endl;
    obj1.show();
    obj2.show();
    obj3.show();

    cout << "\n=== CLASS D1 ===" << endl;
    obj4.show();

    cout << "\n=== CLASS D2 ===" << endl;
    obj5.show();

    cout << "\n=== OPERATOR << FOR D2 ===" << endl;
    cout << obj5 << endl;

    cout << "\n=== GET METHODS ===" << endl;
    cout << "B1: " << obj5.getValueB1() << endl;
    cout << "B2: " << obj5.getValueB2() << endl;
    cout << "B3: " << obj5.getB3Value() << endl;
    cout << "D1: " << obj5.getValueD1() << endl;
    cout << "D2: " << obj5.getValueD2() << endl;

   


    cout << "\n=== POLYMORPHISM ===" << endl;

    B1* ptrB1 = &obj5;
    B2* ptrB2 = &obj5;
    D1* ptrD1 = &obj5;

    cout << "\nPointer B1 -> D2:" << endl;
    ptrB1->show();

    cout << "\nPointer B2 -> D2:" << endl;
    ptrB2->show();

    cout << "\nPointer D1 -> D2:" << endl;
    ptrD1->show();


    cout << "\n=== VIRTUAL FUNCTIONS ===" << endl;

    B1* ptr1 = &obj4;
    B1* ptr2 = &obj5;

    cout << "\nB1 pointer -> D1 object:" << endl;
    ptr1->show();

    cout << "\nB1 pointer -> D2 object:" << endl;
    ptr2->show();

    return 0;
}
