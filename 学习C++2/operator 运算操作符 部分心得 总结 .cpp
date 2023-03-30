#include "bookģ��ʵ�ֵ�ͷ�ļ�.h"
#include "StrVec��̬�ڴ����allocate.h"


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
//	//*******************************     �ȼ���                        ****************
//	//*******************************  operator + ( SD1 , SD2 )         ****************
//
//	//*******************************  cout << SD3                      ****************
//	//*******************************     �ȼ���                        ****************
//	//*******************************  operator << ( cout , SD3 )       ****************
//
//	return 0;
//}

////  ****************************************************************************************
////  ********************************   2. �����Ƕ�  ��  ���� �����  ��ֵ����  ��  �������
//
//
StrVec& StrVec::operator = (initializer_list<string> il)
{
	//     ********************   alloc_n_copy  ���� �Զ�����ռ䣬���ҿ��� �� begin �� end �����ڵ� ����  ������һ��pair ����
	//******************************************************�� pair ���� ��һ��ָ�� �ռ� �׶��� ���ڶ���ָ�� β���� ��һ���ռ�
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

//  + / += / ++ �Ȳ����� ���� ����
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
//   �����    ��������...............                          3.С����  ����������
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


//*******************************   ת������    **************************************************
//*******************************  4.ͨ��ת��������������� ת��Ϊ "����(����������)" ����
//*******************************   ��ʽΪ  operator type() {};

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

	//operator int() const { return value; }  // ֧����ʽת��

	explicit operator int() const { return value; }  //  ��֧����ʽת��

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
//	si = 3; // ��4��ʽת��Ϊ small_int �� ����
//	cout << si.shou_value() << endl;
//
//	/*int i = si + 3;*/    // ����ͨ�� ת������ �� si ����� ��ʽ ת��Ϊint����
//	                 // ���ת������ ������ explicit ����  ��֧����ʽת��
//	                 
//	//***************��Ҫ ��ʽ����ת��
//	int i = (int)si + 3;
//	cout << i << endl;
//	//*************** ���� ���� ��ʾ���� ת��
//	i = static_cast<int>(si) + 6;
//
//	cout << i << endl;
//
//	unsigned char c;
//
//	return 0;
//}







