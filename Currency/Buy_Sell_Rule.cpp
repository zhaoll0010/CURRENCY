#include "Buy_Sell_Rule.h"

Buy_Sell_Rule::Buy_Sell_Rule() {}
void Buy_Sell_Rule::operator=(Buy_Sell_Rule &r)
{
	for (int i = 0; i < NUMBER1; i++)
	{
		gen1[i] = r.gen1[i];
	}
}
