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
//两种写法，第二种写法  引用范围较小

// ：：
//一、（类）作用域符号
//二、全局作用域符号
//三、作用域分解运算符
//四、命名空间作用域符号


class screen
{
public:
	//screen();
	//~screen();
	typedef string::size_type pos;

private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	string contents;
};

//screen::screen()
//{
//}
//
//screen::~screen()
//{
//}

class Screen
{
	//typedef string::size_type pos;    //这里是 字段
	//pos height1;
	//pos width1;
	//char c;


public:

	int i = 0;

	typedef string::size_type pos;

	Screen() = default;
	//           这里是参数                 //我弄明白了，这里是一个初始化函数, 冒号后边,括号外是类 成员变量 ，括号内 是初始化函数的参数
	                                          //    *******************************这里用函数里边的参数来初始化类成员变量
	Screen(	pos height1 , pos width1 , char c )  : height ( height1 ) , width ( width1 ) , contents ( 6 , c)
	{
		// 我甚至可以在这里直接赋值，来初始化 类成员变量
		/*height1 = 10;*/ //参数也可以初始化或赋值

		cout << height << endl;


		height = 20;  //函数体内部的初始化    我不确定是优先级高于  函数体外部的初始化  还是说函数内部的初始化在函数外部的初始化的后边
		              //             函数体内部的初始化  ！！覆盖了！！  函数体外部的初始化***********************

		cout << height << " "       
			<< width << " " 
			<< contents << endl;    //这里边可以是操作函数
	};

	//读取光标处的字符
	char get() const                          //隐式内联
	{
		return contents[cursor];
	}
	inline char get(pos ht, pos wd)const;

	    //显式内联
	

	Screen& move(pos r, pos c);              //能在之后设置为内联

	Screen& Change_content(char);
	//这里不要写成   Scrren& Screen::Change_content(char);    不然会报错

	inline Screen& Change_content2(size_t , size_t , char );


	void example_mutable() const
	{
		count++;
		// 这里虽然 this* 被 const 修饰了 ， 但是由于 count 是一个 mutable  可变数据类型 ， 所以 this->count 依旧可以被修改

	}


	//**************************  我不明白为什么下边这三个函数不能够外部声明，只能写在里边  **************************
	//**************************  有空一定请教下他人
	const Screen& display(ostream& os) const
	{
		do_display(os);

		return *this;
	}

	Screen do_display(ostream& os) const
	{
		os << contents;
		return *this;
	}

	Screen& display(ostream& os) 
	{
		do_display(os);

		return *this;
	}

	pos get_height()
	{
		return height;
	}

private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	string contents;
	// 可变数据成员类型   mutable
	mutable size_t count = 0 ;

};

inline Screen& Screen::move(pos r, pos c)
{
	pos row = r * width;
	(*this).cursor = row + c;

	return *this;

}

char Screen::get(pos r, pos c) const
{
	pos row = r * width;

	return contents[row + c];
}

inline Screen& Screen::Change_content(char c)
{
	contents[cursor] = c;
	return *this;

}

inline Screen& Screen::Change_content2(size_t row ,size_t column ,char c)
{
	contents[row * width + column] = c;

	return *this;
}

//const Screen& Screen::display(ostream& os) const
//{
//	do_display(os);
//
//	return *this;
//}

//Screen Screen::do_display(ostream& os) const
//{
//	os << contents;
//	return *this;
//}

//Screen& Screen::display(ostream& os)
//{
//	do_display(os);
//
//	return *this;
//}















