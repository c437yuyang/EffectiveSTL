// 03_避免容器里对象的拷贝_指针拷贝没有分割.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

class Widget {
public:
	virtual void printInfo() { cout << "base" << endl; }
	void printInfo1() {};

};

class SpecialWidget:public Widget {
public:
	virtual void printInfo() { cout << "Derived" << endl; }
	void printInfo2() {};
};

int main()
{
	Widget *pw = new Widget;
	SpecialWidget *psw = new SpecialWidget;
	Widget *pw1 = new SpecialWidget;

	vector<Widget*> vec1;
	vec1.push_back(pw);
	vec1.push_back(psw);
	vec1.push_back(pw1);

	vec1[0]->printInfo();
	vec1[0]->printInfo1(); 
	//容器里面调用的时候，先是按照静态类型来，执行的时候，实行动态绑定
	//所以现在容器里面装的是父类的指针，只能调父类有的方法

	vec1[1]->printInfo(); //derived,虽然vec里面装的是父类指针，但是所有指针大小都一样，所以不会出现分割？
	vec1[2]->printInfo();//derived
	cout << typeid(vec1).name() << endl;
	cout << typeid(vec1[0]).name() << endl; //都是widget *
	cout << typeid(vec1[1]).name() << endl; //widget *

    return 0;
}

