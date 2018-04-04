// 06_函数声明的不同方式.cpp : 定义控制台应用程序的入口点。
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
int f(double d) //实现1和3
{
	cout << d << endl;
	return 1;
}
//int f(double (d)) //实现2，报错，1,2,3都是同一个函数的不同声明，参数为double
//{
//	cout << d << endl;
//} 

int g(double(*pf));
int g(double pf());
int g(double ()); //这三种声明等价，都是有一个返回double类型的函数指针的参数
int g(double(*pf(int))); //里面也可以带参数

int main()
{
	f(10);

	ifstream dataFile("aa");
	//list<int> data(istream_iterator<int>(dataFile), istream_iterator<int>()); //声明了一个函数，而不是一个变量，因为你在变量前面加上了类型名字
	list<int> data1((istream_iterator<int>(dataFile)), istream_iterator<int>()); //加上括号后也就可以了

	//所以，建议不要在参数内递临时构建对象再来传入，而是先构建，再传入
	istream_iterator<int> dataBegin(dataFile);
	istream_iterator<int> dataEnd; //这里不能有括号，默认构造函数不加括号，加了又成了声明函数了。
	list<int> data1(dataBegin, dataEnd); //最后这样调就不会有问题了

	string str(10, 'c'); //比如这里就是正确的，不是 int 10, char 'c'这样


	system("pause");
    return 0;
}

