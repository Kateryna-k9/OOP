// Lab 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
	double x, y;
	double a = 0.25;

	double period = 19.75 / 3.5;
	double start = 0.9 * period;
	double end = period;

	for (x = 0; x <= 19.75; x += a) {
		double local = fmod(x, period);

		if (local >= start && local <= end) {
			printf("\n");
				continue;
		}

		y = 2 * sin((3.14 * x) / (period / 2));
			printf("x = %5.2f    y = %6.3f    ", x, y);

			int p = (int)((y + 2) * 9);
			for (int i = 0; i < p; i++) printf(" ");
			printf("*\n");



	}




	return 0;
}