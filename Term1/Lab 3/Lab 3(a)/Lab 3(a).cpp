// Lab 3(a).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "windows.h"
#include <math.h>
using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    while (true) {

        int a, b, c;

        printf("Розв'язок квадратного рівняння ax^2 + bx + c = 0\n");

        printf("Введіть a: ");
        if (scanf("%d", &a) != 1) {
            printf("Помилка введення!\n");
            return 0;
        }

        printf("Введіть b: ");
        if (scanf("%d", &b) != 1) {
            printf("Помилка введення!\n");
            return 0;
        }

        printf("Введіть c: ");
        if (scanf("%d", &c) != 1) {
            printf("Помилка введення!\n");
            return 0;
        }

        if (a == 0) {
            printf("Це не квадратне рівняння.\n");
            if (b == 0) {
                if (c == 0)
                    printf("Рівняння 0 = 0 — нескінченна кількість розв'язків.\n");
                else
                    printf("Рівняння не має розв'язків.\n");
            }
            else {
                double x = -(double)c / b;
                printf("Лінійне рівняння. Розв'язок: x = %.2lf\n", x);
            }
            return 0;
        }

        int D = b * b - 4 * a * c;
        printf("Дискримінант D = %d\n", D);

        if (D > 0) {
            double x1 = (-b + sqrt(D)) / (2.0 * a);
            double x2 = (-b - sqrt(D)) / (2.0 * a);
            printf("Два різні дійсні корені:\n");
            printf("x1 = %.2lf\n", x1);
            printf("x2 = %.2lf\n", x2);
        }
        else if (D == 0) {
            double x = -b / (2.0 * a);
            printf("Один подвійний корінь: x = %.2lf\n", x);
        }
        else if (D < 0) {
            printf("Немає коренів");
        }

        return 0;
    }
}