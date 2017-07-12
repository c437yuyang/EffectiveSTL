// 00_总记.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	return 0;
}

//M1:仔细选择容器
// 1.连续内存容器:vector,string,deque，插入删除操作会使迭代器失效
// 2.基于结点的容器:list,插入删除不会使迭代器失效

//M2:小心对"容器无关代码"的幻想
// 不同容器是不同的，优点和缺点大不相同，不要去对它们做包装
// 1.尽量用typedef来代替冗长的container<class> 以及container<class>::iterator代码
// 2.如果不想对用户暴露所使用容器的类型，则把容器进行封装，把容器类型定义在private域，只提供相应的接口给用户


//M3:使容器里对象的拷贝操作轻量而且正确
// 1.派生类对象拷贝进入基类容器的时候会被砍掉派生类部分
// 2.所以建议装指针来避免这个问题，并且指针的拷贝代价最小

//M4:用empty()代替size()==0
// 1.empty()总是常数时间(因为只检查有没有)
// 2.size()不一定是常数时间(可能需要遍历所有的成员)

//M5:用区间成员函数代替单元素操作
// 1.当要给一个容器完全新的数据集时，assign()应该使用
// 2.所有的目标区间是通过迭代器指定的copy都可以由区间成员函数代替,如insert
// 3.使用区间成员函数的意义:(1)代码更少，程序含义更加明确(2)对于不同的容器而言，效率提升不一样，
// 对于序列容器，提升很大，就算是list，也能省去很多指针赋值的操作,关联容器选择区间函数也没有损失


//M6: C++里的解析方式(函数声明)
// 参看06

//M7: 容器里是指针的时候记得delete
// 参看07

//M8: 容器里不能装智能指针
// 1.因为容易出现拷贝后，原指针就是null的情况，所以禁止使用，但是vs好像可以用。。。
// 参看07

//M9:不同类型容器的delete
// 参看09


//M13:尽量使用vector和string来代替动态数组
// 1.new进行分配的话，要确保(1)有delete(2)delete是正确的形式(3)只delete一次(所以通常delete接把指针=null)
//

//M14:使用reverse来避免不必要的重新分配
// 1.size,capacity,resize,reverse的含义
// 虽然vector等可以自动把空间变大，但是每次这样都需要重新移动所有元素，代价其实挺大的
// 2.当确定知道需要多大空间的时候，可以直接先reverse，避免不必要的分配，提高效率

//M16:vector和string传递给传统的C API
// 1.vector因为存储是连续的，所以可以用&v[0]来获取首元素指针之后跟数组一样操作
// 建议前面跟if(!v.empty())避免出现未定义操作
// 2.迭代器不是指针，不能用.begin()代替&v[0],但是可以&*v.begin();则是一模一样的
// 2.string不保证连续，所以不能这样，应该使用.c_str()，而且string结尾不保证有null
// 3.vector传给C风格的指针操作后，可以修改内容，但是不能增加或删除，之后就不知道数量了
// 5.string要实现从C风格初始化的话，必须先vector<char>,在把迭代器给string(x.begin(),x.end())这样来实现
// 事实上这个方法适用于所有的容器

//M17:使用交换技巧来修正过剩容量
// 1.vector在内容变少的时候，不会动态修正其容量(capacity)，reverse也不能变小
// 2.通过vector<T>(v).swap(v)来拷贝一次使其变小
// 3.string也是类似的

//M18:避免使用vector<bool>
// 1.vector<bool>里面装的是bit，故不能用C风格的方法来读取元素 bool *p = &v[0]
// 2.vector<bool>替代可以使用deque，但是内存不连续，也不能用C风格，但是装的是真正的bool
// 3.或者使用bitset

//M19:相等和等价的区别
// 1.set的成员函数insert是利用等价来判断的，
// 基于operator<,而标准库的find算法，是利用相等判断的，基于operator==
// operator<判断等价: !(a<b)&&!(b<a)，等价是在一个有序区间中判断对象的相对位置
// operator==判断相等: a==b
// 2.使用的时候优先使用成员函数的版本，才能保持统一
// 3.关联容器之所有使用等价而不是相等，原因在于关联容器本身还要做排序
// 因此就需要oeprator<,之后其他的也可以利用这个oeprator<来判断，更省事

//M20:为元素是指针的关联容器指定比较类型
// 除了用于指针的时候，还可以用于所有需要按照指定属性进行排序的地方，比如set里面装Person类
// 可以按照ID进行排序
// 参见20_01

//M21:为关联容器自己指定比较器的时候不能在相等的时候返回true
// 1.就是不能用<=来进行比较，必须强＜才行，否则会出问题

//M22:set和map的键（影响排序的值）不允许被改变
// 1.参见22_01

