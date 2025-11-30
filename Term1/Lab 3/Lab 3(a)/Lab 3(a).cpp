#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <windows.h>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true) {

        printf("Знаходження коренів квадратного рівняння ax² + bx + c = 0\n\n");

        double a, b, c;

        
        printf("Введіть a: ");
        if (scanf("%lf", &a) != 1) {
            printf("Помилка! Ви ввели не число.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Введіть b: ");
        if (scanf("%lf", &b) != 1) {
            printf("Помилка! Ви ввели не число.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Введіть c: ");
        if (scanf("%lf", &c) != 1) {
            printf("Помилка! Ви ввели не число.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("\n");

        
        if (a == 0) {
            printf("Це не квадратне рівняння.\n");

            if (b != 0) {
                double x = -c / b;
                printf("Корінь рівняння: x = %.2lf\n\n", x);
            }
            else {
                if (c == 0)
                    printf("Рівняння має безліч розв'язків.\n\n");
                else
                    printf("Рівняння не має розв'язків.\n\n");
            }
        }
        else {
            double D = b * b - 4 * a * c;
            printf("Дискримінант D = %.2lf\n", D);

            if (D > 0) {
                double x1 = (-b + sqrt(D)) / (2 * a);
                double x2 = (-b - sqrt(D)) / (2 * a);
                printf("Рівняння має два різних дійсних корені:\n");
                printf("x₁ = %.2lf, x₂ = %.2lf\n\n", x1, x2);
            }
            else if (D == 0) {
                double x = -b / (2 * a);
                printf("Рівняння має один дійсний корінь: x = %.2lf\n\n", x);
            }
            else {
                printf("Рівняння не має дійсних коренів (D < 0).\n\n");
            }
        }


    }
}