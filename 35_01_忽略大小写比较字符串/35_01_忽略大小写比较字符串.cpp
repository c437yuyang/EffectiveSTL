// 35_01_���Դ�Сд�Ƚ��ַ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <string>
#include <algorithm>
#include <functional>
using namespace std;

#pragma region ���ϵİ汾
int ciCharCompare(char left_char, char right_char)
{
	int c1 = tolower(static_cast<unsigned char>(left_char));
	int c2 = tolower(static_cast<unsigned char>(right_char));
	if (c1 < c2)
		return -1;
	if (c1 > c2)
		return 1;
	return 0;
}

//�����s1�ı�s2��
int ciStringCompareImpl(const string&s1, const string&s2)
{
	typedef std::pair<string::const_iterator, string::const_iterator> PSCI;

	PSCI p = mismatch(s1.begin(), s1.end(), s2.begin(), not2(ptr_fun(ciCharCompare))); //�ҵ�����ȵĵ�һ��λ�ã������������õ�ciCharCompareȥ���бȽϣ����
	if (p.first == s1.end()) //s1��һ��������end,˵��s1ȫ������s2��ͬ
	{
		if (p.second == s2.end())
			return 0; //s2Ҳ��end,˵������������ͬ������ȫһ��
		else return -1; //s2��s1����ֱ��˵��s1С��s2
	}
	return ciCharCompare(*p.first, *p.second); //����Ƚϵ�һ������ȵ��ַ�
}

int ciStringCompare(const string&s1, const string&s2)
{
	if (s1.size() <= s2.size())
		return ciStringCompareImpl(s1, s2);
	else
		return -ciStringCompareImpl(s2, s1);
}

#pragma endregion



int main()
{

	string s1 = "abcDe";
	string s2 = "abcDE";
	string s3 = "abcddf";
	string s4 = "abCE";


	int i = _stricmp(s1.c_str(), s2.c_str()); //�����0
	int i1 = _stricmp(s1.c_str(), s3.c_str()); //����������ע��e��>d�ģ�
	int i2 = _stricmp(s1.c_str(), s4.c_str()); //С�ڸ���

	i = ciStringCompare(s1, s2);
	i = ciStringCompare(s1, s3);
	i = ciStringCompare(s1, s4);

	return 0;
}

