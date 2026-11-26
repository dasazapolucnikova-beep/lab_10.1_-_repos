#include "student .h"
#include <iostream>
#include <iomanip>

using namespace std;

void Create(Student* s, const int N) {
    int spec;
    for (int i = 0; i < N; i++) {
        cout << "Student # " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();

        cout << " surname: ";
        getline(cin, s[i].surname);

        do {
            cout << " course (1-6): ";
            cin >> s[i].course;
        } while (s[i].course < 1 || s[i].course > 6);

        do {
            cout << " specialty (0 - CS, 1 - Informatics, 2 - Math & Econ, 3 - Phys & Inf, 4 - Labor Training): ";
            cin >> spec;
        } while (spec < 0 || spec > 4);
        s[i].spec = (Specialnist)spec;

        do {
            cout << " physics grade (2-5): ";
            cin >> s[i].physics;
        } while (s[i].physics < 2 || s[i].physics > 5);

        do {
            cout << " math grade (2-5): ";
            cin >> s[i].math;
        } while (s[i].math < 2 || s[i].math > 5);

        switch (s[i].spec) {
        case CS:
            do {
                cout << " programming grade (2-5): ";
                cin >> s[i].programming;
            } while (s[i].programming < 2 || s[i].programming > 5);
            break;
        case INF:
            do {
                cout << " numerical methods grade (2-5): ";
                cin >> s[i].numerical_methods;
            } while (s[i].numerical_methods < 2 || s[i].numerical_methods > 5);
            break;
        case ME:
        case PI:
        case LT:
            do {
                cout << " pedagogy grade (2-5): ";
                cin >> s[i].pedagogy;
            } while (s[i].pedagogy < 2 || s[i].pedagogy > 5);
            break;
        }
        cout << endl;
    }
}

void Print(const Student* s, const int N) {
    string specStr[] = { "Computer Science", "Informatics", "Math & Economics", "Physics & Informatics", "Labor Training" };

    cout << "=======================================================================================================================" << endl;
    cout << "| #  | Surname       | Crse | Specialty               | Physics | Math       | Program.   | Num. Meth. | Pedagogy   |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(2) << right << i + 1 << " ";
        cout << "| " << setw(13) << left << s[i].surname;
        cout << "| " << setw(4) << right << s[i].course << " ";
        cout << "| " << setw(23) << left << specStr[s[i].spec] << " ";
        cout << "| " << setw(7) << right << s[i].physics << " ";
        cout << "| " << setw(10) << right << s[i].math << " ";

        switch (s[i].spec) {
        case CS:
            cout << "| " << setw(10) << right << s[i].programming << " "
                << "| " << setw(10) << right << " " << " "
                << "| " << setw(10) << right << " " << " |" << endl;
            break;
        case INF:
            cout << "| " << setw(10) << right << " " << " "
                << "| " << setw(10) << right << s[i].numerical_methods << " "
                << "| " << setw(10) << right << " " << " |" << endl;
            break;
        case ME:
        case PI:
        case LT:
            cout << "| " << setw(10) << right << " " << " "
                << "| " << setw(10) << right << " " << " "
                << "| " << setw(10) << right << s[i].pedagogy << " |" << endl;
            break;
        }
    }
    cout << "=======================================================================================================================" << endl;
    cout << endl;
}

// 1. Обчислення кількості оцінок «добре» (4) з кожного предмету
void CountGoodGrades(const Student* s, const int N, int& goodPhys, int& goodMath, int& goodProg, int& goodNumMeth, int& goodPed) {
    goodPhys = 0;
    goodMath = 0;
    goodProg = 0;
    goodNumMeth = 0;
    goodPed = 0;

    for (int i = 0; i < N; i++) {
        if (s[i].physics == 4)
            goodPhys++;
        if (s[i].math == 4)
            goodMath++;

        switch (s[i].spec) {
        case CS:
            if (s[i].programming == 4)
                goodProg++;
            break;
        case INF:
            if (s[i].numerical_methods == 4)
                goodNumMeth++;
            break;
        case ME:
        case PI:
        case LT:
            if (s[i].pedagogy == 4)
                goodPed++;
            break;
        }
    }
}

// 2. Обчислення проценту студентів, які отримали і з фізики і з математики оцінку «5»
double CalcPhysAndMath5Percent(const Student* s, const int N) {
    if (N <= 0)
        return 0.0;

    int count5 = 0;
    for (int i = 0; i < N; i++) {
        if (s[i].physics == 5 && s[i].math == 5)
            count5++;
    }
    return 100.0 * count5 / N;
}