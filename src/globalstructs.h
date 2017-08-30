#ifndef _GLOBAL_STRUCTS_H_
#define _GLOBAL_STRUCTS_H_

#define BOARD_SIZE 15   //棋盘的长度

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
}ROLE;

inline bool reverse(int role)
{
   return role == ROLE.HUM ? ROLE.COM : ROLE.HUM;
}

typedef struct Position
{
	int x;
	int y;
}Pos;


#endif