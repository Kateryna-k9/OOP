
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
        cout << "2. Show array" << endl;
        cout << "3. Save array to results.txt" << endl;
        cout << "4. Read results.txt" << endl;
        cout << "5. Calculate sum" << endl;
        cout << "6. Append sum to results.txt" << endl;
        cout << "7. Get element by index (try-catch)" << endl;
        cout << "0. Exit" << endl;
        cout << "============================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (!cin)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice!" << endl;
            continue;
        }

        if (choice == 1)
        {
            int n;

            cout << "Enter array size: ";
            cin >> n;

            if (!cin)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid array size!" << endl;
                continue;
            }

            try
            {
                arr.createArray(n);

                for (int i = 0; i < n; i++)
                {
                    int value;

                    cout << "Enter element " << i + 1 << ": ";
                    cin >> value;

                    if (!cin)
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        throw "Invalid element value!";
                    }

                    arr.setElement(i, value);
                }

                cout << "Dynamic array created!" << endl;
            }
            catch (const char* error)
            {
                cout << "Error: " << error << endl;
            }
        }
        else if (choice == 2)
        {
            if (arr.getSize() == 0)
            {
                cout << "Array is empty!" << endl;
            }
            else
            {
                cout << "Array elements: ";

                for (int i = 0; i < arr.getSize(); i++)
                    cout << arr.getElement(i) << " ";

                cout << endl;
            }
        }
        else if (choice == 3)
        {
            if (arr.getSize() == 0)
            {
                cout << "Array is empty!" << endl;
            }
            else if (arr.saveToFile("results.txt"))
            {
                cout << "Array saved to results.txt!" << endl;
            }
            else
            {
                cout << "Error saving file!" << endl;
            }
        }
        else if (choice == 4)
        {
            ifstream in("results.txt");

            if (!in)
            {
                cout << "Cannot open results.txt!" << endl;
            }
            else
            {
                cout << "File contents:" << endl;

                char line[200];

                while (in.getline(line, 200))
                    cout << line << endl;

                in.close();
            }
        }
        else if (choice == 5)
        {
            if (arr.getSize() == 0)
            {
                cout << "Array is empty!" << endl;
            }
            else
            {
                cout << "Sum of elements: "
                    << arr.getSum() << endl;
            }
        }
        else if (choice == 6)
        {
            if (arr.getSize() == 0)
            {
                cout << "Array is empty!" << endl;
            }
            else if (arr.appendSumToFile("results.txt"))
            {
                cout << "Sum appended to results.txt!" << endl;
            }
            else
            {
                cout << "Error! Save array to file first!" << endl;
            }
        }
        else if (choice == 7)
        {
            if (arr.getSize() == 0)
            {
                cout << "Array is empty!" << endl;
            }
            else
            {
                int index;

                cout << "Enter element number: ";
                cin >> index;

                if (!cin)
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid element number!" << endl;
                    continue;
                }

                try
                {
                    int value = arr.getElement(index - 1);
                    cout << "Element: " << value << endl;
                }
                catch (const char* error)
                {
                    cout << "Error: " << error << endl;
                }
            }
        }
        else if (choice == 0)
        {
            cout << "Program finished!" << endl;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}

