// Lab 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int main() {
    srand(time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int mas[] = { 10, -3, 1, 4, -5, 2 };
    int N = sizeof(mas) / sizeof(int);

    cout << "Тестовий масив:\n";
    for (int i = 0; i < N; i++) {
        cout << mas[i] << " ";
    }

    
    int temp[20];
    for (int i = 0; i < N; i++) temp[i] = mas[i];

   
    for (int j = 0; j < N - 1; j++) {
        for (int k = 0; k < N - j - 1; k++) {
            if (temp[k] < temp[k + 1]) {
                int t = temp[k];
                temp[k] = temp[k + 1];
                temp[k + 1] = t;
            }
        }
    }

    int thirdMax = temp[2];
    cout << "\n\n3-й за величиною елемент = " << thirdMax << endl;

    
    for (int i = 0; i < N; i++) {
        if (mas[i] > thirdMax)
            mas[i] = thirdMax;
    }

    cout << "\nМасив після заміни:\n";
    for (int i = 0; i < N; i++) {
        cout << mas[i] << " ";
    }

    
    cout << "\n\nВипадковий масив:\n";
    N = 10;
    int randMas[20];
    for (int i = 0; i < N; i++) {
        randMas[i] = rand() % 41 - 20; 
        cout << randMas[i] << " ";
    }

    for (int i = 0; i < N; i++) temp[i] = randMas[i];

    
    for (int j = 0; j < N - 1; j++) {
        for (int k = 0; k < N - j - 1; k++) {
            if (temp[k] < temp[k + 1]) {
                int t = temp[k];
                temp[k] = temp[k + 1];
                temp[k + 1] = t;
            }
        }
    }

    thirdMax = temp[2];
    cout << "\n\n3-й за величиною елемент = " << thirdMax << endl;

    for (int i = 0; i < N; i++) {
        if (randMas[i] > thirdMax)
            randMas[i] = thirdMax;
    }

    cout << "\nМасив після заміни:\n";
    for (int i = 0; i < N; i++) {
        cout << randMas[i] << " ";
    }

    cout << endl;
    return 0;
}