// lab 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
        size_t size = 0;

        size = sizeof(short);
        printf("short: %zu bytes\n", size);

        size = sizeof(int);
        printf("int: %zu bytes\n", size);

        size = sizeof(long);
        printf("long: %zu bytes\n", size);

        size = sizeof(long long);
        printf("long long: %zu bytes\n", size);

        size = sizeof(unsigned short);
        printf("unsigned short: %zu bytes\n", size);

        size = sizeof(unsigned int);
        printf("unsigned int: %zu bytes\n", size);

        size = sizeof(unsigned long);
        printf("unsigned long: %zu bytes\n", size);

        size = sizeof(unsigned long long);
        printf("unsigned long long: %zu bytes\n", size);

        size = sizeof(float);
        printf("float: %zu bytes\n", size);

        size = sizeof(double);
        printf("double: %zu bytes\n", size);

        size = sizeof(long double);
        printf("long double: %zu bytes\n", size);

        size = sizeof(char);
        printf("char: %zu byte\n", size);

    

	return 0;
}



