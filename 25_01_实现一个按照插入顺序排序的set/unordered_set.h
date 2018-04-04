#pragma once

#ifndef UNORDERED_SET
#define UNORDERED_SET
#include <vector>
#include <algorithm>
#include <iostream>
using std::ostream;
using std::cout;
using std::vector;
namespace yxp_utility {

	template<class T>
	class unordered_set {
	public:

		unordered_set() {};

		bool insert(const T& obj)
		{
			if (std::find(data.begin(), data.end(), obj) == data.end())
			{
				data.push_back(obj);
				return true;
			}
			return false;
		}
		size_t size() const
		{
			return data.size();
		}
		bool empty()
		{
			return data.empty();
		}
		const T& operator[](int idx) const { return data[idx]; }
		T& operator[](int idx) { return data[idx]; }
		//������Ž����г��õķ���ʵ�ּ��ɣ��ı����ʵֻ��һ��insert����
	private:
		vector<T> data;
	};

	template<class T> //��Ϊ�����β���const�ģ����������size()����Ҳ������const���У���Ȼ�ᱨ��
	ostream& operator<<(ostream& os, const unordered_set<T> &us)
	{
		for (size_t i = 0; i != us.size(); ++i)
		{
			os << (us[i]) << " ";
		}
		return os;

	}



}


#endif

