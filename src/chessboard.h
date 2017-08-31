#ifndef _CHESSBOARD_H_
#define _CHESSBOARD_H_

#include <list>
#include <map>
#include "zobrist.h"
using namespace std;  
#define MAX_AB(a,b)  (a>b?a:b)

typedef list<Pos> ListPos; 

typedef map<int,int> EvaluateCacheMap;

class ChessBoard
{
	int m_board[BOARD_SIZE][BOARD_SIZE];
	ListPos m_step;
	Zobrist  m_zobrist;
	EvaluateCacheMap m_evaluateCache;  //棋面估分缓存

	int m_comMaxScore;  //棋面电脑最高分
	int m_humMaxScore;  //棋面人最高分

	int m_comScore[BOARD_SIZE][BOARD_SIZE];
	int m_humScore[BOARD_SIZE][BOARD_SIZE];
public:
	ChessBoard();
	~ChessBoard();
	void _initChessBoard();  //初始化棋盘
	void _initChessScore();  //初始化分数
	bool put(Pos p, int role);  //下子
	bool remove(Pos p);		    //移除棋子
	bool back();                //悔棋   
	int isWin();				//赢了嘛 0 没有 返回角色
	bool isFive(Pos pos);       //这个点是否练成了五子    

	bool hasNeighbor(Pos pos, int distance, int count);		 //是否有邻居
	int scorePoint(Pos pos,int role); 		 //计算分数
	int countToType(int count, int block, int empty);
	int typeToScore(int chessType);
	void updateScore(Pos pos); //只更新一个点附近的分数
	int evaluate(int role);  //棋面估分

	
	ListPos gen();//启发函数

	Zobrist getZobrist()
	{
		return m_zobrist;
	}

};

#endif
