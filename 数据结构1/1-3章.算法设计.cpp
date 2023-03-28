#include "1-3章.算法设计.h"

//**********************************************③.循环顺序队列*******************************************

int Enter_Circu_SeqQueue(Circu_SeqQueue* Csq, int elem)
{
	//  if (Csq->head == Csq->rear && Csq->elem[Csq->head] != -1)   //这里也可以设置标记变量flag来判断
	if (Csq->head == Csq->rear && Csq->space_empty_flag == 0)   //这里也可以设置标记变量flag来判断
	{
		printf("队列已满，插入失败！\n");
		return 0;
	}
	else
	{
		Csq->elem[Csq->rear] = elem;
		Csq->rear = (Csq->rear + 1) % 10;
	}
	if (Csq->space_empty_flag == 1)
	{
		Csq->space_empty_flag = 0;
	}

	return 1;
}

//************************************测量头指针到尾指针的距离,也是数据个数**********************************
int get_distance(const Circu_SeqQueue* Csq)
{
	if (Csq->rear > Csq->head)
	{
		return Csq->rear - Csq->head;
	}
	else if (/*Csq->rear == Csq->head  &&*/  Csq->space_empty_flag == 1)
	{
		printf("队列空，测得距离为0无意义!\n");
		return 0;
	}
	else
	{
		return (Csq->rear + 10) - Csq->head;
	}

}

int Leave_Circu_SeqQueue(Circu_SeqQueue* Csq)
{
	if (Csq->space_empty_flag == 1)
	{
		printf("队列为空，无法出队\n");
		return 0;
	}
	else
	{
		Csq->head = (Csq->head + 1) % 10;
	}
	if (Csq->head == Csq->rear)
	{
		Csq->space_empty_flag = 1;
	}


	return 1;
}

//************************************************②.链队*******************************************************

int Enter_LinkQueue(LinkQueue* Lq, LinkQueue_Node*& rear, int elem)
//                 *********************这里有个问题一定要注意
//            *******************rear传参要传rear指针的地址，不然rear的内容是链队Lq的地址
//      ****************************也就无法改变rear指针，让rear指针层层传递了************重点！所以要rear指针前边要加  &    ！！！
{
	if (Lq->elem == -1)
	{
		Lq->elem = elem;  //链队第一个位置的数据，初始值为-1
	}
	else
	{
		LinkQueue_Node* New_LinkQueue_Node = (LinkQueue_Node*)malloc(sizeof(LinkQueue_Node));
		New_LinkQueue_Node->elem = elem;

		rear->next = New_LinkQueue_Node;
		rear = rear->next;
		rear->next = NULL;
	}

	return 1;
}

int Leave_LinkQueue(LinkQueue*& Lq)
//*******************************下边是复述，这里的Lq指针同样存在这个问题，需当心******************rear看做Lq********************
//                 *********************这里有个问题一定要注意
//            *******************rear传参要传rear指针的地址，不然rear的内容是链队Lq的地址
//      ****************************也就无法改变rear指针，让rear指针层层传递了************重点！所以要rear指针前边要加  &    ！！！


{
	LinkQueue_Node* p = Lq;
	if (Lq->next == NULL && Lq->elem != -1)
	{
		printf("链队为空，无法出队！");
		return 0;
	}

	else
	{
		Lq = Lq->next;
		//p->next = NULL;
		//free(p);
	}

	return 1;
}

//***********************************************4.队列*************************************************
// 
////**************************************①.顺序队列************************************************

int Enter_SeqQueue(SeqQueue* sq, int elem)
{
	if (sq->count == 100)
	{
		printf("队列已满!\n");
		return 0;
	}
	else
	{
		sq->elem[sq->count] = elem;
		sq->count++;
		printf("插入成功!\n");
		return 1;
	}


}

int Leave_SeqQueue(SeqQueue* sq)
{
	if (sq->head == sq->count)
	{
		printf("队列空，出队错误!");
		return 0;
	}
	else
	{
		sq->head++;
		//sq->elem = &sq->elem[sq->head];

		printf("出队成功!\n");
		return 1;
	}


}

//****************************************③.栈与递归****************************************************
int Fib(int x)
{
	if (x == 1 || x == 2)
	{
		return 1;
	}
	else
	{
		return (Fib(x - 1) + Fib(x - 2));
	}
}


// *************************************************②.链栈*****************************************************

// *******************************************链栈的入栈*********************************************
LinkStack_Node* Push_LinkStack(LinkStack_Node* Ls, int elem)
{
	if (Ls->elem == -1)
	{
		Ls->elem = elem;
		return Ls;
	}
	else
	{
		LinkStack_Node* New_LinkStack_Node = (LinkStack_Node*)malloc(sizeof(LinkStack_Node));
		if (New_LinkStack_Node == NULL)
		{
			printf("创建新链栈元素失败!");
			return 0;
		}
		New_LinkStack_Node->elem = elem;
		//Ls->front = Ls;
		Ls->behind = New_LinkStack_Node;
		New_LinkStack_Node->front = Ls;
		New_LinkStack_Node->behind = NULL;


		return New_LinkStack_Node;
	}


}

//**********************************************链栈的出栈***************************************
LinkStack_Node* Pop_LinkStack(LinkStack_Node* Ls, LinkStack_Node* top)
{
	if (Ls == top && Ls->elem == -1)
	{
		printf("栈空");
		return Ls;
	}
	else if (Ls == top && Ls->elem != -1)
	{
		Ls->elem = -1;
		return Ls;
	}
	else
	{
		top = top->front;
		free(top->behind);
		top->behind = NULL;

		return top;

	}


}

