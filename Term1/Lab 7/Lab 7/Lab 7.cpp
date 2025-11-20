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
		mas1[i] = rand() % 20;
		cout << setw(4) << mas1[i];
    }
		
	cout << endl;

	Fun(mas1);
	cout << endl;

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
	
	for (int i = 0; i < N / 2; i++)
		for (int j = 0; j < N; j++)
			mas2[N - i - 1][j] = mas2[i][j];
	cout << "\nДрук нового ДМ (пiсля відзеркалення): \n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << mas2[i][j] << " ";
		cout << endl;
	}
	// Отримати ОМ з ДМ 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			mas1[i * M + j] = mas2[i][j];
	}

	int D = 1;
	for (int i = 0; i < N; i++)
		D *= mas2[i][0];
	cout << "\nДобуток нульового стовпця віддзеркаленї матриці:" << setw(4) << D;
	return D;
	
} // end Fun



		

