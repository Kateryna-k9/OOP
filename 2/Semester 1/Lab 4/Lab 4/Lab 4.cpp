// Lab 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#define _CRT_SECURE_NO_WARNINGS
#include "Component.h"
#include <iostream>
#include <fstream>

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

    Component* components = new Component[3];
    Component* componentsWithParameters = new Component[3];

    fopen_s(&f, "data.txt", "r");

    if (f == NULL)
    {
        cout << "Error opening data file." << endl;
        delete[] components;
        delete[] componentsWithParameters;
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

        (*(componentsWithParameters + i)) =
            Component(designation, type, nominal, quantity);
    }

    fclose(f);

    Component* componentsCopy = new Component[3];

    *(componentsCopy) = Component(*(componentsWithParameters));
    *(componentsCopy + 1) = Component(*(componentsWithParameters + 1));
    *(componentsCopy + 2) = Component(*(componentsWithParameters + 2));

    int choice;

    while (true)
    {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Show components" << endl;
        cout << "2. Change component" << endl;
        cout << "3. Show data using get()" << endl;
        cout << "4. Show copied components" << endl;
        cout << "5. Show default components" << endl;
        cout << "6. Save one component to binary file" << endl;
        cout << "7. Read one component from binary file" << endl;
        cout << "8. Save all components to binary file" << endl;
        cout << "9. Read all components from binary file" << endl;
        cout << "0. Exit" << endl;
        cout << "==========================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (!cin)
        {
            cout << "Invalid input!" << endl;
            break;
        }

        if (choice == 1)
        {
            cout << "\nDesignation     Type      Nominal        Quantity" << endl;
            cout << "-------------------------------------------------" << endl;

            for (int i = 0; i < 3; i++)
                (*(componentsWithParameters + i)).show();
        }

        else if (choice == 2)
        {
            int number;
            int parameter;

            cout << "\nEnter component number (1-3): ";
            cin >> number;

            if (!cin || number < 1 || number > 3)
            {
                cout << "Invalid component number." << endl;
                if (!cin) break;
                continue;
            }

            cout << "\nWhat do you want to change?" << endl;
            cout << "1. Designation" << endl;
            cout << "2. Type" << endl;
            cout << "3. Nominal" << endl;
            cout << "4. Quantity" << endl;
            cout << "Enter parameter: ";
            cin >> parameter;

            if (!cin)
            {
                cout << "Invalid input!" << endl;
                break;
            }

            if (parameter == 1)
            {
                char newDesignation[20];

                cout << "Enter new designation: ";
                cin.width(20);
                cin >> newDesignation;

                (*(componentsWithParameters + number - 1)).setDesignation(newDesignation);
            }

            else if (parameter == 2)
            {
                char newType;

                cout << "Enter new type: ";
                cin >> newType;

                (*(componentsWithParameters + number - 1)).setType(newType);
            }

            else if (parameter == 3)
            {
                double newNominal;

                cout << "Enter new nominal: ";
                cin >> newNominal;

                (*(componentsWithParameters + number - 1)).setNominal(newNominal);
            }

            else if (parameter == 4)
            {
                int newQuantity;

                cout << "Enter new quantity: ";
                cin >> newQuantity;

                (*(componentsWithParameters + number - 1)).setQuantity(newQuantity);
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

            if (!cin || number < 1 || number > 3)
            {
                cout << "Invalid component number." << endl;
                if (!cin) break;
                continue;
            }

            cout << "\nData of component:" << endl;
            cout << "Designation: "
                << (*(componentsWithParameters + number - 1)).getDesignation() << endl;
            cout << "Type: "
                << (*(componentsWithParameters + number - 1)).getType() << endl;
            cout << "Nominal: "
                << (*(componentsWithParameters + number - 1)).getNominal() << endl;
            cout << "Quantity: "
                << (*(componentsWithParameters + number - 1)).getQuantity() << endl;
        }

        else if (choice == 4)
        {
            cout << "\nCopied components:" << endl;
            cout << "Designation     Type      Nominal        Quantity" << endl;
            cout << "-------------------------------------------------" << endl;

            for (int i = 0; i < 3; i++)
                (*(componentsCopy + i)).show();
        }

        else if (choice == 5)
        {
            cout << "\nDefault components:" << endl;
            cout << "Designation     Type      Nominal        Quantity" << endl;
            cout << "-------------------------------------------------" << endl;

            for (int i = 0; i < 3; i++)
                (*(components + i)).show();
        }

        
        else if (choice == 6)
        {
            int number;

            cout << "\nEnter component number (1-3): ";
            cin >> number;

            if (!cin || number < 1 || number > 3)
            {
                cout << "Invalid component number." << endl;
                if (!cin) break;
                continue;
            }

            ofstream out("components.bin", ios::binary | ios::app);

            if (!out)
            {
                cout << "Error opening binary file!" << endl;
                continue;
            }

            (*(componentsWithParameters + number - 1)).writeToFile(out);

            if (out)
                cout << "Component saved successfully!" << endl;
            else
                cout << "Error writing component!" << endl;

            out.close();
        }

        
        else if (choice == 7)
        {
            ifstream in("components.bin", ios::binary | ios::in);

            if (!in)
            {
                cout << "Binary file not found!" << endl;
                continue;
            }

            in.seekg(0, ios::end);
            int count = (int)(in.tellg() / sizeof(Component));

            if (count == 0)
            {
                cout << "Binary file is empty!" << endl;
                in.close();
                continue;
            }

            int number;

            cout << "\nEnter record number (1-" << count << "): ";
            cin >> number;

            if (!cin || number < 1 || number > count)
            {
                cout << "Invalid record number!" << endl;
                in.close();
                if (!cin) break;
                continue;
            }

            in.seekg((number - 1) * sizeof(Component), ios::beg);

            Component temp;
            temp.readFromFile(in);

            if (in)
            {
                cout << "\nComponent from binary file:" << endl;
                cout << "Designation     Type      Nominal        Quantity" << endl;
                cout << "-------------------------------------------------" << endl;
                temp.show();
            }
            else
                cout << "Error reading component!" << endl;

            in.close();
        }

        
        else if (choice == 8)
        {
            ofstream out("components.bin", ios::binary | ios::out);

            if (!out)
            {
                cout << "Error creating binary file!" << endl;
                continue;
            }

            for (int i = 0; i < 3; i++)
                (*(componentsWithParameters + i)).writeToFile(out);

            if (out)
                cout << "All components saved successfully!" << endl;
            else
                cout << "Error saving components!" << endl;

            out.close();
        }

       
        else if (choice == 9)
        {
            ifstream in("components.bin", ios::binary | ios::in);

            if (!in)
            {
                cout << "Binary file not found!" << endl;
                continue;
            }

            in.seekg(0, ios::end);
            int count = (int)(in.tellg() / sizeof(Component));
            in.seekg(0, ios::beg);

            if (count != 3)
            {
                cout << "File must contain exactly 3 components!" << endl;
                cout << "Components in file: " << count << endl;
                in.close();
                continue;
            }

            Component temp[3];

            for (int i = 0; i < 3; i++)
                (*(temp + i)).readFromFile(in);

            if (in)
            {
                for (int i = 0; i < 3; i++)
                    *(componentsWithParameters + i) = *(temp + i);

                cout << "\nAll components loaded from binary file:" << endl;
                cout << "Designation     Type      Nominal        Quantity" << endl;
                cout << "-------------------------------------------------" << endl;

                for (int i = 0; i < 3; i++)
                    (*(componentsWithParameters + i)).show();
            }
            else
                cout << "Error reading components!" << endl;

            in.close();
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
