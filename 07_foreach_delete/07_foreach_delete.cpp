// 07_foreach_delete.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
using namespace std;

//template <typename T>
//struct DeleteObject:public unary_function<const T*,void>
//{
//	void operator()(const T* ptr) const 
//	{
//		delete ptr;
//	}
//};


//版本2
struct DeleteObject
{
	template <typename T>
	void operator()(const T* ptr) const
	{
		delete ptr;
	}
};

void doSomething() 
{
	vector<string *> v1;
	for (int i=0;i!=10;++i)
	{
		v1.push_back(new string());
	}

	//for_each(v1.begin(), v1.end(), DeleteObject<string>());
	for_each(v1.begin(), v1.end(), DeleteObject()); //版本2
}



int main()
{
#ifdef _DEBUG
	CheckMemoryLeak;
#endif
	doSomething();
	vector<auto_ptr<int>> v; //编译器禁止使用auto_ptr的容器,VS测试表明可以？
	vector<unique_ptr<int>> v1;
	vector<shared_ptr<int>> v2;

    return 0;
}

