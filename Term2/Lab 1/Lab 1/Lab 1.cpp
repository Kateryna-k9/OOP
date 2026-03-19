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
    int d = 1;
    bool n = false;

    for (int i = 0; i < N; i++) {
        if (A[i] < 0) {
            d *= A[i];
            n = true;
        }
    }

    if (!n) return 0;
    return d;
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