// 10_01_vector���ݸ�C���Ĳ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void printArr(const int *p, int size)
{
	for (int i=0;i!=size;++i)
	{
		cout << p[i] << endl;
	}
}

int main()
{
	vector<int> v = { 1,2,3,4,5 };


	printArr(&v[0], v.size()); //��Ϊvector�Ĵ洢���ڴ���Ҳ�������ģ����Կ�������ʹ�ã��ǵ��ж�!v.empty
	//printArr(v.begin(), v.size()); //����iterator��ָ���ǲ�һ����
	system("pause");
    return 0;
}

