// 35_01_���Դ�Сд�Ƚ��ַ���.cpp : �������̨Ӧ�ó������ڵ㡣
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


	int i = _stricmp(s1.c_str(), s2.c_str()); //�����0
	int i1 = _stricmp(s1.c_str(), s3.c_str()); //����������ע��e��>d�ģ�
	int i2 = _stricmp(s1.c_str(), s4.c_str()); //С�ڸ���
    return 0;
}

