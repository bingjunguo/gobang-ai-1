// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�:
#include <windows.h>

// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <stdio.h>

// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include <list>  
using namespace std;

#define  MAX_NUM  16    //������
enum ChessPalyer
{
	KONG = -1,
	JIA = 0,
	YI = 1
};
typedef struct ChessBoardShow
{
	int intChessBoard[MAX_NUM][MAX_NUM];   //10*10������  -1 Ϊ�գ�0Ϊ������  1Ϊ������
	int intWhoPlay;              //-1 Ϊ�գ�0Ϊ��  1Ϊ��
	COLORREF chessColor ;        //������ɫ 
	COLORREF chessLineColor ;    //�����ߵ���ɫ
	COLORREF AColor;             //����ɫ 
	COLORREF BColor;             //����ɫ
	int intLineWidth;            //�����߳���
	POINT ALast;                 //��һ������µ�λ��
	POINT BLast;                 //��һ�������µ�λ��
	list<POINT> replayList;   //����
}ChessBoardShow,*pChessBoardShow;

#define WM_AUTOPLAY WM_USER + 1