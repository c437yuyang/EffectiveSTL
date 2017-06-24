// 06_函数声明的不同方式.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int f(double d);//1
int f(double (d));//2
int f(double);//3
int f(double d) //实现1 和 3
{
	cout << d << endl;
}
//int f(double (d)) //实现2，报错，1,2,3都是同一个函数的不同声明，参数为double
//{
//	cout << d << endl;
//
//} 


int g(double(*pf));
int g(double pf());
int g(double ()); //这三种声明等价，都是有一个返回double类型的函数指针的参数

int main()
{
	f(10);


	system("pause");
    return 0;
}

