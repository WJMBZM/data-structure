#include "game.h"



void PVE_Game()
{
	int FirstHand = 0;  //判断先手的变量
	int ContinueFlag = 1;  //判断是否继续下棋的变量
	int EndFlag = 0;   //判断是否结束的变量
	static int NumOfPiece = 0;    //棋盘上棋子总数，判断是否平局的静态变量
	char ChessBoard[ROW][COLUMN] = { 0 };
	InitializeChessBoard(ChessBoard, ROW, COLUMN);
	DisplayChessBoard(ChessBoard, ROW , COLUMN);
	FirstHand = IsFirstHand();  //x取先手的返回值，1为先手，2为后手
	printf("%d\n", FirstHand);
	if (FirstHand == 1)
	{
		while (ContinueFlag)
		{

		
		//玩家走棋
			 printf("轮到玩家走棋\n\n");
		     PlayerMove(ChessBoard);
		     DisplayChessBoard(ChessBoard, ROW, COLUMN);

		     EndFlag = IsEnd(ChessBoard,&NumOfPiece);  // 判断是否结束，1为平局，2为胜负已定，3为未结束继续
		     if (EndFlag != 3)
		     {
			    ContinueFlag = 0;
				break;
		     }

		     //电脑走棋
			 printf("轮到电脑走棋\n\n");
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

			//电脑走棋
			printf("轮到电脑走棋\n\n");
			ComputerMove(ChessBoard);
			DisplayChessBoard(ChessBoard, ROW, COLUMN);
			EndFlag = IsEnd(ChessBoard, &NumOfPiece);
			if (EndFlag != 3)
			{
				ContinueFlag = 0;
				break;
			}


			//玩家走棋
			printf("轮到玩家走棋\n\n");
			PlayerMove(ChessBoard);
			DisplayChessBoard(ChessBoard, ROW, COLUMN);

			EndFlag = IsEnd(ChessBoard, &NumOfPiece);  // 判断是否结束，1为平局，2为胜负已定，3为未结束继续
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
	int FirstHand = 0;  //判断先手的变量
	int ContinueFlag = 1;  //判断是否继续下棋的变量
	int EndFlag = 0;  //判断是否结束的变量
	static int NumOfPiece2 = 0;   //棋盘上棋子总数，判断是否平局的静态变量
	char ChessBoard[ROW][COLUMN] = { 0 };
	InitializeChessBoard(ChessBoard, ROW, COLUMN);
	DisplayChessBoard(ChessBoard, ROW, COLUMN);
	FirstHand = IsFirstHand();  //x取先手的返回值，1为先手，2为后手
	printf("%d\n", FirstHand);
	//printf("%s\n", FirstHand == 1 ?"先手":"后手");  //改写的先后手打印
	if (FirstHand == 1)
	{
		while (ContinueFlag)
		{


			//玩家1走棋
			printf("轮到玩家1走棋\n\n");
			Player1Move(ChessBoard);
			DisplayChessBoard(ChessBoard, ROW, COLUMN);

			EndFlag = IsEnd2(ChessBoard, &NumOfPiece2);  // 判断是否结束，1为平局，2为胜负已定，3为未结束继续
			if (EndFlag != 3)
			{
				ContinueFlag = 0;
				break;
			}

			//玩家2走棋
			printf("轮到玩家2走棋\n\n");
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

			//玩家2走棋
			printf("轮到玩家2走棋\n\n");
			Player2Move(ChessBoard);
			DisplayChessBoard(ChessBoard, ROW, COLUMN);
			EndFlag = IsEnd2(ChessBoard, &NumOfPiece2);
			if (EndFlag != 3)
			{
				ContinueFlag = 0;
				break;
			}


			//玩家1走棋
			printf("轮到玩家1走棋\n\n");
			Player1Move(ChessBoard);
			DisplayChessBoard(ChessBoard, ROW, COLUMN);

			EndFlag = IsEnd2(ChessBoard, &NumOfPiece2);  // 判断是否结束，1为平局，2为胜负已定，3为未结束继续
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
	int choice1 = 0;  // 选择开始游戏或者退出
	int choice2 = 0;  // 选择人机对战、玩家对战或者返回上一层

	ShowMenu1();
	printf("请选择数字\n");
	scanf_s("%d", &choice1);
	if (choice1 == 1)
	{
		printf("您选择了开始游戏\n");
		ShowStartMenu();
		printf("请选择模式\n");
		scanf_s("%d", &choice2);
		if (choice2 == 1) //PVE人机对战
		{
			printf("您选择了人机对战\n");
			PVE_Game();
		}
		else if (choice2 == 2)  //PVP玩家对战
		{
			printf("你选择了玩家对战\n");
			PVP_Game();
		}
		else if (choice2 == 3)  //返回上一层
		{
			play();
		}
	}
	else if (choice1 == 2)
	{
		
		printf("欢迎游玩%d子棋,下次再见", ROW);
        exit(0);
	}

	int Continue = 1;  // 选择是否再来一盘
	OnceAgainMenu3(); //1继续，2不继续
	while (Continue == 1 || Continue == 2)
	{

		scanf_s("%d", &Continue);//1继续，2不继续

		if (Continue == 1)
		{
			printf("你选择再来一盘\n");
			play();

		}
		else if (Continue == 2)
		{
			printf("游戏已退出\n");
			exit;
			break;

		}
		else
		{
			printf("输入不规范，请重新输入\n");
		}
	}

}

int main()
{
	play();

	return 0;
}