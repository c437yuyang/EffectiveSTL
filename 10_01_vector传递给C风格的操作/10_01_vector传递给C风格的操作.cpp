// 10_01_vector传递给C风格的操作.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void printArr(const int *p, int size)
{
	for (int i=0;i!=size;++i)
	{
		cout << p[i] << endl;
	}
}

int main()
{
	vector<int> v = { 1,2,3,4,5 };


	printArr(&v[0], v.size()); //因为vector的存储在内存中也是连续的，所以可以正常使用，记得判断!v.empty
	//printArr(v.begin(), v.size()); //错误，iterator和指针是不一样的
	system("pause");
    return 0;
}

