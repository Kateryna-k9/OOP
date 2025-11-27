// rgz(Smoothsort).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <chrono>
#include <windows.h>

using namespace std;
using namespace std::chrono;

// -------------------------------------------------
// Допоміжні функції
// -------------------------------------------------

// Копіювання масиву
void copyArr(int src[], int dst[], int n) {
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

// Вивід масиву на екран
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// -------------------------------------------------
// Smoothsort
// -------------------------------------------------

int Lnum[25]; // Масив чисел Леонардо

// Ініціалізація чисел Леонардо
void initLeonardo() {
    Lnum[0] = Lnum[1] = 1;
    for (int i = 2; i < 25; i++)
        Lnum[i] = Lnum[i - 1] + Lnum[i - 2] + 1;
}

// Просіювання вниз у дереві Леонардо
void sift(int arr[], int head, int size) {
    while (size > 1) {
        int r = head - 1;
        int l = head - 1 - Lnum[size - 2];
        int largest = l;

        if (arr[r] > arr[l]) largest = r;

        if (arr[largest] > arr[head]) {
            swap(arr[head], arr[largest]);
            head = largest;
            size = (largest == r ? size - 1 : size - 2);
        }
        else {
            break;
        }
    }
}

// Просіювання вгору і вниз
void trinkle(int arr[], int head, int p, int size) {
    while (p != 1) {
        int steps = 0;
        while ((p & 1) == 0) {
            p >>= 1;
            steps++;
        }
        int b = size + steps;
        int r = head - Lnum[b - 1];

        if (arr[r] <= arr[head])
            break;

        swap(arr[head], arr[r]);
        head = r;
        size = b;
        p >>= 1;
    }
    sift(arr, head, size);
}

// Основна функція Smoothsort
void smoothsort(int arr[], int n) {
    if (n < 2) return;

    initLeonardo();

    int p = 1;      // Маска дерев
    int size = 1;   // Розмір поточного дерева

    // ---------------- Фаза побудови ----------------
    for (int i = 1; i < n; i++) {
        if ((p & 3) == 3) {
            sift(arr, i - 1, size);
            p = (p + 1) >> 2;
            size += 2;
        }
        else if (size > 1) {
            p <<= 1;
            size--;
        }
        else {
            p <<= 1;
            size = 1;
        }

        p |= 1;
        trinkle(arr, i, p, size);
    }

    // ---------------- Фаза видалення ----------------
    for (int i = n - 1; i > 0; i--) {
        if (size <= 1) {
            int bit = p & (~1);
            while ((bit & 1) == 0) {
                bit >>= 1;
                size++;
            }
            p--;
        }
        else {
            p--;
            p <<= 2;
            size -= 2;

            int r = i - 1;
            trinkle(arr, r - Lnum[size - 1], p | 1, size - 1);
            trinkle(arr, r, p | 2, size);
        }
    }
}

// -------------------------------------------------
// Головна програма
// -------------------------------------------------
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int N = 20;      // Розмір масиву
    const int RUNS = 100;  // Кількість запусків

    int sorted[N], reverseSorted[N], randomArr[N];
    int temp[N];

    

    // ---------------- Створення масивів ----------------
    for (int i = 0; i < N; i++) {
        sorted[i] = i + 1;
        reverseSorted[i] = N - i;
        randomArr[i] = rand() % 100;
    }

    chrono::high_resolution_clock::time_point start, stop;

    // ---------------- Впорядкований масив ----------------
    cout << "\n=== SMOOTHSORT: УПОРЯДКОВАНИЙ МАСИВ ===\nМасив: ";
    printArray(sorted, N);

    for (int k = 0; k < RUNS; k++) {
        copyArr(sorted, temp, N);
        start = high_resolution_clock::now();
        smoothsort(temp, N);
        stop = high_resolution_clock::now();
        cout << "Запуск " << k + 1 << ": "
            << duration<double, milli>(stop - start).count() << " ms\n";
    }

    // ---------------- Зворотний масив ----------------
    cout << "\n=== SMOOTHSORT: ЗВОРОТНИЙ МАСИВ ===\nМасив: ";
    printArray(reverseSorted, N);

    for (int k = 0; k < RUNS; k++) {
        copyArr(reverseSorted, temp, N);
        start = high_resolution_clock::now();
        smoothsort(temp, N);
        stop = high_resolution_clock::now();
        cout << "Запуск " << k + 1 << ": "
            << duration<double, milli>(stop - start).count() << " ms\n";
    }

    // ---------------- Випадковий масив ----------------
    cout << "\n=== SMOOTHSORT: ВИПАДКОВИЙ МАСИВ ===\nМасив: ";
    printArray(randomArr, N);

    for (int k = 0; k < RUNS; k++) {
        copyArr(randomArr, temp, N);
        start = high_resolution_clock::now();
        smoothsort(temp, N);
        stop = high_resolution_clock::now();
        cout << "Запуск " << k + 1 << ": "
            << duration<double, milli>(stop - start).count() << " ms\n";
    }

    return 0;
}
