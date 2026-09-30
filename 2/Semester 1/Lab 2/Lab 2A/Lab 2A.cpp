// Lab 2A.cpp

#include "RealNumber.h"
#include "RealNumberArray.h"
#include <iostream>

using namespace std;

int main()
{
    RealNumber number1(10.5);
    RealNumber number2(20.3);

    RealNumberArray numbers(5);

    numbers.operator[](0) = RealNumber(10.5);
    numbers.operator[](1) = RealNumber(20.3);
    numbers.operator[](2) = RealNumber(5.7);
    numbers.operator[](3) = RealNumber(15.2);
    numbers.operator[](4) = RealNumber(30.1);

    int choice;

    while (true)
    {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Show numbers" << endl;
        cout << "2. Compare using ==" << endl;
        cout << "3. Compare using !=" << endl;
        cout << "4. Compare using <" << endl;
        cout << "5. Compare using >" << endl;
        cout << "6. Compare using <=" << endl;
        cout << "7. Compare using >=" << endl;
        cout << "8. Addition +" << endl;
        cout << "9. Subtraction -" << endl;
        cout << "10. Multiplication *" << endl;
        cout << "11. Division /" << endl;
        cout << "12. Prefix ++" << endl;
        cout << "13. Postfix ++" << endl;
        cout << "14. Prefix --" << endl;
        cout << "15. Postfix --" << endl;
        cout << "16. Assignment =" << endl;
        cout << "17. Output using <<" << endl;
        cout << "18. Input using >>" << endl;
        cout << "19. Find minimum" << endl;
        cout << "20. Find maximum" << endl;
        cout << "21. Average" << endl;
        cout << "22. Access using []" << endl;
        cout << "23. Object count" << endl;
        cout << "0. Exit" << endl;
        cout << "==========================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\nNumbers:" << endl;

            for (int i = 0; i < numbers.getSize(); i++)
            {
                cout << i << ": "
                    << numbers.operator[](i)
                    << endl;
            }
        }

        else if (choice == 2)
        {
            if (number1 == number2)
            {
                cout << "Numbers are equal." << endl;
            }
            else
            {
                cout << "Numbers are not equal." << endl;
            }
        }

        else if (choice == 3)
        {
            if (number1 != number2)
            {
                cout << "Numbers are not equal." << endl;
            }
            else
            {
                cout << "Numbers are equal." << endl;
            }
        }

        else if (choice == 4)
        {
            cout << number1 << " < " << number2
                << " = " << (number1 < number2) << endl;
        }

        else if (choice == 5)
        {
            cout << number1 << " > " << number2
                << " = " << (number1 > number2) << endl;
        }

        else if (choice == 6)
        {
            cout << number1 << " <= " << number2
                << " = " << (number1 <= number2) << endl;
        }

        else if (choice == 7)
        {
            cout << number1 << " >= " << number2
                << " = " << (number1 >= number2) << endl;
        }

        else if (choice == 8)
        {
            RealNumber result = number1 + number2;

            cout << "Result: " << result << endl;
        }

        else if (choice == 9)
        {
            RealNumber result = number1 - number2;

            cout << "Result: " << result << endl;
        }

        else if (choice == 10)
        {
            RealNumber result = number1 * number2;

            cout << "Result: " << result << endl;
        }

        else if (choice == 11)
        {
            RealNumber result = number1 / number2;

            cout << "Result: " << result << endl;
        }

        else if (choice == 12)
        {
            ++number1;

            cout << "After prefix ++: "
                << number1 << endl;
        }

        else if (choice == 13)
        {
            RealNumber oldValue = number1++;

            cout << "Old value: "
                << oldValue << endl;

            cout << "New value: "
                << number1 << endl;
        }

        else if (choice == 14)
        {
            --number1;

            cout << "After prefix --: "
                << number1 << endl;
        }

        else if (choice == 15)
        {
            RealNumber oldValue = number1--;

            cout << "Old value: "
                << oldValue << endl;

            cout << "New value: "
                << number1 << endl;
        }

        else if (choice == 16)
        {
            number1 = number2;

            cout << "Assignment completed." << endl;
            cout << "Number 1: " << number1 << endl;
        }

        else if (choice == 17)
        {
            cout << "Number using <<: "
                << number1 << endl;
        }

        else if (choice == 18)
        {
            cout << "Enter a real number: ";
            cin >> number1;

            cout << "Entered number: "
                << number1 << endl;
        }

        else if (choice == 19)
        {
            cout << "Minimum: "
                << numbers.findMin() << endl;
        }

        else if (choice == 20)
        {
            cout << "Maximum: "
                << numbers.findMax() << endl;
        }

        else if (choice == 21)
        {
            cout << "Average: "
                << numbers.average() << endl;
        }

        else if (choice == 22)
        {
            int index;

            cout << "Enter index (0-4): ";
            cin >> index;

            if (index < 0 || index >= numbers.getSize())
            {
                cout << "Invalid index." << endl;
                continue;
            }

            cout << "Element: "
                << numbers.operator[](index)
                << endl;
        }

        else if (choice == 23)
        {
            cout << "Number of existing objects: "
                << RealNumber::getCount()
                << endl;
        }

        else if (choice == 0)
        {
            cout << "Program finished." << endl;
            break;
        }

        else
        {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}