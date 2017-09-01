#ifndef _ZOBRIST_H_
#define _ZOBRIST_H_

#include "globalstructs.h"
#include <time.h> 
#include <stdlib.h>
#include <math.h>

class Zobrist
{
	int m_com[BOARD_SIZE*BOARD_SIZE];
	int m_hum[BOARD_SIZE*BOARD_SIZE];
	int m_code;
public:
	Zobrist()
	{
		for(int i=0;i<BOARD_SIZE*BOARD_SIZE;i++) {
    		this->m_com[i] = this->_rand();
    		this->m_hum[i] = this->_rand();
  		}
  		this->m_code = this->_rand();
	}
	~Zobrist(){};
	int _rand()
	{
		//return Math.floor(Math.random() * 1000000000);  //再多一位就溢出了。。
		//这里需要改一下
		srand((unsigned int)time(NULL));     //每次执行种子不同，生成不同的随机数
		return (int)floor(1000000000 * (double)rand() / RAND_MAX);
	}
	int go(int x, int y, int role) {
		int index = BOARD_SIZE * x + y;
		this->m_code ^= (role == COM ? this->m_com[index] : this->m_hum[index]);
		return this->m_code;

	}
	int getCode()
	{
		return this->m_code;
	}
	
};

#endif
