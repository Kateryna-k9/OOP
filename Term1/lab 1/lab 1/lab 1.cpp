// lab 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	unsigned int s_short = sizeof(short);
	unsigned int s_int = sizeof(int);
	unsigned int s_long = sizeof(long);
	unsigned int s_llong = sizeof(long long);
	unsigned int s_ushort = sizeof(unsigned short);
	unsigned int s_uint = sizeof(unsigned int);
	unsigned int s_ulong = sizeof(unsigned long);
	unsigned int s_ullong = sizeof(unsigned long long);
	unsigned int s_float = sizeof(float);
	unsigned int s_double = sizeof(double);
	unsigned int s_ldouble = sizeof(long double);
	unsigned int s_char = sizeof(char);

	cout << "Sizes of type (in bytes):\n";
	cout << "short: " << s_short << endl;
	cout << "int: " << s_int << endl;
	cout << "long: " << s_long << endl;
	cout << "long long: " << s_llong << endl;
	cout << "unsigned short : " << s_ushort << endl;
	cout << "unsigned int: " << s_uint << endl;
	cout << "unsigned long: " << s_ulong << endl;
	cout << "unsigned long long: " << s_llong << endl;
	cout << "float: " << s_float << endl;
	cout << "char: " << s_char << endl;

	double a = 3, b = 4, c = 5;
	double p = (a + b + c) / 2.0;
	double S = sqrt(p * (p - a) * (p - b) * (p - c));
	cout << "\nArea of triangle (Heron): " << S << endl;

	double x = 2, y = 3;
	double expr = sqrt(pow(x, 2) + pow(y, 2));
	cout << "\nExpression result: " << expr << endl;

	double num = 2;
	cout << "\n" << num << "^8 = " << pow(num, 8) << endl;

	int years = 1;
	int days = years * 365;
	long long hours = days * 24;
	long long minutes = hours * 60;
	long long seconds = minutes * 60;

	cout << "\nIn " << years << " year:\n";
	cout << "Days: " << days << endl;
	cout << "Hours: " << hours << endl;
	cout << "Minutes: " << minutes << endl;
	cout << "Seconds: " << seconds << endl;

	return 0;
}


