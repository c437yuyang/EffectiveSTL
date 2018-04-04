// 12_01_STL容器线程安全.cpp : 定义控制台应用程序的入口点。
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

	//原始情况
	{
		vector<int> v;
		vector<int>::iterator first5(find(v.begin(), v.end(), 5));
		if (first5 != v.end())
			*first5 = 0; //多线程环境下是不安全的
	}

	//改为线程安全
	{
		vector<int> v;
		getMutexFor(v);
		vector<int>::iterator first5(find(v.begin(), v.end(), 5));
		if (first5 != v.end())
			*first5 = 0; //现在用互斥量控制了
		releaseMutexFor(v);
	}

	//使用对象管理
	{
		vector<int> v;
		//在一个块内来使用,好处是，Lock析构函数会自动释放，并且出现异常的情况下，C++保证了出了异常，局部对象会被销毁，因此当Lock对象异常的时候，Lock将会释放互斥量。
		//如果手动调用,getmutexfor之后releasemutex之前出现了异常，则不会释放互斥量
		{
			Lock<vector<int> > lock(v);
			vector<int>::iterator first5(find(v.begin(), v.end(), 5));
			if (first5 != v.end())
				*first5 = 0;
		}

	}



	return 0;
}

