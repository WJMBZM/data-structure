#include "1-3��.�㷨���.h"

//              ****************************************1.˳���***********************************************
//
//int main()
//{
//	SqList s1;
//	s1.length = 10;
//	s1.arr = (int*)malloc(sizeof(int) * 100);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		s1.arr[i] = i;
//
//	}
//
//	printf("˳���s1������Ϊ3��Ԫ���ǵ�%d��\n", Locate_SqList(s1 , 3));
//
//	Insert_SqList(s1, 66, 11);
//	for ( i = 0; i < s1.length; i++)
//	{
//		printf("%d ", s1.arr[i]);
//	}
//
//	putchar('\n');
//
//	Delete_SqList(s1, 11);
//	for ( i = 0; i < s1.length; i++)
//	{
//		printf("%d ", s1.arr[i]);
//	}
//	putchar('\n');
//
//	Updata_SqList(s1,88,10);
//	for ( i = 0; i < s1.length; i++)
//	{
//		printf("%d ", s1.arr[i]);
//	}
//	putchar('\n');
//
//	free(s1.arr);
//
//	return 0;
//}


//   *********************************************2.����*************************************************

//int main()
//{
//	int i = 0;
//
//	LinkList* L1 = (LinkList*)malloc(sizeof(LinkList));
//	if (L1 == NULL)
//	{
//		printf("��������ʧ��!");
//		return 0;
//	}
//	L1->next = NULL;
//	L1->LinkList_length = 0;
//	
//	// ******************************************����βָ���ʼ������L1**********************************
//	LinkNode* p_rear = (LinkNode*)L1;
//
//	p_rear->next = (LinkNode*)malloc(sizeof(LinkNode));
//	p_rear = p_rear->next;
//	p_rear->elem = 1;
//	L1->LinkList_length++;
//	p_rear->next = (LinkNode*)malloc(sizeof(LinkNode));
//	p_rear = p_rear->next;
//	p_rear->elem = 2;
//	L1->LinkList_length++;
//	p_rear->next = (LinkNode*)malloc(sizeof(LinkNode));
//	p_rear = p_rear->next;
//	p_rear->elem = 3;
//	L1->LinkList_length++;
//	p_rear->next = (LinkNode*)malloc(sizeof(LinkNode));
//	p_rear = p_rear->next;
//	p_rear->elem = 4;
//	L1->LinkList_length++;
//	p_rear->next = NULL;
//
//	// ****************************************��ʼ������********************************************
//
//	p_rear = (LinkNode*)L1;
//	printf("��ʼ���������L1Ϊ :");
//	for ( i = 0; i < L1->LinkList_length ; i++)
//	{
//		p_rear = p_rear->next;
//		printf("%d ", p_rear->elem);
//	}
//	putchar('\n');
//	printf("����L1�ĳ�����:%d\n", L1->LinkList_length);
//
//	// **********************************************���в������****************************************��
//	Insert_LinkList(L1, 66, 2);
//
//	p_rear = (LinkNode*)L1;
//	for ( i = 0; i < L1->LinkList_length ; i++)
//	{
//		p_rear = p_rear->next;
//		printf("%d ", p_rear->elem);
//	}
//	putchar('\n');
//	printf("����L1�ĳ�����:%d \n", L1->LinkList_length);
//
//	// **********************************************����ɾ������****************************************��
//	Delete_LinkList(L1,3);
//	p_rear =(LinkNode*) L1;
//	for ( i = 0; i < L1->LinkList_length; i++)
//	{
//		p_rear = p_rear->next;
//		printf("%d ", p_rear->elem);
//	}
//	putchar('\n');
//	printf("����L1�ĳ�����:%d\n", L1->LinkList_length);
//
//	Updata_LinkList(L1, 88, 3);
//	p_rear = (LinkNode*)L1;
//	for ( i = 0; i < L1->LinkList_length; i++)
//	{
//		p_rear = p_rear->next;
//		printf("%d ", p_rear->elem);
//	}
//	putchar('\n');
//	printf("����L1�ĳ�����:%d\n", L1->LinkList_length);
//
//	Locate_LinkList(L1,66);
//	putchar('\n');
//	Locate_LinkList(L1, 7);
//	putchar('\n');
//
//	return 0;
//}


// *****************************************3.ջ****************************************************
 
 //****************************************��.˳��ջ******************************************************
 
//int main()
//{
//	//*****************************************����˳��ջ����ʼ��******************************
//	SeqStack s1;
//	//printf("%p\n", &s1);
//	//printf("%p\n", s1);
//	s1.elem = (int*)malloc(sizeof(int) * 100);
//	//printf("%p\n", s1.elem);
//	s1.top = s1.elem;
//	//printf("%p\n", s1.top);
//
//	int i = 0;
//	//Push_SeqStack(&s1, 15);
//	for (i = 0; i < 10; i++)  //****************************˳��ջ����ջ�ͳ�ջ**********************************
//	{
//		Push_SeqStack(&s1, i);
//	}
//
//	for (i = 0; i < s1.top-s1.elem ; i++)
//	{
//		printf("%d ", s1.elem[i]);
//	}
//	putchar('\n');
//	//printf("%d\n", s1.top - s1.elem);
//	for (i = 0; i < 5; i++)
//	{
//		Pop_SeqStack(&s1);
//	}
//	//printf("%d\n", s1.top - s1.elem);
//	for ( i = 0; i < s1.top-s1.elem ; i++)
//	{
//		printf("%d ", s1.elem[i]);
//	}
//
//
//	return 0;
//}


