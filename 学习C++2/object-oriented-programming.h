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

#include <array>
#include <memory>
#include <functional>

//  ���¼��

#include <iostream>
#include <iterator>
#include <initializer_list>
#include <stdexcept>  //runtime_error() ��ʾ�쳣���ͺ���
//#include <wincrypt.h>

using namespace std;
using  std::string;

class quote
{
public:
	quote() = default;
	quote(string book_no, double pri) :book_number(book_no) , price (pri ) {};
	string isbn()
	{
		return book_number;
	}
	virtual double revenue(size_t n) const
	{
		return n * price;
	}
	virtual ~quote() = default;

private:
	string book_number;


protected:
	double price = 0;


};

class bulk_quote : public  quote
{
public:
	bulk_quote() = default;
	bulk_quote(string ,double , const size_t , double);
	double revenue(size_t n) const override;    // �������� override  �����˳�Ա  ��������  �麯�� virtual
	//{
	//	return (n * discount) * min_quantity;
	//}

	//      // �˴��ᱨ��   ��Ϊ����Ȩ��
	//friend string test( )
	//{
	//	return book_number;
	//}

private:
	size_t min_quantity = 0;
	double discount = 0;

};

bulk_quote::bulk_quote(string book_number, double price, const size_t n, double d2) : quote( book_number , price), min_quantity(n), discount(d2) {};

double bulk_quote::revenue(size_t n)const
{
	if (n >= min_quantity)
	{
		return n * (price * discount);
	}
	else
	{
		return n * price;
	}

}









