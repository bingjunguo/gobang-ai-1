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

	//ͳ������ ����maxmin max reset����Ϊ�� 
	int total;  //�ܽڵ���
    int steps;  //�ܲ���
    int count;  //ÿ��˼���Ľڵ���
    int PVcut;
    int ABcut;  //AB��֦����
    int cacheCount; //zobrist����ڵ���
    int cacheGet; //zobrist������������

    AICacheMap m_cache;  //��ǰ���zobrist���� <deep ,score>

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


	Pos deppingFind(int deep); //�������λ�ú�����ʼ��
	/*
	 * max min search
	 * white is max, black is min
	 */
	DeeppingRet maxmin(int deep);
	int max(int deep,int alpha,int beta,int role);
	void cacheMaxmin(int deep, int score);  //����maxmin����Сֵ�����㷨�Ļ���

	/*
	 * ��ɱ
	 * ��ɱ��ԭ��ͼ���Сֵ������һ����
	 * ������ɱֻ���ǳ��Ļ�������Է�������ص���
	 * �����ɱ�ĸ��Ӷ���Ȼ�� M^N �����ǵ���M�ر�С�������㵽16�����ϵ�ɱ�塣
	 */

	/*
	 * ����˼·
	 * �����л������߳��ģ���Ϊ����ұ�����ص�
	 * ��ҷ��ص�ʱ��ȴ��һ�����ݵ��Ե������ߣ�����ѡ�����Լ���õ��壬�����п������Լ�ѡ�����
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
