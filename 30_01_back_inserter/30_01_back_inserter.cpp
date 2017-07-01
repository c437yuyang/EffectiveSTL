// 30_01_back_inserter.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int doSomthing(int x) {
	return x*x;
}

int main()
{


	vector<int> v = { 1,2,3,4,5 };
	vector<int> results = { 2,3,4,5,6 };


	//transform(v.begin(), v.end(), results.end(), doSomthing); //运行时错误，超出下标，因为.end本身是没有值的

	transform(v.begin(), v.end(), back_inserter(results), doSomthing); //会在任何有push_back的容器上调用Push_back
	//list,deque,string也可以

	//front_inserter只能在deque和list用

	transform(v.begin(), v.end(), inserter(results, results.begin() + results.size() / 2), doSomthing);

	//还有inserter，连续容器如vector在调用之前，
	//最好先reverse（reverse只是容量变大，但是size没变，所以还是必须inserter，而不能直接更改那个位置），但是还是得忍受移动的代价

	for_each(results.begin(), results.end(), [](int x) {cout << x << " "; });

	return 0;
}

