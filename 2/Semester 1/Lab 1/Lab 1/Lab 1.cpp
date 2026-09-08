// Lab 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"
#include <iostream>

using namespace std;

int main()
{
    Component components[3];

    cout << "Designation    Type    Nominal    Quantity" << endl;
    cout << "------------------------------------------" << endl;

    for (int i = 0; i < 3; i++)
    {
        components[i].show();
    }

    Component componentsWithParameters[3] =
    {
        Component("RT-11-24", 'R', 100000, 12),
        Component("RT-11-24", 'R', 50000, 10),
        Component("CGU-12K", 'C', 17.5, 3)
    };

    cout << "\nArray with parameterized constructor:" << endl;

    for (int i = 0; i < 3; i++)
    {
        componentsWithParameters[i].show();
    }

    componentsWithParameters[0].setQuantity(15);
    componentsWithParameters[1].setNominal(75000);
    componentsWithParameters[2].setType('R');
    componentsWithParameters[2].setDesignation("NEW-COMPONENT");

    cout << "\nArray after changes:" << endl;

    for (int i = 0; i < 3; i++)
    {
        componentsWithParameters[i].show();
    }

    cout << "\nData using get methods:" << endl;

    cout << "Designation: " << componentsWithParameters[0].getDesignation() << endl;
    cout << "Type: " << componentsWithParameters[0].getType() << endl;
    cout << "Nominal: " << componentsWithParameters[0].getNominal() << endl;
    cout << "Quantity: " << componentsWithParameters[0].getQuantity() << endl;

    Component original1("RT-11-24", 'R', 100000, 12);
    Component original2("RT-11-24", 'R', 50000, 10);
    Component original3("CGU-12K", 'C', 17.5, 3);

    Component componentsCopy[3] =
    {
        Component(original1),
        Component(original2),
        Component(original3)
    };

    cout << "\nArray with copy constructor:" << endl;

    for (int i = 0; i < 3; i++)
    {
        componentsCopy[i].show();
    }

    return 0;
}