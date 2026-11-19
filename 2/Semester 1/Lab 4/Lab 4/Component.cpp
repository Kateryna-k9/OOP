
#include "Component.h"
#include <iostream>
#include <iomanip>
#include <cmath>

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
    if (!isfinite(newNominal) || newNominal < 0)
        throw "Invalid nominal value!";

    nominal = newNominal;
}

void Component::setType(char newType)
{
    if (newType == '\0' || newType == ' ')
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
    if (newDesignation == nullptr || *newDesignation == '\0')
        throw "Invalid designation!";

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
        throw "Binary file is not open for writing!";

    out.write(reinterpret_cast<const char*>(this),
        sizeof(Component));

    if (!out)
        throw "Error writing component to binary file!";
}

void Component::readFromFile(ifstream& in)
{
    if (!in)
        throw "Binary file is not open for reading!";

    Component temp;

    in.read(reinterpret_cast<char*>(&temp),
        sizeof(Component));

    if (!in)
        throw "Error reading component from binary file!";

    bool hasEnd = false;

    for (int i = 0; i < 20; i++)
    {
        if (*(temp.designation + i) == '\0')
        {
            hasEnd = true;
            break;
        }
    }

    if (!hasEnd)
        throw "Invalid designation in binary file!";

    if (!isfinite(temp.nominal) || temp.nominal < 0)
        throw "Invalid nominal in binary file!";

    if (temp.quantity < 0)
        throw "Invalid quantity in binary file!";

    if (temp.type == '\0' || temp.type == ' ')
        throw "Invalid type in binary file!";

    *this = temp;
}
