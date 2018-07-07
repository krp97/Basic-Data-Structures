#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DArrayTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::cout << "test1";
		}
		TEST_METHOD(IKSDE)
		{
			std::cout << "test2";
		}
	};
}