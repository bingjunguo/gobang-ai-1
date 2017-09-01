#if !defined AUTOPLAY_H
#define AUTOPLAY_H
#endif
#include "stdafx.h"
#include<time.h>
#include <math.h>
#define random(x) (rand()%x)
//���ط���
//����1��19�� 1-19�� б�� Ѱ���������ĸ�������������
/*
  1. ptBegin .. .. ptEnd    2.  ptBegin    4.            ptBegin
  3. ptBegin                       ..                  ..
	        ..                     ..                ..
			   ..                ptEnd          ptEnd
				  ptEnd       
*/
//#define CHESSMAN_HENG       1
//#define CHESSMAN_SHU        2
//#define CHESSMAN_XIE_LEFT   3
//#define CHESSMAN_XIE_RIGHT  4
enum ChessManLine
{
	CHESSMAN_HENG = 1,
	CHESSMAN_SHU,
	CHESSMAN_XIE_LEFT,
	CHESSMAN_XIE_RIGHT

};

enum SeriesLine
{
	TWO = 2,
	THREE,
	FOUR
};
typedef struct ChessMan  //��������   Ӧ���Ǵ�С�������
{
	POINT ptBegin;  //����ͼ��ʾ�Ŀ�ʼ
	POINT ptEnd;    //����ͼ��ʾ�Ľ���
	int type;       //����ͼ��ʾ��ö�������е�һ��
	//bool bVisit;    //�Ƿ񱻷���  ����ֻ��2����ѭ��������ʹ��
}ChessMan,*pChessMan;
typedef struct ChessManLineList
{
	list<ChessMan> fourChessManList;
	list<ChessMan> threeChessManList;
	list<ChessMan> twoChessManList;
}ChessManLineList,*pChessManLineList;

typedef struct DepriorityLevel    //���ȼ�
{
	list<POINT> zeroLevelList;   //һ������   һ����Ӯ   
	list<POINT> oneLevelList;    //һ������   һ����Ӯ
	list<POINT> twoLevelList;    //��������   ������Ӯ
};
//����һ��4�����ӵ�
/*
   @ int a[MAX_NUM][MAX_NUM] ������������� 1-19
   @ int chessManNum   ��ѯ�������ӵ�����
   @ int aOrb    ���廹�Ǻ���  0Ϊ���� 1Ϊ����
*/
void FindChessManLineShu(int a[MAX_NUM][MAX_NUM],list<ChessMan> &chessManList,int chessManNum,int aOrb);
void FindChessManLineHeng(int a[MAX_NUM][MAX_NUM],list<ChessMan> &chessManList,int chessManNum,int aOrb);
void FindChessManLineXieLeft(int a[MAX_NUM][MAX_NUM],list<ChessMan> &chessManList,int chessManNum,int aOrb);
void FindChessManLineXieRight(int a[MAX_NUM][MAX_NUM],list<ChessMan> &chessManList,int chessManNum,int aOrb);

//��ʼ�������� ���������ȼ�
void ManageSeriesFourLine(int a[MAX_NUM][MAX_NUM],list<ChessMan> chessManList,DepriorityLevel &dl,int aOrb);
void ManageSeriesThreeLine(int a[MAX_NUM][MAX_NUM],list<ChessMan> chessManList,DepriorityLevel &dl,int aOrb);
void ManageSeriesTwoLine(int a[MAX_NUM][MAX_NUM],list<ChessMan> chessManList,DepriorityLevel &dl,int aOrb);
//     x
//    x x
//     x
//���������������
// @ POINT pt �м��Ǹ���
// @int a[MAX_NUM][MAX_NUM] ��������
bool FindFourChessManMidKONG(int a[MAX_NUM][MAX_NUM],POINT pt,int aOrb);
void ManageSeriesOneChessMan(int a[MAX_NUM][MAX_NUM],POINT otherSideLastPt,DepriorityLevel &dl,int aOrb);
//���������������� �� ������������  2 2 ��2 3 �� ֮������
// o** ����˵�������
//  *
//   *
void ManageSeriesTwoThreeLine(int a[MAX_NUM][MAX_NUM],list<ChessMan> chessManTwoList,
							  list<ChessMan> chessManThreeList,DepriorityLevel &dl,int aOrb);
//    x
// xxx
//    x   Ѱ��������������.
bool FindTheInterSectPoint(int a[MAX_NUM][MAX_NUM],POINT ptOneSide,POINT &rtPt,int lineType,int aOrb);
//�������������Ϊ�˷��� ���� ���� ���� ���� ���� ���� �Ļ� �ĳ�   ��������û���õ���Ѱ���Ļ�
void FindLineListLive(int a[MAX_NUM][MAX_NUM],list<ChessMan> chessManList,ChessMan *chm,int &intChessManNum);
//����һ���߶��Ƿ��ǻ�� 
// ret -1 �󲻿�  1�ɲ��� 0 ���߿� -2���߲���
int FindLineLive(int a[MAX_NUM][MAX_NUM],ChessMan chm);
//������ y=kx+b���ߵĽ��� �еĻ����� true ���ݴ�������Point��

//�������Ļ����϶��ǲ���ǽ��
bool TwoLineInterSect(ChessMan &chm1,ChessMan &chm2,POINT &pt);


//�����㷨 �빥���㷨�ļ���
/*
* @int a[MAX_NUM][MAX_NUM] ����
* @int aOrb �����Ƿ��� 0�׷� 1�ҷ�
* @DepriorityLevel &dl ���ȼ�����
*/
void LuoziAlgorithm(int a[MAX_NUM][MAX_NUM],int aOrb,DepriorityLevel &dl,POINT otherSideLastPt);
//�����ܺ���
POINT MachinePlay(int a[MAX_NUM][MAX_NUM],int aOrb,POINT otherSideLastPt);