// 40_01_�º����������.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//���ҵ�һ������Ȥ��Widgetָ��
	auto it = std::find_if(widgetPtrs.begin(), widgetPtrs.end(), isInteresting);
	//���ҵ�һ��������Ȥ��ָ��
	//it = std::find_if(widgetPtrs.begin(), widgetPtrs.end(), std::not1(isInteresting)); //����
	it = std::find_if(widgetPtrs.begin(), widgetPtrs.end(), std::not1(std::ptr_fun(isInteresting))); //Ҫ��������
	//ptr_fun��������ʹһЩtypedef��Ч��(argument_type,first_argument_type,second_argument_type,result_type)
	//�����Ҫֱ���ܹ�ʹ�õĻ������Դ�ģ��̳У��Ͱ���ʵ������Щtypedefs
	struct IsInterestringFunctor :
		public std::unary_function<Widget*, bool>
	{
		bool operator()(Widget*pw) const { return true; }
	};
	it = std::find_if(widgetPtrs.begin(), widgetPtrs.end(), std::not1(IsInterestringFunctor())); //��������Ҳ����

	//struct IsInterestringFunctor1 
	//{
	//	bool operator()(Widget*pw) const { return true; }
	//};
	//it = std::find_if(widgetPtrs.begin(), widgetPtrs.end(), std::not1(IsInterestringFunctor1())); //���������ǲ��еģ��ᱨ����ʾargument_typeδ֪

	//���:Ҫô��std::unary_function����std::binary_function�̳У��Ͱ���ʵ������Щtypedef,Ҫô����ptr_fun

	struct IsInterestringFunctor2:
		public std::unary_function<Widget, bool>
	{
		bool operator()(const Widget&w) const { return true; } //ע�⴫�ݵ�unary_function�б�����û�д�const���õģ����������õ�(��ָ�����Ͷ�ȥ����const������)��û��Ϊʲô��
	};


	return 0;
}

