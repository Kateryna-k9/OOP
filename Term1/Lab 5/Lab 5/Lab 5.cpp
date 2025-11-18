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

    int oMas[6];
    for (int i = 0; i < N; i++)
        oMas[i] = mas[i];

    cout << "Тестовий масив:\n";
    for (int i = 0; i < N; i++) {
        cout << mas[i] << " ";
    }
   

    int t;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i; j < N; j++) {
            if (mas[i] > mas[j]) {
                t = mas[i];
                mas[i] = mas[j];
                mas[j] = t;
            }
        }
    }

    /*cout << "\n Вiдсортований масив : \n";
    for (int i = 0; i < N; i++)
        cout << mas[i] << " ";*/


    int thirdMax = mas[2];
    cout << "\n\n3-й за величиною елемент = " << thirdMax << endl;

    for (int i = 0; i < N; i++) {
        if (oMas[i] > thirdMax)
            oMas[i] = thirdMax;
    }

    cout << "\nМасив після заміни:\n";
    for (int i = 0; i < N; i++) {
        cout << oMas[i] << " ";
    }


    cout << "\n\nВипадковий масив:\n";
    N = 10;
    int randMas[10];
    for (int i = 0; i < N; i++) {
        randMas[i] = rand() % 41 - 20;
        cout << randMas[i] << " ";
       
    }
    int oRandMas[10];
    for (int i = 0; i < N; i++)
        oRandMas[i] = randMas[i];
    cout << endl;

    
    for (int i = 0; i < N - 1; i++) {
        for (int j = i; j < N; j++) {
            if (randMas[i] > randMas[j]) {
                t = randMas[i];
                randMas[i] = randMas[j];
                randMas[j] = t;
            }
        }
    }
    
   /* cout << "\n Вiдсортований масив : \n";
    for (int i = 0; i < N; i++)
        cout << randMas[i] << " ";*/


    
    thirdMax = randMas[2];
    cout << "\n\n3-й за величиною елемент = " << thirdMax << endl;

   
    for (int i = 0; i < N; i++) {
        if (oRandMas[i] > thirdMax)
            oRandMas[i] = thirdMax;
    }

    cout << "\nМасив після заміни:\n";
    for (int i = 0; i < N; i++) {
        cout << oRandMas[i] << " ";
    }

    cout << endl;
    return 0;
}