#include <iostream>
using namespace std;

void rec() {
    int n;
    cout << "\nEnter the number (0 to exit) -> ";
    cin >> n;

    int i = 1, x = 0;
    for (int y = 0; y < n; y++) {
        cout << i << " ";
        x++;
        if (x == i) {
            i++;
            x = 0;
        }
    }
    if (n == 0) return;

    rec();
}

int main() {
    rec();
    return 0;
}