#include "4��.��-KMP-next-nextval.h"

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
//	int* next = (int*)malloc(sizeof(int));  //�����next�����������Ͷ����Ը�Ϊchar�����õģ�����Ϊ�˷����������int
//	//int next[20];  //�������ֲ����޸ĵ�����
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
