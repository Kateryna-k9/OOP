// Lab 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include "Header.h"

using namespace std;

int main() {

    srand(time(0));

    const char* filename = "components.dat";

    int choice;

    do {

        cout << "\n========= MENU =========\n";

        cout << "1. Input from keyboard and write to file\n";
        cout << "2. Random input and write to file\n";
        cout << "3. Add record to beginning\n";
        cout << "4. Add record to end\n";
        cout << "5. Print one record\n";
        cout << "6. Print all records\n";
        cout << "7. Change record\n";
        cout << "8. Exit\n";

        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            writeFromKeyboard(filename);
            break;

        case 2:
            writeRandom(filename);
            break;

        case 3:
            addToBeginning(filename);
            break;

        case 4:
            addToEnd(filename);
            break;

        case 5:
            printOne(filename);
            break;

        case 6:
            printAll(filename);
            break;

        case 7:
            editRecord(filename);
            break;

        case 8:
            cout << "Exit...\n";
            break;

        default:
            cout << "Wrong choice!\n";
        }

    } while (choice != 8);

    return 0;
}