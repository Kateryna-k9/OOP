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

void writeFromKeyboard(const char* filename) {

    ofstream file(filename, ios::binary);

    if (!file) {
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

        file.write((char*)&c, sizeof(Component));
    }

    file.close();

    cout << "Data written to file!\n";
}

void writeRandom(const char* filename) {

    ofstream file(filename, ios::binary);

    if (!file) {
        cout << "File error!\n";
        return;
    }

    int n = rand() % 5 + 3;

    Component c;

    for (int i = 0; i < n; i++) {

        randomFill(c);

        file.write((char*)&c, sizeof(Component));
    }

    file.close();

    cout << "Random data written!\n";
}

void addToBeginning(const char* filename) {

    ifstream fin(filename, ios::binary);

    ofstream temp("temp.dat", ios::binary);

    Component c;

    cout << "Enter new record:\n";
    input(c);

    temp.write((char*)&c, sizeof(Component));

    while (fin.read((char*)&c, sizeof(Component))) {

        temp.write((char*)&c, sizeof(Component));
    }

    fin.close();
    temp.close();

    remove(filename);
    rename("temp.dat", filename);

    cout << "Record added to beginning!\n";
}

void addToEnd(const char* filename) {

    ofstream file(filename, ios::binary | ios::app);

    if (!file) {
        cout << "File error!\n";
        return;
    }

    Component c;

    cout << "Enter new record:\n";

    input(c);

    file.write((char*)&c, sizeof(Component));

    file.close();

    cout << "Record added to end!\n";
}

void printComponent(Component c) {

    cout << setw(12) << c.name
        << setw(8) << c.type
        << setw(12) << c.value
        << setw(10) << c.quantity
        << endl;
}

void printOne(const char* filename) {

    ifstream file(filename, ios::binary);

    if (!file) {
        cout << "File error!\n";
        return;
    }

    int number;

    cout << "Enter record number: ";
    cin >> number;

    Component c;

    file.seekg((number - 1) * sizeof(Component), ios::beg);

    if (file.read((char*)&c, sizeof(Component))) {

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

    file.close();
}

void printAll(const char* filename) {

    ifstream file(filename, ios::binary);

    if (!file) {
        cout << "File error!\n";
        return;
    }

    Component c;

    cout << "\n---------------------------------------------\n";

    cout << setw(12) << "Name"
        << setw(8) << "Type"
        << setw(12) << "Value"
        << setw(10) << "Qty" << endl;

    while (file.read((char*)&c, sizeof(Component))) {

        printComponent(c);
    }

    file.close();
}

void editRecord(const char* filename) {

    fstream file(filename, ios::binary | ios::in | ios::out);

    if (!file) {
        cout << "File error!\n";
        return;
    }

    int number;

    cout << "Enter record number: ";
    cin >> number;

    Component c;

    file.seekg((number - 1) * sizeof(Component), ios::beg);

    if (!file.read((char*)&c, sizeof(Component))) {

        cout << "Record not found!\n";

        file.close();

        return;
    }

    cout << "\nCurrent record:\n";

    printComponent(c);

    cout << "\nEnter new data:\n";

    input(c);

    file.seekp((number - 1) * sizeof(Component), ios::beg);

    file.write((char*)&c, sizeof(Component));

    file.close();

    cout << "Record changed!\n";
}