// 25_01_ʵ��һ�����ղ���˳�������set.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "unordered_set.h"
#include <iostream>
using namespace std;

int main()
{
	using namespace yxp_utility;
	unordered_set<int> us;

	us.insert(10);
	us.insert(20);
	us.insert(20);
	us.insert(30);

	cout << us.size() << endl;

	cout << us[1] << endl;

	cout << us << endl;


    return 0;
}

