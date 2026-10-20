#pragma once


#include <iostream>

class B1
{
private:
    int valueB1;

public:
    B1(const int value);
    virtual ~B1() = default;

    int getValueB1() const;
    virtual void show() const;

    friend std::ostream& operator<<(std::ostream& out, const B1& obj);
};

class B2
{
private:
    int valueB2;

public:
    B2(const int value);
    virtual ~B2() = default;

    int getValueB2() const;
    virtual void show() const;

    friend std::ostream& operator<<(std::ostream& out, const B2& obj);
};

class B3
{
private:
    int valueB3;

public:
    B3(const int value);
    virtual ~B3() = default;

    int getValueB3() const;
    virtual void show() const;

    friend std::ostream& operator<<(std::ostream& out, const B3& obj);
};
