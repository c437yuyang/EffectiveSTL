// 03_�������������Ŀ���_ָ�뿽��û�зָ�.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//����������õ�ʱ�����ǰ��վ�̬��������ִ�е�ʱ��ʵ�ж�̬��
	//����������������װ���Ǹ����ָ�룬ֻ�ܵ������еķ���

	vec1[1]->printInfo(); //derived,��Ȼvec����װ���Ǹ���ָ�룬��������ָ���С��һ�������Բ�����ַָ
	vec1[2]->printInfo();//derived
	cout << typeid(vec1).name() << endl;
	cout << typeid(vec1[0]).name() << endl; //����widget *
	cout << typeid(vec1[1]).name() << endl; //widget *

    return 0;
}

