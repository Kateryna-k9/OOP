// Lab 4(b).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(void) {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a, b, x, y = 0;
    int i;

    srand((unsigned)time(NULL));

    printf("Перевірка знань таблиці множення. Відповідайте на 10 прикладів.\n");

    for (i = 0; i < 10; i++) {
        a = rand() % 8 + 2; 
        b = rand() % 8 + 2; 

        printf("Приклад %d: %d * %d = ", i + 1, a, b);
        if (scanf("%d", &x) != 1) {
            printf("Введено не число. Спроба пропущена.\n");
            while (getchar() != '\n'); 
        }

        if (x == a * b) {
            printf("Вірно!\n");
            y++;
        }
        else {
            printf("Невірно. Правильна відповідь: %d\n", a * b);
        }
    }

    printf("\nКількість вірних відповідей: %d\n", y);

    
    int g;
    switch (y) {
    case 10:
        g = 5;
        break;
    case 9:
        g = 4;
        break;
    case 8:
    case 7:
        g = 3;
        break;
    default:
        g = 2;
        break;
    }

    printf("Ваша оцінка: %d\n", g);

    return 0;
}