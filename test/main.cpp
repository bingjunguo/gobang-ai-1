#include <iostream>
#include "../src/ai.h"
using namespace std;


void print_chess(int [][]board)
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; i < BOARD_SIZE; ++i)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	cout<<"com 1 ...hum 2.."<<endl;
	int board[BOARD_SIZE][BOARD_SIZE];
	board[7][7] = 1;
	AI ai;
	int x = -1 , y = -1;
	Pos p;
	while(1)
	{
		cin>>x>>y;
		p.x = x; p.y = y;
		board[p.x][p.y] = 2;
		print_chess(board);
		int x = ai.getChessBoard().isWin();
		if (x > 0)
		{
			cout<<"game over"<<endl;
			break;
		}
		p = ai.set(p);
		board[p.x][p.y] = 1;
		x = ai.getChessBoard().isWin();
		if (x > 0)
		{
			cout<<"game over"<<endl;
			break;
		}
		system("clear");
	}
	return 0;
}
