#include "ai.h"
#include "aimath.h"
#include <iostream>
#include <math.h>

using namespace std; 

AI::AI()
{
	total = 0; steps = 0;
	cacheCount = 0;cacheGet = 0; 
}

AI::~AI()
{

}

Pos AI::set(Pos pos)
{
	m_chessBoard.put(pos, HUM);
	Pos p = deppingFind(SEARCH_DEEP);

	m_chessBoard.put(p, COM);
	return p;
}
bool AI::back()
{
	if(m_chessBoard.back())
		return true;
	return false;
}


Pos AI::deppingFind(int deep)
{
	//迭代加深
	//注意这里不要比较分数的大小，因为深度越低算出来的分数越不靠谱，所以不能比较大小，而是是最高层的搜索分数为准
	DeeppingRet result;
	for(int i=2;i <= deep; i += 2) 
	{
		result = maxmin(i);
		if(AIMath::greatOrEqualThan(result.score, FOUR)) 
			return result.pos;
	}
	return result.pos;
}

DeeppingRet AI::maxmin(int deep)
{
	int best = MIN;
	ListPos points = m_chessBoard.gen();
	ListPos bestPoints;

	reset();

	for(int i=0; i < points.size();i++) 
	{
		Pos p = points.front();
		points.pop_front();
		m_chessBoard.put(p, COM);
		int v = -max(deep-1, -MAX, -best, HUM);

		//边缘棋子的话，要把分数打折，避免电脑总喜欢往边上走
		if(p.x<3 || p.x > 11 || p.y < 3 || p.y > 11) 
		{
		  	v = 0.5 * v;
		}
		cout<<"v = "<<v<<" pos["<<p.x<<","<<p.y<<"]"<<endl;
		//如果跟之前的一个好，则把当前位子加入待选位子
		if(AIMath::equal(v, best)) 
		{
		  	bestPoints.push_back(p);
		}
		//找到一个更好的分，就把以前存的位子全部清除
		if(AIMath::greatThan(v, best)) 
		{
			best = v;
			bestPoints.clear();
			bestPoints.push_back(p);
		}
		m_chessBoard.remove(p);
	}
	//cout<<"score:"<<best<<"  points :bestPoints"<<endl
	srand((unsigned int)time(NULL));

	//Pos p = bestPoints[floor(bestPoints.size() * (double)rand() / RAND_MAX)];
	int rd = floor(bestPoints.size() * (double)rand() / RAND_MAX);
	if(rd == bestPoints.size())
		rd = rd - 1;
	int i = 0;
	Pos p;
	for(ListPos::iterator it = bestPoints.begin(); it != bestPoints.end(); ++it)
	{
		if(i == rd)
		{
			p = *it;
			break;
		}
		i++;
	}
	DeeppingRet result;
	result.score = best;
	result.pos = p;

	steps ++;
	total += count;
	cout<<"搜索节点数:"<< count<< ",AB剪枝次数:"<<ABcut << ", PV剪枝次数:" << PVcut << ", 缓存命中:" << (cacheGet / cacheCount) + ","
		<< cacheGet << "/" << cacheCount<<endl;
	 //注意，减掉的节点数实际远远不止 ABcut 个，因为减掉的节点的子节点都没算进去。实际 4W个节点的时候，剪掉了大概 16W个节点
	cout<<"当前统计：总共"<< steps << "步, " << total << "个节点, 平均每一步" << floor(total/steps) <<"个节点"<<endl;

	return result;
}

int AI::max(int deep,int alpha,int beta,int role)
{
	if(CACHE) 
	{
		if(m_cache.count(m_chessBoard.getZobrist().getCode()) > 0)
		{
			AICache c = m_cache[m_chessBoard.getZobrist().getCode()];
			if(c.deep >= deep) 
			{
				cacheGet ++;
				return c.score;
			}
		}
	}

	int v = m_chessBoard.evaluate(role);
	count ++;
	if(deep <= 0 || AIMath::greatOrEqualThan(v, FIVE)) {
		return v;
	}

	int best = MIN;
	ListPos points = m_chessBoard.gen();

	for(int i = 0;i < points.size();i++) 
	{
		Pos p = points.front();
		points.pop_front();
		m_chessBoard.put(p, role);

		int v = - max(deep-1, -beta, -1 *( best > alpha ? best : alpha), reverse(role)) * DEEP_DECREASE;
		m_chessBoard.remove(p);

		if(AIMath::greatThan(v, best)) 
		{
			best = v;
		}
		if(AIMath::greatOrEqualThan(v, beta)) 		//AB 剪枝
		{ 

			ABcut ++;
			cacheMaxmin(deep, v);
			return v;
		}
	}
	if((deep == 2 || deep == 3 ) && AIMath::littleThan(best, THREE*2) && AIMath::greatThan(best, THREE * -1)) 
	{
		int mate = checkmateFast(role, CHECKMATE_DEEP,false);
		if(mate > 0) 
		{
			//int score = mate.score * Math.pow(0.8, mate.length) * (role === R.com ? 1 : -1);
			int score = mate * 0.8 * (role == COM ? 1 : -1);
			cacheMaxmin(deep, score);
			return score;
		}
	}
	cacheMaxmin(deep, best);

	return best;
}

void AI::cacheMaxmin(int deep, int score)
{
	if(!CACHE) 
		return;
	AICache cache;
	cache.deep = deep;
	cache.score = score;
  	m_cache[m_chessBoard.getZobrist().getCode()] = cache;
    cacheCount ++;
}
