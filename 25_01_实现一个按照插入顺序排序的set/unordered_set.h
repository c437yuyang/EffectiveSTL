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
		//下面接着将所有常用的方法实现即可，改变的其实只有一个insert方法
	private:
		vector<T> data;
	};

	template<class T> //因为这里形参是const的，所以上面的size()函数也必须是const才行，不然会报错
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

