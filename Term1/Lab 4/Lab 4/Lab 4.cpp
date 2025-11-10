// Lab 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
	short n;
	double x, y;
	short h;
	for (n = 0; n < 10; n++) {
		double e = n * 2;
		double s = e + 2;
		printf("|   x    |      y      |\n");
		printf("|        |             |\n");
		
			
			for (x = e; x <= s; x += 0.25) {
				if (n % 2 == 0)
					y = sqrt(4 - (x - s) * (x - s));
				else
					y = -sqrt(4 - (x - e) * (x - e));



				printf("x = %5.2f  y = %6.5f    ", x, y);

				h = (short)((y + 2) * 10);
				for (int i = 0; i < h; i++) printf(" ");
				printf("*\n");

			}
			
		
		getchar();
	}



	return 0;
}