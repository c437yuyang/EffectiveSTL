// 17_01_vector����������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{

	vector<int> ivec1 = { 1,2,3,4,5 };


	cout << ivec1.capacity() << endl; //5
	ivec1.push_back(10);
	cout << ivec1.capacity() << endl;//7

	ivec1.reserve(10);
	cout << ivec1.capacity() << endl;//10

	ivec1.reserve(6);
	cout << ivec1.capacity() << endl;//10  reverse���ܵ�С

	vector<int>(ivec1).swap(ivec1);  //ͨ�����ֽ���һ����ʱ����ķ���������һ��Ԫ�أ�����vector������

	cout << ivec1.capacity() << endl;//6,�˷������Ե���


	//stringҲ�����Ƶ�

	system("pause");
    return 0;
}

