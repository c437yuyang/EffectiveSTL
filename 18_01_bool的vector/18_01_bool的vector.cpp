// 18_01_bool��vector.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<bool> v = {true,false,false,false ,false,true,false,true,false }; //9����capacity,32
	cout << sizeof(v) << endl; //��Ȼ��size����ò�Ʋ�����װ��bit
	cout << sizeof(bool) << endl;
	//bool *a = &v[0]; //�������ܱ��룬vector<bool>������ʹ��C���װ����bit����bool
	//bool *a1 = &v[1];

	vector<int> v1 = { 1,2,3 }; //��������(����int)���;Ϳ���
	int *a2 = &v1[0];

    return 0;
}

