#include "game.h"



void PVE_Game()
{
	int FirstHand = 0;  //�ж����ֵı���
	int ContinueFlag = 1;  //�ж��Ƿ��������ı���
	int EndFlag = 0;   //�ж��Ƿ�����ı���
	static int NumOfPiece = 0;    //�����������������ж��Ƿ�ƽ�ֵľ�̬����
	char ChessBoard[ROW][COLUMN] = { 0 };
	InitializeChessBoard(ChessBoard, ROW, COLUMN);
	DisplayChessBoard(ChessBoard, ROW , COLUMN);
	FirstHand = IsFirstHand();  //xȡ���ֵķ���ֵ��1Ϊ���֣�2Ϊ����
	printf("%d\n", FirstHand);
	if (FirstHand == 1)
	{
		while (ContinueFlag)
		{

		
		//�������
			 printf("�ֵ��������\n\n");
		     PlayerMove(ChessBoard);
		     DisplayChessBoard(ChessBoard, ROW, COLUMN);

		     EndFlag = IsEnd(ChessBoard,&NumOfPiece);  // �ж��Ƿ������1Ϊƽ�֣�2Ϊʤ���Ѷ���3Ϊδ��������
		     if (EndFlag != 3)
		     {
			    ContinueFlag = 0;
				break;
		     }

		     //��������
			 printf("�ֵ���������\n\n");
		     ComputerMove(ChessBoard);
		     DisplayChessBoard(ChessBoard, ROW, COLUMN);
		     EndFlag = IsEnd(ChessBoard,&NumOfPiece);
		     if (EndFlag != 3)
		     {
			     ContinueFlag = 0;
				 break;
		     }

        } 

	}
	
	else if (FirstHand == 2 )
	{
		while (ContinueFlag)
		{

			//��������
			printf("�ֵ���������\n\n");
			ComputerMove(ChessBoard);
			DisplayChessBoard(ChessBoard, ROW, COLUMN);
			EndFlag = IsEnd(ChessBoard, &NumOfPiece);
			if (EndFlag != 3)
			{
				ContinueFlag = 0;
				break;
			}


			//�������
			printf("�ֵ��������\n\n");
			PlayerMove(ChessBoard);
			DisplayChessBoard(ChessBoard, ROW, COLUMN);

			EndFlag = IsEnd(ChessBoard, &NumOfPiece);  // �ж��Ƿ������1Ϊƽ�֣�2Ϊʤ���Ѷ���3Ϊδ��������
			if (EndFlag != 3)
			{
				ContinueFlag = 0;
				break;
			}


		}
	}
	NumOfPiece = 0;
}

void PVP_Game()
{
	int FirstHand = 0;  //�ж����ֵı���
	int ContinueFlag = 1;  //�ж��Ƿ��������ı���
	int EndFlag = 0;  //�ж��Ƿ�����ı���
	static int NumOfPiece2 = 0;   //�����������������ж��Ƿ�ƽ�ֵľ�̬����
	char ChessBoard[ROW][COLUMN] = { 0 };
	InitializeChessBoard(ChessBoard, ROW, COLUMN);
	DisplayChessBoard(ChessBoard, ROW, COLUMN);
	FirstHand = IsFirstHand();  //xȡ���ֵķ���ֵ��1Ϊ���֣�2Ϊ����
	printf("%d\n", FirstHand);
	//printf("%s\n", FirstHand == 1 ?"����":"����");  //��д���Ⱥ��ִ�ӡ
	if (FirstHand == 1)
	{
		while (ContinueFlag)
		{


			//���1����
			printf("�ֵ����1����\n\n");
			Player1Move(ChessBoard);
			DisplayChessBoard(ChessBoard, ROW, COLUMN);

			EndFlag = IsEnd2(ChessBoard, &NumOfPiece2);  // �ж��Ƿ������1Ϊƽ�֣�2Ϊʤ���Ѷ���3Ϊδ��������
			if (EndFlag != 3)
			{
				ContinueFlag = 0;
				break;
			}

			//���2����
			printf("�ֵ����2����\n\n");
			Player2Move(ChessBoard);
			DisplayChessBoard(ChessBoard, ROW, COLUMN);
			EndFlag = IsEnd2(ChessBoard, &NumOfPiece2);
			if (EndFlag != 3)
			{
				ContinueFlag = 0;
				break;
			}

		}

	}

	else if (FirstHand == 2)
	{
		while (ContinueFlag)
		{

			//���2����
			printf("�ֵ����2����\n\n");
			Player2Move(ChessBoard);
			DisplayChessBoard(ChessBoard, ROW, COLUMN);
			EndFlag = IsEnd2(ChessBoard, &NumOfPiece2);
			if (EndFlag != 3)
			{
				ContinueFlag = 0;
				break;
			}


			//���1����
			printf("�ֵ����1����\n\n");
			Player1Move(ChessBoard);
			DisplayChessBoard(ChessBoard, ROW, COLUMN);

			EndFlag = IsEnd2(ChessBoard, &NumOfPiece2);  // �ж��Ƿ������1Ϊƽ�֣�2Ϊʤ���Ѷ���3Ϊδ��������
			if (EndFlag != 3)
			{
				ContinueFlag = 0;
				break;
			}


		}
	}
	NumOfPiece2 = 0;
}

void play()
{
	int choice1 = 0;  // ѡ��ʼ��Ϸ�����˳�
	int choice2 = 0;  // ѡ���˻���ս����Ҷ�ս���߷�����һ��

	ShowMenu1();
	printf("��ѡ������\n");
	scanf_s("%d", &choice1);
	if (choice1 == 1)
	{
		printf("��ѡ���˿�ʼ��Ϸ\n");
		ShowStartMenu();
		printf("��ѡ��ģʽ\n");
		scanf_s("%d", &choice2);
		if (choice2 == 1) //PVE�˻���ս
		{
			printf("��ѡ�����˻���ս\n");
			PVE_Game();
		}
		else if (choice2 == 2)  //PVP��Ҷ�ս
		{
			printf("��ѡ������Ҷ�ս\n");
			PVP_Game();
		}
		else if (choice2 == 3)  //������һ��
		{
			play();
		}
	}
	else if (choice1 == 2)
	{
		
		printf("��ӭ����%d����,�´��ټ�", ROW);
        exit(0);
	}

	int Continue = 1;  // ѡ���Ƿ�����һ��
	OnceAgainMenu3(); //1������2������
	while (Continue == 1 || Continue == 2)
	{

		scanf_s("%d", &Continue);//1������2������

		if (Continue == 1)
		{
			printf("��ѡ������һ��\n");
			play();

		}
		else if (Continue == 2)
		{
			printf("��Ϸ���˳�\n");
			exit;
			break;

		}
		else
		{
			printf("���벻�淶������������\n");
		}
	}

}

int main()
{
	play();

	return 0;
}