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

//  ���¼��

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include<cstring>
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
	//typedef string::size_type pos;    //������ �ֶ�
	//pos height1;
	//pos width1;
	//char c;


public:

	int i = 0;

	typedef string::size_type pos;

	Screen() = default;
	//           �����ǲ���                 //��Ū�����ˣ�������һ����ʼ������, ð�ź��,���������� ��Ա���� �������� �ǳ�ʼ�������Ĳ���
	                                          //    *******************************�����ú�����ߵĲ�������ʼ�����Ա����
	Screen(	pos height1 , pos width1 , char c )  : height ( height1 ) , width ( width1 ) , contents ( 6 , c)
	{
		// ����������������ֱ�Ӹ�ֵ������ʼ�� ���Ա����
		/*height1 = 10;*/ //����Ҳ���Գ�ʼ����ֵ

		cout << height << endl;


		height = 20;  //�������ڲ��ĳ�ʼ��    �Ҳ�ȷ�������ȼ�����  �������ⲿ�ĳ�ʼ��  ����˵�����ڲ��ĳ�ʼ���ں����ⲿ�ĳ�ʼ���ĺ��
		              //             �������ڲ��ĳ�ʼ��  ���������ˣ���  �������ⲿ�ĳ�ʼ��***********************

		cout << height << " "       
			<< width << " " 
			<< contents << endl;    //����߿����ǲ�������
	};

	//��ȡ��괦���ַ�
	char get() const                          //��ʽ����
	{
		return contents[cursor];
	}
	inline char get(pos ht, pos wd)const;

	    //��ʽ����
	

	Screen& move(pos r, pos c);              //����֮������Ϊ����

	Screen& Change_content(char);
	//���ﲻҪд��   Scrren& Screen::Change_content(char);    ��Ȼ�ᱨ��

	inline Screen& Change_content2(size_t , size_t , char );


	void example_mutable() const
	{
		count++;
		// ������Ȼ this* �� const ������ �� �������� count ��һ�� mutable  �ɱ��������� �� ���� this->count ���ɿ��Ա��޸�

	}


	//**************************  �Ҳ�����Ϊʲô�±��������������ܹ��ⲿ������ֻ��д�����  **************************
	//**************************  �п�һ�����������
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
	// �ɱ����ݳ�Ա����   mutable
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















