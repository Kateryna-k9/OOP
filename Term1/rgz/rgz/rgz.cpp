#include <iostream>
#include <ctime>
#include <chrono>
#include <windows.h>  // для української мови
using namespace std;
using namespace std::chrono;

// -------------------------------
// INSERTION SORT (від меншого до більшого)
// -------------------------------
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) arr[j + 1] = arr[j], j--;
        arr[j + 1] = key;
    }
}

// -------------------------------
// SMOOTHSORT (від меншого до більшого)
// -------------------------------
static const int leonardo[] = { 1,1,2,3,5,8,13,21,34,55,89,144 };

void sift(int arr[], int head, int order) {
    while (order > 1) {
        int r = head - 1;
        int l = head - 1 - leonardo[order - 2];
        int mx = (arr[l] < arr[r]) ? l : r;
        if (arr[mx] < arr[head]) {
            swap(arr[mx], arr[head]);
            head = mx;
            order = (mx == l) ? order - 1 : order - 2;
        }
        else break;
    }
}

void trinkle(int arr[], int head, int order, unsigned long long p) {
    while (p != 1) {
        int steps = 0;
        while ((p & 1) == 0) p >>= 1, steps++;
        int prev = head - leonardo[order + steps];
        if (arr[prev] >= arr[head]) return;
        swap(arr[head], arr[prev]);
        head = prev;
        order += steps;
        sift(arr, head, order);
        p >>= 1;
    }
}

void smoothsort(int arr[], int n) {
    unsigned long long p = 1;
    int order = 1, head = 0;

    for (head = 1; head < n; head++) {
        if ((p & 3) == 3) {
            sift(arr, head - 1, order);
            p = (p + 1) >> 2;
            order += 2;
        }
        else if (order == 1) {
            p <<= 1;
            order = 0;
        }
        else {
            p <<= (order - 1);
            order = 1;
        }
    }

    trinkle(arr, head - 1, order, p);

    while (head > 1) {
        if (order <= 1)
            while ((p & 1) == 0) p >>= 1, order++;
        else {
            p <<= 2;
            p ^= 7;
            order -= 2;
            trinkle(arr, head - leonardo[order] - 1, order + 1, p >> 1);
            trinkle(arr, head - 1, order, p);
        }
        head--;
    }
}

// -------------------------------
// Допоміжні функції
// -------------------------------
void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

void copyArr(int from[], int to[], int n) {
    for (int i = 0; i < n; i++) to[i] = from[i];
}

// -------------------------------
// MAIN
// -------------------------------
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(NULL));

    const int N = 20;
    const int REPEATS = 10000;   // повтори для вимірювання часу

    int sorted[N], reverseSorted[N], randomArr[N];

    for (int i = 0; i < N; i++) {
        sorted[i] = i + 1;
        reverseSorted[i] = N - i;
        randomArr[i] = rand() % 100;
    }

    int a1[N], a2[N], a3[N];

    cout << "\n=== Початкові масиви ===\n";
    cout << "Упорядкований: "; printArr(sorted, N);
    cout << "Зворотний:     "; printArr(reverseSorted, N);
    cout << "Випадковий:    "; printArr(randomArr, N);

    chrono::high_resolution_clock::time_point start, stop;

    // ------------------- Insertion Sort -------------------
    start = high_resolution_clock::now();
    for (int r = 0; r < REPEATS; r++) {
        copyArr(sorted, a1, N);
        insertionSort(a1, N);
    }
    stop = high_resolution_clock::now();
    cout << "\nInsertion Sort (упорядкований) - "
        << duration_cast<milliseconds>(stop - start).count() << " ms\n";

    start = high_resolution_clock::now();
    for (int r = 0; r < REPEATS; r++) {
        copyArr(reverseSorted, a2, N);
        insertionSort(a2, N);
    }
    stop = high_resolution_clock::now();
    cout << "Insertion Sort (зворотний) - "
        << duration_cast<milliseconds>(stop - start).count() << " ms\n";

    start = high_resolution_clock::now();
    for (int r = 0; r < REPEATS; r++) {
        copyArr(randomArr, a3, N);
        insertionSort(a3, N);
    }
    stop = high_resolution_clock::now();
    cout << "Insertion Sort (випадковий) - "
        << duration_cast<milliseconds>(stop - start).count() << " ms\n";

    // ------------------- Smoothsort -------------------
    start = high_resolution_clock::now();
    for (int r = 0; r < REPEATS; r++) {
        copyArr(sorted, a1, N);
        smoothsort(a1, N);
    }
    stop = high_resolution_clock::now();
    cout << "\nSmoothsort (упорядкований) - "
        << duration_cast<milliseconds>(stop - start).count() << " ms\n";

    start = high_resolution_clock::now();
    for (int r = 0; r < REPEATS; r++) {
        copyArr(reverseSorted, a2, N);
        smoothsort(a2, N);
    }
    stop = high_resolution_clock::now();
    cout << "Smoothsort (зворотний) - "
        << duration_cast<milliseconds>(stop - start).count() << " ms\n";

    start = high_resolution_clock::now();
    for (int r = 0; r < REPEATS; r++) {
        copyArr(randomArr, a3, N);
        smoothsort(a3, N);
    }
    stop = high_resolution_clock::now();
    cout << "Smoothsort (випадковий) - "
        << duration_cast<milliseconds>(stop - start).count() << " ms\n";

    return 0;
}
