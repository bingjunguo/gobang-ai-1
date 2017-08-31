#ifndef _AI_H_
#define _AI_H_

#include "chessboard.h"

#define MAX FIVE*10
#define MIN -1*MAX


struct DeeppingRet
{
	Pos pos;
	int score;
};
bool compareDeeppingRet(DeeppingRet a,DeeppingRet b)
{
	if (a.score < b.score)
		return true;
	return false;
}
struct AICache
{
	int deep;
	int score;
};
struct CheckMateCache
{
	int deep;
	int length; //节点的数量
};
struct CheckMateRet
{
	int score;
	int length; //节点的数量
};
typedef map<int,AICache> AICacheMap;
typedef map<int,CheckMateCache> CheckMateCacheMap;
typedef list<DeeppingRet> DeeppingRetList;
class AI
{
	ChessBoard m_chessBoard;


	//统计数据 用于maxmin max reset设置为零 
	int total;  //总节点数
    int steps;  //总步数
    int count;  //每次思考的节点数
    int PVcut;
    int ABcut;  //AB剪枝次数
    int cacheCount; //zobrist缓存节点数
    int cacheGet; //zobrist缓存命中数量

  	AICacheMap m_cache;  //当前深度zobrist缓存 <deep ,score>

  	//算杀数据统计
  	CheckMateCacheMap m_cacheCheckMate;
	int checkmateNodeCount;
	int CHECKMATE_MAX_SCORE;
	int CHECKMATE_MIN_SCORE;

public:
	AI();
	~AI();
	Pos set(Pos pos);
	bool back();
	int reset()
	{	
    	count = 0; PVcut = 0;
    	ABcut = 0; 
	}


	Pos deppingFind(int deep); //查找最棒位置函数起始点
	/*
	 * max min search
	 * white is max, black is min
	 */
	DeeppingRet maxmin(int deep);
	int max(int deep,int alpha,int beta,int role);
	void cacheMaxmin(int deep, int score);  //对于maxmin极大极小值搜索算法的缓存
	/*
	 * 算杀
	 * 算杀的原理和极大极小值搜索是一样的
	 * 不过算杀只考虑冲四活三这类对方必须防守的棋
	 * 因此算杀的复杂度虽然是 M^N ，但是底数M特别小，可以算到16步以上的杀棋。
	 */

	/*
	 * 基本思路
	 * 电脑有活三或者冲四，认为是玩家必须防守的
	 * 玩家防守的时候却不一定根据电脑的棋来走，而是选择走自己最好的棋，比如有可能是自己选择冲四
	 */
	CheckMateRet checkmateFast(int role,int deep,bool onlyFour);
	int checkmateDeeping(int role,int deep);
	int checkmateMin(int role,int deep);
	int checkmateMax(int role,int deep);
	DeeppingRetList checkmateFindMin(int role,int score);
	DeeppingRetList checkmateFindMax(int role,int score);
	void cacheCheckmate(int deep, int length);  //对于算杀算法的缓存
};
#endif
