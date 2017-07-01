// 31_各种sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Widget {
public:
	Widget(int i) :age(i) {}
	int age;

};

int main()
{

	vector<Widget> v;
	for (int i = 20; i != 0; --i)
	{
		v.push_back(rand()%20);
	}

	//partial_sort(v.begin(), v.begin() + 5, v.end(), //找出前5个，并且把前五个按顺序排列
	//	[](const Widget& lhs, const Widget& rhs) {return lhs.age < rhs.age; });


	//nth_element(v.begin(), v.begin() + 5, v.end(), //只找到前5个放在前面，但是对于这五个不管顺序
	//	[](const Widget& lhs, const Widget& rhs) {return lhs.age < rhs.age; });

	//stable_sort(); //当两个元素相同比较的时候，保持其原来位置

	//partition,找到所有满足条件的元素，移动到vector前段，
	//返回第一个不满足条件的元素,前面和后面的元素顺序都不一定,只看漫不满足条件
	vector<Widget>::iterator firstNotSatisfy = partition(v.begin(), v.end(), [](Widget i) {return i.age <= 5; });
	//stable_partition()的作用类似
	

	system("pause");
	return 0;
}

