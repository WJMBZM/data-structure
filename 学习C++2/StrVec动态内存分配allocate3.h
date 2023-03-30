//#pragma once
//
//#include<stdio.h>
//#include<stdlib.h>
//
//#include<cstring>
//#include<string>
//#include<vector>
//#include<set>
//#include<map>
//#include<stack>
//#include<queue>
//#include<unordered_map>
//#include<unordered_set>
//#include<bitset>
//#include<algorithm>
//#include<cctype>
//
//
//#include <thread>
//#include <deque>
//#include <numeric>
//#include <utility>
//
//
//#include <fstream>
//#include <sstream>
//
//#include <array>
//#include <memory>
//#include <memory.h>
//
//#include <functional>
//
////  上下间隔
//
//#include <iostream>
//#include <vector>
//#include <iterator>
//#include <string>
//#include<cstring>
//#include <initializer_list>
//#include <stdexcept>  //runtime_error() 显示异常类型函数
////#include <wincrypt.h>
//
//using namespace std;
//
//using  std::string;
//
//
//
//
//class StrVec {
//public:
//	StrVec() : elements(nullptr), first_free(nullptr), capacity(nullptr) {};
//	StrVec(const StrVec&);
//	StrVec& operator = (const StrVec&);
//	~StrVec();
//	void push_back(const string&);
//	size_t size() const;
//	size_t capacity_size() const;
//	const string* cbegin();
//	const string* cend();
//	string* begin();
//	string* end();
//	void free();
//	void reallocate();
//	void move_reallocate();
//	void check_alloc_fullspace();
//
//private:
//	allocator<string>alloc;
//
//
//	pair<string*, string*> alloc_n_copy(const string*, const string*);
//
//
//	string* elements;
//	string* first_free;
//	string* capacity;
//
//
//};
//
////拷贝构造函数
//
//StrVec::StrVec(const StrVec& SV) : elements(nullptr),first_free(nullptr),capacity(nullptr)
//{
//	//elements = new string;
//	// 这里需要改
//	//alloc.allocate(SV.capacity - SV.elements);
//	//*elements = *this->begin();
//	//first_free = elements + (SV.first_free - SV.elements);
//	//capacity = elements + (SV.capacity - SV.elements);
//	pair<string*, string*> newdata = alloc_n_copy(SV.elements, SV.first_free);
//	elements = newdata.first ;
//	first_free = newdata.second ;
//	capacity = newdata.second;
//
//	
//}
//
////赋值操作数函数
//StrVec& StrVec::operator = (const StrVec& SV)
//{
//	/*elements = SV.elements*/;
//	//alloc.allocate(elements, alloc_n_copy(SV.begin(), SV.end()));
//
//	pair<string* , string* > data = alloc_n_copy(SV.elements, SV.first_free);
//
//	free();
//
//	elements = data.first;
//	first_free = data.second;
//	capacity = data.second;
//	return *this;
//
//}
//
//
//StrVec::~StrVec()
//{
//	free();
//}
//
//
//void StrVec::push_back(const string& s)
//{
//	check_alloc_fullspace();
//	alloc.construct(first_free++ , s ) ;
//}
//
//size_t StrVec::size() const
//{
//	return first_free - elements;
//}
//
//size_t StrVec::capacity_size() const
//{
//	return capacity - elements;
//}
//
//const string* StrVec::cbegin() 
//{
//	return elements;
//}
//
//const string* StrVec::cend() 
//{
//	return first_free;
//}
//
//string* StrVec::begin()
//{
//	return elements;
//}
//
//string* StrVec::end()
//{
//	return first_free;
//}
//
//void StrVec::free()
//{
//	if (elements)
//	{
//		for (string* i = first_free; i != elements; )
//		{
//			alloc.destroy(--i);
//		}
//	}
//
//	alloc.deallocate(elements, capacity-elements);
//
//	//elements = nullptr;
//	//first_free = nullptr;
//	//capacity = nullptr;
//}
//
//
//void StrVec::reallocate()
//{
//	size_t newcapacity = ( size() == 0 ? 8 : ( size() <= 512 ? size()*8 : size() * 2 ) );
//	//alloc.construct(elements, begin(), end());
//	//free();
//
//	string* newdata = alloc.allocate(newcapacity);
//	string* source = elements;
//	string* destination = newdata;
//	for (size_t i = 0; i < size(); i++)
//	{
//		alloc.construct(destination++, *(source+i));  // move( * (source + i) ) 可以 强制 将其转为 右值 并移动赋值
//	}
//	// 如果没有 if 判断语句 ，那么会在第一次调用 reallocate 函数的时候 ，对一个赋值的空间进行 非法 解引用
//	if (size())
//	{
//		cout << *begin() << endl;
//	}
//
//	free();
//	elements = newdata;
//	first_free = destination;
//	capacity = elements + newcapacity;
//
//	
//}
//
//void StrVec::move_reallocate()
//{
//	size_t newcapacity = (size() == 0 ? 8 : (size() <= 512 ? size() * 8 : size() * 2));
//
//	string* first = alloc.allocate(newcapacity);
//	//************************  make_move_iterator 改为移动迭代器 ，移动迭代器 解引用后 变为 右值，因此该赋值为  移动赋值  **************
//    //**************************************************************************************  类似于  上个函数的 move( * (source + i) )
//	string* last = uninitialized_copy(make_move_iterator (begin()) ,make_move_iterator (end()), first);
//
//	if (size())
//	{
//		cout << *begin() << endl;
//	}
//
//	free();
//	elements = first;
//	first_free = last;
//	capacity = first + newcapacity;
//
//}
//
//
//
//
//void StrVec::check_alloc_fullspace() {
//	if (size() == capacity_size())
//	{
//		reallocate();
//	}
//}
//
//pair<string*, string*> StrVec::alloc_n_copy(const string* b, const string* e)
//{
//	string* data = alloc.allocate(e - b);
//	return { data , uninitialized_copy(b , e , data) };
//
//}
//
//
//
//
//
