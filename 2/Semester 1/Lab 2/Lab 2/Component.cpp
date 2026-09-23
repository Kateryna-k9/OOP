#define _CRT_SECURE_NO_WARNINGS

#include "Component.h"
#include <iostream>
#include <iomanip>

using namespace std;


Component::Component()
{
    designation[0] = '\0';
    type = 'U';
    nominal = 0;
    quantity = 0;
}


Component::Component(const char* newDesignation, char newType,
    double newNominal, int newQuantity)
{
    setDesignation(newDesignation);
    type = newType;
    nominal = newNominal;
    quantity = newQuantity;
}


Component::Component(const Component& other)
{
    setDesignation(other.designation);
    type = other.type;
    nominal = other.nominal;
    quantity = other.quantity;
}


char Component::getType() const
{
    return type;
}

const char* Component::getDesignation() const
{
    return designation;
}

double Component::getNominal() const
{
    return nominal;
}

int Component::getQuantity() const
{
    return quantity;
}


void Component::setNominal(double newNominal)
{
    nominal = newNominal;
}

void Component::setDesignation(const char* newDesignation)
{
    int i = 0;

    while (newDesignation[i] != '\0' && i < 19)
    {
        designation[i] = newDesignation[i];
        i++;
    }

    designation[i] = '\0';
}

void Component::setType(char newType)
{
    type = newType;
}

void Component::setQuantity(int newQuantity)
{
    quantity = newQuantity;
}


void Component::show() const
{
    cout << left
        << setw(15) << designation
        << setw(8) << type
        << setw(15) << nominal
        << setw(10) << quantity
        << endl;
}




Component& Component::operator=(const Component& other)
{
    if (this != &other)
    {
        setDesignation(other.designation);
        type = other.type;
        nominal = other.nominal;
        quantity = other.quantity;
    }

    return *this;
}




bool Component::operator==(const Component& other) const
{
    const char* first = designation;
    const char* second = other.designation;

    while (*first != '\0' || *second != '\0')
    {
        if (*first != *second)
        {
            return false;
        }

        if (*first == '\0' || *second == '\0')
        {
            return false;
        }

        first++;
        second++;
    }

    return type == other.type &&
        nominal == other.nominal &&
        quantity == other.quantity;
}




Component Component::operator+(const Component& other) const
{
    Component result;

    result.setDesignation(designation);
    result.setType(type);
    result.setNominal(nominal + other.nominal);
    result.setQuantity(quantity + other.quantity);

    return result;
}




int Component::operator[](const char* text) const
{
    if (text == nullptr)
    {
        return 0;
    }

    int length = 0;
    const char* pointer = text;

    while (*pointer != '\0')
    {
        length++;
        pointer++;
    }

    return length;
}




void Component::operator()(const char* newDesignation, char newType,
    double newNominal, int newQuantity)
{
    setDesignation(newDesignation);
    type = newType;
    nominal = newNominal;
    quantity = newQuantity;
}




bool operator==(const Component& left, const Component& right)
{
    const char* first = left.designation;
    const char* second = right.designation;

    while (*first != '\0' || *second != '\0')
    {
        if (*first != *second)
        {
            return false;
        }

        if (*first == '\0' || *second == '\0')
        {
            return false;
        }

        first++;
        second++;
    }

    return left.type == right.type &&
        left.nominal == right.nominal &&
        left.quantity == right.quantity;
}




Component operator+(const Component& left, const Component& right)
{
    Component result;

    result.setDesignation(left.designation);
    result.setType(left.type);
    result.setNominal(left.nominal + right.nominal);
    result.setQuantity(left.quantity + right.quantity);

    return result;
}




ostream& operator<<(ostream& out, const Component& component)
{
    out << left
        << setw(15) << component.designation
        << setw(8) << component.type
        << setw(15) << component.nominal
        << setw(10) << component.quantity;

    return out;
}



istream& operator>>(istream& in, Component& component)
{
    char designation[20];
    char type;
    double nominal;
    int quantity;

    in >> designation >> type >> nominal >> quantity;

    if (in)
    {
        component.setDesignation(designation);
        component.setType(type);
        component.setNominal(nominal);
        component.setQuantity(quantity);
    }

    return in;
}