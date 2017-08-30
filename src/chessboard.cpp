#include "chessboard.h"


ChessBoard::ChessBoard()
{
	_initChessBoard();
	//默认黑先走
	m_board[7][7] = COM;
	m_zobrist.go(7, 7, COM);
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
					int cs = scorePoint(pos, COM);
					int hs = scorePoint(pos, HUM);
					m_comScore[i][j] = cs;
					m_humScore[i][j] = hs;
				}
		  }
		}
  	}
	return;
}
void ChessBoard::updateScore(Pos pos)
{
	int radius = 8,
	int len = BOARD_SIZE;

	/*function update(x, y) {
	int cs = scorePoint(board, [x,y], R.com);
	int hs = scorePoint(board, [x,y], R.hum);
	self.comScore[x][y] = cs;
	self.humScore[x][y] = hs;
	//注意下面这样写是错的！因为很可能最高分已经没了，不是总是取最高分的，这样分数会越来越高的。所以改成每次遍历计算
	/*self.comMaxScore = Math.max(cs, self.comMaxScore);
	self.humMaxScore = Math.max(hs, self.humMaxScore);
	}*/
  // -
	for(int i = -radius;i < radius;i++) 
	{
		int x = pos.x, y = pos.y+i;
		if(y < 0) continue;
		if(y >= len) break;
		if(m_board[x][y] != EMPTY) 
			continue;
		Pos pos; pos.x = x; pos.y = y;
		self.comScore[x][y] = scorePoint(pos, R.com);
		self.humScore[x][y] = scorePoint(pos, R.hum);
	}

	// |
	for(int i = -radius;i < radius;i++) 
	{
		int x = pos.x + i, y = pos.y ; 
		if(x < 0) 
			continue;
		if(x >= len) 
			break;
		if(m_board[x][y] != EMPTY) 
			continue;
		Pos pos; pos.x = x; pos.y = y;
		self.comScore[x][y] = scorePoint(pos, R.com);
		self.humScore[x][y] = scorePoint(pos, R.hum);
	}

	// \  -
	for(int i = -radius;i < radius;i++)
	{

		int x = pos.x + i, y = pos.y + i;
		if(x < 0 || y < 0) 
			continue;
		if(x >= len || y >= len) 
			break;
		if(m_board[x][y] != EMPTY) 
			continue;
		Pos pos; pos.x = x; pos.y = y;
		self.comScore[x][y] = scorePoint(pos, R.com);
		self.humScore[x][y] = scorePoint(pos, R.hum);
	}

	// /
	for(int i=-radius;i<radius;i++) {
		int x = pos.x + i, y = pos.y - i;
		if(x < 0 || y < 0) continue;
		if(x >= len || y >= len) continue;
		if(m_board[x][y] != EMPTY) 
			continue;
		Pos pos; pos.x = x; pos.y = y;
		self.comScore[x][y] = scorePoint(pos, R.com);
		self.humScore[x][y] = scorePoint(pos, R.hum);
	}
  //通过遍历来计算最高分
}

bool ChessBoard::hasNeighbor(Pos pos, int distance, int count)
{
	int len = BOARD_SIZE;
	int startX = pos.x - distance;
	int endX = pos.x + distance;
	int startY = pos.y - distance;
	int endY = pos.y + distance;
	for(int i = startX;i <= endX; i++) 
	{
		if(i < 0||i >= len) 
			continue;
		for(int j = startY;j <= endY; j++) 
		{
			if(j < 0||j >= len) 
				continue;
			if(i == pos.x && j == pos.y) 
				continue;
			if(board[i][j] != EMPTY) 
			{
				count --;
				if(count <= 0) 
					return true;
			}
		}
	}
	return false;
}

