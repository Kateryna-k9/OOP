
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
    designation[0] = '\0';
    type = 'U';
    nominal = 0;
    quantity = 0;

    setDesignation(newDesignation);
    setType(newType);
    setNominal(newNominal);
    setQuantity(newQuantity);
}

Component::Component(const Component& other)
{
    designation[0] = '\0';
    type = 'U';
    nominal = 0;
    quantity = 0;

    setDesignation(other.designation);
    setType(other.type);
    setNominal(other.nominal);
    setQuantity(other.quantity);
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
    if (newNominal < 0)
        throw "Invalid nominal value!";

    nominal = newNominal;
}

void Component::setType(char newType)
{
    if (newType == ' ' || newType == '\0')
        throw "Invalid component type!";

    type = newType;
}

void Component::setQuantity(int newQuantity)
{
    if (newQuantity < 0)
        throw "Invalid quantity!";

    quantity = newQuantity;
}

void Component::setDesignation(const char* newDesignation)
{
    if (newDesignation == nullptr)
        throw "Invalid designation!";

    if (*newDesignation == '\0')
        throw "Designation cannot be empty!";

    int i = 0;

    while (*(newDesignation + i) != '\0')
    {
        if (i >= 19)
            throw "Designation is too long!";

        i++;
    }

    for (int j = 0; j <= i; j++)
        *(designation + j) = *(newDesignation + j);
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

void Component::writeToFile(ofstream& out) const
{
    if (!out)
        throw "Error opening binary file for writing!";

    out.write((const char*)this, sizeof(Component));

    if (!out)
        throw "Error writing component!";
}

void Component::readFromFile(ifstream& in)
{
    if (!in)
        throw "Error opening binary file for reading!";

    Component temp;

    in.read((char*)&temp, sizeof(Component));

    if (!in)
        throw "Error reading component!";

    bool correct = false;

    for (int i = 0; i < 20; i++)
    {
        if (*(temp.designation + i) == '\0')
        {
            correct = true;
            break;
        }
    }

    if (!correct)
        throw "Invalid designation in file!";

    if (temp.nominal < 0)
        throw "Invalid nominal in file!";

    if (temp.quantity < 0)
        throw "Invalid quantity in file!";

    if (temp.type == ' ' || temp.type == '\0')
        throw "Invalid type in file!";

    *this = temp;
}
