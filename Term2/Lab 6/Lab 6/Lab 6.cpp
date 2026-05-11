// Lab 6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
    const int SIZE = 10;

    while (true)
    {
        char* str = new char[SIZE];

        cout << "\nEnter string (max "
            << SIZE - 1
            << " symbols): ";

        cin.getline(str, SIZE);

        
        if (cin.fail())
        {
            cin.clear();

            while (cin.get() != '\n');

            cout << "Error! String is too long.\n";

            delete[] str;

            continue;
        }

        
        if (*str == '\0')
        {
            cout << "Error! Empty string.\n";

            delete[] str;

            continue;
        }

        int number;

        cout << "Enter word number: ";
        cin >> number;

        
        if (cin.fail())
        {
            cin.clear();

            while (cin.get() != '\n');

            cout << "Error! Incorrect input.\n";

            delete[] str;

            continue;
        }

        while (cin.get() != '\n');

        
        if (number <= 0)
        {
            cout << "Error! Word number must be > 0.\n";

            delete[] str;

            continue;
        }

        int result = findWordPosition(str, number);

        if (result == -1)
        {
            cout << "Word not found.\n";
        }
        else
        {
            cout << "Position of word #"
                << number
                << " = "
                << result
                << endl;
        }

        delete[] str;
    }

    return 0;
}
