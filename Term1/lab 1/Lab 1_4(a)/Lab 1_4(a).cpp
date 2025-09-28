// Lab 1_4(a).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>

int main() {
    int a = 5;
    int b = 10;

    printf("Before swap: a = %d, b = %d\n", a, b);

    int temp = a;  
    a = b;
    b = temp;

    printf("After swap (with temp): a = %d, b = %d\n", a, b);

    return 0;
}

