// 09_��ͬ������delete.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	//1.vector,string,deque
	vector<int> v1 = { 7 ,1, 9, 2, 0, 7, 7, 3, 4, 6, 8, 5, 7, 7 };
	auto new_end =remove(v1.begin(), v1.end(), 1); //remove ɾ��ָ����Ԫ�أ����ǻ���ǰ��λ,���Ĳ���Ӱ�죬����ָ����Ӱ��ĵ�һ��(����ĵ�һ���������erase)
	//after remove:1 9 2 0 3 4 6 8 5 6 8 5 7 7
	v1.erase(new_end,v1.end());
	//after erase:1 9 2 0 3 4 6 8 5
	
	//��дΪ:
	//v1.erase(remove(v1.begin(), v1.end(), 1), v1.end());

	//2.list
	list<int> iList = { 1,2,3,4,55,23,2,3,312,1 };
	iList.remove(3);

	//3.��������
	set<int> iSet = { 1,2,3,4,5 };
	iSet.erase(2);


	//��������ɾ��
	//1.vector,string,deque
	vector<int> v2 = { 7 ,1, 9, 2, 0, 7, 7, 3, 4, 6, 8, 5, 7, 7 };
	v2.erase(remove_if(v2.begin(), v2.end(), [](int a) {return a > 6; }), v2.end());

	//2.list
	list<int> iList1 = { 1,2,3,4,55,23,2,3,312,1 };
	iList1.remove_if([](int a) {return a > 4; });

	//3.��������
	set<int> iSet1 = { 1,2,3,4,5 };
	for (auto it = iSet1.begin(); it != iSet1.end();) 
	{
		if (*it == 3) 
		{
			iSet1.erase(it++); //ɾ����ǰiterator���Ѿ�ʧЧ�ˣ����Բ�����ȥ++���������õ�һ������
		}
		else
		{
			++it;
		}
	}


	//��Ҫ����ʲô�����µ����
	//1.vector,string,deque
	vector<int> v3 = { 7 ,1, 9, 2, 0, 7, 7, 3, 4, 6, 8, 5, 7, 7 };
	for (auto it=v3.begin();it!=v3.end();)
	{
		if (*it == 7) //ɾ���󣬵�ǰԪ�غ������е�it��ʧЧ���������¸�ֵ��erase����ɾ��Ԫ��֮���һ��Ԫ��
		{
			it = v3.erase(it);
			//dosomething
		}
		else
			++it;
	}

	//2.list(���ú�vector���Ƶľ�����)

	//3.��������(ͬ��)


	system("pause");
    return 0;
}

