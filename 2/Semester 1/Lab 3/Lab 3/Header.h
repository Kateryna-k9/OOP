
#pragma once
#include <iostream>
using namespace std;

class B1
{
private:
    int valueB1;

public:
    B1(const int value);
    virtual ~B1();

    int getValueB1() const;
    virtual void show() const;

    friend ostream& operator<<(ostream& out, const B1& obj);
};

class B2
{
private:
    int valueB2;

public:
    B2(const int value);
    virtual ~B2();

    int getValueB2() const;
    virtual void show() const;

    friend ostream& operator<<(ostream& out, const B2& obj);
};

class B3
{
private:
    int valueB3;

public:
    B3(const int value);
    virtual ~B3();

    int getValueB3() const;
    virtual void show() const;

    friend ostream& operator<<(ostream& out, const B3& obj);
};


class D1 : public B1, public B2, private B3
{
private:
    int valueD1;

public:
    D1(const int v1, const int v2, const int v3, const int v4);
    virtual ~D1();

    int getValueD1() const;
    virtual void show() const;

    friend ostream& operator<<(ostream& out, const D1& obj);
};