//M23:考虑用有序vector替代关联容器
// 1.标准管理容器的实现是使用平衡二叉树，每个元素都会有其父指针及兄弟指针，
// 因此最少一个元素12个字节，而vector则不用，但是得自己忍受排序的价值，排序的时候又要全部拷贝
// 但是排序完成后，查找速度更快
// 2.具体的实现则是vector里面存储pair结构，自行实现排序的算法(针对pair)

//M24:map容器的下标操作和insert操作
// 1.结论:当添加的时候，应该用insert，当更新的时候，用[]
// 2.添加的时候若用[],会先创建对象再去赋值，所以不如insert
// 3.而更新的时候，insert必须构建对象，且不美观。

//M25:熟悉散列容器，unordered_set
// 1.可以自己改写hash函数，比较是通过相等而不是等价，因为不需要排序了
// 2.但是仍然不是按照插入顺序来排序的，如果需要这种需求的话，自己改写一个vector
// 然后insert的时候，判断是否已经存在，不存在再插入便达到了需求

//M26:尽量使用iterator而不是const_iterator或者reverse_iterator
// 1.不存在从const_iterator到iterator之间的隐式转换，反着可以，所以背后的其实还是那句话
// const的可以操作非const的，非const的不能操作const的
// 2.涉及到插入和删除的时候，必须用Iterator，所以尽量都用Iterator


//M27:使用distance和advance实现去掉const_iterator的const
// 1.不能直接const_cast,本质上const_iterator和iterator是两个完全不同的类型，不是只加了const修饰符
// 2.但是vector和string内部就是typedef const T* vector<T>::iterator,所以可以直接转型，亲测VS不行
// 3.转型办法参加26_01

//M28:通过reverse_iterator转换成Iterator
// 1.reverse_iterator的insert可以直接.base来实现
// 2.reverse_iterator.base()，返回指向其(正序)前一个元素的iterator
// 3.插入操作就是将新元素插入到指定迭代器位置，然后将原先的迭代器指向的元素移到遍历过程的下一个(这里下一个是看正序还是反序而定的)

//M30:确保容器的容量足够大小
// 1.back_inserter等inserter的使用可以确保不会出现未定义的操作，参见30_01
// 2.连续容器如vector在调用之前，
// 最好先reverse（reverse只是容量变大，但是size没变，所以还是必须inserter，而不能直接更改那个位置），但是还是得忍受移动的代价
// 3.任何时候，容器需要增加大小的时候，一定要用inserter

 //M31:选择合适的sort
// 1.vector,deque,string,数组为第一类，list第二类
// 2.对于第一类，完全排序用sort或者stable_sort,只排序前N个用partial_sort,不关心前N个顺序
// 用nth_element,只需要按条件分为两部分但并不排序，用Partition或者stable_partition
// 3.list中sort可代替stable_sort
// 4.性能: partion>stable_partition>nth_element>partial_sort>sort>stable_sort

//M32:std:remove一定要和成员的erase联合使用
// 1.std::remove并不删除元素，只是将不删除的元素移到开始，返回第一个需要删除的元素的iterator，因此要接erase
// 2.list.remove是整合了erase的，可以直接用
// 3.类似的还有remove_if和unique

//M33:避免在装有指针的容器使用remove类似的算法
// 1.remove会向前移动元素，就会有覆盖，覆盖了指针的话，就会内存泄露
// 2.解决方法是，先用一个for_each，delete掉相应的内存，或者使用Partition
// 3.如果用的是智能指针的话，就可以直接remove_erase了

//M35:copy_if在VS里面已经实现了



//M43：尽量用算法代替手写循环
// 1.效率(开发算法的人几乎总是比你更能写出高效率的算法)，代码清晰度
// 2.

//M44:尽量用成员函数替代同名的std::algorithm
// 1.成员函数版本更快
// 2.与容器结合的更好
// 3.判断元素相同，使用的是等价而不是相等。
// 4.list的成员函数的行为和std::版本通常都不一样

//M45:find,count,binary_search,lower_bound,upper_bound,equal_range的区别
// 1.无序区间用find和count，有序用剩下的
// 2.find和count都可以用来检测存在与否，但是find()找到第一个就停了，因此效率更好。
// 3.find()返回迭代器可以继续操作，count不能
// 4.count和find是线性时间，而其他的是对数时间
// 5.count和find用相等搜索，其他的用的等价
// 6.binary_search返回bool,只检查是否存在，equal_range返回一个区间，为找到的元素的区间

//M46:考虑用函数对象替代函数作为算法的参数
// 1.对象里面的函数可以inline
// 2.直接算法的话，其实是传的一个指针参数，再通过指针去找的函数，所以更慢

//M47:避免写太过复杂的算法代码，尽量分步写的简单一些，考虑到后期的维护

//M48:虽然可能一个头文件里面已经包含了另一个头文件，但是尽量还是手动去包含所需要的头文件，这样有利于移植性

//M49:STL库的错误信息可能非常多，但是要学会整理，替换，最后就很简单了

//M50:在const成员函数内部，类的所有非静态成员变量都会成为const的