#include "5��.���νṹ.h"

//                     ����ַ��ɢ�б�����ڽӱ��
//int main()
//{
//	int* p = (int*)malloc(sizeof(int)*10);
//	int a = 10;
//	p[0] = a;
//
//	int** q = NULL;
//	q = (int**)malloc(sizeof(int*)*10);
//	q[0] = p;
//
//	printf("%d ",a);
//	printf("%d ", *q[0]);
//	putchar('\n');
//
//
//
//	return 0;
//}

//����ָ�롢����ָ�����顢ָ����ָ�������ָ��

int Add(int x, int y)
{
	return x + y;
}

int main()
{
	int arr1[] = { 1,2,3,4 };
	int arr2[] = { 2,3,4,5 };
	int arr3[] = { 3,4,5,6 };
	int* p[] = { arr1,arr2,arr3 };
	int* (*q)[3] = &p;
	printf("%d\n", (*q)[1][2]);

	int(*f[4])(int, int) = { Add };
	int(*(*pf)[4])(int, int) = &f;
	printf("%d", (*pf)[0](3, 5));

	return 0;
}

