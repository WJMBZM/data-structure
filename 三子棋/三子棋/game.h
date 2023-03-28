#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<windows.h>

#define ROW 3
#define COLUMN 3



void ShowMenu1();
void ShowStartMenu();
void InitializeChessBoard(char ChessBoard[ROW][COLUMN], int row, int column);
void DisplayChessBoard(char ChessBoard[ROW][COLUMN] , int row, int column);
int IsFirstHand();
void PlayerMove(char ChessBoard[ROW][COLUMN]);
void ComputerMove(char ChessBoard[ROW][COLUMN]);
int IsEnd(char ChessBoard[ROW][COLUMN],int *NumOfPiece1);

void Player1Move(char ChessBoard[ROW][COLUMN]);
void Player2Move(char ChessBoard[ROW][COLUMN]);
int IsEnd2(char ChessBoard[ROW][COLUMN], int* NumOfPiece2);
void OnceAgainMenu3();