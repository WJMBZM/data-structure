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

typedef size_t line_number;

class QueryResult;

class TextQuery 
{
public:
	TextQuery(ifstream&);
	QueryResult query(const string&) const;

private:
	shared_ptr<vector<string>> file_line;
	map < string , shared_ptr < set<line_number>>> map_find_line;

};



TextQuery::TextQuery(ifstream& is) : file_line( new vector<string> )
{
	string text;
	while ( getline (is, text ) )
	{
		file_line->push_back(text);
		size_t n = file_line->size() - 1;
		istringstream line(text);
		string word;

		//shared_ptr < set<line_number>> lines1 = map_find_line["I"];
		//shared_ptr < set<line_number>> lines2 = map_find_line["have"];
		//shared_ptr < set<line_number>> lines3 = map_find_line["a"];
		//shared_ptr < set<line_number>> lines4 = map_find_line["dream"];

		while (line >> word)
		{
			shared_ptr < set<line_number>> lines = map_find_line[word];
			//shared_ptr < set<line_number>> & lines = map_find_line[word];
			//***********此处引用极其重要
			//***************后方动态分配空间的时候，如果没有这个引用，该新建指针 将会失去意义 ，不能将空间分给 map

			//if (lines == NULL)


			if ( !lines )
			{
				/*lines.reset(new set<line_number>);*/
				//map_find_line[word] = (shared_ptr<set <line_number>>) new set<line_number>;
				lines = (shared_ptr<set <line_number>>) new set<line_number>;
				map_find_line[word] = lines;
			}
			lines->insert(n);


			// /*<<  *lines->begin()*/    /*(map_find_line[word]->size())*/   /*" size2 " << map_find_line[word]->size() <<*/ 
			cout << word << " "  << " " << *(--lines->end()) << " size " << lines->size() 
				<< endl;
		}
		//static set<line_number> p = *map_find_line[word];
		//for (auto i : *map_find_line[word])
		//{
		//	cout << i << endl;
		//}
	}

	;
}



class QueryResult 
{

public:
	friend ostream& print(ostream&, const QueryResult&);
public:
	QueryResult(string sought_1, shared_ptr< set<line_number>> line_num, shared_ptr< vector<string>> file_l)
		: sought(sought_1) , line_number(line_num) , file_line (file_l) {};


private:
	string sought;
	shared_ptr <set <line_number>> line_number;
	shared_ptr < vector < string>> file_line;

};
ostream& print(ostream&, const QueryResult&);

QueryResult TextQuery::query(const string& sought) const
{
	static shared_ptr <set<line_number>> nodata (new set<line_number>);

	map<string, shared_ptr <set<line_number>>>::const_iterator  locate = map_find_line.find(sought);

	if (locate == map_find_line.end())
	{
		return QueryResult( sought , nodata , file_line);
	}
	else
	{
		return QueryResult(sought, map_find_line.find(sought)->second, file_line);
	}


}

ostream& print(ostream& os, const QueryResult& qr)
{
	cout << qr.sought << " occurs " << qr.line_number->size() << " " << (qr.line_number->size() >= 2 ? " times " : " time ") << endl;

	for (line_number num : *(qr.line_number))
	{
		os << "\t(line:" << num + 1 << ")" << *(qr.file_line->begin() + num) << endl;
	}

	return os;
}


void runQueries( ifstream& infile)
{
	TextQuery tq(infile);

	while (true)
	{
		cout << "input the word that you want query , or q to quit" << endl;
		string sought;
		if (!(cin >> sought) || sought == "q")
		{
			break;
		}
		print(cout, tq.query(sought)) << endl;

	}

}





