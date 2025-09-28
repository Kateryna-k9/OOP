// Lab 1_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>   
#include <cmath>

int main()
{ 
        float a = 3;
        float b = 4;
        float c = 5;

        float p = (a + b + c) / 2;

        float area = sqrtf(p * (p - a) * (p - b) * (p - c));

        printf("\"Side a\" = %.1f\n", a);
        printf("\"Side b\" = %.1f\n", b);
        printf("\"Side c\" = %.1f\n", c);
        printf("\"Semi-perimeter\" = %.1f\n", p);
        printf("\"Triangle area (Heron's formula)\" = %.1f\n", area);


        return 0;
    }
