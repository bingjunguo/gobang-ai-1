#ifndef _CHESSBOARD_H_
#define _CHESSBOARD_H_

#include <list>
#include "zobrist.h"
using namespace std;  

typedef list<Pos> Step; 

class ChessBoard
{
	int m_board[BOARD_SIZE][BOARD_SIZE];
	Step m_step;
	Zobrist  m_zobrist;

	int m_comScore[BOARD_SIZE][BOARD_SIZE];
	int m_humScore[BOARD_SIZE][BOARD_SIZE];
public:
	ChessBoard();
	~ChessBoard();
	void _initChessBoard();  //初始化棋盘
	void _initChessScore();  //初始化分数
	bool hasNeighbor();		 //是否有邻居
	int scorePoint(); 		 //计算分数
};

#endif
