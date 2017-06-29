#pragma once

#ifndef UNORDERED_SET
#define UNORDERED_SET
#include <vector>
#include <algorithm>
using std::vector;
namespace yxp_utility {

	template<class T>
	class unordered_set {

	public:
		bool insert(const T& obj)
		{
			if (std::find(data.begin(), data.end(), obj) != data.end())
			{
				data.push_back(obj);
				return true;
			}
			return false;
		}
		size_t size()
		{
			return data.size();
		}
		bool empty()
		{
			return data.empty();
		}
		//下面接着将所有常用的方法实现即可，只改变一个insert方法
	private:
		vector<T> data;
		data.insert()
	};


}


#endif

