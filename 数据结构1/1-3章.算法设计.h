#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
//
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<assert.h>
#include<float.h>
#include<ctype.h>
#include<stddef.h>
#include<errno.h>
#include<malloc.h>
#include<stddef.h>
#include<iostream>


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


using namespace std;

//**********************************************ѭ��˳�����*******************************************
// 
typedef struct circu_seqqueue
{
	int* elem;
	int head;
	int rear;
	int space_empty_flag;

}Circu_SeqQueue;

int Enter_Circu_SeqQueue(Circu_SeqQueue* Csq, int elem);
int get_distance(const Circu_SeqQueue* Csq);
int Leave_Circu_SeqQueue(Circu_SeqQueue* Csq);

//************************************************����*******************************************************

typedef struct linkqueue_node
{
	int elem;
	struct linkqueue_node* next;

}LinkQueue_Node;

typedef  LinkQueue_Node LinkQueue;

int Enter_LinkQueue(LinkQueue* Lq, LinkQueue_Node*& rear, int elem);
int Leave_LinkQueue(LinkQueue*& Lq);


////**************************************˳�����************************************************
typedef struct seqqueue
{
	int* elem;
	//int* rear;
	int count;
	int head;

}SeqQueue;

int Enter_SeqQueue(SeqQueue* sq, int elem);
int Leave_SeqQueue(SeqQueue* sq);


//****************************************ջ��ݹ�****************************************************
//***************쳲���������***********
int Fib(int x);


// *************************************************��.��ջ*****************************************************

typedef struct linkstack_node
{
	int elem;
	struct linkstack_node* front;
	struct linkstack_node* behind;

}LinkStack_Node;

LinkStack_Node* Push_LinkStack(LinkStack_Node* Ls, int elem);
LinkStack_Node* Pop_LinkStack(LinkStack_Node* Ls, LinkStack_Node* top);


//****************************************��.˳��ջ******************************************************

typedef struct seqstack
{
	int* elem;
	int* top;

}SeqStack;

int Push_SeqStack(SeqStack* s, int elem);
int Pop_SeqStack(SeqStack* s);

//**************************�������������ڿ�ʼ��˳��*********************************************

//              ****************************************1.˳���***********************************************
typedef struct Sqlist
{
	int* arr;
	int length;

}SqList;

int Insert_SqList(SqList& L, int elem, int locate);
int Delete_SqList(SqList& L, int locate);
int Updata_SqList(SqList& L, int elem, int locate);
int Locate_SqList(const SqList& L, int elem);


//   *********************************************2.����*************************************************
#define LinkList_length elem

typedef struct linknode
{
	int elem;
	struct linknode* next;

}LinkNode;

typedef struct head_linknode             //ͷ�������λ��������
{
	int length;
	LinkNode* next;
}Head_LinkNode;

typedef struct linklist                  //�Ľ������ͷ���
{
	int LinkList_length;
	LinkNode* next;

}LinkList;

int Insert_LinkList(LinkList* L, int elem, int locate);
LinkNode* Delete_LinkList(LinkList* L, int locate);
int Updata_LinkList(LinkList* L, int elem, int locate);
int Locate_LinkList(LinkList* L, int elem);




