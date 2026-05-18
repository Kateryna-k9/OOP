#include "Header.h"

int main() {

    int choice;

    do {

        cout << "\n========= MENU =========\n";

        cout << "1. Input from keyboard and write to file\n";
        cout << "2. Random input and write to file\n";
        cout << "3. Add record to beginning\n";
        cout << "4. Add record to end\n";
        cout << "5. Print one record\n";
        cout << "6. Print all records\n";
        cout << "7. Change record\n";
        cout << "8. Exit\n";

        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            writeFromKeyboard();
            break;

        case 2:
            writeRandom();
            break;

        case 3:
            addToBeginning();
            break;

        case 4:
            addToEnd();
            break;

        case 5:
            printOne();
            break;

        case 6:
            printAll();
            break;

        case 7:
            editRecord();
            break;

        case 8:
            cout << "Exit...\n";
            break;

        default:
            cout << "Wrong choice!\n";
        }

    } while (choice != 8);

    return 0;
}