
#include "Header.h"



B1::B1(const int value) : valueB1(value)
{
}

B1::~B1()
{
}

int B1::getValueB1() const
{
    return valueB1;
}

void B1::show() const
{
    cout << "B1: " << valueB1 << endl;
}

ostream& operator<<(ostream& out, const B1& obj)
{
    out << "B1: " << obj.valueB1;
    return out;
}



B2::B2(const int value) : valueB2(value)
{
}

B2::~B2()
{
}

int B2::getValueB2() const
{
    return valueB2;
}

void B2::show() const
{
    cout << "B2: " << valueB2 << endl;
}

ostream& operator<<(ostream& out, const B2& obj)
{
    out << "B2: " << obj.valueB2;
    return out;
}



B3::B3(const int value) : valueB3(value)
{
}

B3::~B3()
{
}

int B3::getValueB3() const
{
    return valueB3;
}

void B3::show() const
{
    cout << "B3: " << valueB3 << endl;
}

ostream& operator<<(ostream& out, const B3& obj)
{
    out << "B3: " << obj.valueB3;
    return out;
}
