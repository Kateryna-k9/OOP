// Lab 6.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

    const int N = 9;
    int mas[N][N];

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mas[i][j] = rand() % 41 - 20; 
        }
    }

    cout << "Початкова матриця:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mas[i][j] << "\t";
        }
        cout << endl;
    }

    
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N; j++) {
            mas[N - 1 - i][j] = mas[i][j];
        }
    }

    cout << "\nМатриця після відображення:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mas[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

