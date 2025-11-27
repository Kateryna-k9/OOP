// Lab 3(b).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "windows.h"
using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true) {
		int a;
		printf("Введіть кількість грибів\n");
		printf("--> ");
		scanf("%d", &a);

		switch (a) {
		case 1:
			printf("У кошику %d гриб\n", a);
			break;

		case 2: case 3: case 4:
			printf("У кошику %d гриба\n", a);
			break;


		}  // switch (a) 
		if (a >= 5 && a <= 20) {
			if (a = (char)a) {
			printf("Помилка! Ви ввели не число.\n");


			while (getchar() != '\n');
			continue;
		}
		
			printf("У кошику %d грибів\n", a);

		} // if (a >= 5 && a <= 20)


		if (a > 20) {
			
			int d = a % 100;
			int b = a % 10;
			if (d >= 11 && d <= 19) {
				printf("У кошику %d грибів\n", a);
			}
			else {

				switch (b) {
				
				case 0:
					printf("У кошику %d грибів\n", a);
					break;
				case 1:
					printf("У кошику %d гриб\n", a);
					break;
				case 2: case 3: case 4:
					printf("У кошику %d гриба\n", a);
					break;




				} // switch (b)
			} //else
			
			
			
		} // if (a > 20)
		
		if (a < 0) {
			printf("Число повинно бути невід'ємним!\n");
			//continue;
		}
		if (a == 0) {
			printf("У вас немає грибів\n");
			//continue;
		}

		if (a = (char)a) {
			printf("Помилка! Ви ввели не число.\n");


			while (getchar() != '\n');
			continue;
		}
		
		
	} // while (true)

	

}