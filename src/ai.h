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
struct AICache
{
	int deep;
	int score;
};
typedef map<int,AICache> AICacheMap;
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
	int checkmateFast(int role,int deep,bool onlyFour);
	bool checkmateDeeping(int role,int deep);
	void checkmateCache(int deep, bool result);
	bool checkmateMin(int role,int deep);
	bool checkmateMax(int role,int deep);
	bool checkmateFindMin(int role,int score);
	bool checkmateFindMax(int role,int score);
};
#endif
