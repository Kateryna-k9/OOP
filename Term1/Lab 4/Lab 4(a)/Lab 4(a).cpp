// Lab 4(a).cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(void) {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a, b;
    int i = 0; 

    srand((unsigned)time(NULL));
    a = rand() % 100 + 1; 

    printf("Я загадав число від 1 до 100.\n");

    while (1) {
        printf("Введіть число: ");
        if (scanf("%d", &b) != 1) {
            printf("Введено не число. Перезапустіть програму та спробуйте ще.\n");
            break; 
        }

        i++; 

        if (b < a) {
            printf("Більше\n");
        }
        else if (b > a) {
            printf("Менше\n");
        }
        else {
            printf("Вітаю! Ви відгадали число %d.\n", a);
            printf("Кількість спроб: %d\n", i);
            break; 
        }
    }

    return 0;
}