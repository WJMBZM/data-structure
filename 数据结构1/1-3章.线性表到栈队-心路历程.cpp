//#define _CRT_SECURE_NO_WARNINGS 1
//#pragma once
//#include "1-3��.�㷨���.h"
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
//
//#define LinkList_length elem
////#define MaxSize 100
//
////              ****************************************1.˳���***********************************************
////typedef struct Sqlist
////{
////	int* arr;
////	int length;
////
////}SqList;
////
////int Locate_SqList(const SqList& L, int elem)
////{
////	int i = 0;
////	while (L.arr[i] != elem && i < L.length)
////	{
////		i++;
////	}
////	if (i == L.length)
////	{
////		printf("˳�����û�и�Ԫ��");
////		return 0;
////	}
////	return ++i;
////}
////
////int Insert_SqList(SqList &L,int elem,int locate)  //����ɹ�����1�����򷵻�0
////{   
////	int i = 0;
////	if (locate >L.length+1 || locate < 1 )
////	{
////		printf("����λ���쳣,�������һ��λ�û�С�����һ��λ��");
////		return 0;
////	}
////	else
////	{
////		for ( i = L.length ; i >= locate ; i--)
////		{
////			L.arr[i] = L.arr[i - 1];
////		}
////		L.arr[locate-1] = elem;  // �����locate λ��ҲҪ-1 ����Ϊ�±�-1
////
////	}
////
////	L.length++;                //********************��һ������Ҫ�������һ��Ҫ����  +1
////
////	return 1;
////}
////
////int Delete_SqList( SqList &L , int locate)
////{
////	int i = 0;
////	if ( locate < 1 || locate >L.length )
////	{
////		printf("ɾ��λ�ô���");
////		return 0;
////
////	}
////	else
////	{
////		for (i = locate; i < L.length; i++)
////		{
////			L.arr[i - 1] = L.arr[i];
////		}
////	}
////	L.length--;
////
////	return 1;
////}
////
////int Updata_SqList(SqList &L , int elem , int locate)
////{
////	if (locate > L.length || locate < 1)
////	{
////		printf("�޸�λ�ô���");
////		return 0;
////	}
////	else
////	{
////		L.arr[locate-1] = elem;            //ע��-1
////	}
////
////
////	return 1;
////}
////
////int main()
////{
////	SqList s1;
////	s1.length = 10;
////	s1.arr = (int*)malloc(sizeof(int) * 100);
////	int i = 0;
////	for (i = 0; i < 10; i++)
////	{
////		s1.arr[i] = i;
////
////	}
////
////	printf("˳���s1������Ϊ3��Ԫ���ǵ�%d��\n", Locate_SqList(s1 , 3));
////
////	Insert_SqList(s1, 66, 11);
////	for ( i = 0; i < s1.length; i++)
////	{
////		printf("%d ", s1.arr[i]);
////	}
////
////	putchar('\n');
////
////	Delete_SqList(s1, 11);
////	for ( i = 0; i < s1.length; i++)
////	{
////		printf("%d ", s1.arr[i]);
////	}
////	putchar('\n');
////
////	Updata_SqList(s1,88,10);
////	for ( i = 0; i < s1.length; i++)
////	{
////		printf("%d ", s1.arr[i]);
////	}
////	putchar('\n');
////
////	free(s1.arr);
////
////	return 0;
////}
//
//
//////   *********************************************2.����*************************************************
////
////typedef struct linknode
////{
////	int elem;
////	struct linknode* next;
////
////}LinkNode;
////
////typedef struct head_linknode             //ͷ�������λ��������
////{
////	int length ;
////	LinkNode* next;
////}Head_LinkNode;
////
////typedef struct linklist                  //�Ľ������ͷ���
////{
////	int LinkList_length;
////	LinkNode* next;
////
////}LinkList;
////
////// *************************************************����ɹ�����1�����򷵻�0 **********************************
////int Insert_LinkList(LinkList *L,int elem , int locate)          
////{
////	int i = 0;
////	LinkNode* p_prior =(LinkNode*)L;
////	LinkNode* p_back =(LinkNode*)L;
////	LinkNode* New_Node = (LinkNode*)malloc(sizeof(LinkNode));
////	if (New_Node == NULL)
////	{
////		printf("�����½ڵ�ʱʧ��!");
////		return 0;
////	}
////	New_Node->elem = elem;
////	if (locate < 1 || locate > L->elem)
////	{
////		printf("����λ�ô���");
////		return 0;
////	}
////	else if (locate == L->LinkList_length)
////	{
////		for ( i = 0; i < locate-1; i++)
////		{
////			p_prior = p_prior->next;
////		}
////		p_prior->next = New_Node;
////		New_Node->next = NULL;
////		L->LinkList_length++;
////
////	}
////	else
////	{
////		for ( i = 0; i < locate-1 ; i++)
////		{
////			p_prior = p_prior->next;
////		}
////		p_back = p_prior->next;
////		New_Node->next = p_back;
////		p_prior->next = New_Node;
////		L->LinkList_length++;
////	}
////
////	return 1;
////}
////
////// ***************************************ɾ���ɹ�����ɾ���Ľڵ㣬���򷵻�0*********************************
////LinkNode* Delete_LinkList(LinkList* L, int locate)         
////{
////	int i = 0;
////	LinkNode* p_prior = (LinkNode*)L;
////	LinkNode* p_back = (LinkNode*)L;
////	if (locate < 1 || locate > L->LinkList_length)
////	{
////		printf("ɾ����λ�ô���!");
////		return 0;
////
////	}
////	else if (locate == L->LinkList_length)
////	{
////		for ( i = 0; i < locate-1; i++)
////		{
////			p_prior = p_prior->next;
////		}
////		p_back = p_prior->next;
////		p_prior->next = NULL;
////		L->LinkList_length--;
////
////	}
////	else
////	{
////		for (i = 0 ; i < locate-1 ; i++)
////		{
////			p_prior = p_prior->next;
////
////		}
////		p_back = p_prior->next;
////		//if (p_back->next == NULL)
////		//{
////		//	p_prior->next = NULL;
////		//}
////		//else
////		//{ 
////		//    p_prior->next = p_back->next;
////		//    p_back->next = NULL;
////		//}
////		p_prior->next = p_back->next;
////		p_back->next = NULL;
////		L->LinkList_length--;
////
////	}
////
////
////	return p_back;
////}
////
////int Updata_LinkList(LinkList* L, int elem, int locate)
////{
////	int i = 0;
////	LinkNode* p_prior = (LinkNode*)L;
////	if (locate < 0 || locate > L->LinkList_length)
////	{
////		printf("Ҫ�޸ĵ�λ���������");
////		return 0;
////	}
////	else
////	{
////		for ( i = 0; i < locate ; i++)
////		{
////			p_prior = p_prior->next;
////		}
////		p_prior->elem = elem;
////		//L->LinkList_length++;                 �ĺͲ鲻��Ҫ�ı䳤��
////
////	}
////
////	return 1;
////}
////
//////    ***************************�����㷨��ֱ�ӷ�����Ҫ���ҵ�ֵ��λ���������û�в���ֵ����0********************
////int Locate_LinkList(LinkList* L, int elem)  
////{
////	int i = 0;
////	LinkNode* p_prior = (LinkNode*)L;
////	for ( i = 0; i < L->LinkList_length ; i++)
////	{
////		p_prior = p_prior->next;
////		if (p_prior->elem == elem)
////		{
////			printf("�����д�������Ϊ%d�Ľڵ㣬���Ϊ%d", elem,i+1);
////			return i;
////		}
////	}
////	printf("��������û���ҵ���Ӧ%d��ֵ!",elem);
////	return 0;
////}
//
//
//
////
//////#define LinkList LinkNode
//////int main()
//////{
//////	//LinkNode* LinkList;
//////	//LinkList = (LinkNode*)malloc(sizeof(LinkNode));
//////	//Head_LinkNode* p_head = (Head_LinkNode*)malloc(sizeof(Head_LinkNode));
//////	//LinkList = (LinkNode*)p_head;
//////	LinkList* L1= (LinkNode*)malloc(sizeof(LinkNode));
//////	L1->next = NULL;
//////	Head_LinkNode* p_head = (Head_LinkNode*)L1;
//////	p_head->length = 0;
//////	LinkNode* p_rear = (LinkNode*)L1;
//////	p_rear->next = (LinkNode*)malloc(sizeof(LinkNode));
//////	p_rear = p_rear->next;
//////	p_rear->elem = 1;
//////	p_head->length++;
//////	p_rear->next = (LinkNode*)malloc(sizeof(LinkNode));
//////	p_rear = p_rear->next;
//////	p_rear->elem = 2;
//////	p_head->length++;
//////	p_rear->next = (LinkNode*)malloc(sizeof(LinkNode));
//////	p_rear = p_rear->next;
//////	p_rear->elem = 3;
//////	p_head->length++;
//////	p_rear->next = NULL;
//////
//////	p_rear->next = (LinkNode*)malloc(sizeof(LinkNode));
//////	p_rear = p_rear->next;
//////	p_rear->elem = 4;
//////	p_head->length++;
//////	p_rear->next = NULL;
//////
//////	printf("%d\n", p_rear->elem);
//////	printf("%d\n", p_head->length);
//////
//////	return 0;
//////}
//
//
////int main()
////{
////	int i = 0;
////
////	LinkList* L1 = (LinkList*)malloc(sizeof(LinkList));
////	if (L1 == NULL)
////	{
////		printf("��������ʧ��!");
////		return 0;
////	}
////	L1->next = NULL;
////	L1->LinkList_length = 0;
////	
////	// ******************************************����βָ���ʼ������L1**********************************
////	LinkNode* p_rear = (LinkNode*)L1;
////
////	p_rear->next = (LinkNode*)malloc(sizeof(LinkNode));
////	p_rear = p_rear->next;
////	p_rear->elem = 1;
////	L1->LinkList_length++;
////	p_rear->next = (LinkNode*)malloc(sizeof(LinkNode));
////	p_rear = p_rear->next;
////	p_rear->elem = 2;
////	L1->LinkList_length++;
////	p_rear->next = (LinkNode*)malloc(sizeof(LinkNode));
////	p_rear = p_rear->next;
////	p_rear->elem = 3;
////	L1->LinkList_length++;
////	p_rear->next = (LinkNode*)malloc(sizeof(LinkNode));
////	p_rear = p_rear->next;
////	p_rear->elem = 4;
////	L1->LinkList_length++;
////	p_rear->next = NULL;
////
////	// ****************************************��ʼ������********************************************
////	// 
////	//printf("%d\n", p_rear->elem);
////
////	p_rear = (LinkNode*)L1;
////	printf("��ʼ���������L1Ϊ :");
////	for ( i = 0; i < L1->LinkList_length ; i++)
////	{
////		p_rear = p_rear->next;
////		printf("%d ", p_rear->elem);
////	}
////	putchar('\n');
////	printf("����L1�ĳ�����:%d\n", L1->LinkList_length);
////
////	// **********************************************���в������****************************************��
////	Insert_LinkList(L1, 66, 2);
////
////	p_rear = (LinkNode*)L1;
////	for ( i = 0; i < L1->LinkList_length ; i++)
////	{
////		p_rear = p_rear->next;
////		printf("%d ", p_rear->elem);
////	}
////	putchar('\n');
////	printf("����L1�ĳ�����:%d \n", L1->LinkList_length);
////
////	// **********************************************����ɾ������****************************************��
////	Delete_LinkList(L1,3);
////	p_rear =(LinkNode*) L1;
////	for ( i = 0; i < L1->LinkList_length; i++)
////	{
////		p_rear = p_rear->next;
////		printf("%d ", p_rear->elem);
////	}
////	putchar('\n');
////	printf("����L1�ĳ�����:%d\n", L1->LinkList_length);
////
////	Updata_LinkList(L1, 88, 3);
////	p_rear = (LinkNode*)L1;
////	for ( i = 0; i < L1->LinkList_length; i++)
////	{
////		p_rear = p_rear->next;
////		printf("%d ", p_rear->elem);
////	}
////	putchar('\n');
////	printf("����L1�ĳ�����:%d\n", L1->LinkList_length);
////
////	Locate_LinkList(L1,66);
////	putchar('\n');
////	Locate_LinkList(L1, 7);
////	putchar('\n');
////
////	return 0;
////}
//
//
//// *****************************************3.ջ�Ͷ���****************************************************
//
// //****************************************��.˳��ջ******************************************************
//
////typedef struct seqstack
////{
////	int *elem;
////	int *top;
////	
////}SeqStack;
////
////int Push_SeqStack(SeqStack* s, int elem)
////{
////	*(s->top) = elem;
////	s->top++;
////	return 1;
////}
////
////int Pop_SeqStack(SeqStack* s)
////{
////	s->top--;
////	return 1;
////}
////
////
////int main()
////{
////	//*****************************************����˳��ջ����ʼ��******************************
////	SeqStack s1;
////	//printf("%p\n", &s1);
////	//printf("%p\n", s1);
////	s1.elem = (int*)malloc(sizeof(int) * 100);
////	//printf("%p\n", s1.elem);
////	s1.top = s1.elem;
////	//printf("%p\n", s1.top);
////
////	int i = 0;
////	//Push_SeqStack(&s1, 15);
////	for (i = 0; i < 10; i++)  //****************************˳��ջ����ջ�ͳ�ջ**********************************
////	{
////		Push_SeqStack(&s1, i);
////	}
////
////	for (i = 0; i < s1.top-s1.elem ; i++)
////	{
////		printf("%d ", s1.elem[i]);
////	}
////	putchar('\n');
////	//printf("%d\n", s1.top - s1.elem);
////	for (i = 0; i < 5; i++)
////	{
////		Pop_SeqStack(&s1);
////	}
////	//printf("%d\n", s1.top - s1.elem);
////	for ( i = 0; i < s1.top-s1.elem ; i++)
////	{
////		printf("%d ", s1.elem[i]);
////	}
////
////
////	return 0;
////}
//
//
//
////// *************************************************��.��ջ*****************************************************
//// 
//////#define LinkStack_length elem   //���ﲻ��Ҫ��
////
////
////typedef struct linkstack_node
////{
////	int elem;
////	struct linkstack_node* front;
////	struct linkstack_node* behind;
////
////}LinkStack_Node;
////
//////LinkStack_Node* top ;
////
////
////// *******************************************��.��ջ����ջ*********************************************
////LinkStack_Node* Push_LinkStack(LinkStack_Node* Ls,int elem)    
////{
////	if (Ls->elem == -1)
////	{
////		Ls->elem = elem;
////		return Ls;
////	}
////	else
////	{
////		LinkStack_Node* New_LinkStack_Node = (LinkStack_Node*)malloc(sizeof(LinkStack_Node));
////		if (New_LinkStack_Node == NULL)
////		{
////			printf("��������ջԪ��ʧ��!");
////			return 0;
////		}
////		New_LinkStack_Node->elem = elem;
////		//Ls->front = Ls;
////		Ls->behind = New_LinkStack_Node;
////		New_LinkStack_Node->front = Ls;
////		New_LinkStack_Node->behind = NULL;
////
////
////		return New_LinkStack_Node;
////	}
////
////
////}
////
//////**********************************************��.��ջ�ĳ�ջ***************************************
////LinkStack_Node* Pop_LinkStack(LinkStack_Node* Ls,LinkStack_Node* top)
////{
////	if (Ls == top && Ls->elem == -1)
////	{
////		printf("ջ��");
////		return Ls;
////	}
////	else if (Ls == top && Ls->elem != -1)
////	{
////		Ls->elem = -1;
////		return Ls;
////	}
////	else
////	{
////		top = top->front;
////		free(top->behind);
////		top->behind = NULL;
////
////		return top;
////
////	}
////
////
////}
////
////int main()
////{
////	int i = 0;
////	LinkStack_Node* Ls1 = (LinkStack_Node*)malloc(sizeof(LinkStack_Node));  //��ʼ����ջLs1
////	if (Ls1 == NULL)
////	{
////		printf("��ջ����ռ�ʧ��!");
////		return 0;
////	}
////	Ls1->elem = -1;       // ���� //����ջ��һ���ڵ���Ϊͷ��㣬���洢Ԫ�أ�����Ϊ��ջ����
////	Ls1->front = NULL;
////	Ls1->behind = NULL;
////	LinkStack_Node* top = Ls1;           //����ȫ�ֱ���top��ָ����ջ����
////	LinkStack_Node* p_rear = Ls1;        //����ָ��visit��ϰ���Դ�rear
////
////
////	// **************************************��ջ����ջ�ͳ�ջ����*********************************************
////	for ( i = 0; i < 10; i++)
////	{
////		top = Push_LinkStack(top, i);
////	}
////
////	//for ( p_rear = Ls1 ; p_rear != top; p_rear = p_rear->behind)
////	//{
////	//	printf("%d ", p_rear->elem);
////	//}
////	for ( p_rear = Ls1 ; p_rear != NULL; p_rear = p_rear->behind)
////	{
////		printf("%d ", p_rear->elem);
////	}
////	putchar('\n');
////
////	top = Pop_LinkStack(Ls1, top);
////
////	for ( p_rear = Ls1; p_rear != NULL ; p_rear = p_rear->behind)
////	{
////		printf("%d ", p_rear->elem);
////
////	}
////
////	return 0;
////}
//
//
//////****************************************��.ջ��ݹ�****************************************************
////int Fib(int x)
////{
////	if (x == 1 || x == 2)
////	{
////		return 1;
////	}
////	else
////	{
////		return (Fib(x - 1) + Fib(x - 2));
////	}
////}
////
////int main()
////{
////	int x = 0;
////	int a = 20;
////	if (a < 2)
////	{
////		return 0;
////	}
////	else
////	{
////		x = Fib(a);
////	}
////	printf("%d \n", x);
////
////
////	return 0;
////}
//
//
////***********************************************4.����*************************************************
//
//
//////**************************************��.˳�����************************************************
////typedef struct seqqueue
////{
////	int* elem;
////	//int* rear;
////	int count;
////	int head;
////
////}SeqQueue;
////
////int Enter_SeqQueue(SeqQueue* sq ,int elem)
////{
////	if (sq->count == 100)
////	{
////		printf("��������!\n");
////		return 0;
////	}
////	else
////	{
////		sq->elem[sq->count] = elem;
////		sq->count++;
////		printf("����ɹ�!\n");
////		return 1;
////	}
////
////
////}
////
////int Leave_SeqQueue(SeqQueue* sq)
////{
////	if (sq->head == sq->count)
////	{
////		printf("���пգ����Ӵ���!");
////		return 0;
////	}
////	else
////	{
////		sq->head++;
////		//sq->elem = &sq->elem[sq->head];
////		
////		printf("���ӳɹ�!\n");
////		return 1;
////	}
////
////
////}
////
////
////int main() 
////{
////	
////	//************************************************˳����г�ʼ��*****************************************
////	int i = 0;
////	int j = 0;
////	SeqQueue Sq1;
////	Sq1.elem = (int*)malloc(sizeof(Sq1.elem)*100);
////	//Sq1.rear = Sq1.elem;
////    Sq1.count = 0;
////	Sq1.head = 0;
////
////	//*******************************************���*******************************************************
////	for ( i = 0; i < 10; i++)
////	{
////		Enter_SeqQueue(&Sq1, i);
////	}
////	for ( i = 0; i < Sq1.count; i++)
////	{
////		printf("%d ", Sq1.elem[i]);
////	}
////
////	putchar('\n');
////
////	//*******************************************����******************************************************
////	for ( i = 0; i < 5; i++)
////	{
////		Leave_SeqQueue(&Sq1);
////		for (j = Sq1.head; j < Sq1.count; j++)
////		{
////			printf("%d ", Sq1.elem[j]);
////			
////		}
////
////        putchar('\n');
////	}
////
////	for ( i = Sq1.head; i < Sq1.count; i++)
////	{
////		printf("%d ", Sq1.elem[i]);
////	}
////	putchar('\n');
////
////	return 0;
////}
//
//
//
////************************************************��.����*******************************************************
//
////typedef struct linkqueue_node
////{
////	int elem;
////	struct linkqueue_node* next;
////	struct linkqueue_node* rear;
////
////}LinkQueue_Node;
////
////
////typedef  LinkQueue_Node LinkQueue;
//
//
////*********************************************** ��һ�ֽ������еķ������������
////int Enter_LinkQueue(LinkQueue* Lq,int elem)    
////{
////	if (Lq->elem == -1)
////	{
////		Lq->elem = elem;
////	}
////	else
////	{
////		LinkQueue_Node* New_LinkQueue_Node = (LinkQueue_Node*)malloc(sizeof(LinkQueue_Node));
////		New_LinkQueue_Node->elem = elem;
////
////		Lq->rear->next = New_LinkQueue_Node;
////		Lq->rear = Lq->rear->next;
////		Lq->rear->next = NULL;
////	}
////
////    return 1;
////}
//
////int main()
////{
////
////	int i = 0;
////	LinkQueue* visit = 0;
////	LinkQueue* Lq1 = (LinkQueue*)malloc(sizeof(LinkQueue));
////	Lq1->elem = -1;
////	Lq1->next = NULL;
////	Lq1->rear = Lq1;
////
////	for (i = 0; i < 10; i++)
////	{
////		Enter_LinkQueue(Lq1, i);
////	}
////
////	for (visit = Lq1; visit != NULL; visit = visit->next)
////	{
////		printf("%d ", visit->elem);
////	}
////
////
////
////	return 0;
////}
//
//
////**************************************ȥ���ṹ����rearָ���д������********************************************
////**************************************ȥ���ṹ����rearָ���д������********************************************
//
////typedef struct linkqueue_node
////{
////	int elem;
////	struct linkqueue_node* next;
////
////}LinkQueue_Node;
////
////
////typedef  LinkQueue_Node LinkQueue;
////
////
////int Enter_LinkQueue(LinkQueue* Lq, LinkQueue_Node* &rear,int elem)   
//////                 *********************�����и�����һ��Ҫע��
//////            *******************rear����Ҫ��rearָ��ĵ�ַ����Ȼrear������������Lq�ĵ�ַ
//////      ****************************Ҳ���޷��ı�rearָ�룬��rearָ���㴫����************�ص㣡����Ҫrearָ��ǰ��Ҫ��  &    ������
////{
////	if (Lq->elem == -1)
////	{
////		Lq->elem = elem;  //���ӵ�һ��λ�õ����ݣ���ʼֵΪ-1
////	}
////	else
////	{
////		LinkQueue_Node* New_LinkQueue_Node = (LinkQueue_Node*)malloc(sizeof(LinkQueue_Node));
////		New_LinkQueue_Node->elem = elem;
////
////		rear->next = New_LinkQueue_Node;
////		rear = rear->next;
////		rear->next = NULL;
////	}
////
////	return 1;
////}
////
////int Leave_LinkQueue(LinkQueue* &Lq)
//////*******************************�±��Ǹ����������Lqָ��ͬ������������⣬�赱��******************rear����Lq********************
//////                 *********************�����и�����һ��Ҫע��
//////            *******************rear����Ҫ��rearָ��ĵ�ַ����Ȼrear������������Lq�ĵ�ַ
//////      ****************************Ҳ���޷��ı�rearָ�룬��rearָ���㴫����************�ص㣡����Ҫrearָ��ǰ��Ҫ��  &    ������
////
////
////{
////	LinkQueue_Node* p = Lq;
////	if (Lq->next == NULL && Lq->elem != -1)
////	{
////		printf("����Ϊ�գ��޷����ӣ�");
////		return 0;
////	}
////
////	else
////	{
////		Lq = Lq->next;
////		//p->next = NULL;
////		//free(p);
////	}
////
////	return 1;
////}
////
////
////
////int main()
////{
////
////	int i = 0;
////
////	LinkQueue* visit = 0;
////	LinkQueue* Lq1 = (LinkQueue*)malloc(sizeof(LinkQueue));
////	Lq1->elem = -1;
////	Lq1->next = NULL;
////	//Lq1->rear = Lq1;
////
////	struct linkqueue_node* rear = Lq1;
////
////	for ( i = 0; i < 10; i++)
////	{
////		Enter_LinkQueue(Lq1,rear, i);
////
////	}
////                  
////                                       //***********�����ǽ��Ӻͳ���************
////	for (visit = Lq1; visit != NULL; visit = visit->next)
////	{
////		printf("%d ",visit->elem);
////	}
////	putchar('\n');
////
////	for (i = 0; i < 5; i++)
////	{
////		Leave_LinkQueue(Lq1);
////	}
////
////	for (visit = Lq1; visit != NULL; visit = visit->next)
////	{
////		printf("%d ",visit->elem);
////	}
////	putchar('\n');
////
////
////	return 0;
////}
//
//
////**********************************************��.ѭ��˳�����*******************************************
//
////***********************************perfectlyʵ��ѭ��˳����еĹ����ͽ���ջ����!!!!!!!!!!!!!!!!!!****************************
////typedef struct circu_seqqueue
////{
////	int* elem;
////	int head;
////	int rear;
////	int space_empty_flag;
////
////}Circu_SeqQueue;
//
////int Enter_Circu_SeqQueue(Circu_SeqQueue* Csq, int elem)
////{
////	//  if (Csq->head == Csq->rear && Csq->elem[Csq->head] != -1)   //����Ҳ�������ñ�Ǳ���flag���ж�
////	if (Csq->head == Csq->rear && Csq->space_empty_flag == 0)   //����Ҳ�������ñ�Ǳ���flag���ж�
////	{
////		printf("��������������ʧ�ܣ�\n");
////		return 0;
////	}
////	else
////	{
////		Csq->elem[Csq->rear] = elem;
////		Csq->rear = (Csq->rear + 1) % 10;
////	}
////	if (Csq->space_empty_flag == 1)
////	{
////		Csq->space_empty_flag = 0;
////	}
////
////	return 1;
////}
//
//////************************************����ͷָ�뵽βָ��ľ���,Ҳ�����ݸ���**********************************
////int get_distance(const Circu_SeqQueue* Csq)
////{
////	if (Csq->rear > Csq->head)
////	{
////		return Csq->rear - Csq->head;
////	}
////	else if (/*Csq->rear == Csq->head  &&*/  Csq->space_empty_flag == 1)
////	{
////		printf("���пգ���þ���Ϊ0������!\n");
////		return 0;
////	}
////	else
////	{
////		return (Csq->rear + 10) - Csq->head;
////	}
////
////}
////
////int Leave_Circu_SeqQueue(Circu_SeqQueue* Csq)
////{
////	if (Csq->space_empty_flag == 1)
////	{
////		printf("����Ϊ�գ��޷�����\n");
////		return 0;
////	}
////	else
////	{
////		Csq->head = (Csq->head + 1) % 10;
////	}
////	if (Csq->head == Csq->rear)
////	{
////		Csq->space_empty_flag = 1;
////	}
////
////
////	return 1;
////}
//
//
//
//
////int main()
////{
////	//*******************************************��ʼ��**************************************
////	int i = 0;
////	Circu_SeqQueue Csq1 ;
////	Csq1.head = 0;
////	Csq1.rear = 0;
////	Csq1.elem = (int*)malloc(sizeof(int) * 10);
////	Csq1.elem[0] = -1;
////	Csq1.space_empty_flag = 1;
////
////	//*******************************���������кͳ�����************************************
////
////	for ( i = 0; i < 13; i++)
////	{
////		Enter_Circu_SeqQueue(&Csq1, i);
////	}
////	//i = -1;
////	for ( i = Csq1.head; i < Csq1.head+get_distance(&Csq1); i++)
////	{
////		printf("%d ",Csq1.elem[i%10]);
////	}
////	putchar('\n');
////
////	for ( i = 0; i < 6; i++)
////	{
////		Leave_Circu_SeqQueue(&Csq1);
////	}
////	for (i = Csq1.head; i < Csq1.head + get_distance(&Csq1); i++)
////	{
////		printf("%d ", Csq1.elem[i % 10]);
////	}
////	putchar('\n');
////
////	for (i = 0; i < 5; i++)
////	{
////		Enter_Circu_SeqQueue(&Csq1, i);
////	}
////	//i = -1;
////	for (i = Csq1.head; i < Csq1.head + get_distance(&Csq1); i++)
////	{
////		printf("%d ", Csq1.elem[i % 10]);
////	}
////	putchar('\n');
////
////	return 0;
////}
//
//
//
//
//
//
//
//
//
//
