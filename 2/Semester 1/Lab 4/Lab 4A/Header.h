
#pragma once

class DynamicArray
{
private:
    int* data;
    int size;

public:
    DynamicArray();
    ~DynamicArray();

    void createArray(int newSize);
    void setElement(int index, int value);

    int getElement(int index) const;
    int getSize() const;
    int getSum() const;

    bool loadFromFile(const char* filename);
    bool saveToFile(const char* filename) const;
    bool appendSumToFile(const char* filename) const;
};
