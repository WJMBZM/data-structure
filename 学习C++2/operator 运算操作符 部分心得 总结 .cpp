#include "book模拟实现的头文件.h"
#include "StrVec动态内存分配allocate.h"


// ************************************************** 1

ostream& operator<< (ostream& os, Sales_Data2& SD)
{
	os << SD.book_number << "   " << SD.sales_number << "   " << SD.price << "   " << SD.book_revenue << endl;
	return os;
}


Sales_Data2 operator + (const Sales_Data2& first_data, const Sales_Data2& second_data)
{
	if (first_data.book_number == second_data.book_number)
	{
		Sales_Data2 sum = first_data;
		//sum.book_number += second_data.book_number;
		sum.sales_number += second_data.sales_number;
		//sum.price += second_data.price;
		sum.book_revenue += second_data.book_revenue;
		sum.price = sum.book_revenue / sum.sales_number;
		return sum;
	}
	else
	{
		cout << "book_number is different!" << endl;
		Sales_Data2 SD;
		return SD;
	}


}
//
//int main()
//{
//	Sales_Data2 SD1("2023-3-21", 20, 1000);
//	Sales_Data2 SD2(SD1);
//	cout << SD1 << SD2;
//
//	Sales_Data2 SD3 = SD1 + SD2;
//
//	cout << SD3 << endl;
//
//	/*Sales_Data2*/ SD3 = operator+ (SD1, SD2);
//
//	operator<< (cout, SD3) << endl;
//
//	//*******************************  SD3 = SD1 + SD2;                 ****************
//	//*******************************     等价于                        ****************
//	//*******************************  operator + ( SD1 , SD2 )         ****************
//
//	//*******************************  cout << SD3                      ****************
//	//*******************************     等价于                        ****************
//	//*******************************  operator << ( cout , SD3 )       ****************
//
//	return 0;
//}

////  ****************************************************************************************
////  ********************************   2. 以下是对  类  对象 构造的  赋值函数  和  输出函数
//
//
StrVec& StrVec::operator = (initializer_list<string> il)
{
	//     ********************   alloc_n_copy  函数 自动分配空间，并且拷贝 从 begin 到 end 区间内的 对象  ，返回一个pair 对象
	//******************************************************该 pair 对象 第一个指向 空间 首对象 ，第二个指向 尾对象 下一个空间
	pair<string*, string*> data = alloc_n_copy(il.begin(), il.end());
	free();
	this->elements = data.first;
	first_free = data.second;
	capacity = data.second;
	current_position = data.first;
	return *this;

}

ostream& operator<<(ostream& os, StrVec& SV)
{
	for (string* i = SV.begin() ; i != SV.end() ; i++)
	{
		os << *i << " "/*<< endl*/;
	}

	return os;
}
//
//
//int main()
//{
//	vector <string> s;
//	s = { "hello" , "world" };
//	cout << s[0] << endl;
//
//	StrVec SV;
//	SV = { "Hello" , "world" ,"520" , "1314"};
//	cout << *SV.begin() << endl;
//
//	cout << SV;
//
//
//	return 0;
//}


//int main()
//{
//	vector <string> s;
//	s = { "hello" , "world" };
//	cout << s[0] << endl;
//	s.push_back("520");
//	cout << s[2] << endl;
//
//	StrVec SV;
//	SV = { "hello" , "world" ,"5201314"};
//	cout << SV << endl;
//
//	cout << SV[2] << endl;
//
//	//auto s = {"hello" , "world" , "5201314"};
//	//string* ps = s;
//
//
//	return 0;
//}

//  + / += / ++ 等操作符 函数 构造
//int main()
//{
//	StrVec SV1;
//	SV1 = { "hello" , "world" , "520" , "1314" };
//	StrVec SV2 = SV1 + 2;
//	cout << *SV2.current() << "  " << *SV1.current() << endl;
//
//	SV2 += 1;
//	cout << *SV2.current() << endl;
//
//	SV2.operator++ ();
//	cout << *SV2.current() << endl;
//
//	SV2.push_back("5201314_CYM");
//	SV2.operator++();
//	cout << *SV2.current() << endl;
//
//	return 0;
//}


//*********************************************************        3.         ********************************************************
//   神奇的    函数对象...............                          3.小括号  操作符函数
struct absolute_value
{
	int count = 0;
	int operator()(int i)
	{
		count++;
		return i > 0 ? i : -i;
	}

};
//
//int main()
//{
//	int i = -100;
//	absolute_value av;
//	cout << av.count << endl;
//
//	cout <<av(i) << endl;
//
//	cout << av.count << endl;
//
//
//	return 0;
//}


//*******************************   转换函数    **************************************************
//*******************************  4.通过转换函数，将类对象 转换为 "内置(可能有其他)" 类型
//*******************************   形式为  operator type() {};

class  small_int 
{
public:
	small_int() : value(0) {};
	small_int(size_t i) : value(i) 
	{
		if (i < 0 || i > 255)
		{
			cerr << "wrong value!" << endl;
		}
	};

	//operator int() const { return value; }  // 支持隐式转换

	explicit operator int() const { return value; }  //  仅支持显式转换

	size_t shou_value() 
	{
		return value;
	}
private:
	size_t value;

};



//
//int main()
//{
//	small_int si;
//	si = 3; // 将4隐式转换为 small_int 类 对象
//	cout << si.shou_value() << endl;
//
//	/*int i = si + 3;*/    // 这里通过 转换函数 将 si 类对象 隐式 转换为int类型
//	                 // 如果转换函数 声明了 explicit 类型  则不支持隐式转换
//	                 
//	//***************需要 显式类型转换
//	int i = (int)si + 3;
//	cout << i << endl;
//	//*************** 或者 这样 显示类型 转换
//	i = static_cast<int>(si) + 6;
//
//	cout << i << endl;
//
//	unsigned char c;
//
//	return 0;
//}







