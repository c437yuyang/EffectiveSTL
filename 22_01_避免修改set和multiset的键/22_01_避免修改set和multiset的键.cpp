// 22_01_�����޸�set��multiset�ļ�.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//map �����map<const K,V>,�����޸ļ�ֵ
	map<int, char> m1;
	m1.insert(make_pair<int, char>(1, 'c'));
	

	set<int> s1 = { 1,2,3,4,5 };

	//*(s1.begin()) = 10;//�����޸�

	Person p1(1, 2);
	Person p2(2, 3);
	Person p3(0, 4);

	set<Person, LessPersonId> s2 = { p1,p2,p3 };

	for_each(s2.begin(), s2.end(), [](const Person &p) {cout << p.age << endl; });

	auto it = s2.begin();
	//(s2.begin())->age = 10; //�����޸ģ�����VS����ǽ�ֹ�˵ģ����Կ���set���iterator���ص�ֱ����const��

    return 0;
}

