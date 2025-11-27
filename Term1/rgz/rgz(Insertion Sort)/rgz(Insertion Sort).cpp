// rgz(Insertion Sort).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <chrono>
#include <windows.h>
using namespace std;
using namespace std::chrono;

void copyArr(int src[], int dst[], int n) {
    for (int i = 0; i < n; i++) dst[i] = src[i];
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int N = 20, RUNS = 100;
    int sorted[N], reverseSorted[N], randomArr[N];

   
    for (int i = 0; i < N; i++) {
        sorted[i] = i + 1;
        reverseSorted[i] = N - i;
        randomArr[i] = rand() % 100;
    }

    int temp[N];
    chrono::high_resolution_clock::time_point start, stop;

    // ---------------- ÂÏÎÐßÄÊÎÂÀÍÈÉ ----------------
    cout << "\n=== INSERTION SORT: ÓÏÎÐßÄÊÎÂÀÍÈÉ ÌÀÑÈÂ ===\nÌàñèâ: ";
    printArray(sorted, N);

    for (int k = 0; k < RUNS; k++) {
        copyArr(sorted, temp, N);
        start = high_resolution_clock::now();
        insertionSort(temp, N);
        stop = high_resolution_clock::now();
        cout << "Çàïóñê " << k + 1 << ": "
            << duration<double, milli>(stop - start).count() << " ms\n";
    }

    // ---------------- ÇÂÎÐÎÒÍÈÉ ----------------
    cout << "\n=== INSERTION SORT: ÇÂÎÐÎÒÍÈÉ ÌÀÑÈÂ ===\nÌàñèâ: ";
    printArray(reverseSorted, N);

    for (int k = 0; k < RUNS; k++) {
        copyArr(reverseSorted, temp, N);
        start = high_resolution_clock::now();
        insertionSort(temp, N);
        stop = high_resolution_clock::now();
        cout << "Çàïóñê " << k + 1 << ": "
            << duration<double, milli>(stop - start).count() << " ms\n";
    }

    // ---------------- ÂÈÏÀÄÊÎÂÈÉ ----------------
    cout << "\n=== INSERTION SORT: ÂÈÏÀÄÊÎÂÈÉ ÌÀÑÈÂ ===\nÌàñèâ: ";
    printArray(randomArr, N);

    for (int k = 0; k < RUNS; k++) {
        copyArr(randomArr, temp, N);
        start = high_resolution_clock::now();
        insertionSort(temp, N);
        stop = high_resolution_clock::now();
        cout << "Çàïóñê " << k + 1 << ": "
            << duration<double, milli>(stop - start).count() << " ms\n";
    }

    return 0;
}
