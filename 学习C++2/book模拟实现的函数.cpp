#include "book模拟实现的头文件.h"

double Sales_Data::average_price() const   // ()调用的参数 实则为自身  *this
{
	if (sales_number != 0)
	{
		return revenue / sales_number;
	}
	else
	{
		return 0;
	}

}

Sales_Data& Sales_Data::conbine(const Sales_Data& another_one)
{
	if (this->isbn() == another_one.isbn())
	{
		this->sales_number = this->sales_number + another_one.sales_number;
		this->revenue = this->revenue + another_one.revenue;
	}

	return *this;
}

//********************************** conbine 的两种写法   *********************************************
Sales_Data& Sales_Data::conbine2(const Sales_Data& another_one)
{
	if (isbn() == another_one.isbn())
	{
		sales_number = sales_number + another_one.sales_number;
		revenue = revenue + another_one.revenue;
	}

	return *this;
}

istream& read(istream& Data_in, Sales_Data& item)
{
	Data_in >> item.Book_Number >> item.sales_number >> item.price;
	item.revenue = item.sales_number * item.price;
	return Data_in;

}

//istream& read(istream& Data_in, Sales_Data& item)
//{
//	// TODO: 在此处插入 return 语句
//	Data_in >> item.Book_Number >> item.sales_number >> item.price;
//	item.revenue = item.sales_number * item.price;
//	return Data_in;
//}

ostream& print(ostream& Data_out, const Sales_Data& item)
{
	Data_out << /*item.Book_Number*/item.isbn() << " "
		<< item.sales_number << " "
		<< item.revenue << " "
		<< item.average_price() << endl;

	return Data_out;
}

Sales_Data add(const Sales_Data& item1, const Sales_Data& item2)
{
	Sales_Data item3;
	item3.revenue = item1.revenue + item2.revenue;
	item3.sales_number = item1.sales_number + item2.sales_number;
	item3.price = item3.average_price();

	return item3;
}



Sales_Data add2(const Sales_Data& item1, const Sales_Data& item2)
{
	Sales_Data item3 = item1;
	item3.conbine(item2);
	item3.price = item3.average_price();

	return item3;
}


//istream& read2(istream& Data_in, Sales_Data2 item)
//{
//	Data_in >> item.book_number >> item.sales_number >> item.price;
//	item.book_revenue = item.sales_number * item.price;
//	return Data_in;
//
//}

//Sales_Data2& Sales_Data2::combine(const Sales_Data2& another_one)
//{
//	this->sales_number = this->sales_number + another_one.sales_number;
//	this->book_revenue = this->book_revenue + another_one.book_revenue;
//
//	return *this;
//}