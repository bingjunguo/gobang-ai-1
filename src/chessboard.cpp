#include "chessboard.h"


ChessBoard::ChessBoard()
{

}

ChessBoard::~ChessBoard()
{

}

void ChessBoard::initChessBoard()
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
