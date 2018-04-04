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


//template <typename T>
//struct DeleteObject1 //其实不用去继承unary_function也可以
//{
//	void operator()(const T* ptr) const
//	{
//		delete ptr;
//	}
//};


//版本2，这种类型演绎使我们放弃DeleteObject的适配能力，但是我们并不需要在这里
//可以防止出现没有虚析构函数的时候的多态情况的错误删除
struct DeleteObject
{
	template <typename T> //当传入子类指针的时候，会自动类型推断成子类指针的类型，因此可以避免错误删除
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
	//for_each(v1.begin(), v1.end(), DeleteObject()); //版本2
	//for_each(v1.begin(), v1.end(), DeleteObject1<string>()); //版本2
	for_each(v1.begin(), v1.end(), [](string *p) {delete p; }); //版本3 lambda表达式
}



int main()
{
#ifdef _DEBUG
	CheckMemoryLeak;
#endif
	doSomething();
	vector<auto_ptr<int>> v; //编译器禁止使用auto_ptr的容器,VS测试表明可以？
	vector<unique_ptr<int>> v1;
	vector<shared_ptr<int>> v2; //其实doSomething不安全，因为其中任何一个指针可能已经被删除过了
	//这时，最好的做法是用shared_ptr来代替，不能用auto_ptr,因为auto_ptr拷贝总是会丢失对象这些问题。

    return 0;
}

