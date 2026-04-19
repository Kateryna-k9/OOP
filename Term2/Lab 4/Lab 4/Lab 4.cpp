// Lab 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"

int main()
{
    int N, M;

    cout << "Enter elements(N): ";
    cin >> N;

    cout << "Enter elemwnts(M): ";
    cin >> M;

    int** mas = new int* [N];

    for (int i = 0; i < N; i++)
    {
        *(mas + i) = new int[M];
    }

    fill(mas, N, M);

    int* sum = new int;
    int* size = new int;

    int* result = process(mas, N, M, sum, size);

    cout << "\nTwo-digit numbers:\n";

    for (int i = 0; i < *size; i++)
    {
        cout << *(result + i) << " ";
    }

    cout << "\nSum = " << *sum << endl;

    delete[] result;
    delete sum;
    delete size;

    free(mas, N);

    return 0;
}