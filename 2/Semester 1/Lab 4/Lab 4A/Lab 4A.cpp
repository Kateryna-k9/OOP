
#include "DynamicArray.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <exception>

using namespace std;

int main()
{
    DynamicArray arr;
    int choice = -1;

    do
    {
        cout << "\n========== LAB 4A ==========" << endl;
        cout << "1. Create and fill dynamic array" << endl;
        cout << "2. Show array" << endl;
        cout << "3. Save array to results.txt" << endl;
        cout << "4. Read results.txt" << endl;
        cout << "5. Calculate sum" << endl;
        cout << "6. Append sum to results.txt" << endl;
        cout << "7. Get element by index (try-catch)" << endl;
        cout << "0. Exit" << endl;
        cout << "============================" << endl;
        cout << "Enter your choice: ";

        try
        {
            if (!(cin >> choice))
                throw "Invalid menu choice!";

            if (choice == 1)
            {
                int n;

                cout << "Enter array size: ";

                if (!(cin >> n))
                    throw "Invalid array size!";

                arr.createArray(n);

                for (int i = 0; i < n; i++)
                {
                    int value;

                    cout << "Enter element " << i + 1 << ": ";

                    if (!(cin >> value))
                        throw "Invalid element value!";

                    arr.setElement(i, value);
                }

                cout << "Dynamic array created!" << endl;
            }

            else if (choice == 2)
            {
                if (arr.getSize() == 0)
                    throw "Array is empty!";

                cout << "Array elements: ";

                for (int i = 0; i < arr.getSize(); i++)
                    cout << arr.getElement(i) << " ";

                cout << endl;
            }

            else if (choice == 3)
            {
                arr.saveToFile("results.txt");

                cout << "Array saved to results.txt!" << endl;
            }

            else if (choice == 4)
            {
                ifstream in("results.txt");

                if (!in)
                    throw "Cannot open results.txt!";

                cout << "File contents:" << endl;

                char ch;

                while (in.get(ch))
                    cout << ch;

                if (in.bad())
                    throw "Error reading results.txt!";

                in.close();
            }

            else if (choice == 5)
            {
                cout << "Sum of elements: "
                    << arr.getSum() << endl;
            }

            else if (choice == 6)
            {
                arr.appendSumToFile("results.txt");

                cout << "Sum appended to results.txt!" << endl;
            }

            else if (choice == 7)
            {
                if (arr.getSize() == 0)
                    throw "Array is empty!";

                int index;

                cout << "Enter element number: ";

                if (!(cin >> index))
                    throw "Invalid element number!";

                if (index < 1 || index > arr.getSize())
                    throw "Invalid array index!";

                int value = arr.getElement(index - 1);

                cout << "Element: " << value << endl;
            }

            else if (choice == 0)
            {
                cout << "Program finished!" << endl;
            }

            else
            {
                throw "Invalid menu choice!";
            }
        }
        catch (const char* error)
        {
            cout << "Error: " << error << endl;

            if (cin.eof())
                break;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(
                    numeric_limits<streamsize>::max(), '\n');
            }
        }
        catch (const exception& error)
        {
            cout << "Error: " << error.what() << endl;
        }

    } while (choice != 0);

    return 0;
}
