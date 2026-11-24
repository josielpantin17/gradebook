#include <iostream>
#include "student.h"
using namespace std;

int main()
{
    Student s;
    char again;

    do
    {
        cout << "\n===== STUDENT GRADEBOOK =====" << endl;

        collectGrades(s);

        displaySummary(s);

        cout << "\nProcess another student? (Y/N): ";
        cin >> again;

        while (cin.fail() && (again != 'Y' && again != 'y' &&
                              again != 'N' && again != 'n'))
        {
            cout << "ERROR! Enter Y or N: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> again;
        }

        while (again != 'Y' && again != 'y' &&
               again != 'N' && again != 'n')
        {
            cout << "ERROR! Enter Y or N: ";
            cin >> again;
        }

        cin.ignore(1000, '\n');

    } while (again == 'Y' || again == 'y');

    cout << "\nThank you for using the Gradebook!" << endl;

    return 0;
}
