// Lab 5(b).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int SIZE = 10;   // ¬сього 10 м≥сць
    bool seats[SIZE];      // ћасив зайн€тост≥ м≥сць (true = 1, false = 0)

    while (true) {
        // ѕочаткове очищенн€ (ус≥ м≥сц€ в≥льн≥)
        for (int i = 0; i < SIZE; i++) {
            seats[i] = false;
        }

        int filled = 0; // к≥льк≥сть зайн€тих м≥сць

        cout << "=== —истема бронюванн€ м≥сць у л≥таку ===\n";
        cout << "(1-5) Ч м≥сц€ дл€ тих, хто палить\n";
        cout << "(6-10) Ч м≥сц€ дл€ тих, хто не палить\n\n";

        while (filled < SIZE) {
            string answer;
            cout << "ѕалите? (так / н≥): ";
            cin >> answer;

            // нормал≥зуЇмо в≥дпов≥дь
            for (char& c : answer) c = tolower(c);

            int start, end;
            if (answer == "так") {
                start = 0; end = 5; // м≥сц€ 1Ц5
            }
            else if (answer == "н≥") {
                start = 5; end = 10; // м≥сц€ 6Ц10
            }
            else {
                cout << "Ќев≥рна в≥дпов≥дь! ¬вед≥ть 'так' або 'н≥'.\n";
                continue;
            }

            // перев≥р€Їмо на€вн≥сть в≥льних м≥сць у сектор≥
            bool freeSeat = false;
            for (int i = start; i < end; i++) {
                if (!seats[i]) {
                    seats[i] = true;
                    filled++;
                    cout << "¬аше м≥сце заброньовано: є" << i + 1 << "\n";
                    freeSeat = true;
                    break;
                }
            }

            if (!freeSeat) {
                cout << "” цьому сектор≥ м≥сць немаЇ! —пробуйте ≥нший.\n";
            }

            // показуЇмо в≥зуальний стан м≥сць
            cout << "ѕоточний стан м≥сць:\n";
            for (int i = 0; i < SIZE; i++) {
                cout << (seats[i] ? 1 : 0) << " ";
            }
            cout << "\n--------------------------\n";
        }

        // €кщо вс≥ м≥сц€ заповнен≥
        cout << "\n”с≥ м≥сц€ зайн€т≥!\n";
        cout << "ЅажаЇте почати нове бронюванн€? (так / н≥): ";
        string again;
        cin >> again;

        for (char& c : again) c = tolower(c);
        if (again != "так") {
            cout << "ƒ€куЇмо! √арного дн€!\n";
            break;
        }

        cout << "\n\n=== Ќовий рейс ===\n";
    }

    return 0;
}
