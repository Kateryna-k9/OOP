// Lab 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include "Component.h"
#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

int main()
{
    // =====================================================
    // Створення тестового файлу
    // =====================================================

    FILE* file = nullptr;

    fopen_s(&file, "data.txt", "w");

    if (file != nullptr)
    {
        fprintf(file, "RT-11-24 R 100000 12\n");
        fprintf(file, "RT-11-24 R 50000 10\n");
        fprintf(file, "CGU-12K C 17.5 3\n");

        fclose(file);
    }


    // =====================================================
    // Динамічний масив компонентів
    // =====================================================

    const int size = 3;

    Component* components = new Component[size];


    // =====================================================
    // Зчитування з файлу
    // =====================================================

    fopen_s(&file, "data.txt", "r");

    if (file != nullptr)
    {
        char designation[20];
        char type;
        double nominal;
        int quantity;

        int i = 0;

        while (i < size &&
            fscanf_s(file, "%19s %c %lf %d",
                designation, 20,
                &type, 1,
                &nominal,
                &quantity) == 4)
        {
            (*(components + i))(designation, type, nominal, quantity);
            i++;
        }

        fclose(file);
    }


    // =====================================================
    // Другий динамічний масив
    // =====================================================

    Component* componentsCopy = new Component[size];

    int choice = 0;

    // =====================================================
    // МЕНЮ
    // =====================================================

    while (choice != 10)
    {
        cout << "1. Show components\n";
        cout << "2. Assignment operator =\n";
        cout << "3. Comparison operator == (member)\n";
        cout << "4. Addition operator + (member)\n";
        cout << "5. Comparison operator == (friend)\n";
        cout << "6. Addition operator + (friend)\n";
        cout << "7. Operator [] - string length\n";
        cout << "8. Operator () - initialization\n";
        cout << "9. Stream operators << and >>\n";
        cout << "10. Exit\n";
        cout << "Choose: ";

        cin >> choice;

        cout << endl;


        // =================================================
        // 1. Виведення
        // =================================================

        if (choice == 1)
        {
            cout << left
                << setw(15) << "Designation"
                << setw(8) << "Type"
                << setw(15) << "Nominal"
                << setw(10) << "Quantity"
                << endl;

            cout << "------------------------------------------------\n";

            for (int i = 0; i < size; i++)
            {
                cout << *(components + i) << endl;
            }
        }


        // =================================================
        // 2. ОПЕРАТОР =
        // =================================================

        else if (choice == 2)
        {
            *(componentsCopy) = *(components);

            cout << "Original component:\n";
            cout << *(components) << endl;

            cout << "Copied component:\n";
            cout << *(componentsCopy) << endl;
        }


        // =================================================
        // 3. == ФУНКЦІЯ-ЧЛЕН
        // =================================================

        else if (choice == 3)
        {
            if ((*(components)).operator==(*(components + 1)))
            {
                cout << "Components are equal.\n";
            }
            else
            {
                cout << "Components are not equal.\n";
            }
        }

        // =================================================
        // 4. + ФУНКЦІЯ-ЧЛЕН
        // =================================================

        else if (choice == 4)
        {
            Component result;

            result = (*(components)).operator+(*(components + 1));

            cout << "Result of member operator +:\n";
            cout << result << endl;
        }


        // =================================================
        // 5. == ДРУЖНЯ ФУНКЦІЯ
        // =================================================

        else if (choice == 5)
        {
            bool equal = operator==(*(components), *(components + 1));

            if (equal)
            {
                cout << "Components are equal.\n";
            }
            else
            {
                cout << "Components are not equal.\n";
            }
        }


        // =================================================
        // 6. + ДРУЖНЯ ФУНКЦІЯ
        // =================================================

        else if (choice == 6)
        {
            Component result;

            result = operator+(*(components), *(components + 1));

            cout << "Result of friend operator +:\n";
            cout << result << endl;
        }


        // =================================================
        // 7. []
        // =================================================

        else if (choice == 7)
        {
            int length = (*(components))[components->getDesignation()];

            cout << "Designation: "
                << components->getDesignation() << endl;

            cout << "Length: " << length << endl;
        }


        // =================================================
        // 8. ()
        // =================================================

        else if (choice == 8)
        {
            (*(components + 1))(
                "NEW-COMP",
                'T',
                2500,
                7
                );

            cout << "Component after operator () initialization:\n";
            cout << *(components + 1) << endl;
        }


        // =================================================
        // 9. << та >>
        // =================================================

        else if (choice == 9)
        {
            cout << "Stream output operator << demonstration:\n";
            cout << *(components) << endl;

            cout << "\nStream input operator >> demonstration.\n";
            cout << "Enter: designation type nominal quantity\n";

            Component test;

            cin >> test;

            cout << "\nEntered component:\n";
            cout << test << endl;
        }


        // =================================================
        // Неправильний пункт
        // =================================================

        else if (choice != 10)
        {
            cout << "Invalid menu item.\n";
        }
    }


    // =====================================================
    // Звільнення пам'яті
    // =====================================================

    delete[] components;
    delete[] componentsCopy;

    return 0;
}