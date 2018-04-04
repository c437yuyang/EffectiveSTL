// 26_01_const_ierator��iterator.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	deque<int> d1 = { 1,2,3,4,5 };
	typedef deque<int>::iterator DqIter;
	typedef deque<int>::const_iterator DqConstIter;

	DqIter it1(d1.begin());
	DqConstIter cit1(it1); //���Լ���const����
	//DqIter it2(const_cast<DqIter>(cit1)); //��������ȥ��const��
	//��Ϊconst_iterator��iterator��ȫ�����ֲ�ͬ�����ͣ������Ǽ򵥵ļ���const����

	vector<int> v1 = { 1,2,3,4 };
	typedef vector<int>::iterator VecIter;
	typedef vector<int>::const_iterator VecConstIter;

	VecConstIter cit3(v1.cbegin());
	//VecIter it4(const_cast<VecIter>(cit3)); //VS���棬vector��string����Ҳ����ֱ��ȥ��const,releaseģʽҲ����

	//Ӧ��ʹ��distance��advance��ʵ��
	DqIter it5(d1.begin()); //��ָ��ʼ
	advance(it5, distance<DqConstIter>(it5, cit1)); //�����������ȥ��const��ת����
	//��Ȼ��distance�����ڲ��������˴ӷ�const��const����ʽת��(��const�������)


	system("pause");
    return 0;
}

