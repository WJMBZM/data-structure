//#define _CRT_SECURE_NO_WARNINGS 1
//#pragma once
//#include "1-3章.算法设计.h"
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
////              ****************************************1.顺序表***********************************************
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
////		printf("顺序表中没有该元素");
////		return 0;
////	}
////	return ++i;
////}
////
////int Insert_SqList(SqList &L,int elem,int locate)  //插入成功返回1，否则返回0
////{   
////	int i = 0;
////	if (locate >L.length+1 || locate < 1 )
////	{
////		printf("插入位置异常,大于最后一个位置或小于最后一个位置");
////		return 0;
////	}
////	else
////	{
////		for ( i = L.length ; i >= locate ; i--)
////		{
////			L.arr[i] = L.arr[i - 1];
////		}
////		L.arr[locate-1] = elem;  // 这里的locate 位置也要-1 ，因为下标-1
////
////	}
////
////	L.length++;                //********************这一步很重要，插入后一定要长度  +1
////
////	return 1;
////}
////
////int Delete_SqList( SqList &L , int locate)
////{
////	int i = 0;
////	if ( locate < 1 || locate >L.length )
////	{
////		printf("删除位置错误");
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
////		printf("修改位置错误");
////		return 0;
////	}
////	else
////	{
////		L.arr[locate-1] = elem;            //注意-1
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
////	printf("顺序表s1中数据为3的元素是第%d个\n", Locate_SqList(s1 , 3));
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
//////   *********************************************2.链表*************************************************
////
////typedef struct linknode
////{
////	int elem;
////	struct linknode* next;
////
////}LinkNode;
////
////typedef struct head_linknode             //头结点数据位放链表长度
////{
////	int length ;
////	LinkNode* next;
////}Head_LinkNode;
////
////typedef struct linklist                  //改进，替代头结点
////{
////	int LinkList_length;
////	LinkNode* next;
////
////}LinkList;
////
////// *************************************************插入成功返回1，否则返回0 **********************************
////int Insert_LinkList(LinkList *L,int elem , int locate)          
////{
////	int i = 0;
////	LinkNode* p_prior =(LinkNode*)L;
////	LinkNode* p_back =(LinkNode*)L;
////	LinkNode* New_Node = (LinkNode*)malloc(sizeof(LinkNode));
////	if (New_Node == NULL)
////	{
////		printf("创造新节点时失败!");
////		return 0;
////	}
////	New_Node->elem = elem;
////	if (locate < 1 || locate > L->elem)
////	{
////		printf("插入位置错误");
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
////// ***************************************删除成功返回删除的节点，否则返回0*********************************
////LinkNode* Delete_LinkList(LinkList* L, int locate)         
////{
////	int i = 0;
////	LinkNode* p_prior = (LinkNode*)L;
////	LinkNode* p_back = (LinkNode*)L;
////	if (locate < 1 || locate > L->LinkList_length)
////	{
////		printf("删除的位置错误!");
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
////		printf("要修改的位置输入错误！");
////		return 0;
////	}
////	else
////	{
////		for ( i = 0; i < locate ; i++)
////		{
////			p_prior = p_prior->next;
////		}
////		p_prior->elem = elem;
////		//L->LinkList_length++;                 改和查不需要改变长度
////
////	}
////
////	return 1;
////}
////
//////    ***************************查找算法，直接返回需要查找的值的位置序号数，没有查找值返回0********************
////int Locate_LinkList(LinkList* L, int elem)  
////{
////	int i = 0;
////	LinkNode* p_prior = (LinkNode*)L;
////	for ( i = 0; i < L->LinkList_length ; i++)
////	{
////		p_prior = p_prior->next;
////		if (p_prior->elem == elem)
////		{
////			printf("链表中存在数据为%d的节点，序号为%d", elem,i+1);
////			return i;
////		}
////	}
////	printf("在链表里没有找到对应%d的值!",elem);
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
////		printf("创建链表失败!");
////		return 0;
////	}
////	L1->next = NULL;
////	L1->LinkList_length = 0;
////	
////	// ******************************************建立尾指针初始化链表L1**********************************
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
////	// ****************************************初始化结束********************************************
////	// 
////	//printf("%d\n", p_rear->elem);
////
////	p_rear = (LinkNode*)L1;
////	printf("初始化后的链表L1为 :");
////	for ( i = 0; i < L1->LinkList_length ; i++)
////	{
////		p_rear = p_rear->next;
////		printf("%d ", p_rear->elem);
////	}
////	putchar('\n');
////	printf("链表L1的长度是:%d\n", L1->LinkList_length);
////
////	// **********************************************进行插入操作****************************************增
////	Insert_LinkList(L1, 66, 2);
////
////	p_rear = (LinkNode*)L1;
////	for ( i = 0; i < L1->LinkList_length ; i++)
////	{
////		p_rear = p_rear->next;
////		printf("%d ", p_rear->elem);
////	}
////	putchar('\n');
////	printf("链表L1的长度是:%d \n", L1->LinkList_length);
////
////	// **********************************************进行删除操作****************************************增
////	Delete_LinkList(L1,3);
////	p_rear =(LinkNode*) L1;
////	for ( i = 0; i < L1->LinkList_length; i++)
////	{
////		p_rear = p_rear->next;
////		printf("%d ", p_rear->elem);
////	}
////	putchar('\n');
////	printf("链表L1的长度是:%d\n", L1->LinkList_length);
////
////	Updata_LinkList(L1, 88, 3);
////	p_rear = (LinkNode*)L1;
////	for ( i = 0; i < L1->LinkList_length; i++)
////	{
////		p_rear = p_rear->next;
////		printf("%d ", p_rear->elem);
////	}
////	putchar('\n');
////	printf("链表L1的长度是:%d\n", L1->LinkList_length);
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
//// *****************************************3.栈和队列****************************************************
//
// //****************************************①.顺序栈******************************************************
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
////	//*****************************************创建顺序栈并初始化******************************
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
////	for (i = 0; i < 10; i++)  //****************************顺序栈的入栈和出栈**********************************
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
////// *************************************************②.链栈*****************************************************
//// 
//////#define LinkStack_length elem   //这里不需要了
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
////// *******************************************①.链栈的入栈*********************************************
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
////			printf("创建新链栈元素失败!");
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
//////**********************************************②.链栈的出栈***************************************
////LinkStack_Node* Pop_LinkStack(LinkStack_Node* Ls,LinkStack_Node* top)
////{
////	if (Ls == top && Ls->elem == -1)
////	{
////		printf("栈空");
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
////	LinkStack_Node* Ls1 = (LinkStack_Node*)malloc(sizeof(LinkStack_Node));  //初始化链栈Ls1
////	if (Ls1 == NULL)
////	{
////		printf("链栈分配空间失败!");
////		return 0;
////	}
////	Ls1->elem = -1;       // 放弃 //将链栈第一个节点设为头结点，不存储元素，数据为链栈长度
////	Ls1->front = NULL;
////	Ls1->behind = NULL;
////	LinkStack_Node* top = Ls1;           //创建全局变量top来指向链栈顶端
////	LinkStack_Node* p_rear = Ls1;        //访问指针visit，习惯性打rear
////
////
////	// **************************************链栈的入栈和出栈操作*********************************************
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
//////****************************************③.栈与递归****************************************************
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
////***********************************************4.队列*************************************************
//
//
//////**************************************①.顺序队列************************************************
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
////		printf("队列已满!\n");
////		return 0;
////	}
////	else
////	{
////		sq->elem[sq->count] = elem;
////		sq->count++;
////		printf("插入成功!\n");
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
////		printf("队列空，出队错误!");
////		return 0;
////	}
////	else
////	{
////		sq->head++;
////		//sq->elem = &sq->elem[sq->head];
////		
////		printf("出队成功!\n");
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
////	//************************************************顺序队列初始化*****************************************
////	int i = 0;
////	int j = 0;
////	SeqQueue Sq1;
////	Sq1.elem = (int*)malloc(sizeof(Sq1.elem)*100);
////	//Sq1.rear = Sq1.elem;
////    Sq1.count = 0;
////	Sq1.head = 0;
////
////	//*******************************************入队*******************************************************
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
////	//*******************************************出队******************************************************
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
////************************************************②.链队*******************************************************
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
////*********************************************** 第一种进链队列的方法，多个参数
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
////**************************************去掉结构体内rear指针改写的链队********************************************
////**************************************去掉结构体内rear指针改写的链队********************************************
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
//////                 *********************这里有个问题一定要注意
//////            *******************rear传参要传rear指针的地址，不然rear的内容是链队Lq的地址
//////      ****************************也就无法改变rear指针，让rear指针层层传递了************重点！所以要rear指针前边要加  &    ！！！
////{
////	if (Lq->elem == -1)
////	{
////		Lq->elem = elem;  //链队第一个位置的数据，初始值为-1
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
//////*******************************下边是复述，这里的Lq指针同样存在这个问题，需当心******************rear看做Lq********************
//////                 *********************这里有个问题一定要注意
//////            *******************rear传参要传rear指针的地址，不然rear的内容是链队Lq的地址
//////      ****************************也就无法改变rear指针，让rear指针层层传递了************重点！所以要rear指针前边要加  &    ！！！
////
////
////{
////	LinkQueue_Node* p = Lq;
////	if (Lq->next == NULL && Lq->elem != -1)
////	{
////		printf("链队为空，无法出队！");
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
////                                       //***********这里是进队和出队************
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
////**********************************************③.循环顺序队列*******************************************
//
////***********************************perfectly实现循环顺序队列的构建和进出栈任务!!!!!!!!!!!!!!!!!!****************************
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
////	//  if (Csq->head == Csq->rear && Csq->elem[Csq->head] != -1)   //这里也可以设置标记变量flag来判断
////	if (Csq->head == Csq->rear && Csq->space_empty_flag == 0)   //这里也可以设置标记变量flag来判断
////	{
////		printf("队列已满，插入失败！\n");
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
//////************************************测量头指针到尾指针的距离,也是数据个数**********************************
////int get_distance(const Circu_SeqQueue* Csq)
////{
////	if (Csq->rear > Csq->head)
////	{
////		return Csq->rear - Csq->head;
////	}
////	else if (/*Csq->rear == Csq->head  &&*/  Csq->space_empty_flag == 1)
////	{
////		printf("队列空，测得距离为0无意义!\n");
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
////		printf("队列为空，无法出队\n");
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
////	//*******************************************初始化**************************************
////	int i = 0;
////	Circu_SeqQueue Csq1 ;
////	Csq1.head = 0;
////	Csq1.rear = 0;
////	Csq1.elem = (int*)malloc(sizeof(int) * 10);
////	Csq1.elem[0] = -1;
////	Csq1.space_empty_flag = 1;
////
////	//*******************************操作进队列和出队列************************************
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
