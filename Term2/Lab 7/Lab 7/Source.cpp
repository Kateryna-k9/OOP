#include "Header.h"
#include <iomanip>
#include <ctime>

void input(Component& c) {

    cout << "Name: ";
    cin >> c.name;

    cout << "Type (R/C): ";
    cin >> c.type;

    cout << "Value: ";
    cin >> c.value;

    cout << "Quantity: ";
    cin >> c.quantity;
}

void randomFill(Component& c) {

    c.name[0] = 'R';
    c.name[1] = 'T';
    c.name[2] = '-';
    c.name[3] = rand() % 10 + '0';
    c.name[4] = rand() % 10 + '0';
    c.name[5] = '\0';

    c.type = (rand() % 2 == 0) ? 'R' : 'C';
    c.value = rand() % 1000 + 1;
    c.quantity = rand() % 20 + 1;
}

void writeFromKeyboard() {

    FILE* file;

    file = fopen("components.dat", "wb");

    if (file == NULL) {

        cout << "File error!\n";
        return;
    }

    int n;

    cout << "Number of elements: ";
    cin >> n;

    Component c;

    for (int i = 0; i < n; i++) {

        cout << "\nElement " << i + 1 << endl;

        input(c);

        fwrite(&c, sizeof(Component), 1, file);
    }

    fclose(file);

    cout << "Data written to file!\n";
}

void writeRandom() {

    FILE* file;

    file = fopen("components.dat", "wb");

    if (file == NULL) {

        cout << "File error!\n";
        return;
    }

    int n = rand() % 5 + 3;

    Component c;

    for (int i = 0; i < n; i++) {

        randomFill(c);

        fwrite(&c, sizeof(Component), 1, file);
    }

    fclose(file);

    cout << "Random data written!\n";
}

void addToBeginning() {

    FILE* file;
    FILE* temp;

    file = fopen("components.dat", "rb");
    temp = fopen("temp.dat", "wb");

    Component c;

    cout << "Enter new record:\n";

    input(c);

    fwrite(&c, sizeof(Component), 1, temp);

    while (fread(&c, sizeof(Component), 1, file)) {

        fwrite(&c, sizeof(Component), 1, temp);
    }

    fclose(file);
    fclose(temp);

    remove("components.dat");
    rename("temp.dat", "components.dat");

    cout << "Record added to beginning!\n";
}

void addToEnd() {

    FILE* file;

    file = fopen("components.dat", "ab");

    if (file == NULL) {

        cout << "File error!\n";
        return;
    }

    Component c;

    cout << "Enter new record:\n";

    input(c);

    fwrite(&c, sizeof(Component), 1, file);

    fclose(file);

    cout << "Record added to end!\n";
}

void printComponent(Component c) {

    cout << setw(12) << c.name
        << setw(8) << c.type
        << setw(12) << c.value
        << setw(10) << c.quantity
        << endl;
}

void printOne() {

    FILE* file;

    file = fopen("components.dat", "rb");

    if (file == NULL) {

        cout << "File error!\n";
        return;
    }

    int number;

    cout << "Enter record number: ";
    cin >> number;

    Component c;

    fseek(file, (number - 1) * sizeof(Component), SEEK_SET);

    if (fread(&c, sizeof(Component), 1, file)) {

        cout << "\n---------------------------------------------\n";

        cout << setw(12) << "Name"
            << setw(8) << "Type"
            << setw(12) << "Value"
            << setw(10) << "Qty" << endl;

        printComponent(c);
    }
    else {

        cout << "Record not found!\n";
    }

    fclose(file);
}

void printAll() {

    FILE* file;

    file = fopen("components.dat", "rb");

    if (file == NULL) {

        cout << "File error!\n";
        return;
    }

    Component c;

    cout << "\n---------------------------------------------\n";

    cout << setw(12) << "Name"
        << setw(8) << "Type"
        << setw(12) << "Value"
        << setw(10) << "Qty" << endl;

    while (fread(&c, sizeof(Component), 1, file)) {

        printComponent(c);
    }

    fclose(file);
}

void editRecord() {

    FILE* file;

    file = fopen("components.dat", "rb+");

    if (file == NULL) {

        cout << "File error!\n";
        return;
    }

    int number;

    cout << "Enter record number: ";
    cin >> number;

    Component c;

    fseek(file, (number - 1) * sizeof(Component), SEEK_SET);

    if (!fread(&c, sizeof(Component), 1, file)) {

        cout << "Record not found!\n";

        fclose(file);

        return;
    }

    cout << "\nCurrent record:\n";

    printComponent(c);

    cout << "\nEnter new data:\n";

    input(c);

    fseek(file, (number - 1) * sizeof(Component), SEEK_SET);

    fwrite(&c, sizeof(Component), 1, file);

    fclose(file);

    cout << "Record changed!\n";
}