// 22_01_�����޸�set��multiset�ļ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {

public:
	Person(int a, int b) :ID(a), age(b) {}
	int ID;
	int age;


};
struct Less_Equal
{
	
	bool operator()(const Person& _Left, const Person& _Right) const
	{	// apply operator< to operands
		return (_Left.ID < _Right.ID);
	}
};

//struct PersonLess :binary_function<const &Person, const &Person, bool>
//{
//public:
//	bool operator()(const string *ps1, const string *ps2)const
//	{
//		return *ps1 < *ps2;
//	}
//};
class BadPredict:public unary_function


int main()
{

	set<int> s1 = { 1,2,3,4,5 };

	//*(s1.begin()) = 10;//�����޸�

	Person p1(1, 2);
	Person p2(2, 3);
	Person p3(0, 4);

	set<Person, Less_Equal> s2 = { p1,p2,p3 };

	for_each(s2.begin(), s2.end(), [](const Person &p) {cout << p.age << endl; });

	auto it = s2.begin();
	//(s2.begin())->age = 10; //�����޸ģ�����VS����ǽ�ֹ�˵ģ�set��iterator���ص�ֱ����const��

    return 0;
}

