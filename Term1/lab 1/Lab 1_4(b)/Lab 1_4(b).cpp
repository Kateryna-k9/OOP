// Lab 1_4(b).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>

int main() {
    int a = 5;
    int b = 10;

    printf("Before swap: a = %d, b = %d\n", a, b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("After swap (no temp): a = %d, b = %d\n", a, b);

    return 0;
}

