// Lab 5B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"

using namespace std;

int main() {
    int x, y, z;
    int choice;

    cout << "Enter three numbers: ";
    cin >> x >> y >> z;

    cout << "1 - pointers\n2 - references\nChoose: ";
    cin >> choice;

    switch (choice) {
    case 1:
        swapPtr(&x, &y, &z);
        break;
    case 2:
        swapRef(x, y, z);
        break;
    default:
        cout << "Wrong choice\n";
        return 0;
    }

    cout << "Result: " << x << " " << y << " " << z << endl;

    return 0;
}