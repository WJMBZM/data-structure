#pragma once


#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<assert.h>
#include<float.h>
#include<ctype.h>
#include<stddef.h>
#include<errno.h>
#include<malloc.h>
#include<stddef.h>
#include<iostream>


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

//  上下间隔，上为c库


#include <iostream>
#include <vector>
#include <iterator>

#include <string>

#include<cstring>

#include<set>
#include<map>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include<algorithm>
#include<cctype>

#include <initializer_list>

#include <stdexcept>  //runtime_error() 显示异常类型函数

using namespace std;

using  std::string;
//两种写法，第二种写法  引用范围较小

// ：：
//一、（类）作用域符号
//二、全局作用域符号
//三、作用域分解运算符
//四、命名空间作用域符号



#include<string>




struct Sales_Data
{
	string isbn() const
	{
		return Book_Number;
	}
	//Sales_Data& string
	//Sales_Data& isbn2() const
	//{
	//	return Book_Number;
	//}

	Sales_Data& conbine(const Sales_Data&);
	Sales_Data& conbine2(const Sales_Data& another_one);
	double average_price() const;
	string Book_Number;
	unsigned sales_number = 0;
	double revenue = 0.0;
	double price = 0.0/*revenue / sales_number*/;
};



Sales_Data add(const Sales_Data&, const Sales_Data&);
ostream& print(ostream& Data_out, const Sales_Data&);
istream& read(istream& Data_in, Sales_Data&);


//string isbn 类成员函数 实际意义，以下为 伪代码
// 
//string Sales_Data::isbn(const Sales_Data* this)
//{
//	return this->isbn;
//}



//***********以下为自定义构造函数******************************

class Sales_Data2
{
public:
	//string isbn() const 
	//{
	//	return book_number;
	//}

	Sales_Data2() : book_number(""), sales_number(0), price(0), book_revenue(0) {}; //此语句表示类型构造中，使用默认构造函数
	Sales_Data2(const string book_number1, unsigned int sales_number1, double book_revenue1)
		: book_number(book_number1), sales_number(sales_number1), book_revenue(book_revenue1), price(book_revenue1/sales_number1) {}
	/*Sales_Data2(istream&);*/
	Sales_Data2(const Sales_Data2& SD) :book_number(SD.book_number), sales_number(SD.sales_number), price(SD.price)
		, book_revenue(SD.book_revenue) {};

	string is_book_number() const
	{
		return book_number;
	}

	//Sales_Data2& combine2(const Sales_Data2&);
	double average_price()
	{
		return book_revenue / sales_number;
	}

//private:

	string book_number;
	size_t sales_number ;
	double book_revenue ;
	double price ;

};


















