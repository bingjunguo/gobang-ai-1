#if !defined AUTOPLAY_H
#define AUTOPLAY_H
#endif
#include "stdafx.h"
#include<time.h>
#include <math.h>
#define random(x) (rand()%x)
//防守反攻
//遍历1到19行 1-19列 斜着 寻找连续的四个、三个、两个
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
typedef struct ChessMan  //棋子连接   应该是从小到大存入
{
	POINT ptBegin;  //如上图所示的开始
	POINT ptEnd;    //如上图所示的结束
	int type;       //如上图所示的枚举类型中的一个
	//bool bVisit;    //是否被访问  现在只在2棋子循环遍历中使用
}ChessMan,*pChessMan;
typedef struct ChessManLineList
{
	list<ChessMan> fourChessManList;
	list<ChessMan> threeChessManList;
	list<ChessMan> twoChessManList;
}ChessManLineList,*pChessManLineList;

typedef struct DepriorityLevel    //优先级
{
	list<POINT> zeroLevelList;   //一步必输   一步必赢   
	list<POINT> oneLevelList;    //一步稳输   一步稳赢
	list<POINT> twoLevelList;    //两部会输   两部会赢
};
//先找一找4个棋子的
/*
   @ int a[MAX_NUM][MAX_NUM] 传入的棋盘数据 1-19
   @ int chessManNum   查询连续棋子的数量
   @ int aOrb    白棋还是黑棋  0为白棋 1为黑棋
*/
void FindChessManLineShu(int a[MAX_NUM][MAX_NUM],list<ChessMan> &chessManList,int chessManNum,int aOrb);
void FindChessManLineHeng(int a[MAX_NUM][MAX_NUM],list<ChessMan> &chessManList,int chessManNum,int aOrb);
void FindChessManLineXieLeft(int a[MAX_NUM][MAX_NUM],list<ChessMan> &chessManList,int chessManNum,int aOrb);
void FindChessManLineXieRight(int a[MAX_NUM][MAX_NUM],list<ChessMan> &chessManList,int chessManNum,int aOrb);

//开始处理棋子 并分配优先级
void ManageSeriesFourLine(int a[MAX_NUM][MAX_NUM],list<ChessMan> chessManList,DepriorityLevel &dl,int aOrb);
void ManageSeriesThreeLine(int a[MAX_NUM][MAX_NUM],list<ChessMan> chessManList,DepriorityLevel &dl,int aOrb);
void ManageSeriesTwoLine(int a[MAX_NUM][MAX_NUM],list<ChessMan> chessManList,DepriorityLevel &dl,int aOrb);
//     x
//    x x
//     x
//处理上面这种情况
// @ POINT pt 中间那个点
// @int a[MAX_NUM][MAX_NUM] 棋盘数据
bool FindFourChessManMidKONG(int a[MAX_NUM][MAX_NUM],POINT pt,int aOrb);
void ManageSeriesOneChessMan(int a[MAX_NUM][MAX_NUM],POINT otherSideLastPt,DepriorityLevel &dl,int aOrb);
//处理两个棋子连线 和 三个棋子连线  2 2 、2 3 、 之间的情况
// o** 比如说这种情况
//  *
//   *
void ManageSeriesTwoThreeLine(int a[MAX_NUM][MAX_NUM],list<ChessMan> chessManTwoList,
							  list<ChessMan> chessManThreeList,DepriorityLevel &dl,int aOrb);
//    x
// xxx
//    x   寻找类似于这样的.
bool FindTheInterSectPoint(int a[MAX_NUM][MAX_NUM],POINT ptOneSide,POINT &rtPt,int lineType,int aOrb);
//下面这个函数是为了发现 两活 两冲 或者 三活 三冲 或者 四活 四冲   不过这里没有用到过寻找四活
void FindLineListLive(int a[MAX_NUM][MAX_NUM],list<ChessMan> chessManList,ChessMan *chm,int &intChessManNum);
//发现一条线段是否是活的 
// ret -1 左不空  1由不空 0 两边空 -2两边不空
int FindLineLive(int a[MAX_NUM][MAX_NUM],ChessMan chm);
//求两条 y=kx+b的线的交点 有的话返回 true 数据存在引用Point上

//传入来的基本上都是不靠墙的
bool TwoLineInterSect(ChessMan &chm1,ChessMan &chm2,POINT &pt);


//防御算法 与攻击算法的集成
/*
* @int a[MAX_NUM][MAX_NUM] 棋盘
* @int aOrb 分析那方子 0甲方 1乙方
* @DepriorityLevel &dl 优先级返回
*/
void LuoziAlgorithm(int a[MAX_NUM][MAX_NUM],int aOrb,DepriorityLevel &dl,POINT otherSideLastPt);
//下棋总函数
POINT MachinePlay(int a[MAX_NUM][MAX_NUM],int aOrb,POINT otherSideLastPt);