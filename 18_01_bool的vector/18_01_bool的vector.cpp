// 18_01_bool��vector.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<bool> v = {true,false};

	//bool *a = &v[0]; //�������ܱ��룬vector<bool>������ʹ��C���װ����bit����bool
	//bool *a1 = &v[1];

	vector<int> v1 = { 1,2,3 };
	int *a2 = &v1[0];

    return 0;
}

