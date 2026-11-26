#pragma once
#include <string>

using namespace std;

enum Specialnist { CS, INF, ME, PI, LT };

struct Student {
    string surname;
    unsigned course;
    Specialnist spec;
    int physics;
    int math;
    union {
        int programming;
        int numerical_methods;
        int pedagogy;
    };
};

void Create(Student* s, const int N);
void Print(const Student* s, const int N);
void CountGoodGrades(const Student* s, const int N, int& goodPhys, int& goodMath, int& goodProg, int& goodNumMeth, int& goodPed);
double CalcPhysAndMath5Percent(const Student* s, const int N);