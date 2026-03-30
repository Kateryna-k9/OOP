#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

struct Component {
    string name;   
    char type;    
    double value;  
    int quantity;  
};

const int MAX = 100;


int input(Component arr[]) {
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
    return n;
}


int randomFill(Component arr[]) {
    int n;
    srand(time(0));

    n = rand() % 5 + 3; 

    for (int i = 0; i < n; i++) {
        arr[i].name = "RT-" + to_string(rand() % 100);
        arr[i].type = (rand() % 2 == 0) ? 'R' : 'C';
        arr[i].value = rand() % 10000 + 1;
        arr[i].quantity = rand() % 20 + 1;
    }

    cout << "Structure filled randomly!\n";
    return n;
}


void sortByName(Component arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].name > arr[j + 1].name) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "Sorted by name!\n";
}


void print(Component arr[], int n) {
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
}


int main() {
    Component arr[MAX];
    int n = 0;
    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1 - Input from keyboard\n";
        cout << "2 - Random fill\n";
        cout << "3 - Sort by name\n";
        cout << "4 - Print\n";
        cout << "5 - Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            n = input(arr);
            break;
        case 2:
            n = randomFill(arr);
            break;
        case 3:
            sortByName(arr, n);
            break;
        case 4:
            print(arr, n);
            break;
        case 5:
            cout << "Exit...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
// RT-11-24 R 100000 12
// RT-11-24 R 50000 10
// CGU-12K C 17.5 3