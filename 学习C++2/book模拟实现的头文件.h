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

//  ���¼������Ϊc��


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

#include <stdexcept>  //runtime_error() ��ʾ�쳣���ͺ���

using namespace std;

using  std::string;
//����д�����ڶ���д��  ���÷�Χ��С

// ����
//һ�����ࣩ���������
//����ȫ�����������
//����������ֽ������
//�ġ������ռ����������



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


//string isbn ���Ա���� ʵ�����壬����Ϊ α����
// 
//string Sales_Data::isbn(const Sales_Data* this)
//{
//	return this->isbn;
//}



//***********����Ϊ�Զ��幹�캯��******************************

class Sales_Data2
{
public:
	//string isbn() const 
	//{
	//	return book_number;
	//}

	Sales_Data2() : book_number(""), sales_number(0), price(0), book_revenue(0) {}; //������ʾ���͹����У�ʹ��Ĭ�Ϲ��캯��
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


















