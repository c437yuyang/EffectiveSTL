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
	for_each(v1.begin(), v1.end(),test); //#1 非成员函数的调用方式

	vector<Widget*> pv1 = { new Widget(),new Widget(),new Widget(),new Widget(),new Widget() };
	for_each(pv1.begin(), pv1.end(), mem_fun(&Widget::printInfo)); //#2 成员函数的调用方式


	//lambda表达式都可以很容易的解决
	for_each(v1.begin(), v1.end(), [](Widget &w) {w.printInfo(); });
	for_each(pv1.begin(), pv1.end(), [](Widget *pw) {pw->printInfo(); });


    return 0;
}

