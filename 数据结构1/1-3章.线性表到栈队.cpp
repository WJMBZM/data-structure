#include "1-3章.算法设计.h"

//              ****************************************1.顺序表***********************************************
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
//	printf("顺序表s1中数据为3的元素是第%d个\n", Locate_SqList(s1 , 3));
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


//   *********************************************2.链表*************************************************

//int main()
//{
//	int i = 0;
//
//	LinkList* L1 = (LinkList*)malloc(sizeof(LinkList));
//	if (L1 == NULL)
//	{
//		printf("创建链表失败!");
//		return 0;
//	}
//	L1->next = NULL;
//	L1->LinkList_length = 0;
//	
//	// ******************************************建立尾指针初始化链表L1**********************************
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
//	// ****************************************初始化结束********************************************
//
//	p_rear = (LinkNode*)L1;
//	printf("初始化后的链表L1为 :");
//	for ( i = 0; i < L1->LinkList_length ; i++)
//	{
//		p_rear = p_rear->next;
//		printf("%d ", p_rear->elem);
//	}
//	putchar('\n');
//	printf("链表L1的长度是:%d\n", L1->LinkList_length);
//
//	// **********************************************进行插入操作****************************************增
//	Insert_LinkList(L1, 66, 2);
//
//	p_rear = (LinkNode*)L1;
//	for ( i = 0; i < L1->LinkList_length ; i++)
//	{
//		p_rear = p_rear->next;
//		printf("%d ", p_rear->elem);
//	}
//	putchar('\n');
//	printf("链表L1的长度是:%d \n", L1->LinkList_length);
//
//	// **********************************************进行删除操作****************************************增
//	Delete_LinkList(L1,3);
//	p_rear =(LinkNode*) L1;
//	for ( i = 0; i < L1->LinkList_length; i++)
//	{
//		p_rear = p_rear->next;
//		printf("%d ", p_rear->elem);
//	}
//	putchar('\n');
//	printf("链表L1的长度是:%d\n", L1->LinkList_length);
//
//	Updata_LinkList(L1, 88, 3);
//	p_rear = (LinkNode*)L1;
//	for ( i = 0; i < L1->LinkList_length; i++)
//	{
//		p_rear = p_rear->next;
//		printf("%d ", p_rear->elem);
//	}
//	putchar('\n');
//	printf("链表L1的长度是:%d\n", L1->LinkList_length);
//
//	Locate_LinkList(L1,66);
//	putchar('\n');
//	Locate_LinkList(L1, 7);
//	putchar('\n');
//
//	return 0;
//}


// *****************************************3.栈****************************************************
 
 //****************************************①.顺序栈******************************************************
 
//int main()
//{
//	//*****************************************创建顺序栈并初始化******************************
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
//	for (i = 0; i < 10; i++)  //****************************顺序栈的入栈和出栈**********************************
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


// *************************************************②.链栈*****************************************************
// 
//int main()
//{
//	int i = 0;
//	LinkStack_Node* Ls1 = (LinkStack_Node*)malloc(sizeof(LinkStack_Node));  //初始化链栈Ls1
//	if (Ls1 == NULL)
//	{
//		printf("链栈分配空间失败!");
//		return 0;
//	}
//	Ls1->elem = -1;       // 放弃 //将链栈第一个节点设为头结点，不存储元素，数据为链栈长度
//	Ls1->front = NULL;
//	Ls1->behind = NULL;
//	LinkStack_Node* top = Ls1;           //创建全局变量top来指向链栈顶端
//	LinkStack_Node* p_rear = Ls1;        //访问指针visit，习惯性打rear
//
//
//	// **************************************链栈的入栈和出栈操作*********************************************
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


//****************************************③.栈与递归****************************************************
//***************斐波那契数列***********
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


//***********************************************4.队列*************************************************

////**************************************①.顺序队列************************************************

//int main() 
//{
//	
//	//************************************************顺序队列初始化*****************************************
//	int i = 0;
//	int j = 0;
//	SeqQueue Sq1;
//	Sq1.elem = (int*)malloc(sizeof(Sq1.elem)*100);
//	//Sq1.rear = Sq1.elem;
//    Sq1.count = 0;  //这里的count指向队尾
//	Sq1.head = 0;
//
//	//*******************************************入队*******************************************************
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
//	//*******************************************出队******************************************************
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


//************************************************②.链队*******************************************************

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
//                                       //***********这里是进队和出队************
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


//**********************************************③.循环顺序队列*******************************************

//int main()
//{
//	//*******************************************初始化**************************************
//	int i = 0;
//	Circu_SeqQueue Csq1 ;
//	Csq1.head = 0;
//	Csq1.rear = 0;
//	Csq1.elem = (int*)malloc(sizeof(int) * 10);
//	Csq1.elem[0] = -1;
//	Csq1.space_empty_flag = 1;
//
//	//*******************************操作进队列和出队列************************************
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










