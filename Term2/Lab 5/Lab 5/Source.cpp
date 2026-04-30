#include "Header.h"


void convertPointer(int* sec, int* hours, int* minutes)
{
    *hours = *sec / 3600;
    *minutes = (*sec % 3600) / 60;
}


void convertReference(int& sec, int& hours, int& minutes)
{
    hours = sec / 3600;
    minutes = (sec % 3600) / 60;
}