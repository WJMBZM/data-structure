#include "4章.串-KMP-next-nextval.h"

//int main()
//{
//	int i = 0;
//	//char sub_string[20] = "aaaaaaaaaaaab";
//	//char main_string[20] = "aaaaaaaaaaaaaaaaaab";
//
//	char sub_string[20] = "abcabcabcabca";
//	char main_string[20] = "abcabca";
//
//	//char sub_string[20] = "abcabf";
//	//char main_string[20] = "abcabcabfab";
//
//
//
//	int* next = (int*)malloc(sizeof(int));  //整理的next数组整体类型都可以改为char，够用的，但是为了方便理解暂用int
//	//int next[20];  //这里会出现不可修改的问题
//	next = (int*)KMP_next(sub_string);
//	for ( i = 0; i < strlen(sub_string); i++)
//	{
//		printf("%d ", next[i]);
//	}
//	putchar('\n');
//
//	int* nextval = (int*)malloc(sizeof(int) * 20);
//	nextval = KMP_nextval(sub_string);
//	for ( i = 0; i < strlen(sub_string); i++)
//	{
//		printf("%d ", /**(nextval+i)*/nextval[i]);
//	}
//	putchar('\n');
//
//
//	strcmp_KMP(sub_string, main_string);
//
//
//	return 0;
//}
//
