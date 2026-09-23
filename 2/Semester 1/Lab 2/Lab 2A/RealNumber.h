#pragma once

#include <iostream>

class RealNumber
{
private:
    double value;

    static int count;

public:
    
    RealNumber();
    RealNumber(double newValue);
    RealNumber(const RealNumber& other);

    
    ~RealNumber();

    
    double getValue() const;
    void setValue(double newValue);

    
    static int getCount();

    
    bool operator==(const RealNumber& other) const;
    bool operator<(const RealNumber& other) const;
    bool operator<=(const RealNumber& other) const;

    
    RealNumber operator+(const RealNumber& other) const;
    RealNumber operator-(const RealNumber& other) const;
    RealNumber operator*(const RealNumber& other) const;
    RealNumber operator/(const RealNumber& other) const;

    
    RealNumber& operator=(const RealNumber& other);

    
    RealNumber& operator[](int index);
    const RealNumber& operator[](int index) const;

    
    static RealNumber getMin(const RealNumber* numbers, int size);
    static RealNumber getMax(const RealNumber* numbers, int size);

    
    static double getAverage(const RealNumber* numbers, int size);

    
    friend bool operator!=(const RealNumber& left,
        const RealNumber& right);

    friend bool operator>(const RealNumber& left,
        const RealNumber& right);

    friend bool operator>=(const RealNumber& left,
        const RealNumber& right);

    
    friend RealNumber& operator++(RealNumber& number);
    friend RealNumber operator++(RealNumber& number, int);

    friend RealNumber& operator--(RealNumber& number);
    friend RealNumber operator--(RealNumber& number, int);

    
    friend std::ostream& operator<<(std::ostream& out,
        const RealNumber& number);

    friend std::istream& operator>>(std::istream& in,
        RealNumber& number);
};