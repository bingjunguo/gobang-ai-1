#include "stdafx.h"

#include "AutoPlay.h"


//先找一找4个棋子的
/*
   @ int a[MAX_NUM][MAX_NUM] 传入的棋盘数据 1-19
   @ int chessManNum   查询连续棋子的数量
   @ int aOrb    白棋还是黑棋  0为白棋 1为黑棋
*/
void FindChessManLineHeng(int a[MAX_NUM][MAX_NUM],list<ChessMan> &ChessManList,int chessManNum,int aOrb)
{
	ChessMan chm;
	for(int i = 1;i < MAX_NUM;i++)    
	{
		int serialChessManNum = 0;  //连续的棋子数量
		for(int j = 1;j <= MAX_NUM;j++) 
		{  
			if(a[j][i] == aOrb && j != MAX_NUM)
			{	
				serialChessManNum++;
				continue;
			}
			else
			{
				if(serialChessManNum == chessManNum)
				{
					chm.ptBegin.x = j - chessManNum;
					chm.ptBegin.y = i;
					chm.ptEnd.x = j - 1;
					chm.ptEnd.y = i;
					chm.type = CHESSMAN_HENG;
					ChessManList.push_back(chm);
					
				}
				serialChessManNum = 0;
			}
		}
	}
}
void FindChessManLineShu(int a[MAX_NUM][MAX_NUM],list<ChessMan> &ChessManList,int chessManNum,int aOrb)
{
	ChessMan chm;
	for(int i = 1;i < MAX_NUM;i++)    //列
	{
		int serialChessManNum = 0;  //连续的棋子数量
		for(int j = 1;j <= MAX_NUM;j++) 
		{  
			if(a[i][j] == aOrb && j != MAX_NUM)
			{	
				serialChessManNum++;
				continue;
			}
			else
			{
				if(serialChessManNum == chessManNum)
				{
					chm.ptBegin.x = i;
					chm.ptBegin.y = j - chessManNum;
					chm.ptEnd.x = i;
					chm.ptEnd.y = j - 1;
					chm.type = CHESSMAN_SHU;
					ChessManList.push_back(chm);
					
				}
				serialChessManNum = 0;
			}
		}
	}
}
void FindChessManLineXieLeft(int a[MAX_NUM][MAX_NUM],list<ChessMan> &ChessManList,int chessManNum,int aOrb)
{
	ChessMan chm;
	//////下面是从X开始的 x++
	for(int i = 1;i < MAX_NUM - 4;i++)     //这里之所以不 <= 的原因是 左斜16只有4个。不可能五子连珠
	{
		int serialChessManNum = 0;  //连续的棋子数量
		int x,y;
		for(x = i,y = 1;x <= MAX_NUM ;x++,y++) 
		{  
			if(a[x][y] == aOrb && x != MAX_NUM)
			{	
				serialChessManNum++;
				continue;
			}
			else
			{
				if(serialChessManNum == chessManNum)
				{
					chm.ptBegin.x = x - chessManNum;
					chm.ptBegin.y = y - chessManNum;
					chm.ptEnd.x = x - 1;
					chm.ptEnd.y = y - 1;
					chm.type = CHESSMAN_XIE_LEFT;
					ChessManList.push_back(chm);
					
				}
				serialChessManNum = 0;
			}
		}
	}
	//  \ 的下面
	for(int i = 2;i < MAX_NUM - 4;i++)     //这里之所以不 <= 的原因是 左斜16只有4个。不可能五子连珠
	{
		int serialChessManNum = 0;  //连续的棋子数量
		int x,y;
		for(y = i,x = 1;y <= MAX_NUM ;x++,y++) 
		{  
			if(a[x][y] == aOrb && x != MAX_NUM)
			{	
				serialChessManNum++;
				continue;
			}
			else
			{
				if(serialChessManNum == chessManNum)
				{
					chm.ptBegin.x = x - chessManNum;
					chm.ptBegin.y = y - chessManNum;
					chm.ptEnd.x = x - 1;
					chm.ptEnd.y = y - 1;
					chm.type = CHESSMAN_XIE_LEFT;
					ChessManList.push_back(chm);
					
				}
				serialChessManNum = 0;
			}
		}
	}
}
void FindChessManLineXieRight(int a[MAX_NUM][MAX_NUM],list<ChessMan> &ChessManList,int chessManNum,int aOrb)
{
	ChessMan chm;
	//////下面是从X开始的 x--
	for(int i = MAX_NUM - 1;i > 4;i--)   
	{
		int serialChessManNum = 0;  //连续的棋子数量
		int x,y;
		for(x = i,y = 1;x >= 0 ;x--,y++) 
		{  
			if(a[x][y] == aOrb && x != 0)
			{	
				serialChessManNum++;
				continue;
			}
			else
			{
				if(serialChessManNum == chessManNum)
				{
					chm.ptBegin.x = x + chessManNum;
					chm.ptBegin.y = y - chessManNum;
					chm.ptEnd.x = x + 1;
					chm.ptEnd.y = y - 1;
					chm.type = CHESSMAN_XIE_RIGHT;
					ChessManList.push_back(chm);
					
				}
				serialChessManNum = 0;
			}
		}
	}
	//  /的下面
	//y++
	for(int i = 2;i < MAX_NUM - 4;i++)     //这里之所以不 <= 的原因是 左斜16只有4个。不可能五子连珠
	{
		int serialChessManNum = 0;  //连续的棋子数量
		int x,y;
		for(y = i,x = MAX_NUM - 1;y <= MAX_NUM ;x--,y++) 
		{  
			if(a[x][y] == aOrb && x != MAX_NUM)
			{	
				serialChessManNum++;
				continue;
			}
			else
			{
				if(serialChessManNum == chessManNum)
				{
					chm.ptBegin.x = x + chessManNum;
					chm.ptBegin.y = y - chessManNum;
					chm.ptEnd.x = x + 1;
					chm.ptEnd.y = y - 1;
					chm.type = CHESSMAN_XIE_RIGHT;
					ChessManList.push_back(chm);
					
				}
				serialChessManNum = 0;
			}
		}
	}
}


