// Lab 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "windows.h"
using namespace std;
int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while(true) {
	 double x, y;
	 printf("Введіть координати точки (x, y): ");
	 scanf("%lf %lf", &x, &y);

	 if ((x >= 0 && y >= 0 && x * x + y * y <= 1) || (x >= -1 && x <= 0 && y >= -1 && y <= 0)) {
		printf("Точка (%.2f, %.2f) належить заштрихованій області.\n", x, y);
	 }
	 else {
		printf("Точка (%.2f, %.2f) не налележить заштрихованій області.\n", x, y);
	 }
	 
	}
	return 0;
}