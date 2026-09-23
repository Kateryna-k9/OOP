// Lab 2A.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include "RealNumber.h"
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdexcept>

using namespace std;

int main()
{
    const int size = 4;

    

    FILE* file = nullptr;

    fopen_s(&file, "data.txt", "w");

    if (file != nullptr)
    {
        fprintf(file, "10.5\n");
        fprintf(file, "20.3\n");
        fprintf(file, "10.5\n");
        fprintf(file, "5.7\n");

        fclose(file);
    }


    

    RealNumber* numbers = new RealNumber[size];


    

    fopen_s(&file, "data.txt", "r");

    if (file != nullptr)
    {
        double value;
        int i = 0;

        while (i < size &&
            fscanf_s(file, "%lf", &value) == 1)
        {
            (numbers + i)->setValue(value);

            i++;
        }

        fclose(file);
    }


    int choice = 0;


    

    while (choice != 12)
    {

        cout << "1. Show array\n";
        cout << "2. Test comparison operators\n";
        cout << "3. Test arithmetic operators\n";
        cout << "4. Test prefix ++ and --\n";
        cout << "5. Test postfix ++ and --\n";
        cout << "6. Test assignment operator =\n";
        cout << "7. Test stream operators << and >>\n";
        cout << "8. Test operator []\n";
        cout << "9. Find minimum and maximum\n";
        cout << "10. Calculate average\n";
        cout << "11. Show object count\n";
        cout << "12. Exit\n";

        cout << "Choose: ";
        cin >> choice;

        cout << endl;


        

        if (choice == 1)
        {
            for (int i = 0; i < size; i++)
            {
                cout << "Number " << i + 1
                    << ": " << *(numbers + i)
                    << endl;
            }
        }


        

        else if (choice == 2)
        {
            cout << boolalpha;

            cout << "Number 1 == Number 3: "
                << (*(numbers)).operator==(*(numbers + 2))
                << endl;

            cout << "Number 1 != Number 2: "
                << (*(numbers) != *(numbers + 1))
                << endl;

            cout << "Number 1 < Number 2: "
                << (*(numbers)).operator<(*(numbers + 1))
                << endl;

            cout << "Number 2 > Number 1: "
                << (*(numbers + 1) > *(numbers))
                << endl;

            cout << "Number 4 <= Number 1: "
                << (*(numbers + 3)).operator<=(*(numbers))
                << endl;

            cout << "Number 2 >= Number 1: "
                << (*(numbers + 1) >= *(numbers))
                << endl;

            cout << noboolalpha;
        }


       

        else if (choice == 3)
        {
            try
            {
                RealNumber a = *(numbers);
                RealNumber b = *(numbers + 1);

                cout << "Number 1 + Number 2 = "
                    << a + b << endl;

                cout << "Number 1 - Number 2 = "
                    << a - b << endl;

                cout << "Number 1 * Number 2 = "
                    << a * b << endl;

                cout << "Number 1 / Number 2 = "
                    << a / b << endl;
            }
            catch (const exception& error)
            {
                cout << error.what() << endl;
            }
        }


        

        else if (choice == 4)
        {
            RealNumber test = *(numbers);

            cout << "Initial value: "
                << test << endl;

            cout << "Prefix ++: "
                << ++test << endl;

            cout << "Prefix --: "
                << --test << endl;
        }


        

        else if (choice == 5)
        {
            RealNumber test = *(numbers);

            cout << "Initial value: "
                << test << endl;

            cout << "Postfix ++ result: "
                << test++ << endl;

            cout << "Value after ++: "
                << test << endl;

            cout << "Postfix -- result: "
                << test-- << endl;

            cout << "Value after --: "
                << test << endl;
        }


        

        else if (choice == 6)
        {
            RealNumber first;
            RealNumber second(25.5);

            first = second;

            cout << "First number after assignment: "
                << first << endl;
        }


        

        else if (choice == 7)
        {
            RealNumber test;

            cout << "Enter a real number: ";

            cin >> test;

            cout << "You entered: "
                << test << endl;
        }


        

        else if (choice == 8)
        {
            cout << "Number 1: "
                << *(numbers)
                << endl;

            cout << "Access through operator [0]: "
                << (*(numbers))[0]
                << endl;
        }


        

        else if (choice == 9)
        {
            RealNumber minimum =
                RealNumber::getMin(numbers, size);

            RealNumber maximum =
                RealNumber::getMax(numbers, size);

            cout << "Minimum: "
                << minimum << endl;

            cout << "Maximum: "
                << maximum << endl;
        }


        

        else if (choice == 10)
        {
            double average =
                RealNumber::getAverage(numbers, size);

            cout << "Average: "
                << average << endl;
        }


        

        else if (choice == 11)
        {
            cout << "Number of existing objects: "
                << RealNumber::getCount()
                << endl;
        }


        

        else if (choice != 12)
        {
            cout << "Invalid menu item." << endl;
        }
    }


    

    delete[] numbers;

    return 0;
}