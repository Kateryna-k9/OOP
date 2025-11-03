// Lab 3(a).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "windows.h"
#include <math.h>
using namespace std;


int main() {
    while (true) {

        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);


        printf("Лабораторна робота №3А\n");
        printf("Знаходження коренів квадратного рівняння виду ax² + bx + c = 0\n");

        int a, b, c;
        printf("Введіть a: ");
        scanf("%d", &a);
        printf("Введіть b: ");
        scanf("%d", &b);
        printf("Введіть c: ");
        scanf("%d", &c);

        printf("Введіть a: ");
        if (scanf("%d", &a) != 1) {
            printf("Введено не цифру!\n");
            break;
        }

        if (a == 0) {
            printf("Це не квадратне рівняння!\n");

            if (b != 0) {
                double x = -(double)c / b;
                printf("Корінь рівняння: x = %.2f\n", x);
            }
            else {
                if (c == 0)
                    printf("Рівняння має безліч розв’язків.\n");
                else
                    printf("Рівняння не має розв’язків.\n");
            }
        }
        else {
            int D = b * b - 4 * a * c;
            printf("Дискримінант D = %d\n", D);

            if (D > 0) {
                double x1 = (-b + sqrt(D)) / (2.0 * a);
                double x2 = (-b - sqrt(D)) / (2.0 * a);
                printf("Рівняння має два різних дійсних корені:\n");
                printf("x₁ = %.2f, x₂ = %.2f\n", x1, x2);
            }
            else if (D == 0) {
                double x = -b / (2.0 * a);
                printf("Рівняння має один дійсний корінь: x = %.2f\n", x);
            }
            else {
                printf("Рівняння не має дійсних коренів (D < 0).\n");
            }
        }
    }
    return 0;
}
