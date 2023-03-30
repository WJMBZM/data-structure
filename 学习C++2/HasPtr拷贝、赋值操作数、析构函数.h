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


#include <fstream>
#include <sstream>

//  上下间隔

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include<cstring>
#include <initializer_list>
#include <stdexcept>  //runtime_error() 显示异常类型函数
//#include <wincrypt.h>

using namespace std;

using  std::string;


////****************************************************拷贝、赋值操作数、析构函数************************************

class HasPtr
{
public:


	HasPtr( const size_t ) : ps(NULL), id(0) ,function_id(0){} ;

	//HasPtr() = default;

	HasPtr(const string& s = string()) : ps(new string(s)), id(0), function_id(0) {};

	HasPtr(HasPtr& copy) :ps(copy.ps), function_id(copy.function_id), id(copy.id)/* ,id( function_id == 0 ?  copy.id + 1 : function_id-- )*/ 
	{ 
		//if (function_id == 0)
		//{
		//	id += 1;  // id+1 当时怎么想的?................
		//}
		if (function_id != 0)
		{
			function_id--;
		}
		else
		{
			id++;
		}
	};

	HasPtr& operator = (const HasPtr& hp)
	{
		delete ps;
		ps = new string;
		*(this->ps) = *(hp.ps);
		this->id = hp.id + 1;    // 因为这里  分配的是  新建的空间  析构也不会影响其他 类成员 空间   因此 此处不必  id+1
		cout << this->id << endl;
		return *this;
	}

	//HasPtr& operator = (f(HasPtr))



	//HasPtr& f(const HasPtr& hp);

	~HasPtr() { if (id-- == 0 ) delete ps; };

	void id_increase() { id++; }
	void id_reduce() { id--; }
	void function_id_increase() { function_id++; }
private:
	string* ps;
	size_t id;
	size_t function_id;

};

HasPtr& f(const HasPtr& hp)
{
	//hp.id_increase();

	/*static*/    /*HasPtr ret("hello world");*/
	HasPtr ret;
	ret.function_id_increase();
	
	// 
	// ret = (const HasPtr&)    等价于   ret.operator = ( const HasPtr& )
	/*ret = */ ret.operator= ( hp ) ;

	return ret;
}

