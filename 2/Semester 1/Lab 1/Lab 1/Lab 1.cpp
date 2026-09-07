// Lab 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"
#include <iostream>

using namespace std;

int main()
{
    Component component;

    component.setDesignation("RT-11-24");

    cout << "Designation: " << component.getDesignation() << endl;

    return 0;
}