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
        << setw(10) << type
        << setw(15) << nominal
        << setw(10) << quantity
        << endl;
}






bool Component::operator==(const Component& other) const
{
    if (type != other.type)
    {
        return false;
    }

    if (nominal != other.nominal)
    {
        return false;
    }

    if (quantity != other.quantity)
    {
        return false;
    }

    int i = 0;

    while (designation[i] != '\0' || other.designation[i] != '\0')
    {
        if (designation[i] != other.designation[i])
        {
            return false;
        }

        i++;
    }

    return true;
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
    int length = 0;

    while (text[length] != '\0')
    {
        length++;
    }

    return length;
}




void Component::operator()(const char* newDesignation,
    char newType, double newNominal, int newQuantity)
{
    setDesignation(newDesignation);
    setType(newType);
    setNominal(newNominal);
    setQuantity(newQuantity);
}




bool operator==(const Component& first, const Component& second)
{
    if (first.type != second.type)
    {
        return false;
    }

    if (first.nominal != second.nominal)
    {
        return false;
    }

    if (first.quantity != second.quantity)
    {
        return false;
    }

    int i = 0;

    while (first.designation[i] != '\0' ||
        second.designation[i] != '\0')
    {
        if (first.designation[i] != second.designation[i])
        {
            return false;
        }

        i++;
    }

    return true;
}




Component operator+(const Component& first, const Component& second)
{
    Component result;

    result.setDesignation(first.designation);
    result.setType(first.type);
    result.setNominal(first.nominal + second.nominal);
    result.setQuantity(first.quantity + second.quantity);

    return result;
}




ostream& operator<<(ostream& out, const Component& component)
{
    out << "Designation: " << component.designation << endl;
    out << "Type: " << component.type << endl;
    out << "Nominal: " << component.nominal << endl;
    out << "Quantity: " << component.quantity << endl;

    return out;
}




istream& operator>>(istream& in, Component& component)
{
    char newDesignation[20];
    char newType;
    double newNominal;
    int newQuantity;

    cout << "Enter designation: ";
    in >> newDesignation;

    cout << "Enter type: ";
    in >> newType;

    cout << "Enter nominal: ";
    in >> newNominal;

    cout << "Enter quantity: ";
    in >> newQuantity;

    component(newDesignation, newType, newNominal, newQuantity);

    return in;
}