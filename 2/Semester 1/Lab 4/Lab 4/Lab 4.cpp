
#include "Component.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int COUNT = 3;

int readInt()
{
    int value;

    if (!(cin >> value))
        throw "Invalid integer input!";

    return value;
}

double readDouble()
{
    double value;

    if (!(cin >> value))
        throw "Invalid number input!";

    return value;
}

char readChar()
{
    char value;

    if (!(cin >> value))
        throw "Invalid character input!";

    return value;
}

void readDesignation(char* designation)
{
    cin >> ws;
    cin.getline(designation, 20);

    if (!cin)
        throw "Invalid designation input!";

    if (*designation == '\0')
        throw "Designation cannot be empty!";
}

void showHeader()
{
    cout << "Designation     Type      Nominal        Quantity" << endl;
    cout << "-------------------------------------------------" << endl;
}

int main()
{
    Component* components = nullptr;
    Component* componentsWithParameters = nullptr;
    Component* componentsCopy = nullptr;

    try
    {
        
        ofstream testOut("data.txt");

        if (!testOut)
            throw "Error creating data.txt!";

        testOut << "RT-11-24 R 100000 12\n";
        testOut << "RT-11-24 R 50000 10\n";
        testOut << "CGU-12K C 17.5 3\n";

        if (!testOut)
            throw "Error writing test data!";

        testOut.close();

        if (!testOut)
            throw "Error closing data.txt!";

        cout << "Test data file created." << endl;

        
        components = new Component[COUNT];
        componentsWithParameters = new Component[COUNT];

        
        ifstream testIn("data.txt");

        if (!testIn)
            throw "Error opening data.txt!";

        char designation[20];
        char type;
        double nominal;
        int quantity;

        for (int i = 0; i < COUNT; i++)
        {
            testIn.get(designation, 20, ' ');

            if (!testIn)
                throw "Error reading designation!";

            if (!(testIn >> type >> nominal >> quantity))
                throw "Error reading test data!";

            *(componentsWithParameters + i) =
                Component(designation, type, nominal, quantity);

            testIn >> ws;
        }

        testIn.close();

        
        componentsCopy = new Component[COUNT];

        for (int i = 0; i < COUNT; i++)
        {
            *(componentsCopy + i) =
                Component(*(componentsWithParameters + i));
        }

        int choice = -1;

        do
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

            try
            {
                choice = readInt();

                if (choice == 1)
                {
                    cout << "\nComponents:" << endl;
                    showHeader();

                    for (int i = 0; i < COUNT; i++)
                        (*(componentsWithParameters + i)).show();
                }

                else if (choice == 2)
                {
                    int number;
                    int parameter;

                    cout << "\nEnter component number (1-3): ";
                    number = readInt();

                    if (number < 1 || number > COUNT)
                        throw "Invalid component number!";

                    cout << "\nWhat do you want to change?" << endl;
                    cout << "1. Designation" << endl;
                    cout << "2. Type" << endl;
                    cout << "3. Nominal" << endl;
                    cout << "4. Quantity" << endl;
                    cout << "Enter parameter: ";

                    parameter = readInt();

                    if (parameter < 1 || parameter > 4)
                        throw "Invalid parameter!";

                    Component& current =
                        *(componentsWithParameters + number - 1);

                    if (parameter == 1)
                    {
                        char newDesignation[20];

                        cout << "Enter new designation: ";
                        readDesignation(newDesignation);

                        current.setDesignation(newDesignation);
                    }

                    else if (parameter == 2)
                    {
                        cout << "Enter new type: ";

                        char newType = readChar();

                        current.setType(newType);
                    }

                    else if (parameter == 3)
                    {
                        cout << "Enter new nominal: ";

                        double newNominal = readDouble();

                        current.setNominal(newNominal);
                    }

                    else if (parameter == 4)
                    {
                        cout << "Enter new quantity: ";

                        int newQuantity = readInt();

                        current.setQuantity(newQuantity);
                    }

                    cout << "Component changed successfully!" << endl;
                }

                else if (choice == 3)
                {
                    cout << "\nEnter component number (1-3): ";

                    int number = readInt();

                    if (number < 1 || number > COUNT)
                        throw "Invalid component number!";

                    Component& current =
                        *(componentsWithParameters + number - 1);

                    cout << "\nData of component:" << endl;
                    cout << "Designation: "
                        << current.getDesignation() << endl;
                    cout << "Type: "
                        << current.getType() << endl;
                    cout << "Nominal: "
                        << current.getNominal() << endl;
                    cout << "Quantity: "
                        << current.getQuantity() << endl;
                }

                else if (choice == 4)
                {
                    cout << "\nCopied components:" << endl;
                    showHeader();

                    for (int i = 0; i < COUNT; i++)
                        (*(componentsCopy + i)).show();
                }

                else if (choice == 5)
                {
                    cout << "\nDefault components:" << endl;
                    showHeader();

                    for (int i = 0; i < COUNT; i++)
                        (*(components + i)).show();
                }

                else if (choice == 6)
                {
                    cout << "\nEnter component number (1-3): ";

                    int number = readInt();

                    if (number < 1 || number > COUNT)
                        throw "Invalid component number!";

                    ofstream out("components.bin",
                        ios::binary | ios::app);

                    if (!out)
                        throw "Error opening binary file!";

                    (*(componentsWithParameters + number - 1))
                        .writeToFile(out);

                    out.close();

                    if (!out)
                        throw "Error closing binary file!";

                    cout << "Component saved successfully!" << endl;
                }

                else if (choice == 7)
                {
                    ifstream in("components.bin", ios::binary);

                    if (!in)
                        throw "Binary file not found!";

                    in.seekg(0, ios::end);

                    if (!in)
                        throw "Error finding file end!";

                    int bytes = (int)in.tellg();

                    if (bytes < 0)
                        throw "Error determining file size!";

                    if (bytes % sizeof(Component) != 0)
                        throw "Invalid binary file size!";

                    int count = bytes / sizeof(Component);

                    if (count == 0)
                        throw "Binary file is empty!";

                    cout << "\nEnter record number (1-"
                        << count << "): ";

                    int number = readInt();

                    if (number < 1 || number > count)
                        throw "Invalid record number!";

                    in.seekg((number - 1) * sizeof(Component),
                        ios::beg);

                    if (!in)
                        throw "Error finding record!";

                    Component temp;
                    temp.readFromFile(in);

                    cout << "\nComponent from binary file:" << endl;
                    showHeader();
                    temp.show();

                    in.close();
                }

                else if (choice == 8)
                {
                    ofstream out("components.bin",
                        ios::binary | ios::out);

                    if (!out)
                        throw "Error creating binary file!";

                    for (int i = 0; i < COUNT; i++)
                    {
                        (*(componentsWithParameters + i))
                            .writeToFile(out);
                    }

                    out.close();

                    if (!out)
                        throw "Error closing binary file!";

                    cout << "All components saved successfully!" << endl;
                }

                else if (choice == 9)
                {
                    ifstream in("components.bin", ios::binary);

                    if (!in)
                        throw "Binary file not found!";

                    in.seekg(0, ios::end);

                    if (!in)
                        throw "Error finding file end!";

                    int bytes = (int)in.tellg();

                    if (bytes < 0)
                        throw "Error determining file size!";

                    if (bytes % sizeof(Component) != 0)
                        throw "Invalid binary file size!";

                    int count = bytes / sizeof(Component);

                    if (count != COUNT)
                        throw "File must contain exactly 3 components!";

                    in.seekg(0, ios::beg);

                    if (!in)
                        throw "Error finding file beginning!";

                    Component temp[COUNT];

                    for (int i = 0; i < COUNT; i++)
                    {
                        (*(temp + i)).readFromFile(in);
                    }

                    for (int i = 0; i < COUNT; i++)
                    {
                        *(componentsWithParameters + i) =
                            *(temp + i);
                    }

                    cout << "\nAll components loaded from binary file:"
                        << endl;

                    showHeader();

                    for (int i = 0; i < COUNT; i++)
                        (*(componentsWithParameters + i)).show();

                    in.close();
                }

                else if (choice == 0)
                {
                    cout << "Program finished." << endl;
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
                    cin.ignore(10000, '\n');
                }
            }

        } while (choice != 0);
    }

    catch (const char* error)
    {
        cout << "Error: " << error << endl;
    }

    catch (...)
    {
        cout << "Unexpected error!" << endl;
    }

    delete[] components;
    delete[] componentsWithParameters;
    delete[] componentsCopy;

    return 0;
}
