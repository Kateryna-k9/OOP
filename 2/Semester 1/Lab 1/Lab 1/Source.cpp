#include "Header.h"
#include <iostream>

using namespace std;

Component::Component()
{
    designation[0] = '\0';
    type = 'U';
    nominal = 0;
    quantity = 0;
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

void Component::setType(char newType)
{
    type = newType;
}

void Component::setQuantity(int newQuantity)
{
    quantity = newQuantity;
}

void Component::setDesignation(const char* newDesignation)
{
    int i = 0;

    while (newDesignation[i] != '\0')
    {
        designation[i] = newDesignation[i];
        i++;
    }

    designation[i] = '\0';
}

Component::Component(const char* newDesignation, char newType, double newNominal, int newQuantity)
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

void Component::show() const
{
    cout << designation << "\t"
        << type << "\t"
        << nominal << "\t"
        << quantity << endl;
}