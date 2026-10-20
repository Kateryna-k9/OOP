// Lab 3A.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "HeaderA.h"
using namespace std;

int main()
{
    SOBAKA sobaka;
    SPANIEL spaniel;
    DOG dog;

    int choice;
    double newWeight;

    do
    {
        cout << "\n========== LAB 3A MENU ==========" << endl;
        cout << "1. Show SOBAKA" << endl;
        cout << "2. Show SPANIEL" << endl;
        cout << "3. Show DOG" << endl;
        cout << "4. Test golos()" << endl;
        cout << "5. Change weight" << endl;
        cout << "6. Test polymorphism" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n=== SOBAKA ===" << endl;
            sobaka.show();
            break;

        case 2:
            cout << "\n=== SPANIEL ===" << endl;
            spaniel.show();
            break;

        case 3:
            cout << "\n=== DOG ===" << endl;
            dog.show();
            break;

        case 4:
            cout << "\n=== GOLOS ===" << endl;

            cout << "SOBAKA: ";
            sobaka.golos();

            cout << "SPANIEL: ";
            spaniel.golos();

            cout << "DOG: ";
            dog.golos();
            break;

        case 5:
        {
            int dogChoice;

            cout << "\nChoose dog:" << endl;
            cout << "1. SOBAKA" << endl;
            cout << "2. SPANIEL" << endl;
            cout << "3. DOG" << endl;
            cout << "Your choice: ";
            cin >> dogChoice;

            cout << "Enter new weight (kg): ";
            cin >> newWeight;

            switch (dogChoice)
            {
            case 1:
                sobaka.setWeight(newWeight);
                break;

            case 2:
                spaniel.setWeight(newWeight);
                break;

            case 3:
                dog.setWeight(newWeight);
                break;

            default:
                cout << "Invalid dog!" << endl;
            }

            break;
        }

        case 6:
        {
            cout << "\n=== POLYMORPHISM ===" << endl;

            SOBAKA* ptr1 = &spaniel;
            SOBAKA* ptr2 = &dog;

            cout << "\nSOBAKA pointer -> SPANIEL:" << endl;
            ptr1->show();
            ptr1->golos();

            cout << "\nSOBAKA pointer -> DOG:" << endl;
            ptr2->show();
            ptr2->golos();

            break;
        }

        case 0:
            cout << "\nExiting program..." << endl;
            break;

        default:
            cout << "\nInvalid option!" << endl;
        }

    } while (choice != 0);

    return 0;
}
