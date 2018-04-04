// 12_01_STL�����̰߳�ȫ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
using namespace std;

template<class Container>
void getMutexFor(const Container& c)
{

}

template<class Container>
void releaseMutexFor(const Container& c)
{

}

template<class Container>
class Lock
{
public:
	Lock(const Container& container) : container_(container)
	{
		getMutexFor(container_);
	}

	~Lock()
	{
		releaseMutexFor(container_);
	}

private:
	const Container& container_;
};

int main()
{

	//ԭʼ���
	{
		vector<int> v;
		vector<int>::iterator first5(find(v.begin(), v.end(), 5));
		if (first5 != v.end())
			*first5 = 0; //���̻߳������ǲ���ȫ��
	}

	//��Ϊ�̰߳�ȫ
	{
		vector<int> v;
		getMutexFor(v);
		vector<int>::iterator first5(find(v.begin(), v.end(), 5));
		if (first5 != v.end())
			*first5 = 0; //�����û�����������
		releaseMutexFor(v);
	}

	//ʹ�ö������
	{
		vector<int> v;
		//��һ��������ʹ��,�ô��ǣ�Lock�����������Զ��ͷţ����ҳ����쳣������£�C++��֤�˳����쳣���ֲ�����ᱻ���٣���˵�Lock�����쳣��ʱ��Lock�����ͷŻ�������
		//����ֶ�����,getmutexfor֮��releasemutex֮ǰ�������쳣���򲻻��ͷŻ�����
		{
			Lock<vector<int> > lock(v);
			vector<int>::iterator first5(find(v.begin(), v.end(), 5));
			if (first5 != v.end())
				*first5 = 0;
		}

	}



	return 0;
}

