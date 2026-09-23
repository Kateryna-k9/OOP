#define _CRT_SECURE_NO_WARNINGS

#include "RealNumber.h"
#include <iostream>
#include <stdexcept>

using namespace std;



int RealNumber::count = 0;




RealNumber::RealNumber()
{
    value = 0.0;
    count++;
}




RealNumber::RealNumber(double newValue)
{
    value = newValue;
    count++;
}



RealNumber::RealNumber(const RealNumber& other)
{
    value = other.value;
    count++;
}




RealNumber::~RealNumber()
{
    count--;
}



double RealNumber::getValue() const
{
    return value;
}




void RealNumber::setValue(double newValue)
{
    value = newValue;
}




int RealNumber::getCount()
{
    return count;
}




bool RealNumber::operator==(const RealNumber& other) const
{
    return value == other.value;
}




bool RealNumber::operator<(const RealNumber& other) const
{
    return value < other.value;
}



bool RealNumber::operator<=(const RealNumber& other) const
{
    return value <= other.value;
}




RealNumber RealNumber::operator+(const RealNumber& other) const
{
    return RealNumber(value + other.value);
}




RealNumber RealNumber::operator-(const RealNumber& other) const
{
    return RealNumber(value - other.value);
}




RealNumber RealNumber::operator*(const RealNumber& other) const
{
    return RealNumber(value * other.value);
}




RealNumber RealNumber::operator/(const RealNumber& other) const
{
    if (other.value == 0.0)
    {
        throw runtime_error("Division by zero is not allowed.");
    }

    return RealNumber(value / other.value);
}




RealNumber& RealNumber::operator=(const RealNumber& other)
{
    if (this != &other)
    {
        value = other.value;
    }

    return *this;
}



const RealNumber& RealNumber::operator[](int index) const
{
    if (index != 0)
    {
        throw out_of_range("Index must be 0.");
    }

    return *this;
}




RealNumber& RealNumber::operator[](int index)
{
    if (index != 0)
    {
        throw out_of_range("Index must be 0.");
    }

    return *this;
}




RealNumber RealNumber::getMin(
    const RealNumber* numbers,
    int size)
{
    if (size <= 0)
    {
        return RealNumber();
    }

    RealNumber min = *numbers;

    for (int i = 1; i < size; i++)
    {
        if ((numbers + i)->value < min.value)
        {
            min = *(numbers + i);
        }
    }

    return min;
}




RealNumber RealNumber::getMax(
    const RealNumber* numbers,
    int size)
{
    if (size <= 0)
    {
        return RealNumber();
    }

    RealNumber max = *numbers;

    for (int i = 1; i < size; i++)
    {
        if ((numbers + i)->value > max.value)
        {
            max = *(numbers + i);
        }
    }

    return max;
}




double RealNumber::getAverage(
    const RealNumber* numbers,
    int size)
{
    if (size <= 0)
    {
        return 0.0;
    }

    double sum = 0.0;

    for (int i = 0; i < size; i++)
    {
        sum += (numbers + i)->value;
    }

    return sum / size;
}




bool operator!=(
    const RealNumber& left,
    const RealNumber& right)
{
    return !(left == right);
}




bool operator>(
    const RealNumber& left,
    const RealNumber& right)
{
    return right < left;
}




bool operator>=(
    const RealNumber& left,
    const RealNumber& right)
{
    return !(left < right);
}



RealNumber& operator++(RealNumber& number)
{
    number.value++;

    return number;
}




RealNumber operator++(RealNumber& number, int)
{
    RealNumber old(number);

    number.value++;

    return old;
}




RealNumber& operator--(RealNumber& number)
{
    number.value--;

    return number;
}




RealNumber operator--(RealNumber& number, int)
{
    RealNumber old(number);

    number.value--;

    return old;
}




ostream& operator<<(
    ostream& out,
    const RealNumber& number)
{
    out << number.value;

    return out;
}




istream& operator>>(
    istream& in,
    RealNumber& number)
{
    in >> number.value;

    return in;
}