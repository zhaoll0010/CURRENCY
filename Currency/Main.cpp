#include "Chromosome.h"
#include "Sort.h"
#include "Fitness.h"
#include "Select_Parents.h"
#define INITIAL_NUMBER 100

void main()
{
	Chromosome** cp;
	Chromosome** c2;
	float fit[INITIAL_NUMBER];
	
	cp = new Chromosome*[INITIAL_NUMBER];
	c2 = new Chromosome*[INITIAL_NUMBER];
	
	for(int i = 0; i < INITIAL_NUMBER; i++)
	{
		cp[i] = new Chromosome();
		fit[i] = Fitness::fitness(*cp[i]);
	}
	
	
	//while(1)
	{
		Sort::sort(fit, cp, INITIAL_NUMBER);
	
		for(int n = 0; n < INITIAL_NUMBER; n += 2)
		{
			int i, j;
			Select_Parents::selectParents(cp, &i, &j);
			c2[n] = new Chromosome(*cp[i]);
			c2[n + 1] = new Chromosome(*cp[j]);
			c2[n]->Crossover(*c2[n + 1]);
			c2[n]->Mutation();
			c2[n + 1]->Mutation();
			fit[n] = Fitness::fitness(*c2[n + 1]);
			fit[n + 1] = Fitness::fitness(*c2[n + 1]);
		}
		
		for(int i = 0; i < INITIAL_NUMBER; i++)
		{
			delete cp[i];
			cp[i] = new Chromosome(*c2[i]);
			delete c2[i];
		}
	}
	
	for(int i = 0; i < INITIAL_NUMBER; i++)
	{
		delete cp[i];
	}
	delete cp;
	delete c2;
}
