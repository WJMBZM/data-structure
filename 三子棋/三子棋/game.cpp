#include "game.h"

void ShowMenu1()
{
	printf("********************************************\n");
	printf("********************************************\n");
	printf("***********1.��ʼ��Ϸ 2.�˳�****************\n");
	printf("********************************************\n");
	printf("********************************************\n");
}

void ShowStartMenu()
{
	printf("********************************************\n");
	printf("********************************************\n");
	printf("*****1.�˻���ս 2.��Ҷ�ս 3.������һ��*****\n");
	printf("********************************************\n");
	printf("********************************************\n");
}

void InitializeChessBoard(char ChessBoard[ROW][COLUMN],int row,int column)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < column; j++)
		{
			ChessBoard[i][j] = ' ';
		}
	}
}

void DisplayChessBoard(char ChessBoard[ROW][COLUMN] ,int row , int column)
{
	int i = 0;
	int j = 0;

	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < column; j++)
		{
			printf(" %c ", ChessBoard[i][j]);
			if (j < column - 1)
			{
				printf("|");
			}
		}

		printf("\n");

		
		if (i < row - 1)
		{
			for (j = 0; j < column; j++)
			{
				printf("---");

				if (j < column - 1)
				{
					printf("|");
				}

			}

			printf("\n");
		}
		    
	}
}

int IsFirstHand()
{
	int FirstHand = 0;
	printf("**********************************************\n");
	printf("*****************1.���� 2.����****************\n");
	printf("**********************************************\n");

	while (FirstHand != 1 && FirstHand != 2)
	{
		printf("�������������ֻ��ߺ���\n");
		scanf_s("%d", &FirstHand);
		if (FirstHand == 1)
		{
			printf("��ѡ��������\n");
			return 1;
		}
		else if (FirstHand == 2)
		{
			printf("��ѡ���˺���\n");
			return 2;
		}

		else
		{
			printf("�������\n");
		}
	}
	
}


void PlayerMove(char ChessBoard[ROW][COLUMN])
{
	int i;
	int j;
	int flag = 1;

	while (flag)
	{

	    printf("��������Ҫ�����λ��,����2,3,��2��3��\n");
	    scanf_s("%d,%d", &i , &j);
	    if (i > ROW || i < 1  || j > COLUMN || j < 1 )
	    {
		    printf("�������λ�ò���������\n");
	    }
		
		else if (ChessBoard[i-1][j-1] != ' ')
		{
			printf("�������λ���������ӣ�����������\n");

		}

		else 
		{

			ChessBoard[i-1][j-1] = 'X';
			printf("������%d,%d������\n", i, j);
				flag = 0;

		}

    }
}

void ComputerMove(char ChessBoard[ROW][COLUMN])
{
	int i = 0;
	int j = 0;
	int Continveflag = 1;
	srand((unsigned int)time(0));
	while (Continveflag)
	{
		i = rand() % 3;
		j = rand() % 3;
		if (ChessBoard[i][j] == ' ')
		{
			ChessBoard[i][j] = 'O';
			printf("������%d,%d������\n", i+1, j+1);
			Continveflag = 0 ;
		}

	}

}

int IsEnd(char ChessBoard[ROW][COLUMN],int *NumOfPiece1)
{
	*NumOfPiece1 += 1 ;

	//Ӧ���ж���Ӯ�����ж�ʤ�������ж�ʤ���Ļ����п������һ���Ӹպ�Ӯ��ȴ�ж�Ϊƽ�֣���Ϊ����������
	//if (*NumOfPiece1 == ROW * COLUMN)
	//{
	//	printf("ƽ��\n"); 
	//	return 1;
	//}
	int i = 0;
	int j = 0;
	for ( i = 0 , j = 0 ; i < ROW && j < COLUMN; i++ , j++ )
	{
		//�����ж���Ӯ
		if (ChessBoard[i][0] == ChessBoard[i][1] && ChessBoard[i][0] == ChessBoard[i][2] && ChessBoard[i][0] == 'X')
		{
			printf("��һ�ʤ\n");
			return 2;
		}

		else if (ChessBoard[i][0] == ChessBoard[i][1] && ChessBoard[i][0] == ChessBoard[i][2] && ChessBoard[i][0] == 'O')
		{
			printf("���Ի�ʤ\n");
			return 2;
		}
		//�����ж���Ӯ
		else if (ChessBoard[0][j] == ChessBoard[1][j] && ChessBoard[0][j] == ChessBoard[2][j] && ChessBoard[0][j] == 'X')
		{
			printf("��һ�ʤ\n");
			return 2;
		}

		else if (ChessBoard[0][j] == ChessBoard[1][j] && ChessBoard[0][j] == ChessBoard[2][j] && ChessBoard[0][j] == 'O')
		{
			printf("���Ի�ʤ\n");
			return 2;
		}
		//���Խ����ж���Ӯ
		else if (ChessBoard[0][0] == ChessBoard[1][1] && ChessBoard[0][0] == ChessBoard[2][2] && ChessBoard[0][0] == 'X')
		{
			printf("��һ�ʤ\n");
			return 2;
		}
		else if (ChessBoard[0][0] == ChessBoard[1][1] && ChessBoard[0][0] == ChessBoard[2][2] && ChessBoard[0][0] == 'O')
		{
			printf("���Ի�ʤ\n");
			return 2;
		}
		//���Խ����ж���Ӯ
		else if (ChessBoard[2][0] == ChessBoard[1][1] && ChessBoard[2][0] == ChessBoard[0][2] && ChessBoard[2][0] == 'X')
		{
			printf("��һ�ʤ\n");
			return 2;
				
		}

		else if (ChessBoard[2][0] == ChessBoard[1][1] && ChessBoard[2][0] == ChessBoard[0][2] && ChessBoard[2][0] == 'O')
		{
			printf("���Ի�ʤ\n");
			return 2;
		}

	}
	if (*NumOfPiece1 == ROW * COLUMN)
{
	printf("ƽ��\n"); 
	return 1;
}


	return 3;
}


