// 18_01_bool的vector.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<bool> v = {true,false};

	//bool *a = &v[0]; //报错，不能编译，vector<bool>不允许使用C风格，装的是bit不是bool
	//bool *a1 = &v[1];

	vector<int> v1 = { 1,2,3 };
	int *a2 = &v1[0];

    return 0;
}

