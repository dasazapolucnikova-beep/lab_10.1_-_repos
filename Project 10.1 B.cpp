#include <iostream>
#include <iomanip>
#include "student .h"

using namespace std;

int main() {
    int N;
    do {
        cout << "Enter the number of students N (> 0): ";
        cin >> N;
    } while (N <= 0);

    Student* s = new Student[N];
    bool isDataEntered = false;
    int menuItem;

    do {
        cout << endl << endl;
        cout << "Select an action:" << endl;
        cout << " [1] - enter data from keyboard" << endl;
        cout << " [2] - print data on screen" << endl;
        cout << " [3] - count 'good' (4) grades for each subject" << endl;
        cout << " [4] - calculate percentage of students with '5' in both Physics and Math" << endl;
        cout << " [0] - exit program" << endl << endl;
        cout << "Enter choice: ";
        cin >> menuItem;
        cout << endl;

        switch (menuItem) {
        case 1:
            Create(s, N);
            isDataEntered = true;
            break;
        case 2:
            if (isDataEntered)
                Print(s, N);
            else
                cout << "Please enter data first (option 1)!" << endl;
            break;
        case 3:
            if (isDataEntered) {
                int goodPhys, goodMath, goodProg, goodNumMeth, goodPed;
                CountGoodGrades(s, N, goodPhys, goodMath, goodProg, goodNumMeth, goodPed);
                cout << "Number of 'good' (4) grades:" << endl;
                cout << " - Physics:           " << goodPhys << endl;
                cout << " - Math:              " << goodMath << endl;
                cout << " - Programming:       " << goodProg << endl;
                cout << " - Numerical Methods: " << goodNumMeth << endl;
                cout << " - Pedagogy:          " << goodPed << endl;
            }
            else {
                cout << "Please enter data first (option 1)!" << endl;
            }
            break;
        case 4:
            if (isDataEntered) {
                double percent = CalcPhysAndMath5Percent(s, N);
                cout << "Percentage of students with '5' in both Physics and Math: "
                    << fixed << setprecision(2) << percent << "%" << endl;
            }
            else {
                cout << "Please enter data first (option 1)!" << endl;
            }
            break;
        case 0:
            break;
        default:
            cout << "Invalid input! Please enter a menu item number." << endl;
        }
    } while (menuItem != 0);

    delete[] s;
    return 0;
}