// *****************************************3.栈和队列****************************************************

 //****************************************①.顺序栈******************************************************

int Push_SeqStack(SeqStack* s, int elem)
{
	*(s->top) = elem;
	s->top++;
	return 1;
}

int Pop_SeqStack(SeqStack* s)
{
	s->top--;
	return 1;
}

////              ****************************************1.顺序表***********************************************

int Insert_SqList(SqList& L, int elem, int locate)  //插入成功返回1，否则返回0
{
	int i = 0;
	if (locate > L.length + 1 || locate < 1)
	{
		printf("插入位置异常,大于最后一个位置或小于最后一个位置");
		return 0;
	}
	else
	{
		for (i = L.length; i >= locate; i--)
		{
			L.arr[i] = L.arr[i - 1];
		}
		L.arr[locate - 1] = elem;  // 这里的locate 位置也要-1 ，因为下标-1

	}

	L.length++;                //********************这一步很重要，插入后一定要长度  +1

	return 1;
}

int Delete_SqList(SqList& L, int locate)
{
	int i = 0;
	if (locate < 1 || locate >L.length)
	{
		printf("删除位置错误");
		return 0;

	}
	else
	{
		for (i = locate; i < L.length; i++)
		{
			L.arr[i - 1] = L.arr[i];
		}
	}
	L.length--;

	return 1;
}

int Updata_SqList(SqList& L, int elem, int locate)
{
	if (locate > L.length || locate < 1)
	{
		printf("修改位置错误");
		return 0;
	}
	else
	{
		L.arr[locate - 1] = elem;            //注意-1
	}


	return 1;
}

int Locate_SqList(const SqList& L, int elem)
{
	int i = 0;
	while (L.arr[i] != elem && i < L.length)
	{
		i++;
	}
	if (i == L.length)
	{
		printf("顺序表中没有该元素");
		return 0;
	}
	return ++i;
}

//   *********************************************2.链表*************************************************

// *************************************************插入成功返回1，否则返回0 **********************************
int Insert_LinkList(LinkList* L, int elem, int locate)
{
	int i = 0;
	LinkNode* p_prior = (LinkNode*)L;
	LinkNode* p_back = (LinkNode*)L;
	LinkNode* New_Node = (LinkNode*)malloc(sizeof(LinkNode));
	if (New_Node == NULL)
	{
		printf("创造新节点时失败!");
		return 0;
	}
	New_Node->elem = elem;
	if (locate < 1 || locate > L->elem)
	{
		printf("插入位置错误");
		return 0;
	}
	else if (locate == L->LinkList_length)
	{
		for (i = 0; i < locate - 1; i++)
		{
			p_prior = p_prior->next;
		}
		p_prior->next = New_Node;
		New_Node->next = NULL;
		L->LinkList_length++;

	}
	else
	{
		for (i = 0; i < locate - 1; i++)
		{
			p_prior = p_prior->next;
		}
		p_back = p_prior->next;
		New_Node->next = p_back;
		p_prior->next = New_Node;
		L->LinkList_length++;
	}

	return 1;
}

// ***************************************删除成功返回删除的节点，否则返回0*********************************
LinkNode* Delete_LinkList(LinkList* L, int locate)
{
	int i = 0;
	LinkNode* p_prior = (LinkNode*)L;
	LinkNode* p_back = (LinkNode*)L;
	if (locate < 1 || locate > L->LinkList_length)
	{
		printf("删除的位置错误!");
		return 0;

	}
	else if (locate == L->LinkList_length)
	{
		for (i = 0; i < locate - 1; i++)
		{
			p_prior = p_prior->next;
		}
		p_back = p_prior->next;
		p_prior->next = NULL;
		L->LinkList_length--;

	}
	else
	{
		for (i = 0; i < locate - 1; i++)
		{
			p_prior = p_prior->next;

		}
		p_back = p_prior->next;
		//if (p_back->next == NULL)
		//{
		//	p_prior->next = NULL;
		//}
		//else
		//{ 
		//    p_prior->next = p_back->next;
		//    p_back->next = NULL;
		//}
		p_prior->next = p_back->next;
		p_back->next = NULL;
		L->LinkList_length--;

	}


	return p_back;
}

int Updata_LinkList(LinkList* L, int elem, int locate)
{
	int i = 0;
	LinkNode* p_prior = (LinkNode*)L;
	if (locate < 0 || locate > L->LinkList_length)
	{
		printf("要修改的位置输入错误！");
		return 0;
	}
	else
	{
		for (i = 0; i < locate; i++)
		{
			p_prior = p_prior->next;
		}
		p_prior->elem = elem;
		//L->LinkList_length++;                 改和查不需要改变长度

	}

	return 1;
}

//    ***************************查找算法，直接返回需要查找的值的位置序号数，没有查找值返回0********************
int Locate_LinkList(LinkList* L, int elem)
{
	int i = 0;
	LinkNode* p_prior = (LinkNode*)L;
	for (i = 0; i < L->LinkList_length; i++)
	{
		p_prior = p_prior->next;
		if (p_prior->elem == elem)
		{
			printf("链表中存在数据为%d的节点，序号为%d", elem, i + 1);
			return i;
		}
	}
	printf("在链表里没有找到对应%d的值!", elem);
	return 0;
}