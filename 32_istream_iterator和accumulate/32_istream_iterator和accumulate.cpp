// 32_istream_iterator��accumulate.cpp : �������̨Ӧ�ó������ڵ㡣
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
	set<string> s = { "aa","abc","defg" };
	int lengthSum = accumulate(s.begin(), s.end(), 0, [](int sum, const string&s) {return sum + s.size(); });

	set<float> s1 = { 2.0f,3.1f };
	
	float product = accumulate(s1.begin(), s1.end(), 1.0f, [](float product, const float f) {return product * f; });

	//for_each�汾
	float product1 = 1.0f;
	for_each(s1.begin(), s1.end(), [&product1](float f) {product1 *= f; });

	system("pause");
    return 0;
}

