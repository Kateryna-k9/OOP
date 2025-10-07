// Lab 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//RT-11-24 R 100000 12
//RT-11-24 R 50000 10
//CGU-12K C 17.5 3




#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char poz1[20], poz2[20], poz3[20];
    char type1, type2, type3;
    int nominal1;
    int nominal2;
    float nominal3;
    int qty1, qty2, qty3;

    printf("Введіть дані для 3 комплектуючих у форматі:\n");
    printf("Позначення Тип Номінал Кількість\n");

    printf("1. Введіть: Позначення, Тип, Номінал, Кількість > ");
    scanf("%19s %c %d %d", poz1, &type1, &nominal1, &qty1);

    printf("2. Введіть: Позначення, Тип, Номінал, Кількість > ");
    scanf("%19s %c %d %d", poz2, &type2, &nominal2, &qty2);

    printf("3. Введіть: Позначення, Тип, Номінал, Кількість > ");
    scanf("%19s %c %f %d", poz3, &type3, &nominal3, &qty3);

    printf("|-----------------------------------------------------------|\n");
    printf("| Відомість комплектуючих                                   |\n");
    printf("|-----------------------------------------------------------|\n");
    printf("| %-15s | %-4s | %-10s | %-19s |\n", "Позначення", "Тип", "Номінал", "Кількість");
    printf("|-----------------------------------------------------------|\n");
    printf("| %-15s | %-4c | %-10d | %-19d |\n", poz1, type1, nominal1, qty1);
    printf("| %-15s | %-4c | %-10d | %-19d |\n", poz2, type2, nominal2, qty2);
    printf("| %-15s | %-4c | %-10.1f | %-19d |\n", poz3, type3, nominal3, qty3);
    printf("|-----------------------------------------------------------|\n");
    printf("| Примітка: R – резистор; C – конденсатор                   |\n");
    printf("|-----------------------------------------------------------|\n");

    return 0;
}