int ChessBoard::scorePoint(Pos pos,int role)
{
	int result = 0;
	int count = 0, block = 0,
	secondCount = 0;  //另一个方向的count

	int len = BOARD_SIZE;

	count = 1;
	block = 0;
	empty = -1;
	secondCount = 0;  //另一个方向的count

	for(int i = pos.y + 1;true; i++) 
	{
		if(i >= len) 
		{
			block ++;
			break;
		}
		int t = m_board[pos.x][i];
		if(t === EMPTY) 
		{
			if(empty == -1 && i < len-1 && m_board[pos.x][i+1] == role) 
			{
				empty = count;
				continue;
			} 
			else 
			{
				break;
			}
		}
		if(t === role) 
		{
			count ++;
			continue;
		} 
		else 
		{
			block ++;
			break;
		}
	}


	for(int i = pos.y-1;true; i--) 
	{
		if(i < 0) 
		{
			block ++;
			break;
		}
		int t = m_board[pos.x][i];
		if(t === EMPTY) 
		{
			if(empty == -1 && i>0 && m_board[pos.x][i-1] == role) 
			{
				empty = 0;  //注意这里是0，因为是从右往左走的
				continue;
			} 
			else 
			{
				break;
			}
		}
		if(t === role)
		{
			secondCount ++;
			//empty !== -1 && empty ++;  //注意这里，如果左边又多了己方棋子，那么empty的位置就变大了
			if (empty != -1)
				empty++;
			continue;
		} 
		else 
		{
			block ++;
			break;
		}
	}

	count+= secondCount;
	result += countToType(count, block, empty);

	//纵向
	count = 1;
	block = 0;
	empty = -1;
	secondCount = 0;  //另一个方向的count

	for(int i = pos.x + 1;true; i++) 
	{
		if(i >= len) 
		{
			block ++;
			break;
		}
		int t = m_board[i][pos.y];
		if(t === EMPTY) 
		{
			if(empty == -1 && i<len-1 && m_board[i+1][pos.y] == role) 
			{
				empty = count;
				continue;
			} 
			else 
			{
				break;
			}
		}
		if(t === role) 
		{
			count ++;
			continue;
		} 
		else 
		{
			block ++;
			break;
		}
	}

	for(int i= pos.x - 1;true; i--) 
	{
		if(i<0) 
		{
			block ++;
			break;
		}
		int t = m_board[i][pos.y];
		if(t === EMPTY) 
		{
			if(empty == -1 && i > 0 && m_board[i-1][pos.y] == role) 
			{
				empty = 0;
				continue;
			} 
			else 
			{
				break;
			}
		}
		if(t === role) 
		{
			secondCount++;
			//empty !== -1 && empty ++;  //注意这里，如果左边又多了己方棋子，那么empty的位置就变大了
			if (empty != -1)
				empty++;			
			continue;
		} 
		else 
		{
			block ++;
			break;
		}
	}

	count += secondCount;
	result += countToType(count, block, empty);


	// \ ---
	count = 1;
	block = 0;
	empty = -1;
	secondCount = 0;  //另一个方向的count

	for(int i = 1;true; i++) 
	{
		int x = pos.x+i, y = pos.y+i;
		if(x>=len || y>=len) 
		{
			block ++;
			break;
		}
		int t = m_board[x][y];
		if(t === EMPTY) 
		{
			if(empty == -1 && (x<len-1 && y < len-1) && m_board[x+1][y+1] == role) 
			{
				empty = count;
				continue;
			} 
			else 
			{
				break;
			}
		}
		if(t === role) 
		{
			count ++;
			continue;
		} 
		else 
		{
			block ++;
			break;
		}
	}

	for(int i = 1;true;i++) 
	{
		int x = pos.x-i, y = pos.y-i;
		if(x<0||y<0) {
			block ++;
			break;
		}
		int t = m_board[x][y];
		if(t === EMPTY) 
		{
			if(empty == -1 && (x>0 && y>0) && m_board[x-1][y-1] == role) 
			{
				empty = 0;
				continue;
			} 
			else 
			{
				break;
			}
		}
		if(t === role) 
		{
			secondCount ++;
			empty !== -1 && empty ++;  //注意这里，如果左边又多了己方棋子，那么empty的位置就变大了
			continue;
		} 
		else 
		{
			block ++;
			break;
		}
	}

	count+= secondCount;
	result += countToType(count, block, empty);


	// \/
	count = 1;
	block = 0;
	empty = -1;
	secondCount = 0;  //另一个方向的count

	for(int i = 1; true; i++) 
	{
		int x = pos.x+i, y = pos.y-i;
		if(x<0||y<0||x>=len||y>=len) 
		{
			block ++;
			break;
		}
		int t = m_board[x][y];
		if(t === EMPTY) 
		{
			if(empty == -1 && (x<len-1 && y<len-1) && m_board[x+1][y-1] == role) 
			{
				empty = count;
				continue;
			} else {
				break;
			}
		}
		if(t === role) 
		{
			count ++;
			continue;
		} else {
			block ++;
			break;
		}
	}

	for(int i = 1;true; i++) 
	{
		int x = pos.x-i, y = pos.y+i;
		if(x<0||y<0||x>=len||y>=len) 
		{
			block ++;
			break;
		}
		int t = m_board[x][y];
		if(t === EMPTY) 
		{
			if(empty == -1 && (x>0 && y>0) && m_board[x-1][y+1] == role)
			{
				empty = 0;
				continue;
			} else {
				break;
			}
		}
		if(t === role) 
		{
			secondCount++;
			empty !== -1 && empty ++;  //注意这里，如果左边又多了己方棋子，那么empty的位置就变大了
			continue;
		} else {
			block ++;
			break;
		}
	}

	count+= secondCount;
	result += countToType(count, block, empty);


	return typeToScore(result);
}

