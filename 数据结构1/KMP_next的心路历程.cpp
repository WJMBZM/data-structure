//#define _CRT_SECURE_NO_WARNINGS 1
//#pragma once
//#include "4章.串-KMP-next-nextval.h"
////
////#include<stdio.h>
////#include<string.h>
////#include<math.h>
////#include<stdlib.h>
////#include<time.h>
////#include<Windows.h>
////#include<assert.h>
////#include<float.h>
////#include<ctype.h>
////#include<stddef.h>
////#include<errno.h>
////#include<malloc.h>
////#include<stddef.h>
////#include<iostream>
////
////
////#include<cstring>
////#include<string>
////#include<vector>
////#include<set>
////#include<map>
////#include<stack>
////#include<queue>
////#include<unordered_map>
////#include<unordered_set>
////#include<bitset>
////#include<algorithm>
////#include<cctype>
//
//
//using namespace std;
//
//
////**************************************************KMP算法************************************************
//// 
////*******************next[]求法:最长相同前后缀，则为next该下标内的值***************************************
////*****************发生冲突后，主串不动，子串回退到next该下标内的值的子串位置处继续匹配********************
//
////*********************更新版nextval意在防止回退后，退回位置的值与匹配失败的字符相同***********************
////****************************这会是一次无意义的匹配*******************************************************
////*************故当next[]下标内的值对应子串位置与匹配失败位置的值相同时，返回next下标处子串位置的nextval***
////***************************否则直接为匹配失败位置处的next[]值********************************************
//
//
//int main()             //next数组的函数构造
//{
//	//char main_string[20] = "aabaabaaf";    //初始化主串
//	//char sub_string[20] = "aabaaf";        //初始化子串
//	char main_string[20] = "aaaaaaaaab";    //初始化主串
//	char sub_string[20] = "aaaaaaaab";        //初始化子串
//	/*char*/ int next[20] = { 0 };
//	next[0] = -1;
//	int length = strlen(sub_string);
//	int subscript;
//	int i = 0;
//	int j = 0;
//	int cmp = -1;
//	int cmp_num = 0;
//	//for ( subscript = length ; subscript > 1; subscript--)
//	for (subscript = 2; subscript <= strlen(sub_string); subscript++)
//	{
//		for (i = 1  /*, j = subscript-1*/; i < subscript  /*length && j > 0 */; i++)
//		{
//			cmp_num = subscript - i;                  //每次要比较的字符串元素个数
//			cmp = strncmp(sub_string, sub_string + i, cmp_num);  //字符串比较cmp_num位后返回结果
//			if (cmp == 0)
//			{
//
//				break;
//			}
//			if (cmp != 0 && i == subscript - 1)
//			{
//				cmp_num--;
//			}
//
//		}
//
//		next[subscript] = cmp_num;
//
//	}
//	for (i = 0; i < length; i++)
//	{
//		printf("%d ", next[i]);
//	}
//
//	putchar('\n');
//
//	//string s("123456789");
//	//printf("%s\n",s.c_str());
//	//string s1(s, 2, 6);
//	//cout << s1 << endl;
//	//char arr1[] = s1.c_str();
//
//	return 0;
//}
//
//
//
//
//
//
//
//int* KMP_nextval(char* sub_string)
//{
//	int i = 0;
//	int* next = (int*)malloc(sizeof(int) * 20);
//	int* KMP_nextval = (int*)malloc(sizeof(int) * 20);
//	//char sub_string[20] = "aaaaaaaaaaaab";
//	next = KMP_next(sub_string);
//	KMP_nextval[0] = -1;
//
//	//for (i = 0; i < strlen(sub_string); i++)
//	//{
//	//	printf("%d ", next[i]);
//	//}
//	//putchar('\n');
//
//	for (i = 1; i <= strlen(sub_string); i++)
//	{
//		if (sub_string[i] != sub_string[next[i]])
//		{
//			KMP_nextval[i] = next[i];
//		}
//
//		else
//		{
//			KMP_nextval[i] = KMP_nextval[next[i]];
//		}
//
//	}
//
//
//	//for (i = 0; i < strlen(sub_string); i++)
//	//{
//	//	printf("%d ", KMP_nextval[i]);
//	//}
//	//putchar('\n');
//
//	return KMP_nextval;
//}
//
//
//
//
////char* strcmp_KMP()
//int main()
//{
//	int i = 0;
//	char sub_string[20] = "abcabf";
//	char main_string[20] = "abcabcabfab";
//
//	int* strcmp_KMP_next = (int*)malloc(sizeof(int) * 20);  //整理的next数组整体类型都可以改为char，够用的，但是为了方便理解暂用int
//	strcmp_KMP_next = KMP_next(sub_string);
//
//	int* strcmp_KMP_nextval = (int*)malloc(sizeof(int) * 20);
//	strcmp_KMP_nextval = KMP_nextval(sub_string);
//
//	int sub_string_length = strlen(sub_string);
//	int main_string_length = strlen(main_string);
//
//	char* p_main = main_string;
//	char* p_sub = sub_string;
//
//	int sub_string_back_position = 0;
//	int sub_string_corrent_position = 0;
//	int main_string_corrent_position = 0;
//
//	for (i = 0; i < strlen(sub_string); i++)
//	{
//		printf("%d ", strcmp_KMP_next[i]);
//	}
//	putchar('\n');
//
//	for (i = 0; i < strlen(sub_string); i++)
//	{
//		printf("%d ", strcmp_KMP_nextval[i]);
//	}
//	putchar('\n');
//
//	//for (; p_sub == NULL || main_string_length - main_string_corrent_position < sub_string_length - sub_string_corrent_position;)
//	while (*p_sub != '\0' && main_string_length - main_string_corrent_position > sub_string_length - sub_string_corrent_position)
//	{
//
//		if (*p_main == *p_sub)/*(p_main[main_string_corrent_position] == p_sub[sub_string_corrent_position])*/
//		{
//			p_main++;
//			p_sub++;
//			main_string_corrent_position++;
//			sub_string_corrent_position++;
//		}
//		else if (*p_main != *p_sub && strcmp_KMP_nextval[sub_string_corrent_position] == -1)
//			//(p_main[main_string_corrent_position] != p_sub[sub_string_corrent_position] && p_sub[sub_string_corrent_position] == -1)
//		{
//			p_main++;
//			main_string_corrent_position++;
//		}
//		else
//		{
//			sub_string_back_position = strcmp_KMP_nextval[sub_string_corrent_position];
//			sub_string_corrent_position = sub_string_back_position;
//			p_sub = &sub_string[sub_string_corrent_position];
//		}
//	}
//
//	if (*p_sub == '\0')
//	{
//		printf("匹配成功\n");
//		printf("在主串下标为%d的位置处开始完成匹配\n", main_string_corrent_position - sub_string_length);
//	}
//
//	return /*p_main - sub_string_length*/ 1;
//}