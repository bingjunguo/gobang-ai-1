class Zobrist
{
	int m_com[BOARD_SIZE*BOARD_SIZE];
	int m_hum[BOARD_SIZE*BOARD_SIZE];
	int m_code;
public:
	Zobrist()
	{
		for(var i=0;i<BOARD_SIZE*BOARD_SIZE;i++) {
    		this.m_com[i] = this._rand();
    		this.m_hum[i] = this._rand();
  		}
  		this.m_code = this._rand();
	}
	~Zobrist();
	int _rand()
	{
		//return Math.floor(Math.random() * 1000000000);  //再多一位就溢出了。。
		//这里需要改一下
		return 1;
	}
	int go(int x, int y, int role) {
		int index = BOARD_SIZE * x + y;
		this.code ^= (role == ROLE.com ? this.m_com[index] : this.m_hum[index]);
		return this.code;

	}
	
};