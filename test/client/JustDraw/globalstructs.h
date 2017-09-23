#ifndef _GLOBAL_STRUCTS_H_
#define _GLOBAL_STRUCTS_H_

#define BOARD_SIZE 15   //棋盘的长度

#define  SEARCH_DEEP 6  //search deep 搜索深度
#define  DEEP_DECREASE 0.8 //deepDecrease按搜索深度递减分数，为了让短路径的结果比深路劲的分数高
#define  COUNTLIMIT 8 //countLimit gen函数返回的节点数量上限，超过之后将会按照分数进行截断
#define  CHECKMATE_DEEP  5 //checkmateDeep算杀深度
#define  CACHE false  //是否使用效率不高的置换表

/*
 * 棋型表示
 * 用一个6位数表示棋型，从高位到低位分别表示
 * 连五，活四，眠四，活三，活二/眠三，活一/眠二, 眠一
 */
enum SOCORE
{
	ONE = 10,
	TWO = 100,
	THREE = 1000,
	FOUR = 100000,
	FIVE = 1000000,
	BLOCKED_ONE = 1,
	BLOCKED_TWO = 10,
	BLOCKED_THREE = 100,
	BLOCKED_FOUR = 10000
};
enum ROLE
{
	EMPTY = 0,
	HUM = 1,
	COM = 2,
};

inline int reverse(int role)
{
   return role == HUM ? COM : HUM;
}

typedef struct Position
{
	int x;
	int y;
}Pos;


#endif
