#pragma once

#include "RealNumber.h"

class RealNumberArray
{
private:
    RealNumber* numbers;
    int size;

public:
    RealNumberArray(int newSize);
    ~RealNumberArray();

    RealNumber& operator[](int index);
    const RealNumber& operator[](int index) const;

    int getSize() const;

    RealNumber findMin() const;
    RealNumber findMax() const;
    double average() const;
};