#ifndef _INCL_CHROMOSOME_RULE
#define _INCL_CHROMOSOME_RULE
#include <cstdlib>
#include <ctime>
#include "Buy_Sell_Rule.h"
#include "Common_Rule.h"

class Chromosome
{
private:
	Buy_Sell_Rule buy;
	Buy_Sell_Rule sell;
	Common_Rule common;
	static const float CROSS_OVER;
	static const float MUTATION;

public:
	Chromosome();
	Chromosome(Chromosome &c);
	float Random_Ratio();
	int Random_Int(int max);
	void Crossover(Chromosome &c);
	void Mutation();
};
#endif