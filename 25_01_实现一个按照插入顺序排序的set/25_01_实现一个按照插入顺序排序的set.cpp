// 25_01_实现一个按照插入顺序排序的set.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "unordered_set.h"
#include <iostream>
using namespace std;

int main()
{
	using namespace yxp_utility;
	unordered_set<int> us;

	us.insert(10);
	us.insert(20);
	us.insert(20);
	us.insert(30);

	cout << us.size() << endl;

	cout << us[1] << endl;

	cout << us << endl;


    return 0;
}

