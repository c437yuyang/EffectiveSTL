// 21_01_ָ���Ƚ�Ϊless_eual.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

struct Less_Equal
{
	template<class T>
	constexpr bool operator()(const T& _Left, const T& _Right) const
	{	// apply operator< to operands
		return (_Left <= _Right);
	}
};


int main()
{



	set<int, Less_Equal> v = {
		10
	};
	v.insert(10);



	//����ָ����һ�����ܳ��ִ����С�ڵ��ڱȽ�����debugģʽ��ֱ�ӱ�Invalid Operator
	// release�������У����Կ���������set�Ķ����ˣ��������10
	for_each(v.begin(), v.end(), [](int i) {cout << i << endl; });




	system("pause");
	return 0;
}