void ManageSeriesFourLine(int a[MAX_NUM][MAX_NUM],list<ChessMan> chessManList,DepriorityLevel &dl,int aOrb)
{
	ChessMan cm;
	POINT ptTmp;
	int myChess = (aOrb - 1) * (aOrb - 1);    //甲-1的平方是乙   乙减一的平方是甲  
	while(chessManList.size() > 0)
	{
		cm = chessManList.front();
		chessManList.pop_front();
		switch (cm.type)
		{
		case CHESSMAN_HENG:  
			// case  _ xxxx*   * 可以是墙也可以是 棋子
			if(cm.ptBegin.x != 1 && a[cm.ptBegin.x - 1][cm.ptBegin.y] == KONG &&
				((a[cm.ptEnd.x + 1][cm.ptEnd.y] == myChess && cm.ptEnd.x != MAX_NUM -1) 
				   ||cm.ptEnd.x == MAX_NUM -1))
			{
				ptTmp.x = cm.ptBegin.x -1;
				ptTmp.y = cm.ptBegin.y;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//case  *xxxx_
			else if(cm.ptEnd.x != MAX_NUM -1 && a[cm.ptEnd.x + 1][cm.ptEnd.y] == KONG &&
				((a[cm.ptBegin.x - 1][cm.ptBegin.y] == myChess && cm.ptBegin.x != 1)
				|| cm.ptBegin.x == 1))
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//case  _xxxx_   其实这基本上就完蛋了， 但是万一他看不到呢，
			else if(a[cm.ptBegin.x - 1][cm.ptBegin.y] == KONG && 
				a[cm.ptEnd.x + 1][cm.ptEnd.y] == KONG)
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y;
				dl.zeroLevelList.push_front(ptTmp);
			}
			break;
		case CHESSMAN_SHU:
			//case  竖着的  _ xxxx*
			if(cm.ptBegin.y != 1 && a[cm.ptBegin.x][cm.ptBegin.y - 1] == KONG &&
				((a[cm.ptEnd.x][cm.ptEnd.y + 1] == myChess && cm.ptEnd.y != MAX_NUM -1) 
				   ||cm.ptEnd.y == MAX_NUM -1))
			{
				ptTmp.x = cm.ptBegin.x;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//case 竖着的 *xxxx_
			else if(cm.ptEnd.y != MAX_NUM -1 && a[cm.ptEnd.x][cm.ptEnd.y + 1] == KONG &&
				((a[cm.ptBegin.x][cm.ptBegin.y - 1] == myChess && cm.ptBegin.y != 1)
				|| cm.ptBegin.y == 1))
			{
				ptTmp.x = cm.ptEnd.x;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//case 竖着的 _xxxx_   其实这基本上就完蛋了， 但是万一他看不到呢，
			else if(a[cm.ptBegin.x][cm.ptBegin.y - 1] == KONG && 
				a[cm.ptEnd.x][cm.ptEnd.y + 1] == KONG)
			{
				ptTmp.x = cm.ptEnd.x;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
		    break;
		case CHESSMAN_XIE_LEFT:
			//case  左斜着  _ xxxx*
			if(cm.ptBegin.y != 1 && cm.ptBegin.x != 1 && a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == KONG &&
			  ((a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] == myChess && cm.ptEnd.x != MAX_NUM -1 && cm.ptEnd.y != MAX_NUM -1) 
			   ||(cm.ptEnd.x == MAX_NUM -1 || cm.ptEnd.y == MAX_NUM -1)))
			{
				ptTmp.x = cm.ptBegin.x - 1;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//case 左斜着 *xxxx_
			else if(cm.ptEnd.x != MAX_NUM -1 && cm.ptEnd.y != MAX_NUM -1 && a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] == KONG &&
				((a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == myChess && cm.ptBegin.x != 1 &&cm.ptBegin.y != 1)
				|| (cm.ptBegin.x == 1 || cm.ptBegin.y == 1)))
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//case 左斜着 _xxxx_   其实这基本上就完蛋了， 但是万一他看不到呢，
			else if(a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == KONG && 
				a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] == KONG)
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
		    break;
		case CHESSMAN_XIE_RIGHT:
			//case  右斜着  _ xxxx*
			if(cm.ptBegin.x != MAX_NUM - 1 && cm.ptBegin.y != 1 && a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == KONG &&
			  ((a[cm.ptEnd.x - 1][cm.ptEnd.y + 1] == myChess && cm.ptEnd.x != 1 && cm.ptEnd.y != MAX_NUM -1) 
			   ||(cm.ptEnd.x == 1 && cm.ptEnd.y || MAX_NUM -1)))
			{
				ptTmp.x = cm.ptBegin.x + 1;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//case 右斜着 *xxxx_
			else if(cm.ptEnd.x != 1 && cm.ptEnd.y != MAX_NUM -1 && a[cm.ptEnd.x - 1][cm.ptEnd.y + 1] == KONG &&
				((a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == myChess && cm.ptBegin.x != MAX_NUM - 1 && cm.ptBegin.y != 1)
				|| (cm.ptBegin.x == MAX_NUM - 1 || cm.ptBegin.y == 1)))
			{
				ptTmp.x = cm.ptEnd.x - 1;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//case 右斜着 _xxxx_   其实这基本上就完蛋了， 但是万一他看不到呢，
			else if(a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == KONG && 
				a[cm.ptEnd.x - 1][cm.ptEnd.y + 1] == KONG)
			{
				ptTmp.x = cm.ptEnd.x - 1;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
		    break;
		default: 
			break;
		}
	}
}

void ManageSeriesThreeLine(int a[MAX_NUM][MAX_NUM],list<ChessMan> chessManList,DepriorityLevel &dl,int aOrb)
{
	ChessMan cm;
	POINT ptTmp;
	int myChess = (aOrb - 1) * (aOrb - 1);    //甲减一的平方是乙   乙减一的平方是甲  
	while(chessManList.size() > 0)
	{
		cm = chessManList.front();
		chessManList.pop_front();
		switch (cm.type)
		{
		case CHESSMAN_HENG: 
			//这里只能用两个if 因为这两种都有可能发生
			//一步必输  xxx_x   x_xxx
			if(cm.ptEnd.x + 2 < MAX_NUM && a[cm.ptEnd.x + 2][cm.ptEnd.y] == aOrb // xxx_x
				&& a[cm.ptEnd.x + 1][cm.ptEnd.y] == KONG )
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y;
				dl.zeroLevelList.push_front(ptTmp);
			}
			if(cm.ptBegin.x - 2 > 0 && a[cm.ptBegin.x - 2][cm.ptBegin.y] == aOrb // xxx_x
				&& a[cm.ptBegin.x - 1][cm.ptBegin.y] == KONG)
			{
				ptTmp.x = cm.ptBegin.x - 1;
				ptTmp.y = cm.ptBegin.y;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//下面就是三选一咯 *xxx_  -xxx*   _xxx_
			//case  -xxx*  2步会输
			if(cm.ptBegin.x != 1 && a[cm.ptBegin.x - 1][cm.ptBegin.y] == KONG &&
				((a[cm.ptEnd.x + 1][cm.ptEnd.y] == myChess && cm.ptEnd.x != MAX_NUM -1) 
				   ||cm.ptEnd.x == MAX_NUM -1))
			{
				ptTmp.x = cm.ptBegin.x -1;
				ptTmp.y = cm.ptBegin.y;
				dl.twoLevelList.push_front(ptTmp);
			}
			//case  *xxx_ 2步会输
			else if(cm.ptEnd.x != MAX_NUM -1 && a[cm.ptEnd.x + 1][cm.ptEnd.y] == KONG &&
				((a[cm.ptBegin.x - 1][cm.ptBegin.y] == myChess && cm.ptBegin.x != 1)
				|| cm.ptBegin.x == 1))
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y;
				dl.twoLevelList.push_front(ptTmp);
			}
			//case  _xxx_  一步稳输
			else if(a[cm.ptBegin.x - 1][cm.ptBegin.y] == KONG && 
				a[cm.ptEnd.x + 1][cm.ptEnd.y] == KONG)
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y;
				dl.oneLevelList.push_front(ptTmp);
			}
			break;
		case CHESSMAN_SHU: 
			//这里只能用两个if 因为这两种都有可能发生
			//一步必输  xxx_x   x_xxx
			if(cm.ptEnd.y + 2 < MAX_NUM && a[cm.ptEnd.x][cm.ptEnd.y + 2] == aOrb // xxx_x
				&& a[cm.ptEnd.x][cm.ptEnd.y + 1] == KONG )
			{
				ptTmp.x = cm.ptEnd.x;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			if(cm.ptBegin.y - 2 > 0 && a[cm.ptBegin.x][cm.ptBegin.y - 2] == aOrb // xxx_x
				&& a[cm.ptBegin.x][cm.ptBegin.y - 1] == KONG)
			{
				ptTmp.x = cm.ptBegin.x;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//下面就是三选一咯 *xxx_  -xxx*   _xxx_
			//case  竖着的 -xxx*  2步会输
			if(cm.ptBegin.y != 1 && a[cm.ptBegin.x][cm.ptBegin.y - 1] == KONG &&
				((a[cm.ptEnd.x][cm.ptEnd.y + 1] == myChess && cm.ptEnd.y != MAX_NUM -1) 
				   ||cm.ptEnd.y == MAX_NUM -1))
			{
				ptTmp.x = cm.ptBegin.x;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.twoLevelList.push_front(ptTmp);
			}
			//case 竖着的 *xxx_ 2步会输
			else if(cm.ptEnd.y != MAX_NUM -1 && a[cm.ptEnd.x][cm.ptEnd.y + 1] == KONG &&
				((a[cm.ptBegin.x][cm.ptBegin.y - 1] == myChess && cm.ptBegin.y != 1)
				|| cm.ptBegin.y == 1))
			{
				ptTmp.x = cm.ptEnd.x;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.twoLevelList.push_front(ptTmp);
			}
			//case 竖着的 _xxx_  一步稳输
			else if(a[cm.ptBegin.x][cm.ptBegin.y - 1] == KONG && 
				a[cm.ptEnd.x][cm.ptEnd.y + 1] == KONG)
			{
				ptTmp.x = cm.ptEnd.x;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.oneLevelList.push_front(ptTmp);
			}
		    break;
		case CHESSMAN_XIE_LEFT: 
			//这里只能用两个if 因为这两种都有可能发生
			//一步必输  xxx_x   x_xxx
			if(cm.ptEnd.x + 2 < MAX_NUM && cm.ptEnd.x + 2 < MAX_NUM &&          // xxx_x
				a[cm.ptEnd.x + 2][cm.ptEnd.y + 2] == aOrb                  
				&& a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] == KONG )
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			if(cm.ptBegin.x - 2 > 0 && cm.ptBegin.y - 2 > 0 &&                // xxx_x
				a[cm.ptBegin.x - 2][cm.ptBegin.y - 2] == aOrb
				&& a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == KONG)
			{
				ptTmp.x = cm.ptBegin.x - 1;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//下面就是三选一咯 *xxx_  -xxx*   _xxx_ 
			//case  左斜着 -xxx*  2步会输
			if(cm.ptBegin.y != 1 && cm.ptBegin.x != 1 && a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == KONG &&
			  ((a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] == myChess && cm.ptEnd.x != MAX_NUM -1 && cm.ptEnd.y != MAX_NUM -1) 
			   ||(cm.ptEnd.x == MAX_NUM -1 || cm.ptEnd.y == MAX_NUM -1)))
			{
				ptTmp.x = cm.ptBegin.x - 1;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.twoLevelList.push_front(ptTmp);
			}
			//case 左斜着 *xxx_ 2步会输
			else if(cm.ptEnd.x != MAX_NUM -1 && cm.ptEnd.y != MAX_NUM -1 && a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] == KONG &&
				((a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == myChess && cm.ptBegin.x != 1 &&cm.ptBegin.y != 1)
				|| (cm.ptBegin.x == 1 || cm.ptBegin.y == 1)))
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.twoLevelList.push_front(ptTmp);
			}
			//case 左斜着 _xxx_  一步稳输
			else if(a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == KONG && 
				a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] == KONG)
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.oneLevelList.push_front(ptTmp);
			}
			break;
		case CHESSMAN_XIE_RIGHT: 
			//这里只能用两个if 因为这两种都有可能发生
			//一步必输 右斜 xxx_x   x_xxx
			if(cm.ptEnd.x - 2 > 0 && cm.ptEnd.x + 2 < MAX_NUM &&          // xxx_x
				a[cm.ptEnd.x - 2][cm.ptEnd.y + 2] == aOrb                  
				&& a[cm.ptEnd.x - 1][cm.ptEnd.y + 1] == KONG )
			{
				ptTmp.x = cm.ptEnd.x - 1;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			if(cm.ptBegin.x + 2 < MAX_NUM && cm.ptBegin.y - 2 > 0 &&                // xxx_x
				a[cm.ptBegin.x + 2][cm.ptBegin.y - 2] == aOrb
				&& a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == KONG)
			{
				ptTmp.x = cm.ptBegin.x + 1;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//下面就是三选一咯 *xxx_  -xxx*   _xxx_ 
			//case  右斜着  -xxx*  2步会输
			if(cm.ptBegin.x != MAX_NUM - 1 && cm.ptBegin.y != 1 && a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == KONG &&
			  ((a[cm.ptEnd.x - 1][cm.ptEnd.y + 1] == myChess && cm.ptEnd.x != 1 && cm.ptEnd.y != MAX_NUM -1) 
			   ||(cm.ptEnd.x == 1 && cm.ptEnd.y == MAX_NUM -1)))
			{
				ptTmp.x = cm.ptBegin.x + 1;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.twoLevelList.push_front(ptTmp);
			}
			//case 右斜着 *xxx_ 2步会输
			else if(cm.ptEnd.x != 1 && cm.ptEnd.y != MAX_NUM -1 && a[cm.ptEnd.x - 1][cm.ptEnd.y + 1] == KONG &&
				((a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == myChess && cm.ptBegin.x != MAX_NUM - 1 && cm.ptBegin.y != 1)
				|| (cm.ptBegin.x == MAX_NUM - 1 || cm.ptBegin.y == 1)))
			{
				ptTmp.x = cm.ptEnd.x - 1;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.twoLevelList.push_front(ptTmp);
			}
			//case 右斜着 _xxx_  一步稳输
			else if(a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == KONG && 
				a[cm.ptEnd.x - 1][cm.ptEnd.y + 1] == KONG)
			{
				ptTmp.x = cm.ptEnd.x - 1;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.oneLevelList.push_front(ptTmp);
			}
			break;
		default: 
			break;
		}
	}
}

void ManageSeriesTwoLine(int a[MAX_NUM][MAX_NUM],list<ChessMan> chessManList,DepriorityLevel &dl,int aOrb)
{
	ChessMan cm;
	POINT ptTmp;
	int myChess = (aOrb - 1) * (aOrb - 1);    //甲-1的平方是乙   乙减一的平方是甲  
	while(chessManList.size() > 0)
	{
		cm = chessManList.front();
		chessManList.pop_front();
		
		switch (cm.type)
		{
		case CHESSMAN_HENG: 
			if(FindLineLive(a,cm) == 0)
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y;
				dl.twoLevelList.push_front(ptTmp);
				ptTmp.x = cm.ptBegin.x - 1;
				ptTmp.y = cm.ptBegin.y;
				dl.twoLevelList.push_front(ptTmp);
			}
			//xx_xx 特殊情况
			if(cm.ptEnd.x + 3 < MAX_NUM && a[cm.ptEnd.x + 1][cm.ptEnd.y] == KONG &&
				a[cm.ptEnd.x + 2][cm.ptEnd.y] == aOrb && 
				a[cm.ptEnd.x + 3][cm.ptEnd.y] ==aOrb)
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y;
				dl.zeroLevelList.push_front(ptTmp);
			}
			if(cm.ptBegin.x - 3 > 0 && a[cm.ptBegin.x - 1][cm.ptBegin.y] == KONG &&
				a[cm.ptBegin.x - 2][cm.ptBegin.y] == aOrb && 
				a[cm.ptBegin.x - 3][cm.ptBegin.y] ==aOrb)
			{
				ptTmp.x = cm.ptBegin.x - 1;
				ptTmp.y = cm.ptBegin.y;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//case  xx_x
			if(cm.ptEnd.x + 2 < MAX_NUM && a[cm.ptEnd.x + 1][cm.ptEnd.y] == KONG &&
				a[cm.ptEnd.x + 2][cm.ptEnd.y] == aOrb)
			{
				//两步会输
				if(((cm.ptEnd.x + 3 < MAX_NUM && a[cm.ptEnd.x + 1][cm.ptEnd.y] == myChess) ||  //右边是封闭的但是左边有一个位置
					cm.ptEnd.x + 3 == MAX_NUM)
					&& cm.ptBegin.x - 1 > 0 && a[cm.ptBegin.x - 1][cm.ptBegin.y] == KONG)        //左边有一个位置而且为空     
				{
					ptTmp.x = cm.ptEnd.x + 1;
					ptTmp.y = cm.ptEnd.y;
					dl.twoLevelList.push_front(ptTmp);
				}
				else if(((cm.ptBegin.x - 1 > 0 && a[cm.ptBegin.x - 1][cm.ptBegin.y] == myChess)||   //左边是封闭的
					cm.ptBegin.x - 1 == 0)
					&& cm.ptEnd.x + 3 < MAX_NUM && a[cm.ptEnd.x + 3][cm.ptEnd.y] == KONG)
				{
					ptTmp.x = cm.ptEnd.x + 1;
					ptTmp.y = cm.ptEnd.y;
					dl.twoLevelList.push_front(ptTmp);
				}
				else if(cm.ptBegin .x - 1 > 0 && cm.ptEnd.x + 3 < MAX_NUM &&
					a[cm.ptBegin.x][cm.ptBegin.y - 1] == KONG &&
					a[cm.ptBegin.x][cm.ptEnd.y + 3] == KONG)  
				{
					ptTmp.x = cm.ptEnd.x + 1;
					ptTmp.y = cm.ptEnd.y;
					dl.oneLevelList.push_front(ptTmp);
				}
			}
			//case x_xx
			if(cm.ptBegin.x - 2 > 0 && a[cm.ptBegin.x - 1][cm.ptBegin.y] == KONG &&
				a[cm.ptBegin.x - 2][cm.ptBegin.y] == aOrb)
			{
				//两步会输
				if(((cm.ptBegin.x - 3 > 0 && a[cm.ptBegin.x - 1][cm.ptBegin.y] == myChess) ||  //左边是封闭
					cm.ptBegin.x - 3 == 0)
					&& cm.ptEnd.x + 1 < MAX_NUM && a[cm.ptEnd.x + 1][cm.ptBegin.y] == KONG)        //右边有一个位置而且为空     
				{
					ptTmp.x = cm.ptBegin.x - 1;
					ptTmp.y = cm.ptBegin.y;
					dl.twoLevelList.push_front(ptTmp);
				}
				else if(((cm.ptEnd.x + 1 < MAX_NUM && a[cm.ptEnd.x + 1][cm.ptEnd.y] == myChess)||
					cm.ptEnd.x + 1 == MAX_NUM)
					&& cm.ptBegin.x - 3 > 0 && a[cm.ptBegin.x - 3][cm.ptBegin.y] == KONG)
				{
					ptTmp.x = cm.ptBegin.x - 1;
					ptTmp.y = cm.ptBegin.y;
					dl.twoLevelList.push_front(ptTmp);
				}
				else if(cm.ptBegin .x - 3 > 0 && cm.ptEnd.x + 1 < MAX_NUM &&
					a[cm.ptBegin.x][cm.ptBegin.y - 3] == KONG &&
					a[cm.ptBegin.x][cm.ptEnd.y + 1] == KONG) 
				{
					ptTmp.x = cm.ptBegin.x - 1;
					ptTmp.y = cm.ptBegin.y;
					dl.oneLevelList.push_front(ptTmp);
				}
			}
			break;
		case CHESSMAN_SHU: 
			if(FindLineLive(a,cm) == 0)
			{
				ptTmp.x = cm.ptEnd.x;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.twoLevelList.push_front(ptTmp);
				ptTmp.x = cm.ptBegin.x;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.twoLevelList.push_front(ptTmp);
			}
			//xx_xx 特殊情况 竖着
			if(cm.ptEnd.y + 3 < MAX_NUM && a[cm.ptEnd.x][cm.ptEnd.y + 1] == KONG &&
				a[cm.ptEnd.x][cm.ptEnd.y + 2] == aOrb && 
				a[cm.ptEnd.x][cm.ptEnd.y + 3] ==aOrb)
			{
				ptTmp.x = cm.ptEnd.x;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			if(cm.ptBegin.y - 3 > 0 && a[cm.ptBegin.x][cm.ptBegin.y - 1] == KONG &&
				a[cm.ptBegin.x][cm.ptBegin.y - 2] == aOrb && 
				a[cm.ptBegin.x][cm.ptBegin.y - 3] ==aOrb)
			{
				ptTmp.x = cm.ptBegin.x;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//case  xx_x 竖着
			if(cm.ptEnd.y + 2 < MAX_NUM && a[cm.ptEnd.x][cm.ptEnd.y + 1] == KONG &&
				a[cm.ptEnd.x][cm.ptEnd.y + 2] == aOrb)
			{
				//两步会输
				if(((cm.ptEnd.y + 3 < MAX_NUM && a[cm.ptEnd.x][cm.ptEnd.y + 1] == myChess) ||  //右边是封闭的但是左边有一个位置
					cm.ptEnd.y + 3 == MAX_NUM)
					&& cm.ptBegin.y - 1 > 0 && a[cm.ptBegin.x][cm.ptBegin.y - 1] == KONG)        //左边有一个位置而且为空     
				{
					ptTmp.x = cm.ptEnd.x;
					ptTmp.y = cm.ptEnd.y + 1;
					dl.twoLevelList.push_front(ptTmp);
				}
				else if(((cm.ptBegin.y - 1 > 0 && a[cm.ptBegin.x][cm.ptBegin.y - 1] == myChess)||   //左边是封闭的
					cm.ptBegin.y - 1 == 0)
					&& cm.ptEnd.y + 3 < MAX_NUM && a[cm.ptEnd.x][cm.ptEnd.y + 3] == KONG)
				{
					ptTmp.x = cm.ptEnd.x;
					ptTmp.y = cm.ptEnd.y + 1;
					dl.twoLevelList.push_front(ptTmp);
				}
				else  if(cm.ptBegin .y - 1 > 0 && cm.ptEnd .y + 3 < MAX_NUM &&
					a[cm.ptBegin.x][cm.ptBegin.y - 1] == KONG &&
					a[cm.ptBegin.x][cm.ptEnd.y + 3] == KONG)
				{
					ptTmp.x = cm.ptEnd.x;
					ptTmp.y = cm.ptEnd.y + 1;
					dl.oneLevelList.push_front(ptTmp);
				}
			}
			//case x_xx 竖着
			if(cm.ptBegin.y - 2 > 0 && a[cm.ptBegin.x][cm.ptBegin.y - 1] == KONG &&
				a[cm.ptBegin.x][cm.ptBegin.y - 2] == aOrb)
			{
				//两步会输
				if(((cm.ptBegin.y - 3 > 0 && a[cm.ptBegin.x][cm.ptBegin.y - 1] == myChess) ||  //左边是封闭
					cm.ptBegin.y - 3 == 0)
					&& cm.ptEnd.y + 1 < MAX_NUM && a[cm.ptEnd.x][cm.ptBegin.y + 1] == KONG)        //右边有一个位置而且为空     
				{
					ptTmp.x = cm.ptBegin.x;
					ptTmp.y = cm.ptBegin.y - 1;
					dl.twoLevelList.push_front(ptTmp);
				}
				else if(((cm.ptEnd.y + 1 < MAX_NUM && a[cm.ptEnd.x][cm.ptEnd.y + 1] == myChess)||
					cm.ptEnd.y + 1 == MAX_NUM)
					&& cm.ptBegin.y - 3 > 0 && a[cm.ptBegin.x][cm.ptBegin.y - 3] == KONG)
				{
					ptTmp.x = cm.ptBegin.x;
					ptTmp.y = cm.ptBegin.y - 1;
					dl.twoLevelList.push_front(ptTmp);
				}
				else  if(cm.ptBegin .y - 3 > 0 && cm.ptEnd .y + 1 < MAX_NUM &&
					a[cm.ptBegin.x][cm.ptBegin.y - 3] == KONG &&
					a[cm.ptBegin.x][cm.ptEnd.y + 1] == KONG)
				{
					ptTmp.x = cm.ptBegin.x;
					ptTmp.y = cm.ptBegin.y - 1;
					dl.oneLevelList.push_front(ptTmp);
				}
			}
		    break;
		case CHESSMAN_XIE_LEFT: 
			if(FindLineLive(a,cm) == 0)
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.twoLevelList.push_front(ptTmp);
				ptTmp.x = cm.ptBegin.x - 1;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.twoLevelList.push_front(ptTmp);
			}
			//xx_xx 特殊情况 左斜着
			if(cm.ptEnd.x + 3 < MAX_NUM && cm.ptEnd.y + 3 < MAX_NUM &&
				a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] == KONG &&
				a[cm.ptEnd.x + 2][cm.ptEnd.y + 2] == aOrb && 
				a[cm.ptEnd.x + 3][cm.ptEnd.y + 3] ==aOrb)
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			if(cm.ptBegin.x - 3 > 0 && cm.ptBegin.y - 3 > 0 && 
				a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == KONG &&
				a[cm.ptBegin.x - 2][cm.ptBegin.y - 2] == aOrb && 
				a[cm.ptBegin.x - 3][cm.ptBegin.y - 3] ==aOrb)
			{
				ptTmp.x = cm.ptBegin.x - 1;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//case  xx_x 左斜着
			if(cm.ptEnd.x + 2 < MAX_NUM && cm.ptEnd.y + 2 < MAX_NUM && 
				a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] == KONG &&
				a[cm.ptEnd.x + 2][cm.ptEnd.y + 2] == aOrb)
			{
				//两步会输
				if(((cm.ptEnd.x + 3 < MAX_NUM && cm.ptEnd.y + 3 < MAX_NUM && 
					a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] == myChess) ||  //右边是封闭的但是左边有一个位置
					(cm.ptEnd.x + 3 == MAX_NUM && cm.ptEnd.y + 3 == MAX_NUM))
					&& cm.ptBegin.x - 1 > 0 && cm.ptBegin.y - 1 > 0 && 
					a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == KONG)        //左边有一个位置而且为空     
				{
					ptTmp.x = cm.ptEnd.x + 1;
					ptTmp.y = cm.ptEnd.y + 1;
					dl.twoLevelList.push_front(ptTmp);
				}
				else if(((cm.ptBegin.x - 1 > 0 && cm.ptBegin.y - 1 > 0 && 
					a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == myChess)||   //左边是封闭的
					(cm.ptBegin.x - 1 == 0 && cm.ptBegin.y - 1 == 0))&&
					cm.ptEnd.x + 3 < MAX_NUM && cm.ptEnd.y + 3 < MAX_NUM && 
					a[cm.ptEnd.x + 3][cm.ptEnd.y + 3] == KONG)
				{
					ptTmp.x = cm.ptEnd.x + 1;
					ptTmp.y = cm.ptEnd.y + 1;
					dl.twoLevelList.push_front(ptTmp);
				}
				else if(cm.ptBegin.x - 1 > 0 && cm.ptBegin.y - 1> 0 && 
					a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == KONG &&
					cm.ptEnd.x + 3 < MAX_NUM && cm.ptEnd.y + 3 < MAX_NUM
					&& a[cm.ptEnd.x + 3][cm.ptEnd.y + 3] == KONG)  
				{
					ptTmp.x = cm.ptEnd.x + 1;
					ptTmp.y = cm.ptEnd.y + 1;
					dl.oneLevelList.push_front(ptTmp);
				}
			}
			//case x_xx 左斜着
			if(cm.ptBegin.x - 2 > 0 && cm.ptBegin.y - 2 > 0 && 
				a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == KONG &&
				a[cm.ptBegin.x - 2][cm.ptBegin.y - 2] == aOrb)
			{
				//两步会输
				if(((cm.ptBegin.x - 3 > 0 && cm.ptBegin.y - 3 > 0 && 
					a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == myChess) ||  //左边是封闭
					(cm.ptBegin.x - 3 == 0 && cm.ptBegin.y - 3 == 0)) && 
					cm.ptEnd.x + 1 < MAX_NUM && cm.ptEnd.y + 1 < MAX_NUM && 
					a[cm.ptEnd.x + 1][cm.ptBegin.y + 1] == KONG)        //右边有一个位置而且为空     
				{
					ptTmp.x = cm.ptBegin.x - 1;
					ptTmp.y = cm.ptBegin.y - 1;
					dl.twoLevelList.push_front(ptTmp);
				}
				else if(((cm.ptEnd.x + 1 < MAX_NUM && cm.ptEnd.y + 1 < MAX_NUM && 
					a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] == myChess)||
					(cm.ptEnd.x + 1 == MAX_NUM && cm.ptEnd.y + 1 == MAX_NUM)) && 
					cm.ptBegin.x - 3 > 0 && cm.ptBegin.y - 3 > 0 && 
					a[cm.ptBegin.x - 3][cm.ptBegin.y - 3] == KONG)
				{
					ptTmp.x = cm.ptBegin.x - 1;
					ptTmp.y = cm.ptBegin.y - 1;
					dl.twoLevelList.push_front(ptTmp);
				}
				else if(cm.ptBegin.x - 3 > 0 && cm.ptBegin.y - 3 > 0 && 
					a[cm.ptBegin.x -3][cm.ptBegin.y -3] == KONG &&
					cm.ptEnd.x + 1 < MAX_NUM && cm.ptEnd.y + 1 < MAX_NUM
					&& a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] == KONG)
				{
					ptTmp.x = cm.ptBegin.x - 1;
					ptTmp.y = cm.ptBegin.y - 1;
					dl.oneLevelList.push_front(ptTmp);
				}
			}
			break;
		case CHESSMAN_XIE_RIGHT: 
			if(FindLineLive(a,cm) == 0)
			{
				ptTmp.x = cm.ptEnd.x - 1;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.twoLevelList.push_front(ptTmp);
				ptTmp.x = cm.ptBegin.x + 1;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.twoLevelList.push_front(ptTmp);
			}
			//xx_xx 特殊情况 右斜着
			if(cm.ptEnd.x - 3 < MAX_NUM && cm.ptEnd.y + 3 < MAX_NUM &&
				a[cm.ptEnd.x - 1][cm.ptEnd.y + 1] == KONG &&
				a[cm.ptEnd.x - 2][cm.ptEnd.y + 2] == aOrb && 
				a[cm.ptEnd.x - 3][cm.ptEnd.y + 3] ==aOrb)
			{
				ptTmp.x = cm.ptEnd.x - 1;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			if(cm.ptBegin.x + 3 > 0 && cm.ptBegin.y - 3 > 0 && 
				a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == KONG &&
				a[cm.ptBegin.x + 2][cm.ptBegin.y - 2] == aOrb && 
				a[cm.ptBegin.x + 3][cm.ptBegin.y - 3] ==aOrb)
			{
				ptTmp.x = cm.ptBegin.x + 1;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//case  xx_x 右斜着
			if(cm.ptEnd.x - 2 < MAX_NUM && cm.ptEnd.y + 2 < MAX_NUM && 
				a[cm.ptEnd.x - 1][cm.ptEnd.y + 1] == KONG &&
				a[cm.ptEnd.x - 2][cm.ptEnd.y + 2] == aOrb)
			{
				//两步会输
				if(((cm.ptEnd.x - 3 < MAX_NUM && cm.ptEnd.y + 3 < MAX_NUM && 
					a[cm.ptEnd.x - 1][cm.ptEnd.y + 1] == myChess) ||  //右边是封闭的但是左边有一个位置
					(cm.ptEnd.x - 3 == MAX_NUM && cm.ptEnd.y + 3 == MAX_NUM))
					&& cm.ptBegin.x + 1 > 0 && cm.ptBegin.y - 1 > 0 && 
					a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == KONG)        //左边有一个位置而且为空     
				{
					ptTmp.x = cm.ptEnd.x - 1;
					ptTmp.y = cm.ptEnd.y + 1;
					dl.twoLevelList.push_front(ptTmp);
				}
				else if(((cm.ptBegin.x + 1 > 0 && cm.ptBegin.y - 1 > 0 && 
					a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == myChess)||   //左边是封闭的
					(cm.ptBegin.x + 1 == 0 && cm.ptBegin.y - 1 == 0))&&
					cm.ptEnd.x - 3 < MAX_NUM && cm.ptEnd.y + 3 < MAX_NUM && 
					a[cm.ptEnd.x - 3][cm.ptEnd.y + 3] == KONG)
				{
					ptTmp.x = cm.ptEnd.x - 1;
					ptTmp.y = cm.ptEnd.y + 1;
					dl.twoLevelList.push_front(ptTmp);
				}
				else if(cm.ptBegin.x + 1 < MAX_NUM && cm.ptBegin.y - 1> 0 && 
					a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == KONG &&
					cm.ptEnd.x - 3 > 0 && cm.ptEnd.y + 3 < MAX_NUM
					&& a[cm.ptEnd.x - 3][cm.ptEnd.y + 3] == KONG) 
				{
					ptTmp.x = cm.ptEnd.x - 1;
					ptTmp.y = cm.ptEnd.y + 1;
					dl.oneLevelList.push_front(ptTmp);
				}
			}
			//case x_xx 右斜着
			if(cm.ptBegin.x + 2 > 0 && cm.ptBegin.y - 2 > 0 && 
				a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == KONG &&
				a[cm.ptBegin.x + 2][cm.ptBegin.y - 2] == aOrb)
			{
				//两步会输
				if(((cm.ptBegin.x + 3 > 0 && cm.ptBegin.y - 3 > 0 && 
					a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == myChess) ||  //左边是封闭
					(cm.ptBegin.x + 3 == 0 && cm.ptBegin.y - 3 == 0)) && 
					cm.ptEnd.x - 1 < MAX_NUM && cm.ptEnd.y + 1 < MAX_NUM && 
					a[cm.ptEnd.x - 1][cm.ptBegin.y + 1] == KONG)        //右边有一个位置而且为空     
				{
					ptTmp.x = cm.ptBegin.x + 1;
					ptTmp.y = cm.ptBegin.y - 1;
					dl.twoLevelList.push_front(ptTmp);
				}
				else if(((cm.ptEnd.x - 1 < MAX_NUM && cm.ptEnd.y + 1 < MAX_NUM && 
					a[cm.ptEnd.x - 1][cm.ptEnd.y + 1] == myChess)||
					(cm.ptEnd.x - 1 == MAX_NUM && cm.ptEnd.y + 1 == MAX_NUM)) && 
					cm.ptBegin.x + 3 > 0 && cm.ptBegin.y - 3 > 0 && 
					a[cm.ptBegin.x + 3][cm.ptBegin.y - 3] == KONG)
				{
					ptTmp.x = cm.ptBegin.x + 1;
					ptTmp.y = cm.ptBegin.y - 1;
					dl.twoLevelList.push_front(ptTmp);
				}
				else if(cm.ptBegin.x + 3 < MAX_NUM && cm.ptBegin.y - 3 > 0 && 
					a[cm.ptBegin.x + 3][cm.ptBegin.y -3] == KONG &&
					cm.ptEnd.x - 1 > 0 && cm.ptEnd.y + 1 < MAX_NUM
					&& a[cm.ptEnd.x - 1][cm.ptEnd.y + 1] == KONG) 
				{
					ptTmp.x = cm.ptBegin.x + 1;
					ptTmp.y = cm.ptBegin.y - 1;
					dl.oneLevelList.push_front(ptTmp);
				}
			}
			break;
		default: 
			break;
		}
		
	}
}

