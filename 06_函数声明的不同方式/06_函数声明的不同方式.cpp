// 06_���������Ĳ�ͬ��ʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int f(double d);//1
int f(double (d));//2
int f(double);//3
int f(double d) //ʵ��1 �� 3
{
	cout << d << endl;
}
//int f(double (d)) //ʵ��2������1,2,3����ͬһ�������Ĳ�ͬ����������Ϊdouble
//{
//	cout << d << endl;
//
//} 


int g(double(*pf));
int g(double pf());
int g(double ()); //�����������ȼۣ�������һ������double���͵ĺ���ָ��Ĳ���

int main()
{
	f(10);


	system("pause");
    return 0;
}

