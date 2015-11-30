#include "Sort.h"
float* Sort::list1;
Chromosome** Sort::list2;
int Sort::length;

void Sort::sort(float *fit, Chromosome** cp, int len)
{
    list1 = fit;
    list2 = cp;
    length = len;
    quickSort(0, length - 1);
}

void Sort::quickSort(int lowerIndex, int higherIndex) 
{
    int i = lowerIndex;
    int j = higherIndex;
    // calculate pivot number, I am taking pivot as middle index number
    float pivot = list1[lowerIndex+(higherIndex-lowerIndex)/2];
    // Divide into two arrays
    while (i <= j) {

        while (list1[i] < pivot) {
            i++;
        }
        while (list1[j] > pivot) {
            j--;
        }
        if (i <= j) {
            exchangeNumbers(i, j);
            //move index to next position on both sides
            i++;
            j--;
        }
    }
    // call quickSort() method recursively
    if (lowerIndex < j)
        quickSort(lowerIndex, j);
    if (i < higherIndex)
        quickSort(i, higherIndex);
}

void Sort::exchangeNumbers(int i, int j) 
{
    float temp1 = list1[i];
    list1[i] = list1[j];
    list1[j] = temp1;

	Chromosome temp2(*list2[i]);
   	*list2[i] = *list2[j];
   	*list2[j] = temp2;
}
