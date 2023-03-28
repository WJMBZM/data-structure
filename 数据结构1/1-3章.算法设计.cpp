#include "1-3��.�㷨���.h"

//**********************************************��.ѭ��˳�����*******************************************

int Enter_Circu_SeqQueue(Circu_SeqQueue* Csq, int elem)
{
	//  if (Csq->head == Csq->rear && Csq->elem[Csq->head] != -1)   //����Ҳ�������ñ�Ǳ���flag���ж�
	if (Csq->head == Csq->rear && Csq->space_empty_flag == 0)   //����Ҳ�������ñ�Ǳ���flag���ж�
	{
		printf("��������������ʧ�ܣ�\n");
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

//************************************����ͷָ�뵽βָ��ľ���,Ҳ�����ݸ���**********************************
int get_distance(const Circu_SeqQueue* Csq)
{
	if (Csq->rear > Csq->head)
	{
		return Csq->rear - Csq->head;
	}
	else if (/*Csq->rear == Csq->head  &&*/  Csq->space_empty_flag == 1)
	{
		printf("���пգ���þ���Ϊ0������!\n");
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
		printf("����Ϊ�գ��޷�����\n");
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

//************************************************��.����*******************************************************

int Enter_LinkQueue(LinkQueue* Lq, LinkQueue_Node*& rear, int elem)
//                 *********************�����и�����һ��Ҫע��
//            *******************rear����Ҫ��rearָ��ĵ�ַ����Ȼrear������������Lq�ĵ�ַ
//      ****************************Ҳ���޷��ı�rearָ�룬��rearָ���㴫����************�ص㣡����Ҫrearָ��ǰ��Ҫ��  &    ������
{
	if (Lq->elem == -1)
	{
		Lq->elem = elem;  //���ӵ�һ��λ�õ����ݣ���ʼֵΪ-1
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
//*******************************�±��Ǹ����������Lqָ��ͬ������������⣬�赱��******************rear����Lq********************
//                 *********************�����и�����һ��Ҫע��
//            *******************rear����Ҫ��rearָ��ĵ�ַ����Ȼrear������������Lq�ĵ�ַ
//      ****************************Ҳ���޷��ı�rearָ�룬��rearָ���㴫����************�ص㣡����Ҫrearָ��ǰ��Ҫ��  &    ������


{
	LinkQueue_Node* p = Lq;
	if (Lq->next == NULL && Lq->elem != -1)
	{
		printf("����Ϊ�գ��޷����ӣ�");
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

//***********************************************4.����*************************************************
// 
////**************************************��.˳�����************************************************

int Enter_SeqQueue(SeqQueue* sq, int elem)
{
	if (sq->count == 100)
	{
		printf("��������!\n");
		return 0;
	}
	else
	{
		sq->elem[sq->count] = elem;
		sq->count++;
		printf("����ɹ�!\n");
		return 1;
	}


}

int Leave_SeqQueue(SeqQueue* sq)
{
	if (sq->head == sq->count)
	{
		printf("���пգ����Ӵ���!");
		return 0;
	}
	else
	{
		sq->head++;
		//sq->elem = &sq->elem[sq->head];

		printf("���ӳɹ�!\n");
		return 1;
	}


}

//****************************************��.ջ��ݹ�****************************************************
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


// *************************************************��.��ջ*****************************************************

// *******************************************��ջ����ջ*********************************************
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
			printf("��������ջԪ��ʧ��!");
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

//**********************************************��ջ�ĳ�ջ***************************************
LinkStack_Node* Pop_LinkStack(LinkStack_Node* Ls, LinkStack_Node* top)
{
	if (Ls == top && Ls->elem == -1)
	{
		printf("ջ��");
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

// *****************************************3.ջ�Ͷ���****************************************************

 //****************************************��.˳��ջ******************************************************

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

////              ****************************************1.˳���***********************************************

int Insert_SqList(SqList& L, int elem, int locate)  //����ɹ�����1�����򷵻�0
{
	int i = 0;
	if (locate > L.length + 1 || locate < 1)
	{
		printf("����λ���쳣,�������һ��λ�û�С�����һ��λ��");
		return 0;
	}
	else
	{
		for (i = L.length; i >= locate; i--)
		{
			L.arr[i] = L.arr[i - 1];
		}
		L.arr[locate - 1] = elem;  // �����locate λ��ҲҪ-1 ����Ϊ�±�-1

	}

	L.length++;                //********************��һ������Ҫ�������һ��Ҫ����  +1

	return 1;
}

int Delete_SqList(SqList& L, int locate)
{
	int i = 0;
	if (locate < 1 || locate >L.length)
	{
		printf("ɾ��λ�ô���");
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
		printf("�޸�λ�ô���");
		return 0;
	}
	else
	{
		L.arr[locate - 1] = elem;            //ע��-1
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
		printf("˳�����û�и�Ԫ��");
		return 0;
	}
	return ++i;
}

//   *********************************************2.����*************************************************

// *************************************************����ɹ�����1�����򷵻�0 **********************************
int Insert_LinkList(LinkList* L, int elem, int locate)
{
	int i = 0;
	LinkNode* p_prior = (LinkNode*)L;
	LinkNode* p_back = (LinkNode*)L;
	LinkNode* New_Node = (LinkNode*)malloc(sizeof(LinkNode));
	if (New_Node == NULL)
	{
		printf("�����½ڵ�ʱʧ��!");
		return 0;
	}
	New_Node->elem = elem;
	if (locate < 1 || locate > L->elem)
	{
		printf("����λ�ô���");
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

// ***************************************ɾ���ɹ�����ɾ���Ľڵ㣬���򷵻�0*********************************
LinkNode* Delete_LinkList(LinkList* L, int locate)
{
	int i = 0;
	LinkNode* p_prior = (LinkNode*)L;
	LinkNode* p_back = (LinkNode*)L;
	if (locate < 1 || locate > L->LinkList_length)
	{
		printf("ɾ����λ�ô���!");
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
		printf("Ҫ�޸ĵ�λ���������");
		return 0;
	}
	else
	{
		for (i = 0; i < locate; i++)
		{
			p_prior = p_prior->next;
		}
		p_prior->elem = elem;
		//L->LinkList_length++;                 �ĺͲ鲻��Ҫ�ı䳤��

	}

	return 1;
}

//    ***************************�����㷨��ֱ�ӷ�����Ҫ���ҵ�ֵ��λ���������û�в���ֵ����0********************
int Locate_LinkList(LinkList* L, int elem)
{
	int i = 0;
	LinkNode* p_prior = (LinkNode*)L;
	for (i = 0; i < L->LinkList_length; i++)
	{
		p_prior = p_prior->next;
		if (p_prior->elem == elem)
		{
			printf("�����д�������Ϊ%d�Ľڵ㣬���Ϊ%d", elem, i + 1);
			return i;
		}
	}
	printf("��������û���ҵ���Ӧ%d��ֵ!", elem);
	return 0;
}