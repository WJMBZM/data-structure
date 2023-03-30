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
//StrVec::StrVec(const StrVec& SV) : elements(nullptr), first_free(nullptr), capacity(nullptr)
//{
//
//	pair<string*, string*> newdata = alloc_n_copy(SV.elements, SV.first_free);
//	elements = newdata.first;
//	first_free = newdata.second;
//	capacity = newdata.second;
//
//}
//
////赋值操作数函数
//StrVec& StrVec::operator = (const StrVec& SV)
//{
//
//	pair<string*, string* > data = alloc_n_copy(SV.elements, SV.first_free);
//	free();
//	elements = data.first;
//	first_free = data.second;
//	capacity = data.second;
//	return *this;
//
//}
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
//	alloc.construct(first_free++, s);
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
//			i--;
//			alloc.destroy(i);
//		}
//	}
//
//	alloc.deallocate(elements, capacity - elements);
//
//}
//
//void StrVec::reallocate()
//{
//	size_t newcapacity = (size() == 0 ? 8 : (size() <= 512 ? size() * 8 : size() * 2));
//
//	string* newdata = alloc.allocate(newcapacity);
//	string* source = elements;
//	string* destination = newdata;
//	for (size_t i = 0; i < size(); i++)
//	{
//		alloc.construct(destination++, move(*source++));
//	}
//	free();
//	elements = newdata;
//	first_free = destination;
//	capacity = elements + newcapacity;
//
//
//}
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