bool FindFourChessManMidKONG(int a[MAX_NUM][MAX_NUM],POINT pt,int aOrb)
{
	if(a[pt.x][pt.y] != KONG)
		return false;
	if(pt.x + 2 >= MAX_NUM  || pt.x - 2 <= 0 ||pt.y + 2 >= MAX_NUM || pt.y - 2 <= 0)
		return false;
	/*if(a[pt.x + 1][pt.y] == aOrb && a[pt.x - 1][pt.y] == aOrb &&
		a[pt.x][pt.y + 1] == aOrb && a[pt.x][pt.y - 1] == aOrb &&
		a[pt.x + 2][pt.y] == KONG && a[pt.x - 2][pt.y] == KONG &&
		a[pt.x][pt.y + 2] == KONG && a[pt.x][pt.y - 2] == KONG )
		return true;*/
	if(/*a[pt.x + 1][pt.y] == aOrb &&*/ a[pt.x - 1][pt.y] == aOrb &&
		a[pt.x][pt.y + 1] == aOrb && a[pt.x][pt.y - 1] == aOrb &&
		/*a[pt.x + 2][pt.y] == KONG && */a[pt.x - 2][pt.y] == KONG &&
		a[pt.x][pt.y + 2] == KONG && a[pt.x][pt.y - 2] == KONG )
		return true;
	else if(a[pt.x + 1][pt.y] == aOrb && /*a[pt.x - 1][pt.y] == aOrb &&*/
		a[pt.x][pt.y + 1] == aOrb && a[pt.x][pt.y - 1] == aOrb &&
		a[pt.x + 2][pt.y] == KONG && /*a[pt.x - 2][pt.y] == KONG &&*/
		a[pt.x][pt.y + 2] == KONG && a[pt.x][pt.y - 2] == KONG )
		return true;
	else if(a[pt.x + 1][pt.y] == aOrb && a[pt.x - 1][pt.y] == aOrb &&
		/*a[pt.x][pt.y + 1] == aOrb &&*/ a[pt.x][pt.y - 1] == aOrb &&
		a[pt.x + 2][pt.y] == KONG && a[pt.x - 2][pt.y] == KONG &&
		/*a[pt.x][pt.y + 2] == KONG &&*/ a[pt.x][pt.y - 2] == KONG )
		return true;
	else if(a[pt.x + 1][pt.y] == aOrb && a[pt.x - 1][pt.y] == aOrb &&
		a[pt.x][pt.y + 1] == aOrb && /*a[pt.x][pt.y - 1] == aOrb &&*/
		a[pt.x + 2][pt.y] == KONG && a[pt.x - 2][pt.y] == KONG &&
		a[pt.x][pt.y + 2] == KONG/* && a[pt.x][pt.y - 2] == KONG*/ )
		return true;
	return false;
} 
void ManageSeriesOneChessMan(int a[MAX_NUM][MAX_NUM],POINT otherSideLastPt,DepriorityLevel &dl,int aOrb)
{
	//判断 下
	POINT pt;
	pt.x = otherSideLastPt.x;
	pt.y = otherSideLastPt.y + 1;
	if(pt.y < MAX_NUM)
		if(FindFourChessManMidKONG(a,pt,aOrb))
			dl.oneLevelList.push_front(pt);
	//上
	pt.x = otherSideLastPt.x;
	pt.y = otherSideLastPt.y - 1;
	if(pt.y > 0)
		if(FindFourChessManMidKONG(a,pt,aOrb))
			dl.oneLevelList.push_front(pt);
	//右
	pt.x = otherSideLastPt.x + 1;
	pt.y = otherSideLastPt.y;
	if(pt.x < MAX_NUM)
		if(FindFourChessManMidKONG(a,pt,aOrb))
			dl.oneLevelList.push_front(pt);
	//左
	pt.x = otherSideLastPt.x - 1;
	pt.y = otherSideLastPt.y ;
	if(pt.x > 0)
		if(FindFourChessManMidKONG(a,pt,aOrb))
			dl.oneLevelList.push_front(pt);
	
}


