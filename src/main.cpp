#include <iostream>
#include "ai.h"
//#include "aimath.h"
using namespace std;



void print_chess(int board[15][15])
{
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	//cout<<AIMath::equal(-40,-40)<<endl;
	//cout<<AIMath::equal(40,40)<<endl;

	cout<<"com 1 ...hum 2.."<<endl;
	int board[15][15];
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			board[i][j] = 0;
		}
	}
	board[7][7] = 1;
	print_chess(board);

	AI ai;
	int x = -1 , y = -1;
	Pos p;
	cout<<"COM:[7,7]"<<endl;
	while(1)
	{
		cin>>x>>y;
		p.x = x; p.y = y;
		cout<<"You:["<<p.x<<","<<p.y<<"]"<<endl;
		board[p.x][p.y] = 2;
		print_chess(board);
		int x = ai.getChessBoard().isWin();
		cout<<"x="<<x<<endl;
		if (x > 0)
		{
			cout<<"game over"<<endl;
			break;
		}
		p = ai.set(p);
		cout<<"COM:["<<p.x<<","<<p.y<<"]"<<endl;
		if(p.x == 1 || p.y == 1)
		{
			cout<<"game error"<<endl;
			break;
		}
		board[p.x][p.y] = 1;
		print_chess(board);
		x = ai.getChessBoard().isWin();
		if (x > 0)
		{
			cout<<"game over"<<endl;
			break;
		}
		//system("clear");
	}
	//system("pause");
	return 0;
}