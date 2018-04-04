// 20_01_ָ�������ָ���Ƚ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;


//���ַ�ʽ�ֱ���:�̳���binary_function<>ģ���࣬�Լ�дһ���Ƚ����ں��Ƚϵ�ģ�庯����ģ����
struct StringPrtLess :binary_function<const string*, const string *, bool>
{
public:
	bool operator()(const string *ps1, const string *ps2) const
	{
		return *ps1 < *ps2;
	}
};

struct DereferenceLess //ʹ��ģ��ʹ�ò���������
{
	template<class T>
	constexpr bool operator()(const T _Left, const T _Right) const
	{	// apply operator< to operands
		return (*_Left < *_Right);
	}
};

//������VS��Less����
template<class _Ty = void>
struct PtrLess
{	// functor for operator<
	//typedef _Ty first_argument_type;
	//typedef _Ty second_argument_type;
	//typedef bool result_type;

	constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
	{	// apply operator< to operands
		return (*_Left < *_Right);
	}
};

int main()
{



	set<string*, StringPrtLess> v = {
			new string("aaa"),
			new string("baa"),
			new string("aca"),
			new string("acd")
	};

	for_each(v.begin(), v.end(), [](string *ps) {cout << *ps << endl; });//�����Լ�����ıȽ���ʵ�ִ�С��������

	set<string*, PtrLess<string *>> v1 = {
		new string("aaa"),
		new string("baa"),
		new string("aca"),
		new string("acd")
	};
	//���ַ����Ǵ�VS��Դ�ļ����濽�����ģ�Ҳ����
	for_each(v1.begin(), v1.end(), [](string *ps) {cout << *ps << endl; });

	set<string*, DereferenceLess> v2 = {
		new string("aaa"),
		new string("baa"),
		new string("aca"),
		new string("acd")
	};
	//��һ�ַ�����ģ���õ������ڲ���ʹ�õ�ʱ��Ͳ���Ҫ��ָ��������
	for_each(v2.begin(), v2.end(), [](string *ps) {cout << *ps << endl; });

	//�������һ�ַ���
	cout << endl;
	transform(v2.begin(), v2.end(), ostream_iterator<string>(cout, "\n"), [](string *p) {return *p; });
	//transform��ʵ����copy and doSomething
	//copy(v2.begin(), v2.end(), ostream_iterator<string *>(cout, " ")); //�������ָ���ֵ

	system("pause");
	return 0;
}

