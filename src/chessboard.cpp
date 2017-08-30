#include "chessboard.h"


ChessBoard::ChessBoard()
{
	_initChessBoard();
	//默认黑先走
	m_board[7][7] = COM;
	_initChessScore();
}

ChessBoard::~ChessBoard()
{
}

void ChessBoard::_initChessBoard()
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			m_board[i][j] = EMPTY;
		}
	}
	return;
}
void ChessBoard::_initChessScore()
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			m_comScore[i][j] = EMPTY;
			m_humScore[i][j] = EMPTY;
		}
	}
	for(int i = 0;i < BOARD_SIZE; i++)
	{
		for(int j = 0;j < BOARD_SIZE; j++) 
		{
			if(m_board[i][j] == EMPTY) 
			{
				Pos pos;
				pos.x = i; pos.y = j;
				if(hasNeighbor(pos, 2, 2))//必须是有邻居的才行
				{ 
					int cs = scorePoint(board, pos, COM);
					int hs = scorePoint(board, pos, HUM);
					m_comScore[i][j] = cs;
					m_humScore[i][j] = hs;
				}
		  }
		}
  	}
	return;
}
bool ChessBoard::hasNeighbor(Pos pos, int distance, int count)
{
	return false;
}

int ChessBoard::scorePoint()
{
	return 0;
}