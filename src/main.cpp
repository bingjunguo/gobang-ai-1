#include <iostream>
#include "ai.h"
using namespace std;

int board[15][15];
void print_chess()
{
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; i < 15; ++j)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	cout<<"com 1 ...hum 2.."<<endl;
	/*for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; i < 15; ++j)
		{
			board[i][j] = 0;
		}
	}*/
	//board[7][7] = 1;
	//print_chess();

	AI ai;
	int x = -1 , y = -1;
	Pos p;
	cout<<"COM:[7,7]"<<endl;
	while(1)
	{
		cin>>x>>y;
		p.x = x; p.y = y;
		cout<<"You:["<<p.x<<","<<p.y<<"]"<<endl;
		//board[p.x][p.y] = 2;
		//print_chess();
		int x = ai.getChessBoard().isWin();
		cout<<"x="<<x<<endl;
		if (x > 0)
		{
			cout<<"game over"<<endl;
			break;
		}
		p = ai.set(p);
		cout<<"COM:["<<p.x<<","<<p.y<<"]"<<endl;
		//board[p.x][p.y] = 1;
		//print_chess();
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
