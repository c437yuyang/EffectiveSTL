// 40_01_仿函数类可适配.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <list> 
#include <algorithm>
#include <functional>


class Widget {};
bool isInteresting(const Widget*pw)
{
	return true;
}

int main()
{
	std::list<Widget*> widgetPtrs;
	//查找第一个感兴趣的Widget指针
	auto it = std::find_if(widgetPtrs.begin(), widgetPtrs.end(), isInteresting);
	//查找第一个不感兴趣的指针
	//it = std::find_if(widgetPtrs.begin(), widgetPtrs.end(), std::not1(isInteresting)); //报错
	it = std::find_if(widgetPtrs.begin(), widgetPtrs.end(), std::not1(std::ptr_fun(isInteresting))); //要这样才行
	//ptr_fun的作用是使一些typedef有效。(argument_type,first_argument_type,second_argument_type,result_type)
	//而如果要直接能够使用的话，可以从模板继承，就帮你实现了这些typedefs
	struct IsInterestringFunctor :
		public std::unary_function<Widget*, bool>
	{
		bool operator()(Widget*pw) const { return true; }
	};
	it = std::find_if(widgetPtrs.begin(), widgetPtrs.end(), std::not1(IsInterestringFunctor())); //现在这样也可以

	//struct IsInterestringFunctor1 
	//{
	//	bool operator()(Widget*pw) const { return true; }
	//};
	//it = std::find_if(widgetPtrs.begin(), widgetPtrs.end(), std::not1(IsInterestringFunctor1())); //而这样就是不行的，会报错提示argument_type未知

	//因此:要么从std::unary_function或者std::binary_function继承，就帮你实现了这些typedef,要么就用ptr_fun

	struct IsInterestringFunctor2:
		public std::unary_function<Widget, bool>
	{
		bool operator()(const Widget&w) const { return true; } //注意传递的unary_function列表内是没有带const引用的，就是这样用的(非指针类型都去掉了const和引用)，没有为什么。
	};


	return 0;
}

