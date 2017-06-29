// 21_01_指定比较为less_eual.cpp : 定义控制台应用程序的入口点。
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



	//自行指定了一个可能出现错误的小于等于比较器，debug模式会直接报Invalid Operator
	// release可以运行，可以看到打破了set的定义了，输出两个10
	for_each(v.begin(), v.end(), [](int i) {cout << i << endl; });




	system("pause");
	return 0;
}

