#pragma once

#include <iostream>

class RealNumber
{
private:
    double number;

    static int count;

public:
    RealNumber();
    RealNumber(double newNumber);
    RealNumber(const RealNumber& other);
    ~RealNumber();

    double getNumber() const;
    void setNumber(double newNumber);

    static int getCount();

    bool operator==(const RealNumber& other) const;
    bool operator<(const RealNumber& other) const;
    bool operator<=(const RealNumber& other) const;

    RealNumber operator+(const RealNumber& other) const;
    RealNumber operator-(const RealNumber& other) const;
    RealNumber operator*(const RealNumber& other) const;
    RealNumber operator/(const RealNumber& other) const;

    RealNumber& operator=(const RealNumber& other);

    friend bool operator!=(const RealNumber& first, const RealNumber& second);
    friend bool operator>(const RealNumber& first, const RealNumber& second);
    friend bool operator>=(const RealNumber& first, const RealNumber& second);

    friend RealNumber& operator++(RealNumber& value);
    friend RealNumber operator++(RealNumber& value, int);

    friend RealNumber& operator--(RealNumber& value);
    friend RealNumber operator--(RealNumber& value, int);

    friend std::ostream& operator<<(std::ostream& out, const RealNumber& value);
    friend std::istream& operator>>(std::istream& in, RealNumber& value);
};