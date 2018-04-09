// 42_01_新建比较器避免修改less默认行为.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <functional>
#include <set>

class Widget
{
public:
	size_t weight() const {};
	size_t maxSpeed() const {};
	bool operator<(const Widget&other) const 
	{
		return this->weight() < other.weight(); //默认按照weight排序
	}
};

//现在我们想要建立一个按照speed()排序的multiset
//因为multiset使用less<T>来比较，而less<T>默认调用operator<(),在保证不改变operator()(因为你只是这个set要按照speed排序，其他地方需要按照weight排序)
//的前提下，一种方法是特例化less<Widget>:
template<>
struct std::less<Widget> :
	public std::binary_function<Widget, Widget, bool>
{
	bool operator()(const Widget& _Left, const Widget& _Right) const
	{
		return _Left.maxSpeed() < _Right.maxSpeed();
	}
};

//但是这样带来的问题是，违背了最小惊叹原则。
//程序员是可以假设less是调用operator<()的，而这里却改变了这个做法，因此其他用到less的地方也许会出错(对其他用户产生误导)。
//所以最好的办法是直接用一个新的比较器类型,而不是去改变less的行为
struct MaxSpeedCompare:
	public std::binary_function<Widget,Widget,bool>
{
	bool operator()(const Widget& _Left, const Widget& _Right) const
	{
		return _Left.maxSpeed() < _Right.maxSpeed();
	}
};

std::multiset<Widget, MaxSpeedCompare> set; //现在这样用即可。




int main()
{





    return 0;
}

