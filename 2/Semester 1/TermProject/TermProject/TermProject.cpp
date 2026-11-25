
#include <iostream>
#include "Expert.h"

using namespace std;

int main()
{
    Expert expert1("Development", "Website",
        "Ivanenko", "Petrenko Petro",
        "Programming", "Consulting");

    cout << "=== OUTPUT OPERATOR << ===" << endl;

    cout << expert1;

    cout << "\n=== INPUT OPERATOR >> ===" << endl;

    Expert expert2;

    cout << "Enter the following data, one per line:" << endl;
    cout << "1. Team name" << endl;
    cout << "2. Project" << endl;
    cout << "3. Leader" << endl;
    cout << "4. Full name" << endl;
    cout << "5. Specialization" << endl;
    cout << "6. Functions" << endl;

    cout << "\nEnter data:" << endl;

    if (cin >> expert2)
    {
        cout << "\n=== NEW EXPERT ===" << endl;
        cout << expert2;

        cout << "\n=== CHECK SPECIALIZATION ===" << endl;

        if (expert2.hasSpecialization("Databases"))
            cout << "Expert with Databases found!" << endl;
        else
            cout << "Expert not found!" << endl;
    }
    else
    {
        cout << "Invalid input!" << endl;
    }

    return 0;
}
