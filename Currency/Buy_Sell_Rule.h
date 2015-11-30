#ifndef _INCL_BUY_SELL_RULE
#define _INCL_BUY_SELL_RULE
//#include <cstdint>
#include <cstdlib>
class Buy_Sell_Rule
{
public:
	unsigned int gen1[12];

	static const int GEN_LEN1 = 5;

	static const int NUMBER1 = 12;
	static const int NUMBER = NUMBER1;
	static const int LENGTH = GEN_LEN1 * NUMBER1;

	Buy_Sell_Rule();
	void operator=(Buy_Sell_Rule &r);
	int Random_Max_Bit(int max);
	void Generate_Random();
};
#endif
