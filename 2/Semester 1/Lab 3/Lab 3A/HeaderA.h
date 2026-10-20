#pragma once


#pragma once
#include <iostream>
using namespace std;

class SOBAKA
{
private:
    double weight;
    int age;

public:
    SOBAKA();
    virtual ~SOBAKA();

    double getWeight() const;
    int getAge() const;

    virtual void show() const;
    virtual void golos() const;
};

class SPANIEL : public SOBAKA
{
private:
    const char* color;

public:
    SPANIEL();
    ~SPANIEL();

    void show() const;
    void golos() const;
};

class DOG : public SOBAKA
{
private:
    double height;

public:
    DOG();
    ~DOG();

    void show() const;
    void golos() const;
};
