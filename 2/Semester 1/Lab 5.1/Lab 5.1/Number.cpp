#include "Number.h"
#include <limits>
#include <stdexcept>
#include <fstream>

template <class T>
Number<T>::Number() {
    x = 0;
}


template <class T>
Number<T>::Number(const T a) {
    x = a;
}


template <class T>
void Number<T>::show() const {
    cout << x << endl;
}


template <class T>
Number<T>& Number<T>::operator=(const Number<T>& ob) {
    x = ob.x;
    return *this;
}


template <class T>
Number<T> Number<T>::operator+(const Number<T>& ob) const {
    Number<T> temp;
    temp.x = x + ob.x;

    return temp;
}

template <class T>
T Number<T>::getX() const {
    return x;
}


template class Number<int>;
template class Number<float>;



void loadData(Number<int>* intNumbers,
    Number<float>* floatNumbers) {

    ifstream file("data.txt");

    if (!file)
        throw "Cannot open data.txt!";

    int a;
    float b;

    for (int i = 0; i < N; i++) {
        if (!(file >> a))
            throw "Error reading integer numbers!";

        *(intNumbers + i) = Number<int>(a);
    }

    for (int i = 0; i < N; i++) {
        if (!(file >> b))
            throw "Error reading real numbers!";

        *(floatNumbers + i) = Number<float>(b);
    }

    file.close();
}


void saveData(const Number<int>* intNumbers,
    const Number<float>* floatNumbers) {

    ofstream file("data.txt");

    if (!file)
        throw "Cannot open data.txt for writing!";

    for (int i = 0; i < N; i++) {
        file << (intNumbers + i)->getX() << " ";
    }

    file << endl;

    for (int i = 0; i < N; i++) {
        file << (floatNumbers + i)->getX() << " ";
    }

    file << endl;

    if (!file)
        throw "Error writing data to file!";

    file.close();

    if (!file)
        throw "Error closing data.txt!";
}

template <class T>
void showNumbers(const Number<T>* numbers,
    const int size) {

    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". ";
        (numbers + i)->show();
    }
}

template void showNumbers<int>(
    const Number<int>* numbers, const int size);

template void showNumbers<float>(
    const Number<float>* numbers, const int size);


void showMenu() {
    cout << "\n========== MENU ==========\n";
    cout << "1. Show numbers from file\n";
    cout << "2. Test default constructor\n";
    cout << "3. Test constructor with parameter\n";
    cout << "4. Test operator =\n";
    cout << "5. Add integer numbers\n";
    cout << "6. Add real numbers\n";
    cout << "7. Save numbers to file\n";
    cout << "8. Change number\n";
    cout << "0. Exit\n";
    cout << "==========================\n";
    cout << "Enter your choice: ";
}


int inputIndex() {
    int index;

    if (!(cin >> index))
        throw "Invalid input!";

    if (index < 1 || index > N)
        throw "Number index is out of range!";

    return index - 1;
}