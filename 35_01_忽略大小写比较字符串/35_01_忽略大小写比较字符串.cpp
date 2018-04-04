// 35_01_忽略大小写比较字符串.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <string>
using namespace std;

int main()
{

	string s1 = "abcDe";
	string s2 = "abcDE";
	string s3 = "abcddf";
	string s4 = "abCE";


	int i = _stricmp(s1.c_str(), s2.c_str()); //相等是0
	int i1 = _stricmp(s1.c_str(), s3.c_str()); //大于正数（注意e是>d的）
	int i2 = _stricmp(s1.c_str(), s4.c_str()); //小于负数
    return 0;
}

