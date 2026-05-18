#include "Header.h"

int main() {

    int mas1[SIZE] = { 5, 12, 7, 20, 3, 15, 8, 1, 10, 6 };

    int mas2[SIZE];

    writeToFile(mas1);

    copyFromFile(mas2);

    printArray(mas2);

    printFromFile();

    return 0;
}