// Lab 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"
#include <iostream>

using namespace std;

int main()
{
    Component component("RT-11-24", 'R', 100000, 12);

    component.show();

    return 0;
}