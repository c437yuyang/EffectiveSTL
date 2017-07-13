// 22_01_避免修改set和multiset的键.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <set>
#include <map>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

class Person {

public:
	Person(int a, int b) :ID(a), age(b) {}
	int ID;
	int age;


};
struct LessPersonId
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
//class BadPredict:public unary_function


int main()
{
	//map 存的是map<const K,V>,不让修改键值
	map<int, char> m1;
	m1.insert(make_pair<int, char>(1, 'c'));
	

	set<int> s1 = { 1,2,3,4,5 };

	//*(s1.begin()) = 10;//不能修改

	Person p1(1, 2);
	Person p2(2, 3);
	Person p3(0, 4);

	set<Person, LessPersonId> s2 = { p1,p2,p3 };

	for_each(s2.begin(), s2.end(), [](const Person &p) {cout << p.age << endl; });

	auto it = s2.begin();
	//(s2.begin())->age = 10; //不让修改，看来VS这边是禁止了的，可以看到set里的iterator返回的直接是const的

    return 0;
}

