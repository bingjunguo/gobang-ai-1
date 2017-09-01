#include "stdafx.h"
#include "CheckWin.h"
bool CheckWin(int a[MAX_NUM][MAX_NUM],int aOrb,int x,int y)
{
	if(XLine(a,aOrb,x,y)||YLine(a,aOrb,x,y)
		||XBeginYBegin(a,aOrb,x,y)||XEndYBegin(a,aOrb,x,y))
	     return true;
	return false;
}

bool XLine(int a[MAX_NUM][MAX_NUM],int aOrb,int x,int y)
{
	/*int a[10][10];
	int x,y;*/
    int n = 1;
	
    for(int i = x - 1;i > 0;i--)
    {
		if(a[i][y] == aOrb)
		{
			n++;
			if(n == 5)
				return true;
		}
		else
			break;
	}
	for(int i = x + 1;i < MAX_NUM;i++)
    {
		if(a[i][y] == aOrb)
		{
			n++;
			if(n == 5)
				return true;
		}
		else
			break;
	}
	return false;
}
bool YLine(int a[MAX_NUM][MAX_NUM],int aOrb,int x,int y)
{
	//int a[10][10];
	//int x,y;
    int n = 1;
    for(int i = y - 1;i > 0;i--)
    {
		if(a[x][i] == aOrb)
		{
			n++;
			if(n == 5)
				return true;
		}
		else
			break;
	}
	for(int i = y + 1;i < MAX_NUM;i++)
    {
		if(a[x][i] == aOrb)
		{
			n++;
			if(n == 5)
				return true;
		}
		else
			break;
	}
	return false;
}

bool XBeginYBegin(int a[MAX_NUM][MAX_NUM],int aOrb,int x,int y)  //  就这样 、/
{
	/*int a[10][10];
	int x,y;*/
	int i,j;
    int n = 1;
    for(i = x - 1,j = y - 1;(i > 0)&&(j > 0);i--,j--)
    {
		if(a[i][j] == aOrb)
		{
			n++;
			if(n == 5)
				return true;
		}
		else
			break;
	}
    for(i = x + 1,j = y + 1;(i < MAX_NUM)&&(j < MAX_NUM);i++,j++)
    {
		if(a[i][j] == aOrb)
		{
			n++;
			if(n == 5)
				return true;
		}
		else
			break;
	}
	return false;
}
bool XEndYBegin(int a[MAX_NUM][MAX_NUM],int aOrb,int x,int y)  // 就这样 /
{
	/*int a[10][10];
	int x,y;*/
	int i,j;
    int n = 1;
    for(i = x + 1,j = y - 1;( i < MAX_NUM)&&(j > 0);i++,j--)
    {
		if(a[i][j] == aOrb)
		{
			n++;
			if(n == 5)
				return true;
		}
		else
			break;
	}
    for(i = x - 1,j = y + 1;(i > 0)&&(j < MAX_NUM);i--,j++)
    {
		if(a[i][j] == aOrb)
		{
			n++;
			if(n == 5)
				return true;
		}
		else
			break;
	}
	return false;
}

void RepaintChessBoard(HDC hdc,ChessBoardShow chessBoard,RECT rt,int height,int width)
{
	HPEN hPen,hOldP;
	HBRUSH hBrush,hOldB;
	hBrush = CreateSolidBrush(chessBoard.chessColor);
	hOldB = (HBRUSH)SelectObject(hdc,hBrush);
	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
	DeleteObject(hBrush);
		
	//height = (rt.bottom - rt.top)/MAX_NUM;  //每一个格子的高度
	//width = (rt.right - rt.left)/MAX_NUM;   //每一个格子的宽度

	//画出一个棋盘的线。
	hPen = CreatePen(PS_SOLID,chessBoard.intLineWidth,chessBoard.chessLineColor);
	hOldP = (HPEN)SelectObject(hdc,hPen);
	//横
	for(int x = width;x < MAX_NUM * width; x = x + width)
	{
		MoveToEx(hdc,x,rt.top + height,NULL);
		LineTo(hdc,x,rt.bottom - height);
	}
	//竖
	for(int y = height;y < MAX_NUM * height; y = y + height)
	{
		MoveToEx(hdc,rt.left + width,y,NULL);
		LineTo(hdc,rt.right - width,y);
	}
	SelectObject(hdc,hOldP);
	DeleteObject(hPen);

	hPen = CreatePen(PS_SOLID,chessBoard.intLineWidth,chessBoard.chessLineColor);
	hOldP = (HPEN)SelectObject(hdc,hPen);
	//上线粗
	MoveToEx(hdc,rt.left + width - chessBoard.intLineWidth,rt.top + height - chessBoard.intLineWidth,NULL);
	LineTo(hdc,rt.right - width + chessBoard.intLineWidth,rt.top + height - chessBoard.intLineWidth);
	//下线粗
	MoveToEx(hdc,rt.left + width - chessBoard.intLineWidth,rt.bottom - height + chessBoard.intLineWidth,NULL);
	LineTo(hdc,rt.right - width + chessBoard.intLineWidth,rt.bottom - height + chessBoard.intLineWidth);
	//左线粗
	MoveToEx(hdc,rt.left + width - chessBoard.intLineWidth,rt.top + height - chessBoard.intLineWidth,NULL);
	LineTo(hdc,rt.left + width - chessBoard.intLineWidth,rt.bottom - height + chessBoard.intLineWidth);
	//右线粗
	MoveToEx(hdc,rt.right - width + chessBoard.intLineWidth,rt.top + height - chessBoard.intLineWidth,NULL);
	LineTo(hdc,rt.right - width + chessBoard.intLineWidth,rt.bottom - height + chessBoard.intLineWidth);
	SelectObject(hdc,hOldP);
	DeleteObject(hPen);
	//画点
	hBrush = CreateSolidBrush(chessBoard.chessLineColor);
	hOldB = (HBRUSH)SelectObject(hdc,hBrush);

	Ellipse(hdc, width * 8 - MAX_POINT_RADII,height * 8 - MAX_POINT_RADII,width * 8 + MAX_POINT_RADII,height * 8 + MAX_POINT_RADII);

	SelectObject(hdc,hOldB);
	DeleteObject(hBrush);

	

	//重绘棋子
	for(int x = width;x < MAX_NUM * width; x = x + width)
		for(int y = height;y < MAX_NUM * height; y = y + height)
		{
			if(chessBoard.intChessBoard[x/width][y/height] != -1)
			{
				if(chessBoard.intChessBoard[x/width][y/height] == 0)
					hBrush = CreateSolidBrush(chessBoard.AColor);
				else 
					hBrush = CreateSolidBrush(chessBoard.BColor);
				hOldB = (HBRUSH)SelectObject(hdc,hBrush);
				Ellipse(hdc,x - width * 0.5,y - height *0.5,x + width * 0.5,y + height *0.5);
				SelectObject(hdc,hOldB);
				DeleteObject(hBrush);
			}
		}
}
void IniChessBoard(ChessBoardShow &chessBoard)
{
	memset(chessBoard.intChessBoard,-1,(sizeof(int) * MAX_NUM * MAX_NUM));
	chessBoard.intWhoPlay = 0;
	chessBoard.chessColor = RGB(249,214,91);
	chessBoard.chessLineColor = RGB(0,0,0);
	chessBoard.AColor = RGB(255,255,255);
	chessBoard.BColor = RGB(0,0,0);
	chessBoard.intLineWidth = 2;

	chessBoard.intChessBoard[8][8] = 1;
}