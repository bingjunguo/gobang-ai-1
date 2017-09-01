#ifndef _AI_MATH_H_
#define _AI_MATH_H_

class AIMath
{
public:
	AIMath();
	~AIMath();
	static const double threshold;
	
	static bool greatThan(int a,int b) 
	{
		return (double)a >= (double)b * threshold;
	}
	static bool greatOrEqualThan(int a,int b) 
	{
		return (double)a * threshold >= (double)b;
	}
	static bool littleThan(int a,int b) 
	{
		return (double)a * threshold <= (double)b;
	}
	static bool littleOrEqualThan(int a,int b) 
	{
		return (double)a <= (double)b * threshold;
	}
	static bool equal(int a,int b) 
	{
		if (a < 0) a = -a;
		if (b < 0) b = -b;
		return ((double)a * threshold >= (double)b) && ((double)a <= (double)b * threshold);
	}
};
const double AIMath::threshold = 1.1;  
#endif