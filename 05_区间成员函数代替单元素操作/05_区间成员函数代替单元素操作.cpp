// 05_区间成员函数代替单元素操作.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{

	vector<int> vec1 = {1,2,3,4};
	vector<int> vec2 = { 5,6,7,8,9 };
	//使v1的内容和v2的后半段相同
	//1.assign
	vec1.assign(vec2.begin() + vec2.size() / 2, vec2.end());
	//2.insert
	vec1.clear();
	vec1.insert(vec1.end(), vec2.begin() + vec2.size() / 2, vec2.end());
	//3.copy(效率低，内部存在循环)
	vec1.clear();
	copy(vec2.begin() + vec2.size() / 2, vec2.end(), back_inserter(vec1));
	//4.手动单成员赋值
	vec1.clear();
	for (auto it=vec2.begin()+vec2.size()/2;it!=vec2.end();++it)
	{
		vec1.push_back(*it);
	}

	/*vec2.insert(vec2.begin() + 1, 1);*/ //insert是在指定位置之前插入

	//auto it = vec2.erase(vec2.begin() + 1, vec2.begin() + 3); //删除vec2.begin()+1和vec2.begin()+2
	//cout << *it << endl; //返回指向被删除的元素的下一个元素，vec2.begin()+3(删除之前)，这里就是8
	//vec2.erase(vec2.begin()+1); //删除单个元素
	system("pause");
    return 0;
}

