// 05_�����Ա�������浥Ԫ�ز���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{

	vector<int> vec1 = {1,2,3,4};
	vector<int> vec2 = { 5,6,7,8,9 };
	//ʹv1�����ݺ�v2�ĺ�����ͬ
	//1.assign
	vec1.assign(vec2.begin() + vec2.size() / 2, vec2.end());
	//2.insert
	vec1.clear();
	vec1.insert(vec1.end(), vec2.begin() + vec2.size() / 2, vec2.end());
	//3.copy(Ч�ʵͣ��ڲ�����ѭ��)
	vec1.clear();
	copy(vec2.begin() + vec2.size() / 2, vec2.end(), back_inserter(vec1));
	//4.�ֶ�����Ա��ֵ
	vec1.clear();
	for (auto it=vec2.begin()+vec2.size()/2;it!=vec2.end();++it)
	{
		vec1.push_back(*it);
	}

	/*vec2.insert(vec2.begin() + 1, 1);*/ //insert����ָ��λ��֮ǰ����

	//auto it = vec2.erase(vec2.begin() + 1, vec2.begin() + 3); //ɾ��vec2.begin()+1��vec2.begin()+2
	//cout << *it << endl; //����ָ��ɾ����Ԫ�ص���һ��Ԫ�أ�vec2.begin()+3(ɾ��֮ǰ)���������8
	//vec2.erase(vec2.begin()+1); //ɾ������Ԫ��
	system("pause");
    return 0;
}

