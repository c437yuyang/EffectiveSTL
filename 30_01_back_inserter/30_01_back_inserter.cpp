// 30_01_back_inserter.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int doSomthing(int x) {
	return x*x;
}

int main()
{


	vector<int> v = { 1,2,3,4,5 };
	vector<int> results = { 2,3,4,5,6 };


	//transform(v.begin(), v.end(), results.end(), doSomthing); //����ʱ���󣬳����±꣬��Ϊ.end������û��ֵ��

	transform(v.begin(), v.end(), back_inserter(results), doSomthing); //�����κ���push_back�������ϵ���Push_back
	//list,deque,stringҲ����

	//front_inserterֻ����deque��list��

	transform(v.begin(), v.end(), inserter(results, results.begin() + results.size() / 2), doSomthing);

	//����inserter������������vector�ڵ���֮ǰ��
	//�����reverse��reverseֻ��������󣬵���sizeû�䣬���Ի��Ǳ���inserter��������ֱ�Ӹ����Ǹ�λ�ã������ǻ��ǵ������ƶ��Ĵ���

	for_each(results.begin(), results.end(), [](int x) {cout << x << " "; });

	return 0;
}