void Player1Move(char ChessBoard[ROW][COLUMN])
{
	int i;
	int j;
	int flag = 1;

	while (flag)
	{

		printf("��������Ҫ�����λ��,����2,3,��2��3��\n");
		scanf_s("%d,%d", &i, &j);
		if (i > ROW || i < 1 || j > COLUMN || j < 1)
		{
			printf("�������λ�ò���������\n");
		}

		else if (ChessBoard[i-1][j-1] != ' ')
		{
			printf("�������λ���������ӣ�����������\n");

		}

		else
		{

			ChessBoard[i - 1][j - 1] = 'X';
			printf("������%d,%d������\n", i, j);
			flag = 0;

		}

	}
}

void Player2Move(char ChessBoard[ROW][COLUMN])
{
	int i;
	int j;
	int flag = 1;

	while (flag)
	{

		printf("��������Ҫ�����λ��,����2,3,��2��3��\n");
		scanf_s("%d,%d", &i, &j);
		if (i > ROW || i < 1 || j > COLUMN || j < 1)
		{
			printf("�������λ�ò���������\n");
		}

		else if  (ChessBoard[i-1][j-1] != ' ')
		{
			printf("�������λ���������ӣ�����������\n");

		}

		else
		{

			ChessBoard[i - 1][j - 1] = 'O';
			printf("������%d,%d������\n", i, j);
			flag = 0;

		}

	}
}


int IsEnd2(char ChessBoard[ROW][COLUMN], int* NumOfPiece2)
{
	*NumOfPiece2 += 1;

	//Ӧ���ж���Ӯ�����ж�ʤ�������ж�ʤ���Ļ����п������һ���Ӹպ�Ӯ��ȴ�ж�Ϊƽ�֣���Ϊ����������
	//if (*NumOfPiece1 == ROW * COLUMN)
	//{
	//	printf("ƽ��\n"); 
	//	return 1;
	//}
	int i = 0;
	int j = 0;
	for (i = 0, j = 0; i < ROW && j < COLUMN; i++, j++)
	{
		//�����ж���Ӯ
		if (ChessBoard[i][0] == ChessBoard[i][1] && ChessBoard[i][0] == ChessBoard[i][2] && ChessBoard[i][0] == 'X')
		{
			printf("���1��ʤ\n");
			return 2;
		}

		else if (ChessBoard[i][0] == ChessBoard[i][1] && ChessBoard[i][0] == ChessBoard[i][2] && ChessBoard[i][0] == 'O')
		{
			printf("���2��ʤ\n");
			return 2;
		}
		//�����ж���Ӯ
		else if (ChessBoard[0][j] == ChessBoard[1][j] && ChessBoard[0][j] == ChessBoard[2][j] && ChessBoard[0][j] == 'X')
		{
			printf("���1��ʤ\n");
			return 2;
		}

		else if (ChessBoard[0][j] == ChessBoard[1][j] && ChessBoard[0][j] == ChessBoard[2][j] && ChessBoard[0][j] == 'O')
		{
			printf("���2��ʤ\n");
			return 2;
		}
		//���Խ����ж���Ӯ
		else if (ChessBoard[0][0] == ChessBoard[1][1] && ChessBoard[0][0] == ChessBoard[2][2] && ChessBoard[0][0] == 'X')
		{
			printf("���1��ʤ\n");
			return 2;
		}
		else if (ChessBoard[0][0] == ChessBoard[1][1] && ChessBoard[0][0] == ChessBoard[2][2] && ChessBoard[0][0] == 'O')
		{
			printf("���2��ʤ\n");
			return 2;
		}
		//���Խ����ж���Ӯ
		else if (ChessBoard[2][0] == ChessBoard[1][1] && ChessBoard[2][0] == ChessBoard[0][2] && ChessBoard[2][0] == 'X')
		{
			printf("���1��ʤ\n");
			return 2;

		}

		else if (ChessBoard[2][0] == ChessBoard[1][1] && ChessBoard[2][0] == ChessBoard[0][2] && ChessBoard[2][0] == 'O')
		{
			printf("���2��ʤ\n");
			return 2;
		}

	}
	if (*NumOfPiece2 == ROW * COLUMN)
	{
		printf("ƽ��\n");
		return 1;
	}


	return 3;
}


void OnceAgainMenu3()
{
	printf("***********************************************\n");
	printf("******************�Ƿ�����һ��*****************\n");
	printf("***********************************************\n");
	printf("********************1.�� 2.��******************\n");
	printf("***********************************************\n");
	printf("***********************************************\n");
}