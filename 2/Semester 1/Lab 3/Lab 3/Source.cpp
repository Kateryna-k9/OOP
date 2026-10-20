
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


D1::D1(const int v1, const int v2, const int v3, const int v4)
    : B1(v1), B2(v2), B3(v3), valueD1(v4)
{
}

D1::~D1()
{
}

int D1::getValueD1() const
{
    return valueD1;
}

int D1::getB3Value() const
{
    return getValueB3();
}

void D1::show() const
{
    cout << "B1: " << getValueB1() << endl;
    cout << "B2: " << getValueB2() << endl;
    cout << "B3: " << getValueB3() << endl;
    cout << "D1: " << valueD1 << endl;
}

ostream& operator<<(ostream& out, const D1& obj)
{
    out << "B1: " << obj.getValueB1() << endl;
    out << "B2: " << obj.getValueB2() << endl;
    out << "B3: " << obj.getValueB3() << endl;
    out << "D1: " << obj.valueD1;

    return out;
}



D2::D2(const int v1, const int v2, const int v3,
    const int v4, const int v5)
    : D1(v1, v2, v3, v4), valueD2(v5)
{
}

D2::~D2()
{
}

int D2::getValueD2() const
{
    return valueD2;
}

void D2::show() const
{
    cout << "B1: " << getValueB1() << endl;
    cout << "B2: " << getValueB2() << endl;
    cout << "B3: " << getB3Value() << endl;
    cout << "D1: " << getValueD1() << endl;
    cout << "D2: " << valueD2 << endl;
}

ostream& operator<<(ostream& out, const D2& obj)
{
    out << "B1: " << obj.getValueB1() << endl;
    out << "B2: " << obj.getValueB2() << endl;
    out << "B3: " << obj.getB3Value() << endl;
    out << "D1: " << obj.getValueD1() << endl;
    out << "D2: " << obj.valueD2;

    return out;
}

