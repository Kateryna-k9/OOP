#include "Header.h"

void writeToFile(int mas1[]) {

    FILE* f1;

    fopen_s(&f1, "f1.txt", "w");

    if (f1 == NULL) {

        cout << "Error opening f1!\n";
        return;
    }

    for (int i = 0; i < SIZE; i++) {

        fprintf(f1, "%d ", mas1[i]);
    }

    fclose(f1);

    cout << "Data written to f1.txt\n";
}

void copyFromFile(int mas2[]) {

    FILE* f1;
    FILE* f2;

    fopen_s(&f1, "f1.txt", "r");

    if (f1 == NULL) {

        cout << "Error opening f1 for reading!\n";
        return;
    }

    fopen_s(&f2, "f2.txt", "w");

    if (f2 == NULL) {

        cout << "Error opening f2!\n";

        fclose(f1);

        return;
    }

    for (int i = 0; i < SIZE; i++) {

        fscanf_s(f1, "%d", &mas2[i]);

        fprintf(f2, "%d ", mas2[i]);
    }

    fclose(f1);
    fclose(f2);

    cout << "Data copied to mas2 and f2.txt\n";
}

void printArray(int mas2[]) {

    cout << "\nArray mas2:\n";

    for (int i = 0; i < SIZE; i++) {

        cout << mas2[i] << " ";
    }

    cout << endl;
}

void printFromFile() {

    FILE* f2;

    fopen_s(&f2, "f2.txt", "r");

    if (f2 == NULL) {

        cout << "Error opening f2 for reading!\n";
        return;
    }

    int x;

    cout << "\nNumbers from f2:\n";

    while (fscanf_s(f2, "%d", &x) != EOF) {

        cout << x << " ";
    }

    cout << endl;

    fclose(f2);
}