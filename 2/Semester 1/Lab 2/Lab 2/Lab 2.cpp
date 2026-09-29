// Lab 2.cpp 

#define _CRT_SECURE_NO_WARNINGS

#include "Component.h"
#include <iostream>

using namespace std;

int main()
{
    Component* components = new Component[3];

    Component* componentsWithParameters = new Component[3];

    componentsWithParameters[0] =
        Component("RT-11-24", 'R', 100000, 12);

    componentsWithParameters[1] =
        Component("RT-11-24", 'R', 50000, 10);

    componentsWithParameters[2] =
        Component("CGU-12K", 'C', 17.5, 3);

    Component* componentsCopy = new Component[3];

    *(componentsCopy) =
        Component(*(componentsWithParameters));

    *(componentsCopy + 1) =
        Component(*(componentsWithParameters + 1));

    *(componentsCopy + 2) =
        Component(*(componentsWithParameters + 2));

    int choice;

    while (true)
    {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Show components" << endl;
        cout << "2. Compare using member ==" << endl;
        cout << "3. Assign using =" << endl;
        cout << "4. Add using member +" << endl;
        cout << "5. Compare using friend ==" << endl;
        cout << "6. Add using friend +" << endl;
        cout << "7. Calculate char* length using []" << endl;
        cout << "8. Initialize using ()" << endl;
        cout << "9. Show using <<" << endl;
        cout << "10. Enter using >>" << endl;
        cout << "0. Exit" << endl;
        cout << "==========================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\nDesignation     Type      Nominal        Quantity" << endl;
            cout << "-------------------------------------------------" << endl;

            for (int i = 0; i < 3; i++)
            {
                (*(componentsWithParameters + i)).show();
            }
        }

        else if (choice == 2)
        {
            if (*(componentsWithParameters) ==
                *(componentsWithParameters + 1))
            {
                cout << "Components are equal." << endl;
            }
            else
            {
                cout << "Components are not equal." << endl;
            }
        }

        else if (choice == 3)
        {
            *(componentsCopy) =
                *(componentsWithParameters);

            cout << "Assignment completed." << endl;

            cout << "\nCopied component:" << endl;
            cout << *(componentsCopy) << endl;
        }

        else if (choice == 4)
        {
            Component result;

            result =
                *(componentsWithParameters)+
                *(componentsWithParameters + 1);

            cout << "\nResult of member +:" << endl;
            cout << result << endl;
        }

        else if (choice == 5)
        {
            if (operator==(
                *(componentsWithParameters),
                *(componentsWithParameters + 1)))
            {
                cout << "Components are equal." << endl;
            }
            else
            {
                cout << "Components are not equal." << endl;
            }
        }

        else if (choice == 6)
        {
            Component result;

            result =
                operator+(
                    *(componentsWithParameters),
                    *(componentsWithParameters + 1));

            cout << "\nResult of friend +:" << endl;
            cout << result << endl;
        }

        else if (choice == 7)
        {
            char text[20];

            cout << "Enter text: ";
            cin >> text;

            int length =
                (*(componentsWithParameters))[text];

            cout << "Length: " << length << endl;
        }

        else if (choice == 8)
        {
            cout << "Initializing first component using ()..." << endl;

            (*(componentsWithParameters))(
                "NEW-COMP",
                'X',
                2500,
                15);

            cout << "\nUpdated component:" << endl;
            cout << *(componentsWithParameters) << endl;
        }

        else if (choice == 9)
        {
            cout << "\nComponent using <<:" << endl;
            cout << *(componentsWithParameters) << endl;
        }

        else if (choice == 10)
        {
            cout << "\nEnter data for first component:" << endl;

            cin >> *(componentsWithParameters);

            cout << "\nEntered component:" << endl;
            cout << *(componentsWithParameters) << endl;
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

    delete[] components;
    delete[] componentsWithParameters;
    delete[] componentsCopy;

    return 0;
}