
#pragma once

class DynamicArray
{
private:
    int* data;
    int size;

public:
    DynamicArray();
    ~DynamicArray();

    DynamicArray(const DynamicArray& other) = delete;
    DynamicArray& operator=(const DynamicArray& other) = delete;

    void createArray(int newSize);
    void setElement(int index, int value);

    int getElement(int index) const;
    int getSize() const;
    int getSum() const;

    void saveToFile(const char* filename) const;
    void appendSumToFile(const char* filename) const;
};
