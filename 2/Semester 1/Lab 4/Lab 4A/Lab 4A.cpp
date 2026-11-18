// Lab 4A.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    DynamicArray arr;
    int choice;

    do
    {
        cout << "\n========== LAB 4A ==========" << endl;
        cout << "1. Create and fill dynamic array" << endl;
        cout << "2. Load array from input.txt" << endl;
        cout << "3. Show array" << endl;
        cout << "4. Save array to results.txt" << endl;
        cout << "5. Read results.txt" << endl;
        cout << "6. Calculate sum" << endl;
        cout << "7. Append sum to results.txt" << endl;
        cout << "8. Read updated results.txt" << endl;
        cout << "9. Get element by index (try-catch)" << endl;
        cout << "0. Exit" << endl;
        cout << "============================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (!cin)
        {
            cout << "Invalid input!" << endl;
            break;
        }


        if (choice == 1)
        {
            int n;

            cout << "Enter number of elements: ";
            cin >> n;

            if (!cin)
            {
                cout << "Invalid input!" << endl;
                break;
            }

            try
            {
                arr.createArray(n);

                cout << "Enter array elements:" << endl;

                for (int i = 0; i < n; i++)
                {
                    int value;

                    cout << "Element " << i + 1 << ": ";
                    cin >> value;

                    if (!cin)
                    {
                        cout << "Invalid element!" << endl;
                        break;
                    }

                    arr.setElement(i, value);
                }

                if (!cin)
                    break;

                cout << "Array created successfully!" << endl;
            }
            catch (const char* error)
            {
                cout << "Error: " << error << endl;
            }
        }


        else if (choice == 2)
        {
            if (arr.loadFromFile("input.txt"))
                cout << "Array loaded from input.txt!" << endl;
            else
                cout << "Error loading input.txt!" << endl;
        }

        else if (choice == 3)
        {
            if (arr.getSize() == 0)
            {
                cout << "Array is empty!" << endl;
                continue;
            }

            cout << "\nArray elements: ";

            for (int i = 0; i < arr.getSize(); i++)
                cout << arr.getElement(i) << " ";

            cout << endl;
        }

        else if (choice == 4)
        {
            if (arr.getSize() == 0)
            {
                cout << "Array is empty!" << endl;
                continue;
            }

            if (arr.saveToFile("results.txt"))
                cout << "Array saved to results.txt!" << endl;
            else
                cout << "Error saving file!" << endl;
        }

        else if (choice == 5 || choice == 8)
        {
            ifstream in("results.txt");

            if (!in)
            {
                cout << "Cannot open results.txt!" << endl;
                continue;
            }

            if (choice == 5)
                cout << "\nFile contents:" << endl;
            else
                cout << "\nUpdated file contents:" << endl;

            char line[200];

            while (in.getline(line, 200))
                cout << line << endl;

            in.close();
        }

        else if (choice == 6)
        {
            if (arr.getSize() == 0)
            {
                cout << "Array is empty!" << endl;
                continue;
            }

            cout << "Sum of elements: " << arr.getSum() << endl;
        }

        else if (choice == 7)
        {
            if (arr.getSize() == 0)
            {
                cout << "Array is empty!" << endl;
                continue;
            }

            if (arr.appendSumToFile("results.txt"))
                cout << "Sum appended to results.txt!" << endl;
            else
                cout << "Error appending sum!" << endl;
        }


        else if (choice == 9)
        {
            int index;

            cout << "Enter element number: ";
            cin >> index;

            if (!cin)
            {
                cout << "Invalid input!" << endl;
                break;
            }

            try
            {
                cout << "Element: " << arr.getElement(index - 1) << endl;
            }
            catch (const char* error)
            {
                cout << "Error: " << error << endl;
            }
            }


        else if (choice == 0)
        {
            cout << "Program finished." << endl;
        }

        else
        {
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
