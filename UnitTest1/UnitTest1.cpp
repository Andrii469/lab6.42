#include "pch.h"
#include "CppUnitTest.h"
#include "../Project6.4(2)/Source.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64
{
    TEST_CLASS(UnitTest64)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            int t;
            const int SIZE = 5;
            int a[SIZE] = { 1,2,3,4,5 };
            t = max_r(a, SIZE, 0, a[0]);
            Assert::AreEqual(t, 5);
        }
    };
}