//#define _CRT_SECURE_NO_WARNINGS 1
//#pragma once
//#include "4��.��-KMP-next-nextval.h"
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
////**************************************************KMP�㷨************************************************
//// 
////*******************next[]��:���ͬǰ��׺����Ϊnext���±��ڵ�ֵ***************************************
////*****************������ͻ�������������Ӵ����˵�next���±��ڵ�ֵ���Ӵ�λ�ô�����ƥ��********************
//
////*********************���°�nextval���ڷ�ֹ���˺��˻�λ�õ�ֵ��ƥ��ʧ�ܵ��ַ���ͬ***********************
////****************************�����һ���������ƥ��*******************************************************
////*************�ʵ�next[]�±��ڵ�ֵ��Ӧ�Ӵ�λ����ƥ��ʧ��λ�õ�ֵ��ͬʱ������next�±괦�Ӵ�λ�õ�nextval***
////***************************����ֱ��Ϊƥ��ʧ��λ�ô���next[]ֵ********************************************
//
//
//int main()             //next����ĺ�������
//{
//	//char main_string[20] = "aabaabaaf";    //��ʼ������
//	//char sub_string[20] = "aabaaf";        //��ʼ���Ӵ�
//	char main_string[20] = "aaaaaaaaab";    //��ʼ������
//	char sub_string[20] = "aaaaaaaab";        //��ʼ���Ӵ�
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
//			cmp_num = subscript - i;                  //ÿ��Ҫ�Ƚϵ��ַ���Ԫ�ظ���
//			cmp = strncmp(sub_string, sub_string + i, cmp_num);  //�ַ����Ƚ�cmp_numλ�󷵻ؽ��
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
//	int* strcmp_KMP_next = (int*)malloc(sizeof(int) * 20);  //�����next�����������Ͷ����Ը�Ϊchar�����õģ�����Ϊ�˷����������int
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
//		printf("ƥ��ɹ�\n");
//		printf("�������±�Ϊ%d��λ�ô���ʼ���ƥ��\n", main_string_corrent_position - sub_string_length);
//	}
//
//	return /*p_main - sub_string_length*/ 1;
//}