
#include "Header.h"
#include <fstream>

using namespace std;


DynamicArray::DynamicArray()
{
    data = nullptr;
    size = 0;
}


DynamicArray::~DynamicArray()
{
    delete[] data;
}



void DynamicArray::createArray(int newSize)
{
    if (newSize <= 0)
        throw "Invalid array size!";

    int* newData = new int[newSize];

    for (int i = 0; i < newSize; i++)
        *(newData + i) = 0;

    delete[] data;
    data = newData;
    size = newSize;
}


void DynamicArray::setElement(int index, int value)
{
    if (index >= 0 && index < size)
        *(data + index) = value;
}


int DynamicArray::getElement(int index) const
{
    if (index >= 0 && index < size)
        return *(data + index);

    return 0;
}


int DynamicArray::getSize() const
{
    return size;
}


int DynamicArray::getSum() const
{
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += *(data + i);

    return sum;
}

bool DynamicArray::loadFromFile(const char* filename)
{
    ifstream in(filename);

    if (!in)
        return false;

    int newSize;
    in >> newSize;

    if (!in || newSize <= 0)
    {
        in.close();
        return false;
    }

    int* newData = new int[newSize];

    for (int i = 0; i < newSize; i++)
    {
        if (!(in >> *(newData + i)))
        {
            delete[] newData;
            in.close();
            return false;
        }
    }

    delete[] data;

    data = newData;
    size = newSize;

    in.close();
    return true;
}


bool DynamicArray::saveToFile(const char* filename) const
{
    ofstream out(filename);

    if (!out)
        return false;

    out << "Array elements: ";

    for (int i = 0; i < size; i++)
        out << *(data + i) << " ";

    out << endl;

    bool success = (bool)out;
    out.close();

    return success;
}


bool DynamicArray::appendSumToFile(const char* filename) const
{
    ifstream check(filename);

    if (!check)
        return false;

    check.close();

    ofstream out(filename, ios::app);

    if (!out)
        return false;

    out << "Sum of elements: " << getSum() << endl;

    bool success = (bool)out;
    out.close();

    return success;
}
