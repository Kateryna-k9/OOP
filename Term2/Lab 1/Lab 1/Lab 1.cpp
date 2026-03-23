// Lab 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void negative(int A[], int N) {
    if (A[N] < 0) {
        cout << setw(4) << A[N];
    }

    if (N > 0) {
        negative(A, N - 1);
    }
}

int D(int A[], int N) {
    if (N < 0) return 1; 

    if (A[N] < 0)
        return A[N] * D(A, N - 1);
    else
        return D(A, N - 1);
}

int main() {
    const int N = 10;
    int A[N];

    srand(time(0));

    cout << "All:\n";
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 101 - 50;
        cout << setw(4) << A[i];
    }

    cout << "\nNegative:\n";
    negative(A, N - 1);

    cout << "\nProduct of negative numbers: " << D(A, N) << endl;

    return 0;
    
}