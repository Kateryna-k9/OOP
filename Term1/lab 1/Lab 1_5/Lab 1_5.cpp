// Lab 1_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>
#include <climits> 

int main() {
    int seconds_in_year = 365 * 24 * 60 * 60; 

    int years[] = { 100, 1000, 10000, 100000, 1000000, 10000000 };

    for (int i = 0; i < 6; ++i) {
        int y = years[i];

        long long total = (long long)seconds_in_year * y;

        if (total <= INT_MAX) {
            int result = seconds_in_year * y;
            printf("%d years: %d seconds [int]\n", y, result);
        }

        if (total > INT_MAX && total <= LONG_MAX) {
            long result = (long)total;
            printf("%d years: %ld seconds [long]\n", y, result);
        }

        if (total > LONG_MAX) {
            long long result = total;
            printf("%d years: %lld seconds [long long]\n", y, result);
        }
    }

    return 0;
}