void FindLineListLive(int a[MAX_NUM][MAX_NUM],list<ChessMan> chessManList,ChessMan *chm,int &intChessManNum)
{
	ChessMan cm;  //临时变量
	while(chessManList.size() > 0)
	{
		cm = chessManList.front();
		chessManList.pop_front();
		switch (cm.type)
		{
		case CHESSMAN_HENG:
			if((cm.ptBegin.x - 1 <= 0 && cm.ptEnd.x + 1 >= MAX_NUM) ||
				(a[cm.ptBegin.x - 1][cm.ptBegin.y] != KONG && 
				a[cm.ptEnd.x + 1][cm.ptEnd.y] != KONG))
			{
				//do nothing.
			}
			else
			    chm[intChessManNum++] = cm;
			break;
		case CHESSMAN_SHU:
			if((cm.ptBegin.y - 1 <= 0 && cm.ptEnd.y + 1 >= MAX_NUM) ||
				(a[cm.ptBegin.x][cm.ptBegin.y - 1] != KONG && 
				a[cm.ptEnd.x][cm.ptEnd.y + 1] != KONG))
			{
			       //do nothing.
			}
			else
			    chm[intChessManNum++] = cm;
			break;
		case CHESSMAN_XIE_LEFT:
			if((cm.ptBegin.x - 1 <= 0 && cm.ptEnd.x + 1 >= MAX_NUM &&
				cm.ptBegin.y - 1 <= 0 && cm.ptEnd.y + 1 >= MAX_NUM )||
				(a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] != KONG && 
				a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] != KONG))
			{
			       //do nothing.
			}
			else
			    chm[intChessManNum++] = cm;
			break;
		case CHESSMAN_XIE_RIGHT:
			if((cm.ptBegin.x + 1 >= MAX_NUM && cm.ptEnd.x - 1 <= 0   &&
				cm.ptBegin.y - 1 <= 0 && cm.ptEnd.y + 1 >= MAX_NUM )||
				(a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] != KONG && 
				a[cm.ptEnd.x - 1][cm.ptEnd.y + 1] != KONG))
			{
			       //do nothing.
			}
			else
			    chm[intChessManNum++] = cm;
			break;
		}
	}
}
bool TwoLineInterSect(ChessMan &chm1,ChessMan &chm2,POINT &pt)
{
	if((chm1.type == CHESSMAN_SHU && chm2.type == CHESSMAN_SHU)||  //横平行 竖平行
		(chm1.type == CHESSMAN_HENG && chm2.type == CHESSMAN_HENG))
        return false;
	double k1,b1;
	int k2,b2;
	
	if(chm1.type == CHESSMAN_SHU && chm2.type == CHESSMAN_HENG)
	{
		pt.x = chm1.ptBegin.x;
	    pt.y = chm2.ptBegin.y;
	}

	else if(chm1.type == CHESSMAN_HENG && chm2.type == CHESSMAN_SHU)
	{
		pt.x = chm2.ptBegin.x;
	    pt.y = chm1.ptBegin.y;
	}
	else if(chm2.type == CHESSMAN_SHU && chm1.type != CHESSMAN_HENG)
	{
		k1 = (double)((chm1.ptBegin.y -chm1.ptEnd.y)/(chm1.ptBegin.x -chm1.ptEnd.x));
		b1 = (int)(chm1.ptBegin.y - k1 * chm1.ptBegin.x);
		pt.x = (int)chm2.ptBegin.x;
		pt.y = (int)(k1 * pt.x + b1);
		
	}
	else if(chm1.type == CHESSMAN_SHU  && chm2.type != CHESSMAN_HENG)
	{
		k2 = (double)((chm2.ptBegin.y -chm2.ptEnd.y)/(chm2.ptBegin.x -chm2.ptEnd.x));
		b2 = (int)(chm2.ptBegin.y - k2 * chm2.ptBegin.x);
		pt.x = (int)chm1.ptBegin.x;
		pt.y = (int)(k2 * pt.x + b2);
		
		
	}
	else
	{
		k1 = (double)((chm1.ptBegin.y -chm1.ptEnd.y)/(chm1.ptBegin.x -chm1.ptEnd.x));
		k2 = (double)((chm2.ptBegin.y -chm2.ptEnd.y)/(chm2.ptBegin.x -chm2.ptEnd.x));
		b1 = (int)(chm1.ptBegin.y - k1 * chm1.ptBegin.x);
		b2 = (int)(chm2.ptBegin.y - k2 * chm2.ptBegin.x);
		pt.x = (int)((b1 - b2)/(k2 - k1));
		pt.y = (int)(k1 * pt.x + b1);
	}
	//求出焦点之后就看看可不可行了
	if(((pow(pt.x - chm1.ptBegin.x,2) == 1 || pow(pt.x - chm1.ptEnd.x,2) == 1 ||
		pow(pt.y - chm1.ptBegin.y,2) == 1 ||pow(pt.y - chm1.ptEnd.y,2) == 1)) && 
		(pow(pt.x - chm2.ptBegin.x,2) == 1 || pow(pt.x - chm2.ptEnd.x,2) == 1 ||
		pow(pt.y - chm2.ptBegin.y,2) == 1 || pow(pt.y - chm2.ptEnd.y,2) == 1))
		return true;
	return false;
	
}
//发现一条线段是否是活的 
// ret -1 左不空  1由不空 0 两边空 -2两边不空
int FindLineLive(int a[MAX_NUM][MAX_NUM],ChessMan chm)
{
	if((chm.ptBegin.x - 1 <= 0 ||chm.ptBegin.y - 1 <= 0) ||
		(chm.ptBegin.x + 1 >= MAX_NUM ||chm.ptBegin.y + 1 >= MAX_NUM))
		return -2;
	if(chm.ptBegin.x - 1 <= 0 ||chm.ptBegin.y - 1 <= 0)
		return -1;
	if(chm.ptBegin.x + 1 >= MAX_NUM ||chm.ptBegin.y + 1 >= MAX_NUM)
		return 1;
	switch (chm.type)
	{
	case CHESSMAN_HENG:
		if(a[chm.ptBegin.x - 1][chm.ptBegin.y] == KONG && a[chm.ptEnd.x + 1][chm.ptEnd.y] == KONG)
			return 0;
		else if(a[chm.ptBegin.x - 1][chm.ptBegin.y] != KONG && a[chm.ptEnd.x + 1][chm.ptEnd.y] == KONG)
			return -1;
		else if(a[chm.ptBegin.x - 1][chm.ptBegin.y] == KONG && a[chm.ptEnd.x + 1][chm.ptEnd.y] != KONG)
			return 1;
		break;
	case CHESSMAN_SHU:
		if(a[chm.ptBegin.x][chm.ptBegin.y - 1] == KONG && a[chm.ptEnd.x][chm.ptEnd.y + 1] == KONG)
			return 0;
		else if(a[chm.ptBegin.x][chm.ptBegin.y - 1] != KONG && a[chm.ptEnd.x][chm.ptEnd.y + 1] == KONG)
			return -1;
		else if(a[chm.ptBegin.x][chm.ptBegin.y - 1] == KONG && a[chm.ptEnd.x][chm.ptEnd.y + 1] != KONG)
			return 1;
	    break;
	case CHESSMAN_XIE_LEFT:
		if(a[chm.ptBegin.x - 1][chm.ptBegin.y - 1] == KONG && a[chm.ptEnd.x + 1][chm.ptEnd.y + 1] == KONG)
			return 0;
		else if(a[chm.ptBegin.x - 1][chm.ptBegin.y - 1] != KONG && a[chm.ptEnd.x + 1][chm.ptEnd.y + 1] == KONG)
			return -1;
		else if(a[chm.ptBegin.x - 1][chm.ptBegin.y - 1] == KONG && a[chm.ptEnd.x + 1][chm.ptEnd.y + 1] != KONG)
			return 1;
	    break;
	case CHESSMAN_XIE_RIGHT:
		if(a[chm.ptBegin.x + 1][chm.ptBegin.y - 1] == KONG && a[chm.ptEnd.x - 1][chm.ptEnd.y + 1] == KONG)
			return 0;
		else if(a[chm.ptBegin.x + 1][chm.ptBegin.y - 1] != KONG && a[chm.ptEnd.x - 1][chm.ptEnd.y + 1] == KONG)
			return -1;
		else if(a[chm.ptBegin.x + 1][chm.ptBegin.y - 1] == KONG && a[chm.ptEnd.x - 1][chm.ptEnd.y + 1] != KONG)
			return 1;
	    break;
	default:
		break;
	}
	return -2;
}
void ManageSeriesTwoThreeLine(int a[MAX_NUM][MAX_NUM],list<ChessMan> chessManTwoList,
							  list<ChessMan> chessManThreeList,DepriorityLevel &dl,int aOrb)
{
	ChessMan chm[100];
	//临时变量
	ChessMan chmFirst;
	ChessMan cheSecond;
	POINT pt;
	bool ret;
	int intChessManNum = 0;
	//发现两子活棋
	FindLineListLive(a,chessManTwoList,chm,intChessManNum);
	int twoAndThree = intChessManNum;  //二和三的分界点

	//发现三子活棋
	FindLineListLive(a,chessManThreeList,chm,intChessManNum);
	//然后现在就处理这个数组
	//y = kx + b
    //这里是在处理两活和三活的交叉之处点必须要填上  否则必输
	int bOreFir,bOreSec;  //交点在左还是在右  1在右 -1在左
	for(int i = 0;i < intChessManNum - 1;i++)
		for(int j = i + 1;j < intChessManNum;j++)
		{
			chmFirst = chm[i];
			cheSecond = chm[j];
			ret = TwoLineInterSect(chmFirst,cheSecond,pt);
			if(ret)
			{
				if(pt.x < MAX_NUM && pt.x > 0 && pt.y < MAX_NUM && pt.y > 0 &&
					a[pt.x][pt.y] == KONG)
				{
					//这里是将交点与之前的线段合为一体 再判断是否为活
					//chmFirst
					if(pow(pt.x - chmFirst.ptBegin.x,2) > 1 ||pow(pt.y - chmFirst.ptBegin.y,2) > 1)
					{
						chmFirst.ptEnd.x = pt.x;
						chmFirst.ptEnd.y = pt.y;
						bOreFir = 1;
					}
					else if(pow(pt.x - chmFirst.ptEnd.x,2) > 1 ||pow(pt.y - chmFirst.ptEnd.y,2) > 1)
					{
						chmFirst.ptBegin.x = pt.x;
						chmFirst.ptBegin.y = pt.y;	
						bOreFir = -1;
					}
					//cheSecond
					if(pow(pt.x - cheSecond.ptBegin.x,2) > 1 ||pow(pt.y - cheSecond.ptBegin.y,2) > 1)
					{
						cheSecond.ptEnd.x = pt.x;
						cheSecond.ptEnd.y = pt.y;
						bOreSec = 1;
					}
					else if(pow(pt.x - cheSecond.ptEnd.x,2) > 1 ||pow(pt.y - cheSecond.ptEnd.y,2) > 1)
					{
						cheSecond.ptBegin.x = pt.x;
						cheSecond.ptBegin.y = pt.y;	
						bOreSec = -1;
					}
					if((i < twoAndThree && j >= twoAndThree ))  //2 3时候 2活 3 冲 一步必输
					{
						if(0 == FindLineLive(a,chmFirst) && -2 != FindLineLive(a,cheSecond))
							 dl.oneLevelList.push_front(pt);
						else if(-2 != FindLineLive(a,chmFirst) && -2 != FindLineLive(a,cheSecond))
							dl.twoLevelList.push_front(pt);
					}
					else if(i >= twoAndThree && j >= twoAndThree)
					{
						if((0 == FindLineLive(a,chmFirst) && -2 != FindLineLive(a,cheSecond))||
							(-2 != FindLineLive(a,chmFirst) && 0 == FindLineLive(a,cheSecond)))
							 dl.oneLevelList.push_front(pt);
						else if(-2 != FindLineLive(a,chmFirst) && -2 != FindLineLive(a,cheSecond))
							dl.twoLevelList.push_front(pt);
					}
					else    //2 2 或 2 3  两个都是活的必输
					{
						if(0 == FindLineLive(a,chmFirst) && 0 == FindLineLive(a,cheSecond))
							 dl.oneLevelList.push_front(pt);
						else if(-2 != FindLineLive(a,chmFirst) && -2 != FindLineLive(a,cheSecond))
							dl.twoLevelList.push_front(pt);
					}
				}
			}
		}
	//这里要对数组倒着处理. 先处理三个，  在处理两个
	POINT rtPt;
	ChessMan chmTmp;
	for(int i = intChessManNum - 1;i >=  0;i--)
	{
		chmTmp = chm[i];
		switch (chm[i].type)
		{
		case CHESSMAN_HENG:
			pt.x = chm[i].ptBegin.x - 1;
			pt.y = chm[i].ptBegin.y;
			chmTmp.ptBegin = pt;
			if(FindTheInterSectPoint(a,pt,rtPt,CHESSMAN_HENG,aOrb) )
				if(FindLineLive(a,chmTmp) != -2 && i >= twoAndThree)
				     dl.oneLevelList.push_front(pt);
				else if(FindLineLive(a,chmTmp) != -2)
					 dl.twoLevelList.push_front(pt);
			pt.x = chm[i].ptEnd.x + 1;
			pt.y = chm[i].ptEnd.y;
			chmTmp.ptBegin = pt;
			if(FindTheInterSectPoint(a,pt,rtPt,CHESSMAN_HENG,aOrb))
				if(FindLineLive(a,chmTmp) != -2 && i >= twoAndThree)
					 dl.oneLevelList.push_front(pt);
				else if(FindLineLive(a,chmTmp) != -2)
					 dl.twoLevelList.push_front(pt);
			break;
		case CHESSMAN_SHU:
			pt.x = chm[i].ptBegin.x;
			pt.y = chm[i].ptBegin.y - 1;
			chmTmp.ptBegin = pt;
			if(FindTheInterSectPoint(a,pt,rtPt,CHESSMAN_SHU,aOrb))
				if(FindLineLive(a,chmTmp) != -2 && i >= twoAndThree)
				     dl.oneLevelList.push_front(pt);
				else if(FindLineLive(a,chmTmp) != -2)
					 dl.twoLevelList.push_front(pt);
			pt.x = chm[i].ptEnd.x;
			pt.y = chm[i].ptEnd.y + 1;
			chmTmp.ptBegin = pt;
			if(FindTheInterSectPoint(a,pt,rtPt,CHESSMAN_SHU,aOrb))
				if(FindLineLive(a,chmTmp) != -2 && i >= twoAndThree)
				     dl.oneLevelList.push_front(pt);
				else if(FindLineLive(a,chmTmp) != -2)
					 dl.twoLevelList.push_front(pt);
			break;
		case CHESSMAN_XIE_LEFT:
			pt.x = chm[i].ptBegin.x - 1;
			pt.y = chm[i].ptBegin.y - 1;
			chmTmp.ptBegin = pt;
			if(FindTheInterSectPoint(a,pt,rtPt,CHESSMAN_XIE_LEFT,aOrb))
				if(FindLineLive(a,chmTmp) != -2 && i >= twoAndThree)
				     dl.oneLevelList.push_front(pt);
				else if(FindLineLive(a,chmTmp) != -2)
					 dl.twoLevelList.push_front(pt);
			pt.x = chm[i].ptEnd.x + 1;
			pt.y = chm[i].ptEnd.y + 1;
			chmTmp.ptBegin = pt;
			if(FindTheInterSectPoint(a,pt,rtPt,CHESSMAN_XIE_LEFT,aOrb))
				if(FindLineLive(a,chmTmp) != -2 && i >= twoAndThree)
				     dl.oneLevelList.push_front(pt);
				else if(FindLineLive(a,chmTmp) != -2)
					 dl.twoLevelList.push_front(pt);
			break;
		case CHESSMAN_XIE_RIGHT:
			pt.x = chm[i].ptBegin.x + 1;
			pt.y = chm[i].ptBegin.y - 1;
			chmTmp.ptBegin = pt;
			if(FindTheInterSectPoint(a,pt,rtPt,CHESSMAN_XIE_RIGHT,aOrb))
				if(FindLineLive(a,chmTmp) != -2 && i >= twoAndThree)
				     dl.oneLevelList.push_front(pt);
				else if(FindLineLive(a,chmTmp) != -2)
					 dl.twoLevelList.push_front(pt);
			pt.x = chm[i].ptEnd.x - 1;
			pt.y = chm[i].ptEnd.y + 1;
			chmTmp.ptBegin = pt;
			if(FindTheInterSectPoint(a,pt,rtPt,CHESSMAN_XIE_RIGHT,aOrb))
				if(FindLineLive(a,chmTmp) != -2 && i >= twoAndThree)
				     dl.oneLevelList.push_front(pt);
				else if(FindLineLive(a,chmTmp) != -2)
					 dl.twoLevelList.push_front(pt);
			break;
		}
	}
}

