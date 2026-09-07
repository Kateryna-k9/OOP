#include "Header.h"

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