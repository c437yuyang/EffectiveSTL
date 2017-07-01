// 28_01_reverse_iterator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	vector<int> ivec1 = { 1,2,3,4,5 };

	vector<int>::reverse_iterator ri = ivec1.rbegin() + 3;

	cout << *ri << endl; //2，可以看到reverse_iterator的第一个元素是最后一个
	vector<int>::iterator it(ri.base()); //3,.base返回的是下一个元素
	cout << *it << endl;

	//对于insert,因为insert不接受reverse_iterator，可以直接在ri.base()插入就行了
	ivec1.insert(ri.base(), 99);
	cout << endl;
	for_each(ivec1.begin(), ivec1.end(), [](int i) {cout << i << " "; }); //1 2 99 3 4 5,正确，对于ri来说，是在ri指向的元素的前面插入了


	//现在希望删除2，是不能对it进行--操作来删除的，C和C++都规定不能直接修改函数返回的指针
	//ivec1.erase(--ri.base()); //运行时报错
	//ivec1.erase((++ri).base()); //effectiveSTL里面的正确做法，先让ri指向下一个，但是VS貌似行不通
	cout << endl;
	for_each(ivec1.begin(), ivec1.end(), [](int i) {cout << i << " "; }); //1 2 99 3 4 5,正确，对于ri来说，是在ri指向的元素的前面插入了


	vector<int> ivec2 = { 1,2,3 };
	auto it1 = ivec2.insert(ivec2.begin(), {99,21});
	cout << *it1 << endl; //返回指向第一个新元素的迭代器
	system("pause");

    return 0;
}

