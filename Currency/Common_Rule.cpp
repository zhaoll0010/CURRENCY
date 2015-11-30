#include "Common_Rule.h"

Common_Rule::Common_Rule() {}
void Common_Rule::operator=(Common_Rule &r)
{
	for (int i = 0; i < NUMBER1; i++)
	{
		gen1[i] = r.gen1[i];
	}
	for (int i = 0; i < NUMBER2; i++)
	{
		gen2[i] = r.gen2[i];
	}
	for (int i = 0; i < NUMBER3; i++)
	{
		gen3[i] = r.gen3[i];
	}
}

int Common_Rule::Random_Max_Bit(int bit)
{
	int max = 1 << bit;
	return (rand() * max / RAND_MAX);
}

void Common_Rule::Generate_Random()
{
	for (int i = 0; i < NUMBER1; i++)
	{
		gen1[i] = Random_Max_Bit(GEN_LEN1);
	}
	for (int i = 0; i < NUMBER2; i++)
	{
		gen2[i] = Random_Max_Bit(GEN_LEN2);
	}
	for (int i = 0; i < NUMBER3; i++)
	{
		gen3[i] = Random_Max_Bit(GEN_LEN3);
	}
}
