#ifndef _INCL_SORT
#define _INCL_SORT
#include "Chromosome.h"
class Sort
{
private:
	static float* list1;
	static Chromosome** list2;
	static int length;
public:
	static void sort(float *fit, Chromosome** cp, int len);
private:
	static void quickSort(int lowerIndex, int higherIndex);
	static void exchangeNumbers(int i, int j);
};
#endif
