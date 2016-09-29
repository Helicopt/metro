#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Metro/subway.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestInitial)
		{
			subway::subway* a = new subway::subway(string("beijing-subway.txt"));
			//Assert::AreEqual(a->initialize(), false);
			free(a);
		}

		TEST_METHOD(TestEmpty)
		{
			try {
				subway::subway* a = new subway::subway(string("test"));
				free(a);
			}
			catch (subway::Exc e) {
				return;
			}
			Assert::AreEqual(true, false);
		}

		TEST_METHOD(TestBadFile)
		{
			try {
				subway::subway* a = new subway::subway(string("0"));
				free(a);
				a = new subway::subway(string("1"));
				free(a);
				a = new subway::subway(string("2"));
				free(a);
				a = new subway::subway(string("3"));
				free(a);
				a = new subway::subway(string("4"));
				free(a);
				Assert::AreEqual(true, false);
			}
			catch (subway::Exc e) {
				
			}
		}

		TEST_METHOD(TestA0)
		{
			//subway::subway* a = new subway::subway(string("beijing-subway.txt"));
			////Assert::AreEqual(a->initialize(), false);
			////a->do_a("1");
			//freopen("D:/Program Files (x86)/Microsoft Visual Studio 14.0/workspace/subway-master/testResult.txt", "w", stdout);
			//freopen("D:/Program Files (x86)/Microsoft Visual Studio 14.0/workspace/subway-master/testErr.txt", "w", stderr);
			//printf("start\n");
			//a->do_a("Öª´ºÂ·");
			//printf("test end\n");
			//Assert::AreEqual(1, 0);
			////while (1);
		}

	};
}