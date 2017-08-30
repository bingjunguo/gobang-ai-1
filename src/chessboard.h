#ifndef _CHESSBOARD_H_
#define _CHESSBOARD_H_

#include "zobrist.h"


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
	initChessBoard(); //初始化棋盘
	
};

#endif