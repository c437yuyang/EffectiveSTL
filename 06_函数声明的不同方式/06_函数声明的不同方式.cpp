// 06_���������Ĳ�ͬ��ʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
using namespace std;

int f(double d);//1
int f(double (d));//2
int f(double);//3
int f(double d) //ʵ��1��3
{
	cout << d << endl;
	return 1;
}
//int f(double (d)) //ʵ��2������1,2,3����ͬһ�������Ĳ�ͬ����������Ϊdouble
//{
//	cout << d << endl;
//} 

int g(double(*pf));
int g(double pf());
int g(double ()); //�����������ȼۣ�������һ������double���͵ĺ���ָ��Ĳ���
int g(double(*pf(int))); //����Ҳ���Դ�����

int main()
{
	f(10);

	ifstream dataFile("aa");
	//list<int> data(istream_iterator<int>(dataFile), istream_iterator<int>()); //������һ��������������һ����������Ϊ���ڱ���ǰ���������������
	list<int> data1((istream_iterator<int>(dataFile)), istream_iterator<int>()); //�������ź�Ҳ�Ϳ�����

	//���ԣ����鲻Ҫ�ڲ����ڵ���ʱ���������������룬�����ȹ������ٴ���
	istream_iterator<int> dataBegin(dataFile);
	istream_iterator<int> dataEnd; //���ﲻ�������ţ�Ĭ�Ϲ��캯���������ţ������ֳ������������ˡ�
	list<int> data1(dataBegin, dataEnd); //����������Ͳ�����������

	string str(10, 'c'); //�������������ȷ�ģ����� int 10, char 'c'����


	system("pause");
    return 0;
}

