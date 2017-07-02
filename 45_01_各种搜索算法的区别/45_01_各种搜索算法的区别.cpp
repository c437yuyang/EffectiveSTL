// 45_01_各种搜索算法的区别.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v1 = { 1,2,3,3,3,4,5,6 };

	bool b = binary_search(v1.begin(), v1.end(), 4); //true //bianry_search只判断有没有

	//lower_bound和upper_bound分别返回所寻找元素的上下位置界限，其实就是equal_range的返回值

	auto it = equal_range(v1.begin(), v1.end(), 3); //equal_range返回一对迭代器，指向一个区间
	cout << it.first - v1.begin() << endl;
	cout << it.second - v1.begin() << endl;
	cout << distance(it.first, it.second) << endl;

	system("pause");
	return 0;
}

