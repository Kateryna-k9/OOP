// Lab 5(a).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX_SIZE = 100;
    int mas[MAX_SIZE];
    int N;

    cout << "Введіть кількість елементів масиву (не більше 20): ";
    cin >> N;

    if (N <= 0 || N > 20) {
        cout << "Некоректна кількість елементів!\n";
        return 0;
    }

    cout << "Введіть " << N << " елементів масиву:\n";
    for (int i = 0; i < N; i++) {
        cin >> mas[i];
    }

    cout << "\nПочатковий масив: ";
    for (int i = 0; i < N; i++) cout << mas[i] << " ";
    cout << endl;

    
    int p, k;
    cout << "\nСкільки елементів вставити? ";
    cin >> k;

    if (k <= 0 || N + k > MAX_SIZE) {
        cout << "Некоректна кількість для вставлення!\n";
        return 0;
    }

    cout << "На яку позицію вставити (0-" << N << "): ";
    cin >> p;

    if (p < 0 || p > N) {
        cout << "Некоректна позиція вставлення!\n";
        return 0;
    }

    int newElems[50];
    cout << "Введіть " << k << " нових елементів: ";
    for (int i = 0; i < k; i++) cin >> newElems[i];

    
    for (int i = N - 1; i >= p; i--) {
        mas[i + k] = mas[i];
    }

    
    for (int i = 0; i < k; i++) {
        mas[p + i] = newElems[i];
    }
    N += k;

    cout << "\nМасив після вставлення: ";
    for (int i = 0; i < N; i++) cout << mas[i] << " ";
    cout << endl;

   
    int d, g;
    cout << "\nСкільки елементів видалити? ";
    cin >> g;

    if (g <= 0 ||g > N) {
        cout << "Некоректна кількість для видалення!\n";
        return 0;
    }

    cout << "З якої позиції видаляти (0-" << N - 1 << "): ";
    cin >> d;

    if (d < 0 ||  d >= N) {
        cout << "Некоректна позиція видалення!\n";
        return 0;
    }

    if (d + g > N) {
        cout << "Неможливо видалити " << g
            << " елементів із позиції " << d << " (вихід за межі масиву)!\n";
        return 0;
    }

    
    for (int i = d + g; i < N; i++) {
        mas[i - g] = mas[i];
    }

    N -= g;

    cout << "\nМасив після видалення: ";
    for (int i = 0; i < N; i++) cout << mas[i] << " ";
    cout << endl;

    cout << "\nПрограма виконана успішно!\n";
    return 0;
}