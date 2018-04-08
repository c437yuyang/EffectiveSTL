// 32_istream_iterator和accumulate.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iterator>
#include <set>
using namespace std;

int main()
{
	//accumulate本来是一个累加算法，但是改写谓词可以实现各种功能

	//求数组中字符串总长度
	set<string> s = { "aa","abc","defg" };
	int lengthSum = accumulate(s.begin(), s.end(), 0, [](int sum, const string&s) { return sum + s.size(); });

	set<float> s1 = { 2.0f,3.1f };
	float product = accumulate(s1.begin(), s1.end(), 1.0f, [](float product, const float f) { return product * f; });

	//其实就是foreach也可以，还更好用个人觉得
	//for_each版本
	float product1 = 1.0f;
	for_each(s1.begin(), s1.end(), [&product1](float f) { product1 *= f; });

	//字符串连接
	string strAll = "";
	for_each(s.begin(), s.end(), [&strAll](const string &val) { strAll += val; });


	system("pause");
	return 0;
}

