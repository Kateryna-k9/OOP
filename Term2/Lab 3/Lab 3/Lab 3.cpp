// Lab 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
   
#include <iostream>    
#include "Header.h"

using namespace std;

#define PRINT_TYPE 1  

int main() {
    Component arr[MAX];
    int n = 0;
    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1 - Fill structure\n";
        cout << "2 - Sort by name\n";
        cout << "3 - Print\n";
        cout << "4 - Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
#ifdef PRINT_TYPE == 1
            n = input(arr);
#else
            n = randomFill(arr);
#endif
            break;

        case 2:
            sortByName(arr, n);
            break;

        case 3:
            print(arr, n);
            break;

        case 4:
            cout << "Exit...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}