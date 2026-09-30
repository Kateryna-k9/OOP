#include "RealNumberArray.h"

RealNumberArray::RealNumberArray(int newSize)
{
    size = newSize;
    numbers = new RealNumber[size];
}

RealNumberArray::~RealNumberArray()
{
    delete[] numbers;
}

RealNumber& RealNumberArray::operator[](int index)
{
    return *(numbers + index);
}

const RealNumber& RealNumberArray::operator[](int index) const
{
    return *(numbers + index);
}

int RealNumberArray::getSize() const
{
    return size;
}

RealNumber RealNumberArray::findMin() const
{
    RealNumber minimum = *numbers;

    for (int i = 1; i < size; i++)
    {
        if (*(numbers + i) < minimum)
        {
            minimum = *(numbers + i);
        }
    }

    return minimum;
}

RealNumber RealNumberArray::findMax() const
{
    RealNumber maximum = *numbers;

    for (int i = 1; i < size; i++)
    {
        if (*(numbers + i) > maximum)
        {
            maximum = *(numbers + i);
        }
    }

    return maximum;
}

double RealNumberArray::average() const
{
    double sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += (*(numbers + i)).getNumber();
    }

    return sum / size;
}