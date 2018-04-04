// 26_01_const_ierator和iterator.cpp : 定义控制台应用程序的入口点。
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
	DqConstIter cit1(it1); //可以加上const属性
	//DqIter it2(const_cast<DqIter>(cit1)); //报错，不能去掉const，
	//因为const_iterator和iterator完全是两种不同的类型，而不是简单的加了const修饰

	vector<int> v1 = { 1,2,3,4 };
	typedef vector<int>::iterator VecIter;
	typedef vector<int>::const_iterator VecConstIter;

	VecConstIter cit3(v1.cbegin());
	//VecIter it4(const_cast<VecIter>(cit3)); //VS里面，vector和string看来也不能直接去掉const,release模式也不行

	//应该使用distance和advance来实现
	DqIter it5(d1.begin()); //先指向开始
	advance(it5, distance<DqConstIter>(it5, cit1)); //这样就完成了去掉const的转换，
	//当然，distance函数内部，发生了从非const到const的隐式转型(加const是允许的)


	system("pause");
    return 0;
}

