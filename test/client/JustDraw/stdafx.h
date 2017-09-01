// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
// Windows 头文件:
#include <windows.h>

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <stdio.h>

// TODO: 在此处引用程序需要的其他头文件
#include <list>  
using namespace std;

#define  MAX_NUM  16    //行列数
enum ChessPalyer
{
	KONG = -1,
	JIA = 0,
	YI = 1
};
typedef struct ChessBoardShow
{
	int intChessBoard[MAX_NUM][MAX_NUM];   //10*10的棋盘  -1 为空，0为甲落子  1为乙落子
	int intWhoPlay;              //-1 为空，0为甲  1为乙
	COLORREF chessColor ;        //棋盘颜色 
	COLORREF chessLineColor ;    //棋盘线的颜色
	COLORREF AColor;             //甲颜色 
	COLORREF BColor;             //乙颜色
	int intLineWidth;            //棋盘线长度
	POINT ALast;                 //上一步棋甲下的位置
	POINT BLast;                 //上一步棋乙下的位置
	list<POINT> replayList;   //重玩
}ChessBoardShow,*pChessBoardShow;

#define WM_AUTOPLAY WM_USER + 1