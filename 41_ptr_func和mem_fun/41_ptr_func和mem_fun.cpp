// 41_ptr_func和mem_fun.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;


class Widget {

public:
	Widget() { m_wId++; m_Id = m_wId; }
	void printInfo() { cout << m_Id << endl; }
private:
	int m_Id;
	static int m_wId;
};

int Widget::m_wId = 0;

void test(Widget & w) { w.printInfo(); }

int main()
{
	vector<Widget> v1 = { Widget(),Widget(),Widget(), Widget(), Widget() };
	for_each(v1.begin(), v1.end(), test); //#1 非成员函数的调用方式
	for_each(v1.begin(), v1.end(), ptr_fun(test)); //#1 非成员函数的调用方式,加上ptr_fun也可以，多一些typedef是不会错的
	for_each(v1.begin(), v1.end(), mem_fun_ref(&Widget::printInfo)); //#3 成员函数,传递对象本身时用mem_fun_ref来适配成为mem_fun_ref_t对象

	vector<Widget*> pv1 = { new Widget(),new Widget(),new Widget(),new Widget(),new Widget() };
	//for_each(pv1.begin(), pv1.end(), &Widget::printInfo); //#2 报错，不能直接传递成员函数
	for_each(pv1.begin(), pv1.end(), mem_fun(&Widget::printInfo)); //#2 成员函数,传递指针的时候用mem_fun适配成mem_fun_t对象


	//lambda表达式都可以很容易的解决
	for_each(v1.begin(), v1.end(), [](Widget &w) {w.printInfo(); });
	for_each(pv1.begin(), pv1.end(), [](Widget *pw) {pw->printInfo(); });


    return 0;
}

