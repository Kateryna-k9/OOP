#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "windows.h"
using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true) {
        int a;

        printf("Введіть кількість грибів\n--> ");

        
        if (scanf("%d", &a) != 1) {
            printf("Помилка! Ви ввели не число.\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (a < 0) {
            printf("Число повинно бути невід'ємним!\n");
            continue;
        }

        if (a == 0) {
            printf("У вас немає грибів\n");
            continue;
        }

        
        if (a >= 1 && a <= 20) {
            switch (a) {
            case 1:
                printf("У кошику %d гриб\n", a);
                break;
            case 2:
            case 3:
            case 4:
                printf("У кошику %d гриба\n", a);
                break;
            default:
                printf("У кошику %d грибів\n", a);
                break;
            }
            continue;
        }

        
        int d = a % 100; 
        int b = a % 10;  

        if (d >= 11 && d <= 19) {
            printf("У кошику %d грибів\n", a);
        }
        else {
            switch (b) {
            case 1:
                printf("У кошику %d гриб\n", a);
                break;
            case 2:
            case 3:
            case 4:
                printf("У кошику %d гриба\n", a);
                break;
            default:
                printf("У кошику %d грибів\n", a);
                break;
            }
        }
    }
}
