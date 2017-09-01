#include "ai.h"
#include "aimath.h"
#include <iostream>
#include <math.h>

using namespace std; 

bool compareDeeppingRet(DeeppingRet a,DeeppingRet b)
{
	if (a.score < b.score)
		return true;
	return false;
}

AI::AI()
{
	total = 0; steps = 0;
	cacheCount = 0;cacheGet = 0; 

	checkmateNodeCount = 0;
	CHECKMATE_MAX_SCORE = THREE;
	CHECKMATE_MIN_SCORE = FOUR;
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
		CheckMateRet cr = checkmateFast(role, CHECKMATE_DEEP,false);
		if(cr.score > 0) 
		{
			//int score = mate.score * Math.pow(0.8, mate.length) * (role === R.com ? 1 : -1);
			int score = (int)cr.score * pow(0.8, cr.length) * (role == COM ? 1 : -1);
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

int AI::checkmateMin(int role,int deep)
{
	checkmateNodeCount ++;
	int w = m_chessBoard.isWin();
	if(w == role) 
		return 0;
	if(w == reverse(role)) 
		return -1;
	if(deep <= 0) 
		return -1;
	if(CACHE) 
	{
		if(m_cacheCheckMate.count(m_chessBoard.getZobrist().getCode()) > 0)
		{
			CheckMateCache c = m_cacheCheckMate[m_chessBoard.getZobrist().getCode()];
			if(c.deep >= deep || c.length >= 0) {
				return c.length;
			}
		}
	}
	DeeppingRetList points = checkmateFindMin(reverse(role), CHECKMATE_MIN_SCORE);
	if(points.size() == 0) 
		return -1;
	if(points.size() > 0 )
	{
		if(points.front().score >= FOUR) 
			return -1; //为了减少一层搜索，活四就行了。
	}

	list<int> cands;
	int currentRole = reverse(role);
	for(int i = 0;i < points.size(); i++) 
	{
		DeeppingRet dr = points.front();
		points.pop_front();
		Pos p = dr.pos;

		m_chessBoard.put(p, currentRole);
		m_chessBoard.getZobrist().go(p.x, p.y, currentRole);

		int m = checkmateMax(role, deep - 1);

		m_chessBoard.getZobrist().go(p.x, p.y, currentRole);
		m_chessBoard.put(p, EMPTY);	

		if(m > 0) {
			m++;
			cands.push_back(m);
			cacheCheckmate(deep, m);
			continue;
		} else if(m == 0) {  //相当于ture 小于0相当于false
			cacheCheckmate(deep, -1);
			return -1; //只要有一种能防守住
		}
	}
	srand((unsigned int)time(NULL));

	//int result = cands[Math.floor(cands.length*Math.random())];  //无法防守住
	int rd = floor(cands.size() * (double)rand() / RAND_MAX);
	if(rd == cands.size())
		rd = rd - 1;
	int i = 0;
	int result = 0;
	for(list<int>::iterator it = cands.begin(); it != cands.end(); ++it)
	{
		if(i == rd)
		{
			result = *it;
			break;
		}
		i++;
	}

	cacheCheckmate(deep, result);
	return result;
}
int AI::checkmateMax(int role,int deep)
{
	checkmateNodeCount ++;
	if(deep <= 0) 
		return false;

	if(CACHE) 
	{
		if(m_cacheCheckMate.count(m_chessBoard.getZobrist().getCode()) > 0)
		{
			CheckMateCache c = m_cacheCheckMate[m_chessBoard.getZobrist().getCode()];
			if(c.deep >= deep || c.length >= 0) {
				return c.length;
			}
		}
	}

	DeeppingRetList points = checkmateFindMax(role, CHECKMATE_MAX_SCORE);
	if(points.size() > 0 )
	{
		if(points.front().score >= FOUR) 
			return 1; //为了减少一层搜索，活四就行了。
	}
	
	if(points.size() == 0) 
		return -1;
	for(int i = 0;i < points.size();i++) 
	{
		DeeppingRet dr = points.front();
		points.pop_front();
		Pos p = dr.pos;

		m_chessBoard.put(p, role);
		m_chessBoard.getZobrist().go(p.x, p.y, role);

		int m = checkmateMin(role, deep - 1);

		m_chessBoard.getZobrist().go(p.x, p.y, role);
		m_chessBoard.put(p, EMPTY);
		if(m > 0) 
		{
			m++; 
			cacheCheckmate(deep, m);
			return m;
		}else if(m == 0) {  //相当于ture 小于0相当于false 
			cacheCheckmate(deep, 1);
			return 1;
		}
		
	}
	cacheCheckmate(deep, -1);
	return -1;
}
DeeppingRetList AI::checkmateFindMin(int role,int score)
{
	DeeppingRetList result;
	DeeppingRetList fives;
	DeeppingRetList fours;
	for(int i = 0;i < BOARD_SIZE;i++) 
	{
		for(int j = 0;j < BOARD_SIZE;j++) 
		{
			Pos p; p.x = i; p.y = j;
			if(m_chessBoard.getPosRole(p) == EMPTY) 
			{
				if(m_chessBoard.hasNeighbor(p, 2, 1))  //必须是有邻居的才行
				{
					DeeppingRet dr;
					dr.pos = p;
					int s1 = m_chessBoard.scorePoint(p, role);
					int s2 = m_chessBoard.scorePoint(p, reverse(role));
	  				if(s1 >= FIVE) 
	  				{
	  					dr.score = - s1;
	  					result.clear();
	  					result.push_back(dr);
	    				return result;
	  				} 
	  				if(s1 >= FOUR) 
	  				{
	   					dr.score = -s1;
	    				fours.push_front(dr);
	    				continue;
	  				}
					if(s2 >= FIVE) 
					{
						dr.score = s2;
						fives.push_back(dr);
						continue;
					} 
					if(s2 >= FOUR) 
					{
						dr.score = s2;
						fours.push_back(dr);
						continue;
					}

					if(s1 >= score || s2 >= score) {
						dr.score = s1;
						result.push_back(dr);
					}
				}
			}
		}
	}
	if(fives.size() > 0)
	{
		result.clear();
	  	result.push_back(fives.front());
		return result;
	}
	if(fours.size() > 0) 
	{	
		result.clear();
	  	result.push_back(fours.front());
		return result;
	}
	//注意对结果进行排序
	result.sort(compareDeeppingRet);
	return result;
}
DeeppingRetList AI::checkmateFindMax(int role,int score)
{
	DeeppingRetList result;
	for(int i = 0;i < BOARD_SIZE;i++) 
	{
		for(int j = 0;j < BOARD_SIZE;j++) 
		{
			Pos p; p.x = i; p.y = j;
			if(m_chessBoard.getPosRole(p) == EMPTY) 
			{
				if(m_chessBoard.hasNeighbor(p, 2, 1))//必须是有邻居的才行
				{ 					
					int s = m_chessBoard.scorePoint(p, role);
					DeeppingRet dr;
					dr.pos = p;
					dr.score = s;
					if(s >= FIVE) 
					{
						result.clear();
						result.push_back(dr);
						return result;
					}
					if(s >= score) 
					{
						result.push_back(dr);
					}
				}
			}
		}
	}
	//注意对结果进行排序
	result.sort(compareDeeppingRet);
	return result;
}

void AI::cacheCheckmate(int deep, int length)
{
 	if(!CACHE) 
  		return;
  	CheckMateCache cc;
  	cc.deep = deep;
  	cc.length = length;
  	m_cacheCheckMate[m_chessBoard.getZobrist().getCode()] = cc;
  	return;
}
CheckMateRet AI::checkmateFast(int role,int deep,bool onlyFour)
{
	CheckMateRet cr;
	cr.score = 0;
	cr.length = 0;

	if(deep <= 0) 
		return cr;

	//先计算冲四赢的
	CHECKMATE_MAX_SCORE = FOUR;
	CHECKMATE_MIN_SCORE = FIVE;

	int result = checkmateDeeping(role, deep);
	if(result >= 0) 
	{
		cr.score = FOUR;
		cr.length = result;
		return cr;
	}

	if(onlyFour) 
		return cr;  //只计算冲四

	//再计算通过 活三 赢的；
	CHECKMATE_MAX_SCORE = THREE;
	CHECKMATE_MIN_SCORE = FOUR;
	result = checkmateDeeping(role, deep);
	if(result >= 0) 
	{
		cr.score = THREE*2; //虽然不如活四分数高，但是还是比活三分数要高的
		cr.length = result;
	}
	return cr;
}
int AI::checkmateDeeping(int role,int deep)
{
	checkmateNodeCount = 0;
	int result = -1;
	for(int i = 1;i <= deep;i++) 
	{
		result = checkmateMax( role, i);
		if(result >= 0) 
			break; //找到一个就行
	}
	if(result >= 0) 
		cout<<"算杀成功..."<<checkmateNodeCount << "个节点" <<endl;
	return result;
}
