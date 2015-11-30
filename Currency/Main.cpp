#include "Chromosome.h"
#define INITIAL_NUMBER 100

int fitness(Chromosome &c)
{
	return 0;
}

void main()
{
	Chromosome** cp;
	Chromosome** c2;
	int fit[INITIAL_NUMBER];
	
	cp = new Chromosome*[INITIAL_NUMBER];
	c2 = new Chromosome*[INITIAL_NUMBER];
	
	for(int i = 0; i < INITIAL_NUMBER; i++)
	{
		cp[i] = new Chromosome();
		fit[i] = fitness(*cp[i]);
	}
	
	//sort(fit[i], cp[i])
	
	{
		//c2[i] = new Chromosome(*cp[a]);
		//c2[j] = new Chromosome(*cp[b]);
		//c2[i]->Crossover(*c2[j]);
		//c2[i]->Mutation();
		//c2[j]->Mutation();
		//fit[i] = fitness(*c2[i]);
		//fit[j] = fitness(*c2[j]);
	}
	
}
