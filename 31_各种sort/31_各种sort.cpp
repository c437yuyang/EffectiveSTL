// 31_����sort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Widget {
public:
	Widget(int i) :age(i) {}
	int age;

};

int main()
{

	vector<Widget> v;
	for (int i = 20; i != 0; --i)
	{
		v.push_back(rand()%20);
	}

	//partial_sort(v.begin(), v.begin() + 5, v.end(), //�ҳ�ǰ5�������Ұ�ǰ�����˳������
	//	[](const Widget& lhs, const Widget& rhs) {return lhs.age < rhs.age; });


	//nth_element(v.begin(), v.begin() + 5, v.end(), //ֻ�ҵ�ǰ5������ǰ�棬���Ƕ������������˳��
	//	[](const Widget& lhs, const Widget& rhs) {return lhs.age < rhs.age; });

	//stable_sort(); //������Ԫ����ͬ�Ƚϵ�ʱ�򣬱�����ԭ��λ��

	//partition,�ҵ���������������Ԫ�أ��ƶ���vectorǰ�Σ�
	//���ص�һ��������������Ԫ��,ǰ��ͺ����Ԫ��˳�򶼲�һ��,ֻ��������������
	vector<Widget>::iterator firstNotSatisfy = partition(v.begin(), v.end(), [](Widget i) {return i.age <= 5; });
	//stable_partition()����������
	

	system("pause");
	return 0;
}

