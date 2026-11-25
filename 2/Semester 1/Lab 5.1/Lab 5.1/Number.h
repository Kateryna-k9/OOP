#pragma once

#include <iostream>
using namespace std;

template <class T>
class Number {
private:
    T x;

public:
    Number();
    Number(const T a);

    void show() const;

    T getX() const;

    Number<T>& operator=(const Number<T>& ob);
    Number<T> operator+(const Number<T>& ob) const;
};

const int N = 3;

void loadData(Number<int>* intNumbers,
    Number<float>* floatNumbers);

void saveData(const Number<int>* intNumbers,
    const Number<float>* floatNumbers);

template <class T>
void showNumbers(const Number<T>* numbers,
    const int size);

void showMenu();

int inputIndex();