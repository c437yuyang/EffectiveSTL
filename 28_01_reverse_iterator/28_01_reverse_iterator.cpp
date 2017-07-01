// 28_01_reverse_iterator.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	vector<int> ivec1 = { 1,2,3,4,5 };

	vector<int>::reverse_iterator ri = ivec1.rbegin() + 3;

	cout << *ri << endl; //2�����Կ���reverse_iterator�ĵ�һ��Ԫ�������һ��
	vector<int>::iterator it(ri.base()); //3,.base���ص�����һ��Ԫ��
	cout << *it << endl;

	//����insert,��Ϊinsert������reverse_iterator������ֱ����ri.base()���������
	ivec1.insert(ri.base(), 99);
	cout << endl;
	for_each(ivec1.begin(), ivec1.end(), [](int i) {cout << i << " "; }); //1 2 99 3 4 5,��ȷ������ri��˵������riָ���Ԫ�ص�ǰ�������


	//����ϣ��ɾ��2���ǲ��ܶ�it����--������ɾ���ģ�C��C++���涨����ֱ���޸ĺ������ص�ָ��
	//ivec1.erase(--ri.base()); //����ʱ����
	//ivec1.erase((++ri).base()); //effectiveSTL�������ȷ����������riָ����һ��������VSò���в�ͨ
	cout << endl;
	for_each(ivec1.begin(), ivec1.end(), [](int i) {cout << i << " "; }); //1 2 99 3 4 5,��ȷ������ri��˵������riָ���Ԫ�ص�ǰ�������


	vector<int> ivec2 = { 1,2,3 };
	auto it1 = ivec2.insert(ivec2.begin(), {99,21});
	cout << *it1 << endl; //����ָ���һ����Ԫ�صĵ�����
	system("pause");

    return 0;
}

