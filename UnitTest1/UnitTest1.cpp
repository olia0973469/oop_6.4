#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "../oop_6.4/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			vector<int> T(5);
			for (int i = 0; i < 5; i++) {
				Assert::AreEqual(0, T[i]);
			}
		}
	};
}
