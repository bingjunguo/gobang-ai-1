#include "chessboard.h"


ChessBoard::ChessBoard()
{

}

ChessBoard::~ChessBoard()
{

}

ChessBoard::initChessBoard()
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			m_board[i][j] = 0;
		}
	}
}