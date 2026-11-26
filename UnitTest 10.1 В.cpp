#include "pch.h"
#include "CppUnitTest.h"
#include "../Project 10.1 B/student .h"
#include "../Project 10.1 B/student .cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101B
{
    TEST_CLASS(UnitTest101B)
    {
    public:
        TEST_METHOD(TestVariant10B)
        {
            const int N = 4;
            Student s[N] = {
                { "Petrenko", 1, CS, 5, 5, { 4 } },  // Phys=5, Math=5, Prog=4
                { "Ivanenko", 2, INF, 4, 4, { 4 } }, // Phys=4, Math=4, NumMeth=4
                { "Sydorenko", 3, ME, 5, 5, { 5 } }, // Phys=5, Math=5, Ped=5
                { "Kovalenko", 1, PI, 3, 4, { 4 } }  // Phys=3, Math=4, Ped=4
            };

            int goodPhys, goodMath, goodProg, goodNumMeth, goodPed;
            CountGoodGrades(s, N, goodPhys, goodMath, goodProg, goodNumMeth, goodPed);

            Assert::AreEqual(1, goodPhys);
            Assert::AreEqual(2, goodMath);
            Assert::AreEqual(1, goodProg);
            Assert::AreEqual(1, goodNumMeth);
            Assert::AreEqual(1, goodPed);

            double actualPercent = CalcPhysAndMath5Percent(s, N);
            Assert::AreEqual(50.0, actualPercent, 1e-6);
        }
    };
}
