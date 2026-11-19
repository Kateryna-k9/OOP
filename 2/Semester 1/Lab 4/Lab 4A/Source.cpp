
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
    if (index < 0 || index >= size)
        throw "Invalid array index!";

    *(data + index) = value;
}

int DynamicArray::getElement(int index) const
{
    if (index < 0 || index >= size)
        throw "Invalid array index!";

    return *(data + index);
}

int DynamicArray::getSize() const
{
    return size;
}

int DynamicArray::getSum() const
{
    if (size == 0)
        throw "Array is empty!";

    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += *(data + i);

    return sum;
}

void DynamicArray::saveToFile(const char* filename) const
{
    if (size == 0)
        throw "Array is empty!";

    ofstream out(filename);

    if (!out)
        throw "Error opening results.txt for writing!";

    out << "Array elements: ";

    for (int i = 0; i < size; i++)
        out << *(data + i) << " ";

    out << endl;

    if (!out)
        throw "Error writing array to file!";

    out.close();

    if (!out)
        throw "Error closing results.txt!";
}

void DynamicArray::appendSumToFile(const char* filename) const
{
    if (size == 0)
        throw "Array is empty!";

    ifstream check(filename);

    if (!check)
        throw "File does not exist! Save array first!";

    check.close();

    ofstream out(filename, ios::app);

    if (!out)
        throw "Error opening results.txt for appending!";

    out << "Sum of elements: " << getSum() << endl;

    if (!out)
        throw "Error writing sum to file!";

    out.close();

    if (!out)
        throw "Error closing results.txt!";
}
