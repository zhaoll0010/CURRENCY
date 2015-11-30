#include "Buy_Sell_Rule.h"

Buy_Sell_Rule::Buy_Sell_Rule() {}
void Buy_Sell_Rule::operator=(Buy_Sell_Rule &r)
{
	for (int i = 0; i < NUMBER1; i++)
	{
		gen1[i] = r.gen1[i];
	}
}

int Buy_Sell_Rule::Random_Max_Bit(int bit)
{
	int max = 1 << bit;
	return (rand() * max / RAND_MAX);
}

void Buy_Sell_Rule::Generate_Random()
{
	for (int i = 0; i < NUMBER1; i++)
	{
		gen1[i] = Random_Max_Bit(GEN_LEN1);
	}
}
