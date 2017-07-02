// 07_foreach_delete.cpp : �������̨Ӧ�ó������ڵ㡣
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


//�汾2
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
	//for_each(v1.begin(), v1.end(), DeleteObject()); //�汾2
	for_each(v1.begin(), v1.end(), [](string *p) {delete p; }); //�汾3 lambda����ʽ
}



int main()
{
#ifdef _DEBUG
	CheckMemoryLeak;
#endif
	doSomething();
	vector<auto_ptr<int>> v; //��������ֹʹ��auto_ptr������,VS���Ա������ԣ�
	vector<unique_ptr<int>> v1;
	vector<shared_ptr<int>> v2;

    return 0;
}
