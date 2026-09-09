// Lab 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <iostream>

using namespace std;

int main()
{
    FILE* f;

    fopen_s(&f, "data.txt", "w");

    if (f == NULL)
    {
        cout << "Error creating file." << endl;
        return 1;
    }

    fprintf(f, "RT-11-24 R 100000 12\n");
    fprintf(f, "RT-11-24 R 50000 10\n");
    fprintf(f, "CGU-12K C 17.5 3\n");

    fclose(f);

    cout << "Test data file created." << endl;

    Component components[3];

    Component componentsWithParameters[3];

    fopen_s(&f, "data.txt", "r");

    if (f == NULL)
    {
        cout << "Error opening data file." << endl;
        return 1;
    }

    char designation[20];
    char type;
    double nominal;
    int quantity;

   

    for (int i = 0; i < 3; i++)
    {
        fscanf_s(f, "%19s %c %lf %d",
            designation, (unsigned)_countof(designation),
            &type, 1, &nominal, &quantity);

        componentsWithParameters[i].setDesignation(designation);
        componentsWithParameters[i].setType(type);
        componentsWithParameters[i].setNominal(nominal);
        componentsWithParameters[i].setQuantity(quantity);
    }

    fclose(f);

    Component componentsCopy[3] =
    {
        Component(componentsWithParameters[0]),
        Component(componentsWithParameters[1]),
        Component(componentsWithParameters[2])
    };

    int choice;
  

    while (true)
    {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Show components" << endl;
        cout << "2. Change component" << endl;
        cout << "3. Show data using get()" << endl;
        cout << "4. Show copied components" << endl;
        cout << "5. Show default components" << endl;
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
                componentsWithParameters[i].show();
            }
        }

        else if (choice == 2)
        {
            int number;
            int parameter;

            cout << "\nEnter component number (1-3): ";
            cin >> number;
            if (number < 1 || number > 3)
            {
                cout << "Invalid component number." << endl;
                continue;
            }

            cout << "\nWhat do you want to change?" << endl;
            cout << "1. Designation" << endl;
            cout << "2. Type" << endl;
            cout << "3. Nominal" << endl;
            cout << "4. Quantity" << endl;
            cout << "Enter parameter: ";
            cin >> parameter;
            
            if (parameter == 1)
            {
                char newDesignation[20];

                cout << "Enter new designation: ";
                cin >> newDesignation;

                componentsWithParameters[number - 1].setDesignation(newDesignation);
            }
           

            else if (parameter == 2)
            {
                char newType;

                cout << "Enter new type: ";
                cin >> newType;

                componentsWithParameters[number - 1].setType(newType);
            }
            else if (parameter == 3)
            {
                double newNominal;

                cout << "Enter new nominal: ";
                cin >> newNominal;

                componentsWithParameters[number - 1].setNominal(newNominal);
            }
            else if (parameter == 4)
            {
                int newQuantity;

                cout << "Enter new quantity: ";
                cin >> newQuantity;

                componentsWithParameters[number - 1].setQuantity(newQuantity);
            }

            else
            {
                cout << "Invalid parameter." << endl;
            }
        }
        else if (choice == 3)
        {
            int number;

            cout << "\nEnter component number (1-3): ";
            cin >> number;

            if (number < 1 || number > 3)
            {
                cout << "Invalid component number." << endl;
                continue;
            }

            cout << "\nData of component:" << endl;
            cout << "Designation: "
                << componentsWithParameters[number - 1].getDesignation() << endl;

            cout << "Type: "
                << componentsWithParameters[number - 1].getType() << endl;

            cout << "Nominal: "
                << componentsWithParameters[number - 1].getNominal() << endl;

            cout << "Quantity: "
                << componentsWithParameters[number - 1].getQuantity() << endl;

        }

        else if (choice == 4)
        {
            cout << "\nCopied components:" << endl;
            cout << "Designation     Type      Nominal        Quantity" << endl;
            cout << "-------------------------------------------------" << endl;

            for (int i = 0; i < 3; i++)
            {
                componentsCopy[i].show();
            }
        }

        else if (choice == 5)
        {
            cout << "\nDefault components:" << endl;
            cout << "Designation     Type      Nominal        Quantity" << endl;
            cout << "-------------------------------------------------" << endl;

            for (int i = 0; i < 3; i++)
            {
                components[i].show();
            }
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