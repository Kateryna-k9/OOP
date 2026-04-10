
#include "Header.h"
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
using namespace std;

#ifdef DEBUG
#define DEBUG_START cout << "Start: " << __DATE__ << " " << __TIME__ << endl;
#define DEBUG_END cout << "End: " << __FILE__ << " " << __FUNCTION__ << endl;
#else
#define DEBUG_START
#define DEBUG_END
#endif

int input(Component arr[]) {
    DEBUG_START

        int n;
    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nElement " << i + 1 << endl;

        cout << "Name: ";
        cin >> arr[i].name;

        cout << "Type (R/C): ";
        cin >> arr[i].type;

        cout << "Value: ";
        cin >> arr[i].value;

        cout << "Quantity: ";
        cin >> arr[i].quantity;
    }

    DEBUG_END
        return n;
}

int randomFill(Component arr[]) {
    DEBUG_START

        srand(time(0));
    int n = rand() % 5 + 3;

    for (int i = 0; i < n; i++) {
        arr[i].name = "RT-" + to_string(rand() % 100);
        arr[i].type = (rand() % 2 == 0) ? 'R' : 'C';
        arr[i].value = rand() % 10000 + 1;
        arr[i].quantity = rand() % 20 + 1;
    }

    cout << "Structure filled randomly!\n";

    DEBUG_END
        return n;
}

void sortByName(Component arr[], int n) {
    DEBUG_START

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j].name > arr[j + 1].name) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }

    cout << "Sorted by name!\n";

    DEBUG_END
}

void print(Component arr[], int n) {
    DEBUG_START

        cout << "\n---------------------------------------------\n";
    cout << setw(12) << "Name"
        << setw(8) << "Type"
        << setw(12) << "Value"
        << setw(10) << "Qty" << endl;

    for (int i = 0; i < n; i++) {
        cout << setw(12) << arr[i].name
            << setw(8) << arr[i].type
            << setw(12) << arr[i].value
            << setw(10) << arr[i].quantity << endl;
    }

    DEBUG_END
}