bool FindTheInterSectPoint(int a[MAX_NUM][MAX_NUM],POINT ptOneSide,POINT &rtPt,int lineType,int aOrb)
{
	rtPt.x = ptOneSide.x;
	rtPt.y = ptOneSide.y;
	if(rtPt.y - 2 < 0 || rtPt.y + 2 > MAX_NUM || rtPt.x - 2 < 0 || rtPt.x + 2 > MAX_NUM)
		return false;
	switch (lineType)
	{
	case CHESSMAN_HENG:
		
		if(a[rtPt.x][rtPt.y + 1] == aOrb && a[rtPt.x][rtPt.y - 1] == aOrb &&
			a[rtPt.x][rtPt.y + 2] == KONG && a[rtPt.x][rtPt.y - 2] == KONG)
		{
			return  true;
		}
		if(a[rtPt.x + 1][rtPt.y + 1] == aOrb && a[rtPt.x - 1][rtPt.y - 1] == aOrb &&
			a[rtPt.x + 2][rtPt.y + 2] == KONG && a[rtPt.x + 2][rtPt.y - 2] == KONG)
		{
			return  true;
		}
		if(a[rtPt.x + 1][rtPt.y - 1] == aOrb && a[rtPt.x - 1][rtPt.y + 1] == aOrb &&
			a[rtPt.x + 2][rtPt.y - 2] == KONG && a[rtPt.x - 2][rtPt.y + 2] == KONG)
		{
			return  true;
		}
		break;
	case CHESSMAN_SHU:
		if(a[rtPt.x + 1][rtPt.y] == aOrb && a[rtPt.x - 1][rtPt.y] == aOrb &&
			a[rtPt.x + 2][rtPt.y] == KONG && a[rtPt.x - 2][rtPt.y] == KONG)
		{
			return  true;
		}
		if(a[rtPt.x + 1][rtPt.y + 1] == aOrb && a[rtPt.x - 1][rtPt.y - 1] == aOrb &&
			a[rtPt.x + 2][rtPt.y + 2] == KONG && a[rtPt.x + 2][rtPt.y - 2] == KONG)
		{
			return  true;
		}
		if(a[rtPt.x + 1][rtPt.y - 1] == aOrb && a[rtPt.x - 1][rtPt.y + 1] == aOrb &&
			a[rtPt.x + 2][rtPt.y - 2] == KONG && a[rtPt.x - 2][rtPt.y + 2] == KONG)
		{
			return  true;
		}
		break;
	case CHESSMAN_XIE_LEFT:
		if(a[rtPt.x][rtPt.y + 1] == aOrb && a[rtPt.x][rtPt.y - 1] == aOrb &&
			a[rtPt.x][rtPt.y + 2] == KONG && a[rtPt.x][rtPt.y - 2] == KONG)
		{
			return  true;
		}
		if(a[rtPt.x + 1][rtPt.y] == aOrb && a[rtPt.x - 1][rtPt.y] == aOrb &&
			a[rtPt.x + 2][rtPt.y] == KONG && a[rtPt.x - 2][rtPt.y] == KONG)
		{
			return  true;
		}
		if(a[rtPt.x + 1][rtPt.y - 1] == aOrb && a[rtPt.x - 1][rtPt.y + 1] == aOrb &&
			a[rtPt.x + 2][rtPt.y - 2] == KONG && a[rtPt.x - 2][rtPt.y + 2] == KONG)
		{
			return  true;
		}
		break;
	case CHESSMAN_XIE_RIGHT:
		if(a[rtPt.x][rtPt.y + 1] == aOrb && a[rtPt.x][rtPt.y - 1] == aOrb &&
			a[rtPt.x][rtPt.y + 2] == KONG && a[rtPt.x][rtPt.y - 2] == KONG)
		{
			return  true;
		}
		if(a[rtPt.x + 1][rtPt.y] == aOrb && a[rtPt.x - 1][rtPt.y] == aOrb &&
			a[rtPt.x + 2][rtPt.y] == KONG && a[rtPt.x - 2][rtPt.y] == KONG)
		{
			return  true;
		}
		if(a[rtPt.x + 1][rtPt.y - 1] == aOrb && a[rtPt.x - 1][rtPt.y + 1] == aOrb &&
			a[rtPt.x + 2][rtPt.y - 2] == KONG && a[rtPt.x - 2][rtPt.y + 2] == KONG)
		{
			return  true;
		}
		break;
	default:
		break;
	}
	return false;
}
//防御算法 与攻击算法的集成
void LuoziAlgorithm(int a[MAX_NUM][MAX_NUM],int aOrb,DepriorityLevel &dl,POINT otherSideLastPt)
{
	ChessManLineList cmll;
	//寻找连续的四个棋子
	FindChessManLineHeng(a,cmll.fourChessManList,FOUR,aOrb);
	FindChessManLineShu(a,cmll.fourChessManList,FOUR,aOrb);
	FindChessManLineXieLeft(a,cmll.fourChessManList,FOUR,aOrb);
	FindChessManLineXieRight(a,cmll.fourChessManList,FOUR,aOrb);
	//寻找连续的三个棋子
	FindChessManLineHeng(a,cmll.threeChessManList,THREE,aOrb);
	FindChessManLineShu(a,cmll.threeChessManList,THREE,aOrb);
	FindChessManLineXieLeft(a,cmll.threeChessManList,THREE,aOrb);
	FindChessManLineXieRight(a,cmll.threeChessManList,THREE,aOrb);
	//寻找连续的两个棋子
	FindChessManLineHeng(a,cmll.twoChessManList,TWO,aOrb);
	FindChessManLineShu(a,cmll.twoChessManList,TWO,aOrb);
	FindChessManLineXieLeft(a,cmll.twoChessManList,TWO,aOrb);
	FindChessManLineXieRight(a,cmll.twoChessManList,TWO,aOrb);

	//其实这个顺序也是代表着优先级的大小.
	ManageSeriesOneChessMan(a,otherSideLastPt,dl,aOrb);

	ManageSeriesFourLine(a,cmll.fourChessManList,dl,aOrb);
	ManageSeriesThreeLine(a,cmll.threeChessManList,dl,aOrb);
	ManageSeriesTwoLine(a,cmll.twoChessManList,dl,aOrb);
	
	ManageSeriesTwoThreeLine(a,cmll.twoChessManList,cmll.threeChessManList,dl,aOrb);
	
}
POINT MachinePlay(int a[MAX_NUM][MAX_NUM],int aOrb,POINT otherSideLastPt)
{ 
	DepriorityLevel defenseLevel;         //防御等级
	LuoziAlgorithm(a,aOrb,defenseLevel,otherSideLastPt);

	DepriorityLevel attackLevel;          //攻击等级
	int myChess = (aOrb - 1)*(aOrb - 1);
	LuoziAlgorithm(a,myChess,attackLevel,otherSideLastPt);

	POINT pt;
	//一步必赢
	while(attackLevel.zeroLevelList.size() > 0)
	{
		pt = attackLevel.zeroLevelList.front();
		attackLevel.zeroLevelList.pop_front();
		if(a[pt.x][pt.y] == KONG)
		   return pt;
		
	}
	//一步必输
	while(defenseLevel.zeroLevelList.size() > 0)
	{
		pt = defenseLevel.zeroLevelList.front();
		defenseLevel.zeroLevelList.pop_front();
		if(a[pt.x][pt.y] == KONG)
			return pt;
		
	}
	//一步稳输
	while(defenseLevel.oneLevelList.size() > 0)
	{
		pt = defenseLevel.oneLevelList.front();
		defenseLevel.oneLevelList.pop_front();
		if(a[pt.x][pt.y] == KONG)
			return pt;
	}
	//一步稳赢
	while(attackLevel.oneLevelList.size() > 0)
	{
		pt = attackLevel.oneLevelList.front();
		attackLevel.oneLevelList.pop_front();
		if(a[pt.x][pt.y] == KONG)
			return pt;
	}

	//两步会输
	while(defenseLevel.twoLevelList.size() > 0)
	{
		pt = defenseLevel.twoLevelList.front();
		defenseLevel.twoLevelList.pop_front();
		if(a[pt.x][pt.y] == KONG)
			return pt;
	}	
	//两步会赢
	while(attackLevel.twoLevelList.size() > 0)
	{
		pt = attackLevel.twoLevelList.front();
		attackLevel.twoLevelList.pop_front();
		if(a[pt.x][pt.y] == KONG)
			return pt;
	}
	
		


	//如果上面算法都没有返回
	int x,y;
	x = otherSideLastPt.x;
	y = otherSideLastPt.y;
	int randInt;
	srand((int)time(0));
	int intRange = 1;  //所下棋子围绕对方下棋子的范围 
	int intTime = 0;  //如果次数过大的话我们有理由认为对方棋子的1范围内均有棋子。在这里我们定为7
	while(1)
	{
		randInt = random(7);
		switch(randInt)
		{
		case 0: //左上
			pt.x = x - intRange;
			pt.y = y - intRange;
			break;
		case 1: //左下
			pt.x = x - intRange;
			pt.y = y + intRange;
			break;
		case 2: //右上
			pt.x = x + intRange;
			pt.y = y - intRange;
			break;
		case 3: //右下
			pt.x = x + intRange;
			pt.y = y + intRange;
			break;
		case 4: //上
			pt.x = x;
			pt.y = y - intRange;
			break;
		case 5: //下
			pt.x = x;
			pt.y = y + intRange;
			break;
		case 6: //左
			pt.x = x - intRange;
			pt.y = y;
			break;
		case 7: //右
			pt.x = x + intRange;
			pt.y = y;
			break;
		}
		if(pt.x < MAX_NUM && pt.x > 0 && pt.y < MAX_NUM && pt.y > 0 && 
			a[pt.x][pt.y] == -1)
		{
			return pt;
		}
		intTime++;
		if(intTime == 7)
		{
			intTime = 0;
			intRange++;
		}
	}
}