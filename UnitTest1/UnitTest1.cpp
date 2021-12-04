#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab1\Lab1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		List lst;
		TEST_METHOD(Constructor_List)
		{
			Assert::IsTrue(lst.GetSize() == 0);
		}
		TEST_METHOD(Clear)
		{
			for (int i = 0; i < rand() % 10 + 1; i++)
			{
				lst.push_back(i);
			}
			lst.clear();
			Assert::IsTrue(lst.GetSize() == 0);
		}
		TEST_METHOD(Push_back)
		{
			int random = rand() % 10 + 1;
			for (int i = 0; i < random; i++)
			{
				lst.push_back(i);
			}
			for (int i = 0; i < random - 1; i++)
			{
				lst.pop_front();
			}
			Assert::IsTrue(lst.at(0) == random - 1);
		}
		TEST_METHOD(Push_front)
		{
			lst.push_front(1);
			lst.push_front(2);
			lst.pop_back();
			Assert::IsTrue(lst.at(0) == 2);
		}
		TEST_METHOD(Pop_back)
		{
			int c_Size = lst.GetSize();
			lst.pop_back();
			Assert::IsTrue(lst.GetSize() == c_Size);
			lst.push_back(1);
			lst.push_back(2);
			lst.pop_back();
			Assert::IsTrue(lst.at(0) == 1);
		}
		TEST_METHOD(Pop_front)
		{
			int c_Size = lst.GetSize();
			lst.pop_front();
			Assert::IsTrue(lst.GetSize() == c_Size);
			lst.push_back(1);
			lst.push_back(2);
			lst.pop_front();
			Assert::IsTrue(lst.at(0) == 2);
		}
		TEST_METHOD(Insert)
		{
			int c_Size = lst.GetSize();
			lst.insert(1, 10);
			lst.insert(-1, 10);
			Assert::IsTrue(lst.GetSize() == c_Size);
			lst.push_back(1);
			lst.push_back(2);
			lst.insert(1, 3);
			Assert::IsTrue(lst.at(1) == 3);
		}
		TEST_METHOD(At)
		{
			Assert::IsTrue(lst.at(-1) == -1);
			lst.push_back(1);
			Assert::IsTrue(lst.at(0) == 1);
			Assert::IsTrue(lst.at(1) == -1);
		}
		TEST_METHOD(Remove)
		{
			int c_Size = lst.GetSize();
			lst.remove(1);
			lst.remove(-1);
			Assert::IsTrue(lst.GetSize() == c_Size);
			lst.push_back(1);
			lst.remove(0);
			Assert::IsTrue(lst.GetSize() == 0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.remove(1);
			Assert::IsTrue(lst.at(0) == 1 && lst.at(1) == 3);
		}
		TEST_METHOD(Set)
		{
			int c_Size = lst.GetSize();
			lst.set(0, 1);
			lst.set(-1, 1);
			Assert::IsTrue(lst.GetSize() == c_Size);
			lst.push_back(1);
			lst.set(0, 2);
			Assert::IsTrue(lst.at(0) == 2);
		}
		TEST_METHOD(IsEmpty)
		{
			Assert::IsTrue(lst.isEmpty() == true);
			lst.push_back(1);
			Assert::IsTrue(lst.isEmpty() == false);
		}
		TEST_METHOD(Reverse)
		{
			int c_Size = lst.GetSize();
			lst.reverse();
			Assert::IsTrue(lst.GetSize() == c_Size);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.reverse();
			Assert::IsTrue(lst.at(0) == 3 && lst.at(1) == 2 && lst.at(2) == 1 && lst.GetSize() == 3);
		}

	};
}