// *************************************************��.��ջ*****************************************************
// 
//int main()
//{
//	int i = 0;
//	LinkStack_Node* Ls1 = (LinkStack_Node*)malloc(sizeof(LinkStack_Node));  //��ʼ����ջLs1
//	if (Ls1 == NULL)
//	{
//		printf("��ջ����ռ�ʧ��!");
//		return 0;
//	}
//	Ls1->elem = -1;       // ���� //����ջ��һ���ڵ���Ϊͷ��㣬���洢Ԫ�أ�����Ϊ��ջ����
//	Ls1->front = NULL;
//	Ls1->behind = NULL;
//	LinkStack_Node* top = Ls1;           //����ȫ�ֱ���top��ָ����ջ����
//	LinkStack_Node* p_rear = Ls1;        //����ָ��visit��ϰ���Դ�rear
//
//
//	// **************************************��ջ����ջ�ͳ�ջ����*********************************************
//	for ( i = 0; i < 10; i++)
//	{
//		top = Push_LinkStack(top, i);
//	}
//
//	//for ( p_rear = Ls1 ; p_rear != top; p_rear = p_rear->behind)
//	//{
//	//	printf("%d ", p_rear->elem);
//	//}
//	for ( p_rear = Ls1 ; p_rear != NULL; p_rear = p_rear->behind)
//	{
//		printf("%d ", p_rear->elem);
//	}
//	putchar('\n');
//
//	top = Pop_LinkStack(Ls1, top);
//
//	for ( p_rear = Ls1; p_rear != NULL ; p_rear = p_rear->behind)
//	{
//		printf("%d ", p_rear->elem);
//
//	}
//
//	return 0;
//}


//****************************************��.ջ��ݹ�****************************************************
//***************쳲���������***********
//int main()
//{
//	int x = 0;
//	int a = 20;
//	if (a < 2)
//	{
//		return 0;
//	}
//	else
//	{
//		x = Fib(a);
//	}
//	printf("%d \n", x);
//
//	return 0;
//}


//***********************************************4.����*************************************************

////**************************************��.˳�����************************************************

//int main() 
//{
//	
//	//************************************************˳����г�ʼ��*****************************************
//	int i = 0;
//	int j = 0;
//	SeqQueue Sq1;
//	Sq1.elem = (int*)malloc(sizeof(Sq1.elem)*100);
//	//Sq1.rear = Sq1.elem;
//    Sq1.count = 0;  //�����countָ���β
//	Sq1.head = 0;
//
//	//*******************************************���*******************************************************
//	for ( i = 0; i < 10; i++)
//	{
//		Enter_SeqQueue(&Sq1, i);
//	}
//	for ( i = 0; i < Sq1.count; i++)
//	{
//		printf("%d ", Sq1.elem[i]);
//	}
//
//	putchar('\n');
//
//	//*******************************************����******************************************************
//	for ( i = 0; i < 5; i++)
//	{
//		Leave_SeqQueue(&Sq1);
//		for (j = Sq1.head; j < Sq1.count; j++)
//		{
//			printf("%d ", Sq1.elem[j]);
//			
//		}
//
//        putchar('\n');
//	}
//
//	for ( i = Sq1.head; i < Sq1.count; i++)
//	{
//		printf("%d ", Sq1.elem[i]);
//	}
//	putchar('\n');
//
//	return 0;
//}


//************************************************��.����*******************************************************

//int main()
//{
//
//	int i = 0;
//
//	LinkQueue* visit = 0;
//	LinkQueue* Lq1 = (LinkQueue*)malloc(sizeof(LinkQueue));
//	Lq1->elem = -1;
//	Lq1->next = NULL;
//	//Lq1->rear = Lq1;
//
//	struct linkqueue_node* rear = Lq1;
//
//	for ( i = 0; i < 10; i++)
//	{
//		Enter_LinkQueue(Lq1,rear, i);
//
//	}
//                  
//                                       //***********�����ǽ��Ӻͳ���************
//	for (visit = Lq1; visit != NULL; visit = visit->next)
//	{
//		printf("%d ",visit->elem);
//	}
//	putchar('\n');
//
//	for (i = 0; i < 5; i++)
//	{
//		Leave_LinkQueue(Lq1);
//	}
//
//	for (visit = Lq1; visit != NULL; visit = visit->next)
//	{
//		printf("%d ",visit->elem);
//	}
//	putchar('\n');
//
//
//	return 0;
//}


//**********************************************��.ѭ��˳�����*******************************************

//int main()
//{
//	//*******************************************��ʼ��**************************************
//	int i = 0;
//	Circu_SeqQueue Csq1 ;
//	Csq1.head = 0;
//	Csq1.rear = 0;
//	Csq1.elem = (int*)malloc(sizeof(int) * 10);
//	Csq1.elem[0] = -1;
//	Csq1.space_empty_flag = 1;
//
//	//*******************************���������кͳ�����************************************
//
//	for ( i = 0; i < 13; i++)
//	{
//		Enter_Circu_SeqQueue(&Csq1, i);
//	}
//	//i = -1;
//	for ( i = Csq1.head; i < Csq1.head+get_distance(&Csq1); i++)
//	{
//		printf("%d ",Csq1.elem[i%10]);
//	}
//	putchar('\n');
//
//	for ( i = 0; i < 6; i++)
//	{
//		Leave_Circu_SeqQueue(&Csq1);
//	}
//	for (i = Csq1.head; i < Csq1.head + get_distance(&Csq1); i++)
//	{
//		printf("%d ", Csq1.elem[i % 10]);
//	}
//	putchar('\n');
//
//	for (i = 0; i < 5; i++)
//	{
//		Enter_Circu_SeqQueue(&Csq1, i);
//	}
//	//i = -1;
//	for (i = Csq1.head; i < Csq1.head + get_distance(&Csq1); i++)
//	{
//		printf("%d ", Csq1.elem[i % 10]);
//	}
//	putchar('\n');
//
//	return 0;
//}










