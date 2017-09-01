#include "stdafx.h"

#include "AutoPlay.h"


//����һ��4�����ӵ�
/*
   @ int a[MAX_NUM][MAX_NUM] ������������� 1-19
   @ int chessManNum   ��ѯ�������ӵ�����
   @ int aOrb    ���廹�Ǻ���  0Ϊ���� 1Ϊ����
*/
void FindChessManLineHeng(int a[MAX_NUM][MAX_NUM],list<ChessMan> &ChessManList,int chessManNum,int aOrb)
{
	ChessMan chm;
	for(int i = 1;i < MAX_NUM;i++)    
	{
		int serialChessManNum = 0;  //��������������
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
	for(int i = 1;i < MAX_NUM;i++)    //��
	{
		int serialChessManNum = 0;  //��������������
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
	//////�����Ǵ�X��ʼ�� x++
	for(int i = 1;i < MAX_NUM - 4;i++)     //����֮���Բ� <= ��ԭ���� ��б16ֻ��4������������������
	{
		int serialChessManNum = 0;  //��������������
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
	//  \ ������
	for(int i = 2;i < MAX_NUM - 4;i++)     //����֮���Բ� <= ��ԭ���� ��б16ֻ��4������������������
	{
		int serialChessManNum = 0;  //��������������
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
	//////�����Ǵ�X��ʼ�� x--
	for(int i = MAX_NUM - 1;i > 4;i--)   
	{
		int serialChessManNum = 0;  //��������������
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
	//  /������
	//y++
	for(int i = 2;i < MAX_NUM - 4;i++)     //����֮���Բ� <= ��ԭ���� ��б16ֻ��4������������������
	{
		int serialChessManNum = 0;  //��������������
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
	int myChess = (aOrb - 1) * (aOrb - 1);    //��-1��ƽ������   �Ҽ�һ��ƽ���Ǽ�  
	while(chessManList.size() > 0)
	{
		cm = chessManList.front();
		chessManList.pop_front();
		switch (cm.type)
		{
		case CHESSMAN_HENG:  
			// case  _ xxxx*   * ������ǽҲ������ ����
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
			//case  _xxxx_   ��ʵ������Ͼ��군�ˣ� ������һ���������أ�
			else if(a[cm.ptBegin.x - 1][cm.ptBegin.y] == KONG && 
				a[cm.ptEnd.x + 1][cm.ptEnd.y] == KONG)
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y;
				dl.zeroLevelList.push_front(ptTmp);
			}
			break;
		case CHESSMAN_SHU:
			//case  ���ŵ�  _ xxxx*
			if(cm.ptBegin.y != 1 && a[cm.ptBegin.x][cm.ptBegin.y - 1] == KONG &&
				((a[cm.ptEnd.x][cm.ptEnd.y + 1] == myChess && cm.ptEnd.y != MAX_NUM -1) 
				   ||cm.ptEnd.y == MAX_NUM -1))
			{
				ptTmp.x = cm.ptBegin.x;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//case ���ŵ� *xxxx_
			else if(cm.ptEnd.y != MAX_NUM -1 && a[cm.ptEnd.x][cm.ptEnd.y + 1] == KONG &&
				((a[cm.ptBegin.x][cm.ptBegin.y - 1] == myChess && cm.ptBegin.y != 1)
				|| cm.ptBegin.y == 1))
			{
				ptTmp.x = cm.ptEnd.x;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//case ���ŵ� _xxxx_   ��ʵ������Ͼ��군�ˣ� ������һ���������أ�
			else if(a[cm.ptBegin.x][cm.ptBegin.y - 1] == KONG && 
				a[cm.ptEnd.x][cm.ptEnd.y + 1] == KONG)
			{
				ptTmp.x = cm.ptEnd.x;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
		    break;
		case CHESSMAN_XIE_LEFT:
			//case  ��б��  _ xxxx*
			if(cm.ptBegin.y != 1 && cm.ptBegin.x != 1 && a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == KONG &&
			  ((a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] == myChess && cm.ptEnd.x != MAX_NUM -1 && cm.ptEnd.y != MAX_NUM -1) 
			   ||(cm.ptEnd.x == MAX_NUM -1 || cm.ptEnd.y == MAX_NUM -1)))
			{
				ptTmp.x = cm.ptBegin.x - 1;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//case ��б�� *xxxx_
			else if(cm.ptEnd.x != MAX_NUM -1 && cm.ptEnd.y != MAX_NUM -1 && a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] == KONG &&
				((a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == myChess && cm.ptBegin.x != 1 &&cm.ptBegin.y != 1)
				|| (cm.ptBegin.x == 1 || cm.ptBegin.y == 1)))
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//case ��б�� _xxxx_   ��ʵ������Ͼ��군�ˣ� ������һ���������أ�
			else if(a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == KONG && 
				a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] == KONG)
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
		    break;
		case CHESSMAN_XIE_RIGHT:
			//case  ��б��  _ xxxx*
			if(cm.ptBegin.x != MAX_NUM - 1 && cm.ptBegin.y != 1 && a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == KONG &&
			  ((a[cm.ptEnd.x - 1][cm.ptEnd.y + 1] == myChess && cm.ptEnd.x != 1 && cm.ptEnd.y != MAX_NUM -1) 
			   ||(cm.ptEnd.x == 1 && cm.ptEnd.y || MAX_NUM -1)))
			{
				ptTmp.x = cm.ptBegin.x + 1;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//case ��б�� *xxxx_
			else if(cm.ptEnd.x != 1 && cm.ptEnd.y != MAX_NUM -1 && a[cm.ptEnd.x - 1][cm.ptEnd.y + 1] == KONG &&
				((a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == myChess && cm.ptBegin.x != MAX_NUM - 1 && cm.ptBegin.y != 1)
				|| (cm.ptBegin.x == MAX_NUM - 1 || cm.ptBegin.y == 1)))
			{
				ptTmp.x = cm.ptEnd.x - 1;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.zeroLevelList.push_front(ptTmp);
			}
			//case ��б�� _xxxx_   ��ʵ������Ͼ��군�ˣ� ������һ���������أ�
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
	int myChess = (aOrb - 1) * (aOrb - 1);    //�׼�һ��ƽ������   �Ҽ�һ��ƽ���Ǽ�  
	while(chessManList.size() > 0)
	{
		cm = chessManList.front();
		chessManList.pop_front();
		switch (cm.type)
		{
		case CHESSMAN_HENG: 
			//����ֻ��������if ��Ϊ�����ֶ��п��ܷ���
			//һ������  xxx_x   x_xxx
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
			//���������ѡһ�� *xxx_  -xxx*   _xxx_
			//case  -xxx*  2������
			if(cm.ptBegin.x != 1 && a[cm.ptBegin.x - 1][cm.ptBegin.y] == KONG &&
				((a[cm.ptEnd.x + 1][cm.ptEnd.y] == myChess && cm.ptEnd.x != MAX_NUM -1) 
				   ||cm.ptEnd.x == MAX_NUM -1))
			{
				ptTmp.x = cm.ptBegin.x -1;
				ptTmp.y = cm.ptBegin.y;
				dl.twoLevelList.push_front(ptTmp);
			}
			//case  *xxx_ 2������
			else if(cm.ptEnd.x != MAX_NUM -1 && a[cm.ptEnd.x + 1][cm.ptEnd.y] == KONG &&
				((a[cm.ptBegin.x - 1][cm.ptBegin.y] == myChess && cm.ptBegin.x != 1)
				|| cm.ptBegin.x == 1))
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y;
				dl.twoLevelList.push_front(ptTmp);
			}
			//case  _xxx_  һ������
			else if(a[cm.ptBegin.x - 1][cm.ptBegin.y] == KONG && 
				a[cm.ptEnd.x + 1][cm.ptEnd.y] == KONG)
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y;
				dl.oneLevelList.push_front(ptTmp);
			}
			break;
		case CHESSMAN_SHU: 
			//����ֻ��������if ��Ϊ�����ֶ��п��ܷ���
			//һ������  xxx_x   x_xxx
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
			//���������ѡһ�� *xxx_  -xxx*   _xxx_
			//case  ���ŵ� -xxx*  2������
			if(cm.ptBegin.y != 1 && a[cm.ptBegin.x][cm.ptBegin.y - 1] == KONG &&
				((a[cm.ptEnd.x][cm.ptEnd.y + 1] == myChess && cm.ptEnd.y != MAX_NUM -1) 
				   ||cm.ptEnd.y == MAX_NUM -1))
			{
				ptTmp.x = cm.ptBegin.x;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.twoLevelList.push_front(ptTmp);
			}
			//case ���ŵ� *xxx_ 2������
			else if(cm.ptEnd.y != MAX_NUM -1 && a[cm.ptEnd.x][cm.ptEnd.y + 1] == KONG &&
				((a[cm.ptBegin.x][cm.ptBegin.y - 1] == myChess && cm.ptBegin.y != 1)
				|| cm.ptBegin.y == 1))
			{
				ptTmp.x = cm.ptEnd.x;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.twoLevelList.push_front(ptTmp);
			}
			//case ���ŵ� _xxx_  һ������
			else if(a[cm.ptBegin.x][cm.ptBegin.y - 1] == KONG && 
				a[cm.ptEnd.x][cm.ptEnd.y + 1] == KONG)
			{
				ptTmp.x = cm.ptEnd.x;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.oneLevelList.push_front(ptTmp);
			}
		    break;
		case CHESSMAN_XIE_LEFT: 
			//����ֻ��������if ��Ϊ�����ֶ��п��ܷ���
			//һ������  xxx_x   x_xxx
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
			//���������ѡһ�� *xxx_  -xxx*   _xxx_ 
			//case  ��б�� -xxx*  2������
			if(cm.ptBegin.y != 1 && cm.ptBegin.x != 1 && a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == KONG &&
			  ((a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] == myChess && cm.ptEnd.x != MAX_NUM -1 && cm.ptEnd.y != MAX_NUM -1) 
			   ||(cm.ptEnd.x == MAX_NUM -1 || cm.ptEnd.y == MAX_NUM -1)))
			{
				ptTmp.x = cm.ptBegin.x - 1;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.twoLevelList.push_front(ptTmp);
			}
			//case ��б�� *xxx_ 2������
			else if(cm.ptEnd.x != MAX_NUM -1 && cm.ptEnd.y != MAX_NUM -1 && a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] == KONG &&
				((a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == myChess && cm.ptBegin.x != 1 &&cm.ptBegin.y != 1)
				|| (cm.ptBegin.x == 1 || cm.ptBegin.y == 1)))
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.twoLevelList.push_front(ptTmp);
			}
			//case ��б�� _xxx_  һ������
			else if(a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == KONG && 
				a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] == KONG)
			{
				ptTmp.x = cm.ptEnd.x + 1;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.oneLevelList.push_front(ptTmp);
			}
			break;
		case CHESSMAN_XIE_RIGHT: 
			//����ֻ��������if ��Ϊ�����ֶ��п��ܷ���
			//һ������ ��б xxx_x   x_xxx
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
			//���������ѡһ�� *xxx_  -xxx*   _xxx_ 
			//case  ��б��  -xxx*  2������
			if(cm.ptBegin.x != MAX_NUM - 1 && cm.ptBegin.y != 1 && a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == KONG &&
			  ((a[cm.ptEnd.x - 1][cm.ptEnd.y + 1] == myChess && cm.ptEnd.x != 1 && cm.ptEnd.y != MAX_NUM -1) 
			   ||(cm.ptEnd.x == 1 && cm.ptEnd.y == MAX_NUM -1)))
			{
				ptTmp.x = cm.ptBegin.x + 1;
				ptTmp.y = cm.ptBegin.y - 1;
				dl.twoLevelList.push_front(ptTmp);
			}
			//case ��б�� *xxx_ 2������
			else if(cm.ptEnd.x != 1 && cm.ptEnd.y != MAX_NUM -1 && a[cm.ptEnd.x - 1][cm.ptEnd.y + 1] == KONG &&
				((a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == myChess && cm.ptBegin.x != MAX_NUM - 1 && cm.ptBegin.y != 1)
				|| (cm.ptBegin.x == MAX_NUM - 1 || cm.ptBegin.y == 1)))
			{
				ptTmp.x = cm.ptEnd.x - 1;
				ptTmp.y = cm.ptEnd.y + 1;
				dl.twoLevelList.push_front(ptTmp);
			}
			//case ��б�� _xxx_  һ������
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
	int myChess = (aOrb - 1) * (aOrb - 1);    //��-1��ƽ������   �Ҽ�һ��ƽ���Ǽ�  
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
			//xx_xx �������
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
				//��������
				if(((cm.ptEnd.x + 3 < MAX_NUM && a[cm.ptEnd.x + 1][cm.ptEnd.y] == myChess) ||  //�ұ��Ƿ�յĵ��������һ��λ��
					cm.ptEnd.x + 3 == MAX_NUM)
					&& cm.ptBegin.x - 1 > 0 && a[cm.ptBegin.x - 1][cm.ptBegin.y] == KONG)        //�����һ��λ�ö���Ϊ��     
				{
					ptTmp.x = cm.ptEnd.x + 1;
					ptTmp.y = cm.ptEnd.y;
					dl.twoLevelList.push_front(ptTmp);
				}
				else if(((cm.ptBegin.x - 1 > 0 && a[cm.ptBegin.x - 1][cm.ptBegin.y] == myChess)||   //����Ƿ�յ�
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
				//��������
				if(((cm.ptBegin.x - 3 > 0 && a[cm.ptBegin.x - 1][cm.ptBegin.y] == myChess) ||  //����Ƿ��
					cm.ptBegin.x - 3 == 0)
					&& cm.ptEnd.x + 1 < MAX_NUM && a[cm.ptEnd.x + 1][cm.ptBegin.y] == KONG)        //�ұ���һ��λ�ö���Ϊ��     
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
			//xx_xx ������� ����
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
			//case  xx_x ����
			if(cm.ptEnd.y + 2 < MAX_NUM && a[cm.ptEnd.x][cm.ptEnd.y + 1] == KONG &&
				a[cm.ptEnd.x][cm.ptEnd.y + 2] == aOrb)
			{
				//��������
				if(((cm.ptEnd.y + 3 < MAX_NUM && a[cm.ptEnd.x][cm.ptEnd.y + 1] == myChess) ||  //�ұ��Ƿ�յĵ��������һ��λ��
					cm.ptEnd.y + 3 == MAX_NUM)
					&& cm.ptBegin.y - 1 > 0 && a[cm.ptBegin.x][cm.ptBegin.y - 1] == KONG)        //�����һ��λ�ö���Ϊ��     
				{
					ptTmp.x = cm.ptEnd.x;
					ptTmp.y = cm.ptEnd.y + 1;
					dl.twoLevelList.push_front(ptTmp);
				}
				else if(((cm.ptBegin.y - 1 > 0 && a[cm.ptBegin.x][cm.ptBegin.y - 1] == myChess)||   //����Ƿ�յ�
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
			//case x_xx ����
			if(cm.ptBegin.y - 2 > 0 && a[cm.ptBegin.x][cm.ptBegin.y - 1] == KONG &&
				a[cm.ptBegin.x][cm.ptBegin.y - 2] == aOrb)
			{
				//��������
				if(((cm.ptBegin.y - 3 > 0 && a[cm.ptBegin.x][cm.ptBegin.y - 1] == myChess) ||  //����Ƿ��
					cm.ptBegin.y - 3 == 0)
					&& cm.ptEnd.y + 1 < MAX_NUM && a[cm.ptEnd.x][cm.ptBegin.y + 1] == KONG)        //�ұ���һ��λ�ö���Ϊ��     
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
			//xx_xx ������� ��б��
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
			//case  xx_x ��б��
			if(cm.ptEnd.x + 2 < MAX_NUM && cm.ptEnd.y + 2 < MAX_NUM && 
				a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] == KONG &&
				a[cm.ptEnd.x + 2][cm.ptEnd.y + 2] == aOrb)
			{
				//��������
				if(((cm.ptEnd.x + 3 < MAX_NUM && cm.ptEnd.y + 3 < MAX_NUM && 
					a[cm.ptEnd.x + 1][cm.ptEnd.y + 1] == myChess) ||  //�ұ��Ƿ�յĵ��������һ��λ��
					(cm.ptEnd.x + 3 == MAX_NUM && cm.ptEnd.y + 3 == MAX_NUM))
					&& cm.ptBegin.x - 1 > 0 && cm.ptBegin.y - 1 > 0 && 
					a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == KONG)        //�����һ��λ�ö���Ϊ��     
				{
					ptTmp.x = cm.ptEnd.x + 1;
					ptTmp.y = cm.ptEnd.y + 1;
					dl.twoLevelList.push_front(ptTmp);
				}
				else if(((cm.ptBegin.x - 1 > 0 && cm.ptBegin.y - 1 > 0 && 
					a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == myChess)||   //����Ƿ�յ�
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
			//case x_xx ��б��
			if(cm.ptBegin.x - 2 > 0 && cm.ptBegin.y - 2 > 0 && 
				a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == KONG &&
				a[cm.ptBegin.x - 2][cm.ptBegin.y - 2] == aOrb)
			{
				//��������
				if(((cm.ptBegin.x - 3 > 0 && cm.ptBegin.y - 3 > 0 && 
					a[cm.ptBegin.x - 1][cm.ptBegin.y - 1] == myChess) ||  //����Ƿ��
					(cm.ptBegin.x - 3 == 0 && cm.ptBegin.y - 3 == 0)) && 
					cm.ptEnd.x + 1 < MAX_NUM && cm.ptEnd.y + 1 < MAX_NUM && 
					a[cm.ptEnd.x + 1][cm.ptBegin.y + 1] == KONG)        //�ұ���һ��λ�ö���Ϊ��     
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
			//xx_xx ������� ��б��
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
			//case  xx_x ��б��
			if(cm.ptEnd.x - 2 < MAX_NUM && cm.ptEnd.y + 2 < MAX_NUM && 
				a[cm.ptEnd.x - 1][cm.ptEnd.y + 1] == KONG &&
				a[cm.ptEnd.x - 2][cm.ptEnd.y + 2] == aOrb)
			{
				//��������
				if(((cm.ptEnd.x - 3 < MAX_NUM && cm.ptEnd.y + 3 < MAX_NUM && 
					a[cm.ptEnd.x - 1][cm.ptEnd.y + 1] == myChess) ||  //�ұ��Ƿ�յĵ��������һ��λ��
					(cm.ptEnd.x - 3 == MAX_NUM && cm.ptEnd.y + 3 == MAX_NUM))
					&& cm.ptBegin.x + 1 > 0 && cm.ptBegin.y - 1 > 0 && 
					a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == KONG)        //�����һ��λ�ö���Ϊ��     
				{
					ptTmp.x = cm.ptEnd.x - 1;
					ptTmp.y = cm.ptEnd.y + 1;
					dl.twoLevelList.push_front(ptTmp);
				}
				else if(((cm.ptBegin.x + 1 > 0 && cm.ptBegin.y - 1 > 0 && 
					a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == myChess)||   //����Ƿ�յ�
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
			//case x_xx ��б��
			if(cm.ptBegin.x + 2 > 0 && cm.ptBegin.y - 2 > 0 && 
				a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == KONG &&
				a[cm.ptBegin.x + 2][cm.ptBegin.y - 2] == aOrb)
			{
				//��������
				if(((cm.ptBegin.x + 3 > 0 && cm.ptBegin.y - 3 > 0 && 
					a[cm.ptBegin.x + 1][cm.ptBegin.y - 1] == myChess) ||  //����Ƿ��
					(cm.ptBegin.x + 3 == 0 && cm.ptBegin.y - 3 == 0)) && 
					cm.ptEnd.x - 1 < MAX_NUM && cm.ptEnd.y + 1 < MAX_NUM && 
					a[cm.ptEnd.x - 1][cm.ptBegin.y + 1] == KONG)        //�ұ���һ��λ�ö���Ϊ��     
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
	//�ж� ��
	POINT pt;
	pt.x = otherSideLastPt.x;
	pt.y = otherSideLastPt.y + 1;
	if(pt.y < MAX_NUM)
		if(FindFourChessManMidKONG(a,pt,aOrb))
			dl.oneLevelList.push_front(pt);
	//��
	pt.x = otherSideLastPt.x;
	pt.y = otherSideLastPt.y - 1;
	if(pt.y > 0)
		if(FindFourChessManMidKONG(a,pt,aOrb))
			dl.oneLevelList.push_front(pt);
	//��
	pt.x = otherSideLastPt.x + 1;
	pt.y = otherSideLastPt.y;
	if(pt.x < MAX_NUM)
		if(FindFourChessManMidKONG(a,pt,aOrb))
			dl.oneLevelList.push_front(pt);
	//��
	pt.x = otherSideLastPt.x - 1;
	pt.y = otherSideLastPt.y ;
	if(pt.x > 0)
		if(FindFourChessManMidKONG(a,pt,aOrb))
			dl.oneLevelList.push_front(pt);
	
}


void FindLineListLive(int a[MAX_NUM][MAX_NUM],list<ChessMan> chessManList,ChessMan *chm,int &intChessManNum)
{
	ChessMan cm;  //��ʱ����
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
	if((chm1.type == CHESSMAN_SHU && chm2.type == CHESSMAN_SHU)||  //��ƽ�� ��ƽ��
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
	//�������֮��Ϳ����ɲ�������
	if(((pow(pt.x - chm1.ptBegin.x,2) == 1 || pow(pt.x - chm1.ptEnd.x,2) == 1 ||
		pow(pt.y - chm1.ptBegin.y,2) == 1 ||pow(pt.y - chm1.ptEnd.y,2) == 1)) && 
		(pow(pt.x - chm2.ptBegin.x,2) == 1 || pow(pt.x - chm2.ptEnd.x,2) == 1 ||
		pow(pt.y - chm2.ptBegin.y,2) == 1 || pow(pt.y - chm2.ptEnd.y,2) == 1))
		return true;
	return false;
	
}
//����һ���߶��Ƿ��ǻ�� 
// ret -1 �󲻿�  1�ɲ��� 0 ���߿� -2���߲���
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
	//��ʱ����
	ChessMan chmFirst;
	ChessMan cheSecond;
	POINT pt;
	bool ret;
	int intChessManNum = 0;
	//�������ӻ���
	FindLineListLive(a,chessManTwoList,chm,intChessManNum);
	int twoAndThree = intChessManNum;  //�������ķֽ��

	//�������ӻ���
	FindLineListLive(a,chessManThreeList,chm,intChessManNum);
	//Ȼ�����ھʹ����������
	//y = kx + b
    //�������ڴ������������Ľ���֮�������Ҫ����  �������
	int bOreFir,bOreSec;  //��������������  1���� -1����
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
					//�����ǽ�������֮ǰ���߶κ�Ϊһ�� ���ж��Ƿ�Ϊ��
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
					if((i < twoAndThree && j >= twoAndThree ))  //2 3ʱ�� 2�� 3 �� һ������
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
					else    //2 2 �� 2 3  �������ǻ�ı���
					{
						if(0 == FindLineLive(a,chmFirst) && 0 == FindLineLive(a,cheSecond))
							 dl.oneLevelList.push_front(pt);
						else if(-2 != FindLineLive(a,chmFirst) && -2 != FindLineLive(a,cheSecond))
							dl.twoLevelList.push_front(pt);
					}
				}
			}
		}
	//����Ҫ�����鵹�Ŵ���. �ȴ���������  �ڴ�������
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
//�����㷨 �빥���㷨�ļ���
void LuoziAlgorithm(int a[MAX_NUM][MAX_NUM],int aOrb,DepriorityLevel &dl,POINT otherSideLastPt)
{
	ChessManLineList cmll;
	//Ѱ���������ĸ�����
	FindChessManLineHeng(a,cmll.fourChessManList,FOUR,aOrb);
	FindChessManLineShu(a,cmll.fourChessManList,FOUR,aOrb);
	FindChessManLineXieLeft(a,cmll.fourChessManList,FOUR,aOrb);
	FindChessManLineXieRight(a,cmll.fourChessManList,FOUR,aOrb);
	//Ѱ����������������
	FindChessManLineHeng(a,cmll.threeChessManList,THREE,aOrb);
	FindChessManLineShu(a,cmll.threeChessManList,THREE,aOrb);
	FindChessManLineXieLeft(a,cmll.threeChessManList,THREE,aOrb);
	FindChessManLineXieRight(a,cmll.threeChessManList,THREE,aOrb);
	//Ѱ����������������
	FindChessManLineHeng(a,cmll.twoChessManList,TWO,aOrb);
	FindChessManLineShu(a,cmll.twoChessManList,TWO,aOrb);
	FindChessManLineXieLeft(a,cmll.twoChessManList,TWO,aOrb);
	FindChessManLineXieRight(a,cmll.twoChessManList,TWO,aOrb);

	//��ʵ���˳��Ҳ�Ǵ��������ȼ��Ĵ�С.
	ManageSeriesOneChessMan(a,otherSideLastPt,dl,aOrb);

	ManageSeriesFourLine(a,cmll.fourChessManList,dl,aOrb);
	ManageSeriesThreeLine(a,cmll.threeChessManList,dl,aOrb);
	ManageSeriesTwoLine(a,cmll.twoChessManList,dl,aOrb);
	
	ManageSeriesTwoThreeLine(a,cmll.twoChessManList,cmll.threeChessManList,dl,aOrb);
	
}
POINT MachinePlay(int a[MAX_NUM][MAX_NUM],int aOrb,POINT otherSideLastPt)
{ 
	DepriorityLevel defenseLevel;         //�����ȼ�
	LuoziAlgorithm(a,aOrb,defenseLevel,otherSideLastPt);

	DepriorityLevel attackLevel;          //�����ȼ�
	int myChess = (aOrb - 1)*(aOrb - 1);
	LuoziAlgorithm(a,myChess,attackLevel,otherSideLastPt);

	POINT pt;
	//һ����Ӯ
	while(attackLevel.zeroLevelList.size() > 0)
	{
		pt = attackLevel.zeroLevelList.front();
		attackLevel.zeroLevelList.pop_front();
		if(a[pt.x][pt.y] == KONG)
		   return pt;
		
	}
	//һ������
	while(defenseLevel.zeroLevelList.size() > 0)
	{
		pt = defenseLevel.zeroLevelList.front();
		defenseLevel.zeroLevelList.pop_front();
		if(a[pt.x][pt.y] == KONG)
			return pt;
		
	}
	//һ������
	while(defenseLevel.oneLevelList.size() > 0)
	{
		pt = defenseLevel.oneLevelList.front();
		defenseLevel.oneLevelList.pop_front();
		if(a[pt.x][pt.y] == KONG)
			return pt;
	}
	//һ����Ӯ
	while(attackLevel.oneLevelList.size() > 0)
	{
		pt = attackLevel.oneLevelList.front();
		attackLevel.oneLevelList.pop_front();
		if(a[pt.x][pt.y] == KONG)
			return pt;
	}

	//��������
	while(defenseLevel.twoLevelList.size() > 0)
	{
		pt = defenseLevel.twoLevelList.front();
		defenseLevel.twoLevelList.pop_front();
		if(a[pt.x][pt.y] == KONG)
			return pt;
	}	
	//������Ӯ
	while(attackLevel.twoLevelList.size() > 0)
	{
		pt = attackLevel.twoLevelList.front();
		attackLevel.twoLevelList.pop_front();
		if(a[pt.x][pt.y] == KONG)
			return pt;
	}
	
		


	//��������㷨��û�з���
	int x,y;
	x = otherSideLastPt.x;
	y = otherSideLastPt.y;
	int randInt;
	srand((int)time(0));
	int intRange = 1;  //��������Χ�ƶԷ������ӵķ�Χ 
	int intTime = 0;  //�����������Ļ�������������Ϊ�Է����ӵ�1��Χ�ھ������ӡ����������Ƕ�Ϊ7
	while(1)
	{
		randInt = random(7);
		switch(randInt)
		{
		case 0: //����
			pt.x = x - intRange;
			pt.y = y - intRange;
			break;
		case 1: //����
			pt.x = x - intRange;
			pt.y = y + intRange;
			break;
		case 2: //����
			pt.x = x + intRange;
			pt.y = y - intRange;
			break;
		case 3: //����
			pt.x = x + intRange;
			pt.y = y + intRange;
			break;
		case 4: //��
			pt.x = x;
			pt.y = y - intRange;
			break;
		case 5: //��
			pt.x = x;
			pt.y = y + intRange;
			break;
		case 6: //��
			pt.x = x - intRange;
			pt.y = y;
			break;
		case 7: //��
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