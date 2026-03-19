// Lab 1(add7).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main() {
    while (true) {
        int n;
        cout << "\nEnter the number -> ";
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
    }
    return 0;
}