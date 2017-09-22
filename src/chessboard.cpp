#include "chessboard.h"

ChessBoard::ChessBoard()
{
	_initChessBoard();
	//默认黑先走
	Pos pos;
	pos.x = 7; pos.y = 7;

	put(pos, COM);
	m_zobrist.go(pos.x, pos.y, COM);

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
	m_comMaxScore = - FIVE;
	m_humMaxScore = - FIVE;

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

bool ChessBoard::put(Pos p, int role)
{
	if (p.x > BOARD_SIZE || p.y > BOARD_SIZE)
		return false;
	if (m_board[p.x][p.y] != EMPTY && role != EMPTY)
		return false;
	m_board[p.x][p.y] = role;
	m_zobrist.go(p.x, p.y, role);
	updateScore(p);
	m_steps.push_back(p);
	return true;
}
bool ChessBoard::remove(Pos p)
{
	int role = m_board[p.x][p.y];
	m_zobrist.go(p.x, p.y, role);
	m_board[p.x][p.y] = EMPTY;
	updateScore(p);
	return true;
}
bool ChessBoard::back()
{
	//当然要退两步
	if(m_steps.size() < 2) 
		return false;
	Pos pos = m_steps.back();
	m_steps.pop_back();
	m_zobrist.go(pos.x, pos.y, m_board[pos.x][pos.y]);
	m_board[pos.x][pos.y] = EMPTY;
	updateScore(pos);
	
	pos = m_steps.back();
	m_steps.pop_back();
	m_zobrist.go(pos.x, pos.y, m_board[pos.x][pos.y]);
	m_board[pos.x][pos.y] = EMPTY;
	updateScore(pos);

	return true;
}
int ChessBoard::isWin()
{
	for(int i = 0;i < BOARD_SIZE; i++) 
	{
		for(int j = 0;j < BOARD_SIZE; j++) 
		{
			int role = m_board[i][j];
			if(role != EMPTY) 
			{
				Pos pos; pos.x = i; pos.y = j;
				int r = isFive(pos, role);
				if(r > 0) 
					return role;
			}
		}
	}
	return 0;
}
void ChessBoard::updateScore(Pos pos)
{
	int radius = 8;
	int len = BOARD_SIZE;

	for(int i = -radius;i < radius;i++) 
	{
		int x = pos.x, y = pos.y+i;
		if(y < 0) continue;
		if(y >= len) break;
		if(m_board[x][y] != EMPTY) 
			continue;
		Pos pos; pos.x = x; pos.y = y;
		m_comScore[x][y] = scorePoint(pos, COM);
		m_humScore[x][y] = scorePoint(pos, HUM);
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
		m_comScore[x][y] = scorePoint(pos, COM);
		m_humScore[x][y] = scorePoint(pos, HUM);
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
		m_comScore[x][y] = scorePoint(pos, COM);
		m_humScore[x][y] = scorePoint(pos, HUM);
	}

	// /
	for(int i=-radius;i<radius;i++) {
		int x = pos.x + i, y = pos.y - i;
		if(x < 0 || y < 0) continue;
		if(x >= len || y >= len) continue;
		if(m_board[x][y] != EMPTY) 
			continue;
		Pos pos; pos.x = x; pos.y = y;
		m_comScore[x][y] = scorePoint(pos, COM);
		m_humScore[x][y] = scorePoint(pos, HUM);
	}
  //通过遍历来计算最高分
}
int ChessBoard::evaluate(int role)
{
	//这里加了缓存，但是并没有提升速度
	if(m_evaluateCache[m_zobrist.getCode()]) 
		return m_evaluateCache[m_zobrist.getCode()];

	m_comMaxScore = - FIVE;
	m_humMaxScore = - FIVE;

	//遍历出最高分，开销不大
	for(int i = 0;i < BOARD_SIZE; i++) 
	{
		for(int j = 0;j < BOARD_SIZE; j++) 
		{
			if(m_board[i][j] == EMPTY) 
			{
				m_comMaxScore = MAX_AB(m_comScore[i][j], m_comMaxScore);
				m_humMaxScore = MAX_AB(m_humScore[i][j], m_humMaxScore);
			}
		}
	}
	int result = (role == COM ? 1 : -1) * (m_comMaxScore - m_humMaxScore);
	m_evaluateCache[m_zobrist.getCode()] = result;

	return result;
}
ListPos ChessBoard::gen()
{
	ListPos fives;
	ListPos fours;
	ListPos blockedfours;
	ListPos twothrees;
	ListPos threes;
	ListPos twos;
	ListPos neighbors;

	ListPos ret;

	for(int i = 0;i < BOARD_SIZE; i++) 
	{
		for(int j = 0;j < BOARD_SIZE; j++) 
		{
			if(m_board[i][j] == EMPTY) 
			{
				Pos pos;pos.x = i;pos.y = j;
				if(hasNeighbor(pos, 2, 2)) //必须是有邻居的才行
				{ 
					int scoreHum = m_humScore[i][j];
					int scoreCom = m_comScore[i][j];

					if(scoreCom >= FIVE) 
					{//先看电脑能不能连成5
						ret.clear();
						ret.push_back(pos);
						return ret;
					} else if(scoreHum >= FIVE) {//再看玩家能不能连成5
					//别急着返回，因为遍历还没完成，说不定电脑自己能成五。
						fives.push_back(pos);
					} else if(scoreCom >= FOUR) {
						fours.push_front(pos);
					} else if(scoreHum >= FOUR) {
						fours.push_back(pos);
					} else if(scoreCom >= BLOCKED_FOUR) {
						blockedfours.push_front(pos);
					} else if(scoreHum >= BLOCKED_FOUR) {
						blockedfours.push_back(pos);
					} else if(scoreCom >= 2 * THREE) {
						//能成双三也行
						twothrees.push_front(pos);
					} else if(scoreHum >= 2 * THREE) {
						twothrees.push_back(pos);
					} else if(scoreCom >= THREE) {
						threes.push_front(pos);
					} else if(scoreHum >= THREE) {
						threes.push_back(pos);
					} else if(scoreCom >= TWO) {
						twos.push_front(pos);
					} else if(scoreHum >= TWO) {
						twos.push_back(pos);
					} else {
						neighbors.push_back(pos);
					}
				}
			}
		}
	}

	//如果成五，是必杀棋，直接返回
	if(fives.size() > 0) 
	{
		ret.clear();
		ret.push_back(fives.front());
		return ret;
	}

	//注意一个活三可以有两个位置形成活四，但是不能只考虑其中一个，要从多个中考虑更好的选择
	//所以不能碰到活四就返回第一个，应该需要考虑多个
	if(fours.size() > 0) 
	{	
		return fours;
	}
	//冲四活三
	if(blockedfours.size() > 0) 
	{
		ret.clear();
		ret.push_back(blockedfours.front());
		return ret;
	}
	//双三很特殊，因为能形成双三的不一定比一个活三强
	if(twothrees.size() > 0) 
	{
		for (ListPos::iterator  i = threes.begin(); i != threes.end(); ++i)
		{
			twothrees.push_back(*i);
		}
		return twothrees;
	}

	if(twos.size() > 0) 
	{
		for (ListPos::iterator  i = twos.begin(); i != twos.end(); ++i)
		{
			threes.push_back(*i);
		}
	}
	if(neighbors.size() > 0) 
	{
		for (ListPos::iterator  i = neighbors.begin(); i != neighbors.end(); ++i)
		{
			threes.push_back(*i);
		}
	}

	if(threes.size() > COUNTLIMIT) 
	{
		int count = 0;
		for (ListPos::iterator  i = threes.begin(); i != threes.end(); ++i)
		{
			ret.push_back(*i);
			count++;
			if (count >= COUNTLIMIT)
			{
				break;
			}
		}
	}
	else
	{
		return threes;
	}

	return ret;
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
			if(m_board[i][j] != EMPTY) 
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
	int count = 0, block = 0,empty = 0,secondCount = 0;  //另一个方向的count
	
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
		if(t == EMPTY) 
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
		if(t == role) 
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
		if(t == EMPTY) 
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
		if(t == role)
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
		if(t == EMPTY) 
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
		if(t == role) 
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
		if(t == EMPTY) 
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
		if(t == role) 
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
		if(t == EMPTY) 
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
		if(t == role) 
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
		if(t == EMPTY) 
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
		if(t == role) 
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
		if(t == EMPTY) 
		{
			if(empty == -1 && (x<len-1 && y<len-1) && m_board[x+1][y-1] == role) 
			{
				empty = count;
				continue;
			} else {
				break;
			}
		}
		if(t == role) 
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
		if(t == EMPTY) 
		{
			if(empty == -1 && (x>0 && y>0) && m_board[x-1][y+1] == role)
			{
				empty = 0;
				continue;
			} else {
				break;
			}
		}
		if(t == role) 
		{
			secondCount++;
			//empty != -1 && empty ++;  //注意这里，如果左边又多了己方棋子，那么empty的位置就变大了
			if (empty != -1)
				empty++;			
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
		if(block == 0) 
		{
			switch(count) 
			{
				case 1: return ONE;
				case 2: return TWO;
				case 3: return THREE;
				case 4: return FOUR;
			}
		}

		if(block == 1) 
		{
			switch(count) 
			{
				case 1: return BLOCKED_ONE;
				case 2: return BLOCKED_TWO;
				case 3: return BLOCKED_THREE;
				case 4: return BLOCKED_FOUR;
			}
		}

	} else if(empty == 1 || empty == count-1) {
		//第1个是空位
		if(count >= 6) 
		{
			return FIVE;
		}
		if(block == 0) 
		{
			switch(count) 
			{
				case 2: return TWO/2;
				case 3: return THREE;
				case 4: return BLOCKED_FOUR;
				case 5: return FOUR;
			}
		}

		if(block == 1) 
		{
			switch(count) 
			{
				case 2: return BLOCKED_TWO;
				case 3: return BLOCKED_THREE;
				case 4: return BLOCKED_FOUR;
				case 5: return BLOCKED_FOUR;
			}
		}
	} else if(empty == 2 || empty == count-2) {
	//第二个是空位
		if(count >= 7) 
		{
			return FIVE;
		}
		if(block == 0) 
		{
			switch(count) 
			{
				case 3: return THREE;
				case 4: return BLOCKED_FOUR;
				case 5: return BLOCKED_FOUR;
				case 6: return FOUR;
			}
		}

		if(block == 1) 
		{
			switch(count) 
			{
				case 3: return BLOCKED_THREE;
				case 4: return BLOCKED_FOUR;
				case 5: return BLOCKED_FOUR;
				case 6: return FOUR;
			}
		}

		if(block == 2) 
		{
			switch(count) 
			{
				case 4: return BLOCKED_FOUR;
				case 5: return BLOCKED_FOUR;
				case 6: return BLOCKED_FOUR;
			}
		}
	} else if(empty == 3 || empty == count-3) {
		if(count >= 8) 
		{
			return FIVE;
		}
		if(block == 0) 
		{
			switch(count) 
			{
				case 4: return THREE;
				case 5: return THREE;
				case 6: return BLOCKED_FOUR;
				case 7: return FOUR;
			}
		}

		if(block == 1) 
		{
			switch(count) 
			{
				case 4: return BLOCKED_FOUR;
				case 5: return BLOCKED_FOUR;
				case 6: return BLOCKED_FOUR;
				case 7: return FOUR;
			}
		}

		if(block == 2) 
		{
			switch(count) 
			{
				case 4: return BLOCKED_FOUR;
				case 5: return BLOCKED_FOUR;
				case 6: return BLOCKED_FOUR;
				case 7: return BLOCKED_FOUR;
			}
		}
	} else if(empty == 4 || empty == count-4) 
	{
		if(count >= 9) 
		{
			return FIVE;
		}
		if(block == 0) 
		{
			switch(count) 
			{
				case 5: return FOUR;
				case 6: return FOUR;
				case 7: return FOUR;
				case 8: return FOUR;
			}
		}

		if(block == 1) 
		{
			switch(count) 
			{
				case 4: return BLOCKED_FOUR;
				case 5: return BLOCKED_FOUR;
				case 6: return BLOCKED_FOUR;
				case 7: return BLOCKED_FOUR;
				case 8: return FOUR;
			}
		}

		if(block == 2) 
		{
			switch(count) 
			{
				case 5: return BLOCKED_FOUR;
				case 6: return BLOCKED_FOUR;
				case 7: return BLOCKED_FOUR;
				case 8: return BLOCKED_FOUR;
			}
		}
	} else if(empty == 5 || empty == count-5) {
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
bool ChessBoard::isFive(Pos pos,int role)
{
	int len = BOARD_SIZE;
	int count = 1;

	for(int i = pos.y + 1;true;i++) 
	{
		if(i >= len) 
			break;
		int t = m_board[pos.x][i];
		if(t != role) 
			break;
		count ++;
	}


	for(int i = pos.y - 1;true;i--) 
	{
		if(i < 0) 
			break;
		int t = m_board[pos.x][i];
		if(t != role) 
			break;
			count ++;
	}

	if(count >= 5) 
		return true;

	//纵向
	count = 1;

	for(int i = pos.x + 1;true;i++) 
	{
		if(i >= len) 
		{
			break;
		}
		int t = m_board[i][pos.y];
		if(t != role) 
			break;
		count ++;
	}

	for(int i = pos.x - 1;true;i--)
	{
		if(i < 0) 
		{
			break;
		}
		int t = m_board[i][pos.y];
		if(t != role) 
			break;
		count ++;
	}

	if(count >= 5) 
		return true;

	// \\-
	count = 1;

	for(int i = 1;true;i++) 
	{
		int x = pos.x + i, y = pos.y + i;
		if(x >= len || y >= len) 
		{
			break;
		}
		int t = m_board[x][y];
		if(t != role)
		 break;

		count ++;
	}

	for(int i = 1;true;i++) 
	{
		int x = pos.x-i, y = pos.y-i;
		if(x < 0|| y <0) 
		{
			break;
		}
		int t = m_board[x][y];
		if(t != role) 
			break;
		count ++;
	}

	if(count >= 5) return true;

	// \/
	count = 1;

	for(int i = 1; true;i++) 
	{
		int x = pos.x + i, y = pos.y - i;
		if(x < 0||y < 0||x >= len||y >= len) 
		{
			break;
		}
		int t = m_board[x][y];
		if(t != role) 
			break;
		count ++;
	}

	for(int i = 1;true;i++) 
	{
		int x = pos.x - i, y = pos.y + i;
		if(x < 0||y < 0||x >= len||y >= len) 
		{
			break;
		}
		int t = m_board[x][y];
		if(t != role) 
			break;
		count ++;
	}

	if(count >= 5) 
		return true;

	return false;
}
