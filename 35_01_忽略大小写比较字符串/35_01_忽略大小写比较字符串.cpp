// 35_01_忽略大小写比较字符串.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <string>
#include <algorithm>
#include <functional>
using namespace std;

#pragma region 书上的版本
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

//假设的s1的比s2短
int ciStringCompareImpl(const string&s1, const string&s2)
{
	typedef std::pair<string::const_iterator, string::const_iterator> PSCI;

	PSCI p = mismatch(s1.begin(), s1.end(), s2.begin(), not2(ptr_fun(ciCharCompare))); //找到不相等的第一个位置，并且这里是用的ciCharCompare去进行比较，因此
	if (p.first == s1.end()) //s1是一定先来到end,说明s1全部都和s2相同
	{
		if (p.second == s2.end())
			return 0; //s2也是end,说明两个长度相同，则完全一样
		else return -1; //s2比s1长，直接说明s1小于s2
	}
	return ciCharCompare(*p.first, *p.second); //否则比较第一个不相等的字符
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


	int i = _stricmp(s1.c_str(), s2.c_str()); //相等是0
	int i1 = _stricmp(s1.c_str(), s3.c_str()); //大于正数（注意e是>d的）
	int i2 = _stricmp(s1.c_str(), s4.c_str()); //小于负数

	i = ciStringCompare(s1, s2);
	i = ciStringCompare(s1, s3);
	i = ciStringCompare(s1, s4);

	return 0;
}

