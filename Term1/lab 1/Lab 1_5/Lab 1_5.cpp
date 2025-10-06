// Lab 1_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>

int main() {
    const int seconds_in_day = 24 * 60 * 60;     // 86400
    const int days_in_year = 365;

    printf("In 1 year: %llu seconds\n", 1ULL * days_in_year * seconds_in_day);
    printf("In 10 years: %llu seconds\n", 10ULL * days_in_year * seconds_in_day);
    printf("In 100 years: %llu seconds\n", 100ULL * days_in_year * seconds_in_day);
    printf("In 1000 years: %llu seconds\n", 1000ULL * days_in_year * seconds_in_day);
    printf("In 10000 years: %llu seconds\n", 10000ULL * days_in_year * seconds_in_day);
    printf("In 100000 years: %llu seconds\n", 100000ULL * days_in_year * seconds_in_day);
    printf("In 1000000 years: %llu seconds\n", 1000000ULL * days_in_year * seconds_in_day);
    printf("In 10000000 years: %llu seconds\n", 10000000ULL * days_in_year * seconds_in_day);
    printf("In 100000000 years: %llu seconds\n", 100000000ULL * days_in_year * seconds_in_day);
    printf("In 1000000000 years: %llu seconds\n", 1000000000ULL * days_in_year * seconds_in_day);

    return 0;
}


