#include "game.h"

void ShowMenu1()
{
	printf("********************************************\n");
	printf("********************************************\n");
	printf("***********1.开始游戏 2.退出****************\n");
	printf("********************************************\n");
	printf("********************************************\n");
}

void ShowStartMenu()
{
	printf("********************************************\n");
	printf("********************************************\n");
	printf("*****1.人机对战 2.玩家对战 3.返回上一层*****\n");
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
	printf("*****************1.先手 2.后手****************\n");
	printf("**********************************************\n");

	while (FirstHand != 1 && FirstHand != 2)
	{
		printf("请输入您是先手或者后手\n");
		scanf_s("%d", &FirstHand);
		if (FirstHand == 1)
		{
			printf("您选择了先手\n");
			return 1;
		}
		else if (FirstHand == 2)
		{
			printf("您选择了后手\n");
			return 2;
		}

		else
		{
			printf("输出错误\n");
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

	    printf("请输入您要下棋的位置,例如2,3,即2行3列\n");
	    scanf_s("%d,%d", &i , &j);
	    if (i > ROW || i < 1  || j > COLUMN || j < 1 )
	    {
		    printf("你输入的位置不在棋盘内\n");
	    }
		
		else if (ChessBoard[i-1][j-1] != ' ')
		{
			printf("你输入的位置已有棋子，请重新输入\n");

		}

		else 
		{

			ChessBoard[i-1][j-1] = 'X';
			printf("您已在%d,%d处落棋\n", i, j);
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
			printf("电脑在%d,%d处落棋\n", i+1, j+1);
			Continveflag = 0 ;
		}

	}

}

int IsEnd(char ChessBoard[ROW][COLUMN],int *NumOfPiece1)
{
	*NumOfPiece1 += 1 ;

	//应先判断输赢，再判断胜负，先判断胜负的话，有可能最后一颗子刚好赢了却判定为平局，因为棋盘下满了
	//if (*NumOfPiece1 == ROW * COLUMN)
	//{
	//	printf("平局\n"); 
	//	return 1;
	//}
	int i = 0;
	int j = 0;
	for ( i = 0 , j = 0 ; i < ROW && j < COLUMN; i++ , j++ )
	{
		//横向判断输赢
		if (ChessBoard[i][0] == ChessBoard[i][1] && ChessBoard[i][0] == ChessBoard[i][2] && ChessBoard[i][0] == 'X')
		{
			printf("玩家获胜\n");
			return 2;
		}

		else if (ChessBoard[i][0] == ChessBoard[i][1] && ChessBoard[i][0] == ChessBoard[i][2] && ChessBoard[i][0] == 'O')
		{
			printf("电脑获胜\n");
			return 2;
		}
		//竖向判断输赢
		else if (ChessBoard[0][j] == ChessBoard[1][j] && ChessBoard[0][j] == ChessBoard[2][j] && ChessBoard[0][j] == 'X')
		{
			printf("玩家获胜\n");
			return 2;
		}

		else if (ChessBoard[0][j] == ChessBoard[1][j] && ChessBoard[0][j] == ChessBoard[2][j] && ChessBoard[0][j] == 'O')
		{
			printf("电脑获胜\n");
			return 2;
		}
		//正对角线判断输赢
		else if (ChessBoard[0][0] == ChessBoard[1][1] && ChessBoard[0][0] == ChessBoard[2][2] && ChessBoard[0][0] == 'X')
		{
			printf("玩家获胜\n");
			return 2;
		}
		else if (ChessBoard[0][0] == ChessBoard[1][1] && ChessBoard[0][0] == ChessBoard[2][2] && ChessBoard[0][0] == 'O')
		{
			printf("电脑获胜\n");
			return 2;
		}
		//副对角线判断输赢
		else if (ChessBoard[2][0] == ChessBoard[1][1] && ChessBoard[2][0] == ChessBoard[0][2] && ChessBoard[2][0] == 'X')
		{
			printf("玩家获胜\n");
			return 2;
				
		}

		else if (ChessBoard[2][0] == ChessBoard[1][1] && ChessBoard[2][0] == ChessBoard[0][2] && ChessBoard[2][0] == 'O')
		{
			printf("电脑获胜\n");
			return 2;
		}

	}
	if (*NumOfPiece1 == ROW * COLUMN)
{
	printf("平局\n"); 
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

		printf("请输入您要下棋的位置,例如2,3,即2行3列\n");
		scanf_s("%d,%d", &i, &j);
		if (i > ROW || i < 1 || j > COLUMN || j < 1)
		{
			printf("你输入的位置不在棋盘内\n");
		}

		else if (ChessBoard[i-1][j-1] != ' ')
		{
			printf("你输入的位置已有棋子，请重新输入\n");

		}

		else
		{

			ChessBoard[i - 1][j - 1] = 'X';
			printf("您已在%d,%d处落棋\n", i, j);
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

		printf("请输入您要下棋的位置,例如2,3,即2行3列\n");
		scanf_s("%d,%d", &i, &j);
		if (i > ROW || i < 1 || j > COLUMN || j < 1)
		{
			printf("你输入的位置不在棋盘内\n");
		}

		else if  (ChessBoard[i-1][j-1] != ' ')
		{
			printf("你输入的位置已有棋子，请重新输入\n");

		}

		else
		{

			ChessBoard[i - 1][j - 1] = 'O';
			printf("您已在%d,%d处落棋\n", i, j);
			flag = 0;

		}

	}
}


int IsEnd2(char ChessBoard[ROW][COLUMN], int* NumOfPiece2)
{
	*NumOfPiece2 += 1;

	//应先判断输赢，再判断胜负，先判断胜负的话，有可能最后一颗子刚好赢了却判定为平局，因为棋盘下满了
	//if (*NumOfPiece1 == ROW * COLUMN)
	//{
	//	printf("平局\n"); 
	//	return 1;
	//}
	int i = 0;
	int j = 0;
	for (i = 0, j = 0; i < ROW && j < COLUMN; i++, j++)
	{
		//横向判断输赢
		if (ChessBoard[i][0] == ChessBoard[i][1] && ChessBoard[i][0] == ChessBoard[i][2] && ChessBoard[i][0] == 'X')
		{
			printf("玩家1获胜\n");
			return 2;
		}

		else if (ChessBoard[i][0] == ChessBoard[i][1] && ChessBoard[i][0] == ChessBoard[i][2] && ChessBoard[i][0] == 'O')
		{
			printf("玩家2获胜\n");
			return 2;
		}
		//竖向判断输赢
		else if (ChessBoard[0][j] == ChessBoard[1][j] && ChessBoard[0][j] == ChessBoard[2][j] && ChessBoard[0][j] == 'X')
		{
			printf("玩家1获胜\n");
			return 2;
		}

		else if (ChessBoard[0][j] == ChessBoard[1][j] && ChessBoard[0][j] == ChessBoard[2][j] && ChessBoard[0][j] == 'O')
		{
			printf("玩家2获胜\n");
			return 2;
		}
		//正对角线判断输赢
		else if (ChessBoard[0][0] == ChessBoard[1][1] && ChessBoard[0][0] == ChessBoard[2][2] && ChessBoard[0][0] == 'X')
		{
			printf("玩家1获胜\n");
			return 2;
		}
		else if (ChessBoard[0][0] == ChessBoard[1][1] && ChessBoard[0][0] == ChessBoard[2][2] && ChessBoard[0][0] == 'O')
		{
			printf("玩家2获胜\n");
			return 2;
		}
		//副对角线判断输赢
		else if (ChessBoard[2][0] == ChessBoard[1][1] && ChessBoard[2][0] == ChessBoard[0][2] && ChessBoard[2][0] == 'X')
		{
			printf("玩家1获胜\n");
			return 2;

		}

		else if (ChessBoard[2][0] == ChessBoard[1][1] && ChessBoard[2][0] == ChessBoard[0][2] && ChessBoard[2][0] == 'O')
		{
			printf("玩家2获胜\n");
			return 2;
		}

	}
	if (*NumOfPiece2 == ROW * COLUMN)
	{
		printf("平局\n");
		return 1;
	}


	return 3;
}


void OnceAgainMenu3()
{
	printf("***********************************************\n");
	printf("******************是否再来一盘*****************\n");
	printf("***********************************************\n");
	printf("********************1.是 2.否******************\n");
	printf("***********************************************\n");
	printf("***********************************************\n");
}