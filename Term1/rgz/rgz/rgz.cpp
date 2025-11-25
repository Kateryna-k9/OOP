#include <iostream>
#include <ctime>
#include <chrono>
#include <windows.h>

using namespace std;
using namespace std::chrono;

// -------------------------------------------------
// Функція копіювання масиву
// -------------------------------------------------
void copyArr(int src[], int dst[], int n) {
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

// -------------------------------------------------
// Функція виводу масиву
// -------------------------------------------------
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// -------------------------------------------------
// INSERTION SORT
// -------------------------------------------------
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

// -------------------------------------------------
// SMOOTHSORT (Тут має бути твоя реалізація)
// -------------------------------------------------
void smoothsort(int arr[], int n) {
    // ТУТ ТВОЯ РЕАЛІЗАЦІЯ
    // Якщо хочеш — вставлю повністю.
}



// =============================================================
//                      ГОЛОВНА ПРОГРАМА
// =============================================================
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int N = 20;
    const int RUNS = 100;

    int sorted[N], reverseSorted[N], randomArr[N];

    srand(time(NULL));

    // Створення масивів
    for (int i = 0; i < N; i++) {
        sorted[i] = i + 1;
        reverseSorted[i] = N - i;
        randomArr[i] = rand() % 100;
    }

    cout << fixed;
    cout.precision(6);

    int temp[N];
    chrono::high_resolution_clock::time_point start, stop;

    // ============================================================
    //                 INSERTION SORT: УПОРЯДКОВАНИЙ
    // ============================================================
    cout << "\n=== INSERTION SORT: УПОРЯДКОВАНИЙ МАСИВ ===\n";
    cout << "Масив: ";
    printArray(sorted, N);

    cout << "=== 100 запусків ===\n";
    for (int k = 0; k < RUNS; k++) {
        copyArr(sorted, temp, N);
        start = high_resolution_clock::now();
        insertionSort(temp, N);
        stop = high_resolution_clock::now();

        cout << "Запуск " << k + 1 << ": "
            << duration<double, milli>(stop - start).count() << " ms\n";
    }


    // ============================================================
    //                INSERTION SORT: ЗВОРОТНИЙ
    // ============================================================
    cout << "\n=== INSERTION SORT: ЗВОРОТНИЙ МАСИВ ===\n";
    cout << "Масив: ";
    printArray(reverseSorted, N);

    cout << "=== 100 запусків ===\n";
    for (int k = 0; k < RUNS; k++) {
        copyArr(reverseSorted, temp, N);
        start = high_resolution_clock::now();
        insertionSort(temp, N);
        stop = high_resolution_clock::now();

        cout << "Запуск " << k + 1 << ": "
            << duration<double, milli>(stop - start).count() << " ms\n";
    }


    // ============================================================
    //                INSERTION SORT: ВИПАДКОВИЙ
    // ============================================================
    cout << "\n=== INSERTION SORT: ВИПАДКОВИЙ МАСИВ ===\n";
    cout << "Масив: ";
    printArray(randomArr, N);

    cout << "=== 100 запусків ===\n";
    for (int k = 0; k < RUNS; k++) {
        copyArr(randomArr, temp, N);
        start = high_resolution_clock::now();
        insertionSort(temp, N);
        stop = high_resolution_clock::now();

        cout << "Запуск " << k + 1 << ": "
            << duration<double, milli>(stop - start).count() << " ms\n";
    }



    // ============================================================
    //                       SMOOTHSORT: УПОРЯДКОВАНИЙ
    // ============================================================
    cout << "\n=== SMOOTHSORT: УПОРЯДКОВАНИЙ МАСИВ ===\n";
    cout << "Масив: ";
    printArray(sorted, N);

    cout << "=== 100 запусків ===\n";
    for (int k = 0; k < RUNS; k++) {
        copyArr(sorted, temp, N);
        start = high_resolution_clock::now();
        smoothsort(temp, N);
        stop = high_resolution_clock::now();

        cout << "Запуск " << k + 1 << ": "
            << duration<double, milli>(stop - start).count() << " ms\n";
    }



    // ============================================================
    //                       SMOOTHSORT: ЗВОРОТНИЙ
    // ============================================================
    cout << "\n=== SMOOTHSORT: ЗВОРОТНИЙ МАСИВ ===\n";
    cout << "Масив: ";
    printArray(reverseSorted, N);

    cout << "=== 100 запусків ===\n";
    for (int k = 0; k < RUNS; k++) {
        copyArr(reverseSorted, temp, N);
        start = high_resolution_clock::now();
        smoothsort(temp, N);
        stop = high_resolution_clock::now();

        cout << "Запуск " << k + 1 << ": "
            << duration<double, milli>(stop - start).count() << " ms\n";
    }



    // ============================================================
    //                       SMOOTHSORT: ВИПАДКОВИЙ
    // ============================================================
    cout << "\n=== SMOOTHSORT: ВИПАДКОВИЙ МАСИВ ===\n";
    cout << "Масив: ";
    printArray(randomArr, N);

    cout << "=== 100 запусків ===\n";
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
