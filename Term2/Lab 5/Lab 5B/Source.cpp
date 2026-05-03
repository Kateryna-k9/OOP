#include "Header.h"


void swapPtr(int* a, int* b, int* c) {
    int* min = a;
    int* max = a;

    if (*b < *min) min = b;
    if (*c < *min) min = c;

    if (*b > *max) max = b;
    if (*c > *max) max = c;

    int temp = *min;
    *min = *max;
    *max = temp;
}


void swapRef(int& a, int& b, int& c) {
    int* min = &a;
    int* max = &a;

    if (b < *min) min = &b;
    if (c < *min) min = &c;

    if (b > *max) max = &b;
    if (c > *max) max = &c;

    int temp = *min;
    *min = *max;
    *max = temp;
}