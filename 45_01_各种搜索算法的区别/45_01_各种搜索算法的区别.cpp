// 45_01_���������㷨������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v1 = { 1,2,3,3,3,4,5,6 };

	bool b = binary_search(v1.begin(), v1.end(), 4); //true //bianry_searchֻ�ж���û��

	//lower_bound��upper_bound�ֱ𷵻���Ѱ��Ԫ�ص�����λ�ý��ޣ���ʵ����equal_range�ķ���ֵ

	auto it = equal_range(v1.begin(), v1.end(), 3); //equal_range����һ�Ե�������ָ��һ������
	cout << it.first - v1.begin() << endl; //2
	cout << it.second - v1.begin() << endl;//5,��python���ƣ���ǰ������
	cout << distance(it.first, it.second) << endl; //distance�������������Ĳ�ֵ��3

	cout << *(it.first) << endl; //3
	cout << *(it.second) << endl;//4 ,��һ��λ��
	advance(it.first, distance(it.first, it.second));
	cout << *(it.first) << endl; //ǰ������second��λ��

	//find��count

	system("pause");
	return 0;
}

