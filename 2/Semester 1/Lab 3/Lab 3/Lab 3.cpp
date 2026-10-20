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

    cout << "=== BASE CLASSES ===" << endl;

    obj1.show();
    obj2.show();
    obj3.show();

    cout << "\n=== CLASS D1: SHOW ===" << endl;

    obj4.show();

    cout << "\n=== CLASS D1: OPERATOR << ===" << endl;

    cout << obj4 << endl;

    cout << "\n=== GET METHODS ===" << endl;

    cout << "B1: " << obj4.getValueB1() << endl;
    cout << "B2: " << obj4.getValueB2() << endl;
    cout << "D1: " << obj4.getValueD1() << endl;

    return 0;
}

