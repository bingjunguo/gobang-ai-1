class AIMath
{
public:
	AIMath();
	~AIMath();
	static const int threshold = 1.1;
	
	static bool greatThan(int a,int b) 
	{
		return a >= b * threshold;
	}
	static bool greatOrEqualThan(int a,int b) 
	{
		return a * threshold >= b;
	}
	static bool littleThan(int a,int b) 
	{
		return a * threshold <= b;
	}
	static bool littleOrEqualThan(int a,int b) 
	{
		return a <= b * threshold;
	}
	static bool equal(int a,int b) 
	{
		return (a * threshold >= b) && (a <= b * threshold);
	}
};
