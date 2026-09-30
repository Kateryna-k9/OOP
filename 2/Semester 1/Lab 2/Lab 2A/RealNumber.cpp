#include "RealNumber.h"

using namespace std;

int RealNumber::count = 0;

RealNumber::RealNumber()
{
    number = 0;
    count++;
}

RealNumber::RealNumber(double newNumber)
{
    number = newNumber;
    count++;
}

RealNumber::RealNumber(const RealNumber& other)
{
    number = other.number;
    count++;
}

RealNumber::~RealNumber()
{
    count--;
}

double RealNumber::getNumber() const
{
    return number;
}

void RealNumber::setNumber(double newNumber)
{
    number = newNumber;
}

int RealNumber::getCount()
{
    return count;
}

bool RealNumber::operator==(const RealNumber& other) const
{
    return number == other.number;
}

bool RealNumber::operator<(const RealNumber& other) const
{
    return number < other.number;
}

bool RealNumber::operator<=(const RealNumber& other) const
{
    return number <= other.number;
}

RealNumber RealNumber::operator+(const RealNumber& other) const
{
    return RealNumber(number + other.number);
}

RealNumber RealNumber::operator-(const RealNumber& other) const
{
    return RealNumber(number - other.number);
}

RealNumber RealNumber::operator*(const RealNumber& other) const
{
    return RealNumber(number * other.number);
}

RealNumber RealNumber::operator/(const RealNumber& other) const
{
    return RealNumber(number / other.number);
}

RealNumber& RealNumber::operator=(const RealNumber& other)
{
    if (this != &other)
    {
        number = other.number;
    }

    return *this;
}

bool operator!=(const RealNumber& first, const RealNumber& second)
{
    return first.number != second.number;
}

bool operator>(const RealNumber& first, const RealNumber& second)
{
    return first.number > second.number;
}

bool operator>=(const RealNumber& first, const RealNumber& second)
{
    return first.number >= second.number;
}

RealNumber& operator++(RealNumber& value)
{
    value.number++;
    return value;
}

RealNumber operator++(RealNumber& value, int)
{
    RealNumber oldValue(value);
    value.number++;
    return oldValue;
}

RealNumber& operator--(RealNumber& value)
{
    value.number--;
    return value;
}

RealNumber operator--(RealNumber& value, int)
{
    RealNumber oldValue(value);
    value.number--;
    return oldValue;
}

ostream& operator<<(ostream& out, const RealNumber& value)
{
    out << value.number;
    return out;
}

istream& operator>>(istream& in, RealNumber& value)
{
    in >> value.number;
    return in;
}