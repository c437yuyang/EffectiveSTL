// 23_01_����vector����map.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
typedef std::pair<std::string, int> data_type;

struct DataCompare
{
	bool operator()(const data_type& data1, const data_type& data2)
	{
		return key_compare(data1.first, data2.first);
	}

	bool operator()(const data_type& data1, const data_type::first_type& key2)
	{
		return key_compare(data1.first, key2);
	}

	bool operator()(const data_type::first_type& key1, const data_type& data2)
	{
		return key_compare(key1, data2.first);
	}

private:
	bool key_compare(const data_type::first_type&key1, const data_type::first_type&key2)
	{
		return key1 < key2;
	}

};





int main()
{
	std::vector<data_type> v;
	v.push_back(std::make_pair("9", 9));
	v.push_back(std::make_pair("8", 8));
	v.push_back(std::make_pair("7", 7));
	v.push_back(std::make_pair("6", 6));
	std::sort(v.begin(), v.end(), DataCompare()); //��������

	//Ȼ�����ʹ��binary_search,lower_bound,euqal_range�ȵȺ�����

    return 0;
}

