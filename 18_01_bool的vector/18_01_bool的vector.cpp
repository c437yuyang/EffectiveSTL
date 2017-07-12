// 18_01_bool的vector.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<bool> v = {true,false,false,false ,false,true,false,true,false }; //9个，capacity,32
	cout << sizeof(v) << endl; //虽然从size来看貌似并不是装的bit
	cout << sizeof(bool) << endl;
	//bool *a = &v[0]; //报错，不能编译，vector<bool>不允许使用C风格，装的是bit不是bool
	//bool *a1 = &v[1];

	vector<int> v1 = { 1,2,3 }; //其他类型(比如int)类型就可以
	int *a2 = &v1[0];

    return 0;
}

