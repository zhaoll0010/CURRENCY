#include "Chromosome.h"

const float Chromosome::CROSS_OVER = 0.7f;
const float Chromosome::MUTATION = 0.01f;

Chromosome::Chromosome() {}
Chromosome::Chromosome(Chromosome &c)
{
	buy = c.buy;
	sell = c.sell;
	common = c.common;
}

float Chromosome::Random_Ratio()
{
	return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

int Chromosome::Random_Int(int max)
{
	return (rand() * max / RAND_MAX);
}

void Chromosome::Crossover(Chromosome &c)
{
	srand(time(NULL));
	float ratio = Random_Ratio();

	if (ratio < CROSS_OVER)
	{
		int number = Buy_Sell_Rule::NUMBER * 2 + Common_Rule::NUMBER;
		srand(time(NULL));
		int divide = Random_Int(number);

		if (number >= Buy_Sell_Rule::NUMBER)
		{
			for (int i = 0; i < Buy_Sell_Rule::NUMBER1; i++)
			{
				uint8_t temp = buy.gen1[i];
				buy.gen1[i] = c.buy.gen1[i];
				c.buy.gen1[i] = temp;
			}
		}
		if (number >= Buy_Sell_Rule::NUMBER * 2)
		{
			for (int i = 0; i < Buy_Sell_Rule::NUMBER1; i++)
			{
				uint8_t temp = sell.gen1[i];
				sell.gen1[i] = c.sell.gen1[i];
				c.sell.gen1[i] = temp;
			}
		}
		if (number >= Buy_Sell_Rule::NUMBER * 2 + Common_Rule::NUMBER1)
		{
			for (int i = 0; i <= Common_Rule::NUMBER1; i++)
			{
				uint8_t temp = common.gen1[i];
				common.gen1[i] = c.common.gen1[i];
				c.common.gen1[i] = temp;
			}
		}
		if (number >= Buy_Sell_Rule::NUMBER * 2 + Common_Rule::NUMBER1 + Common_Rule::NUMBER2)
		{
			for (int i = 0; i <= Common_Rule::NUMBER2; i++)
			{
				uint8_t temp = common.gen2[i];
				common.gen2[i] = c.common.gen2[i];
				c.common.gen2[i] = temp;
			}
		}


		if (number < Buy_Sell_Rule::NUMBER)
		{
			for (int i = 0; i <= number; i++)
			{
				uint8_t temp = buy.gen1[i];
				buy.gen1[i] = c.buy.gen1[i];
				c.buy.gen1[i] = temp;
			}
		}
		else if (number < Buy_Sell_Rule::NUMBER * 2)
		{
			number -= Buy_Sell_Rule::NUMBER;
			for (int i = 0; i <= number; i++)
			{
				uint8_t temp = sell.gen1[i];
				sell.gen1[i] = c.sell.gen1[i];
				c.sell.gen1[i] = temp;
			}
		}
		else if (number < Buy_Sell_Rule::NUMBER * 2 + Common_Rule::NUMBER1)
		{
			number -= Buy_Sell_Rule::NUMBER * 2;
			for (int i = 0; i <= number; i++)
			{
				uint8_t temp = common.gen1[i];
				common.gen1[i] = c.common.gen1[i];
				c.common.gen1[i] = temp;
			}
		}
		else if (number < Buy_Sell_Rule::NUMBER * 2 + Common_Rule::NUMBER1 + Common_Rule::NUMBER2)
		{
			number -= Buy_Sell_Rule::NUMBER * 2 + Common_Rule::NUMBER1;
			for (int i = 0; i <= number; i++)
			{
				uint8_t temp = common.gen2[i];
				common.gen2[i] = c.common.gen2[i];
				c.common.gen2[i] = temp;
			}
		}
		else if (number < Buy_Sell_Rule::NUMBER * 2 + Common_Rule::NUMBER1 + Common_Rule::NUMBER2 + Common_Rule::NUMBER3)
		{
			number -= Buy_Sell_Rule::NUMBER * 2 + Common_Rule::NUMBER1 + Common_Rule::NUMBER2;
			for (int i = 0; i <= number; i++)
			{
				uint8_t temp = common.gen3[i];
				common.gen3[i] = c.common.gen3[i];
				c.common.gen3[i] = temp;
			}
		}
	}
}

void Chromosome::Mutation()
{
	srand(time(NULL));
	float ratio = Random_Ratio();

	if (ratio < MUTATION)
	{
		int number = Buy_Sell_Rule::LENGTH * 2 + Common_Rule::LENGTH;
		srand(time(NULL));
		int bit = Random_Int(number);

		if (bit < Buy_Sell_Rule::LENGTH)
		{
			int index = bit / Buy_Sell_Rule::GEN_LEN1;
			int shift = Buy_Sell_Rule::GEN_LEN1 - 1 - (bit % Buy_Sell_Rule::GEN_LEN1);

			buy.gen1[index] ^= 1 << shift;
		}
		else if(bit < Buy_Sell_Rule::LENGTH * 2)
		{
			bit -= Buy_Sell_Rule::LENGTH;

			int index = bit / Buy_Sell_Rule::GEN_LEN1;
			int shift = Buy_Sell_Rule::GEN_LEN1 - 1 - (bit % Buy_Sell_Rule::GEN_LEN1);

			sell.gen1[index] ^= 1 << shift;
		}
		else if(bit < Buy_Sell_Rule::LENGTH * 2 + Common_Rule::LENGTH)
		{
			bit -= Buy_Sell_Rule::LENGTH * 2;

			if (bit < Common_Rule::LENGTH1)
			{
				int index = bit / Common_Rule::GEN_LEN1;
				int shift = Common_Rule::GEN_LEN1 - 1 - (bit % Common_Rule::GEN_LEN1);

				common.gen1[index] ^= 1 << shift;
			}
			else if (bit < Common_Rule::LENGTH1 + Common_Rule::LENGTH2)
			{
				bit -= Common_Rule::LENGTH1;

				int index = bit / Common_Rule::GEN_LEN2;
				int shift = Common_Rule::GEN_LEN2 - 1 - (bit % Common_Rule::GEN_LEN2);

				common.gen2[index] ^= 1 << shift;
			}
			else if (bit < Common_Rule::LENGTH1 + Common_Rule::LENGTH2 + Common_Rule::LENGTH3)
			{
				bit -= Common_Rule::LENGTH1 + Common_Rule::LENGTH2;

				int index = bit / Common_Rule::GEN_LEN3;
				int shift = Common_Rule::GEN_LEN3 - 1 - (bit % Common_Rule::GEN_LEN3);

				common.gen3[index] ^= 1 << shift;
			}
		}
	}
}
