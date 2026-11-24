// Lab 5.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include "Number.h"

using namespace std;

int main() {
    Number<int>* intNumbers = nullptr;
    Number<float>* floatNumbers = nullptr;

    try {
        intNumbers = new Number<int>[N];
        floatNumbers = new Number<float>[N];

        loadData(intNumbers, floatNumbers);

        cout << "Data loaded successfully!\n";

        int choice = -1;

        do {
            showMenu();

            try {
                if (!(cin >> choice)) {
                    choice = -1;
                    throw "Invalid menu input!";
                }

                switch (choice) {
                case 1:
                    cout << "\nInteger numbers:\n";
                    showNumbers(intNumbers, N);

                    cout << "\nReal numbers:\n";
                    showNumbers(floatNumbers, N);
                    break;

                case 2: {
                    Number<int> a;
                    Number<float> b;

                    cout << "\nDefault integer: ";
                    a.show();

                    cout << "Default real number: ";
                    b.show();
                    break;
                }

                case 3: {
                    int a;
                    float b;

                    cout << "Enter integer number: ";

                    if (!(cin >> a))
                        throw "Invalid integer number!";

                    cout << "Enter real number: ";

                    if (!(cin >> b))
                        throw "Invalid real number!";

                    Number<int> ob1(a);
                    Number<float> ob2(b);

                    cout << "\nInteger object: ";
                    ob1.show();

                    cout << "Real object: ";
                    ob2.show();
                    break;
                }

                case 4: {
                    Number<int> a;
                    Number<float> b;

                    cout << "\nBefore assignment:\n";

                    cout << "Integer object: ";
                    a.show();

                    cout << "Real object: ";
                    b.show();

                    a = *intNumbers;
                    b = *floatNumbers;

                    cout << "\nAfter assignment:\n";

                    cout << "Integer object: ";
                    a.show();

                    cout << "Real object: ";
                    b.show();
                    break;
                }

                case 5: {
                    cout << "\nInteger numbers:\n";
                    showNumbers(intNumbers, N);

                    cout << "Enter first number index: ";
                    int i = inputIndex();

                    cout << "Enter second number index: ";
                    int j = inputIndex();

                    Number<int> result;

                    result = *(intNumbers + i) +
                        *(intNumbers + j);

                    cout << "Result: ";
                    result.show();
                    break;
                }

                case 6: {
                    cout << "\nReal numbers:\n";
                    showNumbers(floatNumbers, N);

                    cout << "Enter first number index: ";
                    int i = inputIndex();

                    cout << "Enter second number index: ";
                    int j = inputIndex();

                    Number<float> result;

                    result = *(floatNumbers + i) +
                        *(floatNumbers + j);

                    cout << "Result: ";
                    result.show();
                    break;
                }

                case 0:
                    cout << "Program finished!\n";
                    break;

                default:
                    throw "Invalid menu choice!";
                }
            }

            catch (const char* message) {
                cout << "Error: " << message << endl;

                if (cin.eof())
                    break;

                cin.clear();
                cin.ignore(10000, '\n');
            }

            catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }

        } while (choice != 0);
    }

    catch (const char* message) {
        cout << "Error: " << message << endl;
    }

    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    delete[] intNumbers;
    delete[] floatNumbers;

    return 0;
}