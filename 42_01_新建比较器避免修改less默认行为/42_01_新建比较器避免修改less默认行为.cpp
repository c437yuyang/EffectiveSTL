// 42_01_�½��Ƚ��������޸�lessĬ����Ϊ.cpp : �������̨Ӧ�ó������ڵ㡣
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
		return this->weight() < other.weight(); //Ĭ�ϰ���weight����
	}
};

//����������Ҫ����һ������speed()�����multiset
//��Ϊmultisetʹ��less<T>���Ƚϣ���less<T>Ĭ�ϵ���operator<(),�ڱ�֤���ı�operator()(��Ϊ��ֻ�����setҪ����speed���������ط���Ҫ����weight����)
//��ǰ���£�һ�ַ�����������less<Widget>:
template<>
struct std::less<Widget> :
	public std::binary_function<Widget, Widget, bool>
{
	bool operator()(const Widget& _Left, const Widget& _Right) const
	{
		return _Left.maxSpeed() < _Right.maxSpeed();
	}
};

//�������������������ǣ�Υ������С��̾ԭ��
//����Ա�ǿ��Լ���less�ǵ���operator<()�ģ�������ȴ�ı��������������������õ�less�ĵط�Ҳ������(�������û�������)��
//������õİ취��ֱ����һ���µıȽ�������,������ȥ�ı�less����Ϊ
struct MaxSpeedCompare:
	public std::binary_function<Widget,Widget,bool>
{
	bool operator()(const Widget& _Left, const Widget& _Right) const
	{
		return _Left.maxSpeed() < _Right.maxSpeed();
	}
};

std::multiset<Widget, MaxSpeedCompare> set; //���������ü��ɡ�




int main()
{





    return 0;
}

