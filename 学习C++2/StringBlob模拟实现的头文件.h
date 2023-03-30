#pragma once

#include<stdio.h>
#include<stdlib.h>

#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include<algorithm>
#include<cctype>


#include <thread>
#include <deque>
#include <numeric>
#include <utility>

//  上下间隔

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include<cstring>
#include <initializer_list>
#include <stdexcept>  //runtime_error() 显示异常类型函数

using namespace std;

using  std::string;

//typedef vector<string>::size_type size_type;

class StringBlob
{
	friend ostream& operator<< (ostream& os, StringBlob& SB);
public:
	typedef vector<string>::size_type size_type;
	//friend void check(const size_type& size, const string& message);
	StringBlob();
	StringBlob(initializer_list<string>il);
	size_type size();
	bool empty();
	void push_back(string& string);
	void pop_back();
	string front();
	string back();

private:
	shared_ptr<vector<string>> Data;
	void check(const size_type& size ,const string& message);


};

StringBlob::StringBlob():Data(make_shared<vector<string>>()) {};

StringBlob::StringBlob(initializer_list<string>il) :Data(make_shared<vector<string>>(il)){};

StringBlob::size_type StringBlob::size()
{
	return Data->size();
}

bool StringBlob::empty()
{
	return Data->size() == 0 ? 1 : 0;
}

void StringBlob::push_back(string& string)
{
	Data->push_back(string);
}

void StringBlob::pop_back()
{
	check(Data->size(),"StringBlob is empty!");
	Data->pop_back();
}

string StringBlob::front()
{
	check(Data->size(), "StringBlob is empty!");
	return Data->front();
}

string StringBlob::back()
{
	check(Data->size(), "StringBlob is empty!");
	return Data->back();
}

void StringBlob::check(const StringBlob::size_type& size,const string& message)
{
	if (!size)
	{
		throw out_of_range(message);
	}
}

ostream& operator<< (ostream& os, StringBlob& SB)
{
	for (size_t i = 0; i < SB.size(); i++)
	{
		os << *(&SB.Data->front() + i) << "  "/*<< endl*/;
	}
	return os;
}





//blob<T> push_back(T& type_vector)
//{
//	data->push_back(type_vector);
//	return *this;
//}
//blob<T> push_back(T&& type_vector)
//{
//	data->push_back(move(type_vector));
//	return *this;