int ChessBoard::countToType(int count, int block, int empty)
{
	if(empty < 0) 
		empty = 0;

	//没有空位
	if(empty <= 0) 
	{
		if(count >= 5) 
			return FIVE;
		if(block === 0) 
		{
			switch(count) 
			{
				case 1: return ONE;
				case 2: return TWO;
				case 3: return THREE;
				case 4: return FOUR;
			}
		}

		if(block === 1) 
		{
			switch(count) 
			{
				case 1: return BLOCKED_ONE;
				case 2: return BLOCKED_TWO;
				case 3: return BLOCKED_THREE;
				case 4: return BLOCKED_FOUR;
			}
		}

	} else if(empty === 1 || empty == count-1) {
		//第1个是空位
		if(count >= 6) 
		{
			return FIVE;
		}
		if(block === 0) 
		{
			switch(count) 
			{
				case 2: return TWO/2;
				case 3: return THREE;
				case 4: return BLOCKED_FOUR;
				case 5: return FOUR;
			}
		}

		if(block === 1) 
		{
			switch(count) 
			{
				case 2: return BLOCKED_TWO;
				case 3: return BLOCKED_THREE;
				case 4: return BLOCKED_FOUR;
				case 5: return BLOCKED_FOUR;
			}
		}
	} else if(empty === 2 || empty == count-2) {
	//第二个是空位
		if(count >= 7) 
		{
			return FIVE;
		}
		if(block === 0) 
		{
			switch(count) 
			{
				case 3: return THREE;
				case 4: 
				case 5: return BLOCKED_FOUR;
				case 6: return FOUR;
			}
		}

		if(block === 1) 
		{
			switch(count) 
			{
				case 3: return BLOCKED_THREE;
				case 4: return BLOCKED_FOUR;
				case 5: return BLOCKED_FOUR;
				case 6: return FOUR;
			}
		}

		if(block === 2) 
		{
			switch(count) 
			{
				case 4:
				case 5:
				case 6: return BLOCKED_FOUR;
			}
		}
	} else if(empty === 3 || empty == count-3) {
		if(count >= 8) 
		{
			return FIVE;
		}
		if(block === 0) 
		{
			switch(count) 
			{
				case 4:
				case 5: return THREE;
				case 6: return BLOCKED_FOUR;
				case 7: return FOUR;
			}
		}

		if(block === 1) 
		{
			switch(count) 
			{
				case 4:
				case 5:
				case 6: return BLOCKED_FOUR;
				case 7: return FOUR;
			}
		}

		if(block === 2) 
		{
			switch(count) 
			{
				case 4:
				case 5:
				case 6:
				case 7: return BLOCKED_FOUR;
			}
		}
	} else if(empty === 4 || empty == count-4) 
	{
		if(count >= 9) 
		{
			return FIVE;
		}
		if(block === 0) 
		{
			switch(count) 
			{
				case 5:
				case 6:
				case 7:
				case 8: return FOUR;
			}
		}

		if(block === 1) 
		{
			switch(count) 
			{
				case 4:
				case 5:
				case 6:
				case 7: return BLOCKED_FOUR;
				case 8: return FOUR;
			}
		}

		if(block === 2) 
		{
			switch(count) 
			{
				case 5:
				case 6:
				case 7:
				case 8: return BLOCKED_FOUR;
			}
		}
	} else if(empty === 5 || empty == count-5) {
		return FIVE;
	}

	return 0;
}

int ChessBoard::typeToScore(int chessType)
{
	if(chessType < FOUR && chessType >= BLOCKED_FOUR) 
	{
		if(chessType >= BLOCKED_FOUR && chessType < (BLOCKED_FOUR + THREE)) 
		{
			//单独冲四，意义不大
			return THREE;
		} 
		else if(chessType >= BLOCKED_FOUR + THREE && chessType < BLOCKED_FOUR * 2) 
		{
			//冲四活三，比双三分高，相当于自己形成活四
			return FOUR;  
		} else {
			//双冲四 比活四分数也高
			return FOUR * 2;
		}
	}
	return chessType;
}