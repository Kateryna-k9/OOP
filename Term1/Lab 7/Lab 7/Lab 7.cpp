// Lab 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <iomanip>
using namespace std;



#define N 3
#define M 6
int Fun(int mas1[]); //прототип


int main() {

    srand(time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int mas1[N * M];
    cout << "Одновимiрний масив ->: \n";
    for (int i = 0; i < N * M; i++) {
        mas1[i] = rand() % 5;
        cout << setw(4) << mas1[i];
    }

    cout << endl;

    int dobutok = Fun(mas1);   
    cout << "\nДобуток нульового стовпця віддзеркаленої матриці: " << dobutok << endl;

    cout << "\nОдновимiрний масив (пiсля функцiї) ->:\n ";
    for (int i = 0; i < N * M; i++)
        cout << setw(4) << mas1[i];
    cout << endl;

} // main()

int Fun(int mas1[]) {

    int mas2[N][M];

    cout << "\nДрук ДМ з ОМ:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            mas2[i][j] = mas1[i * M + j];
            cout << mas2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nПеретворена матриця:\n";


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            mas2[i][j] = mas2[N - 1 - i][j];
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << mas2[i][j] << " ";
        }
        cout << endl;
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            mas1[i * M + j] = mas2[i][j];
        }
    }

   
     int D = 1;

     for (int i = 0; i < N; i++) {
            D *= mas2[i][0];
     }

     return D;

    


}
    
