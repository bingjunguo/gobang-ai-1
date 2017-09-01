#if !defined CHECKWIN_H
#define CHECKWIN_H
#endif
#include "stdafx.h"

#define MAX_POINT_RADII 5   //ºÚµã°ë¾¶

bool CheckWin(int a[MAX_NUM][MAX_NUM],int aOrb,int x,int y);
bool XLine(int a[MAX_NUM][MAX_NUM],int aOrb,int x,int y);
bool YLine(int a[MAX_NUM][MAX_NUM],int aOrb,int x,int y);
bool XBeginYBegin(int a[MAX_NUM][MAX_NUM],int aOrb,int x,int y);
bool XEndYBegin(int a[MAX_NUM][MAX_NUM],int aOrb,int x,int y);

void RepaintChessBoard(HDC hdc,ChessBoardShow chessBoard,RECT rt,int height,int width);
void IniChessBoard(ChessBoardShow &chessBoard);