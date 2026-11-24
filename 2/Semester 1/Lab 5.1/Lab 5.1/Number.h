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

    Number<T>& operator=(const Number<T>& ob);
    Number<T> operator+(const Number<T>& ob) const;
};