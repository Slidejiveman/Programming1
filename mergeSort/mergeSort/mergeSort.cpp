#include <iostream>

using namespace std;

const int MAX = 8;

void mergeSort(int list[MAX], int lowBound, int upperBound);
void merge(int list[MAX], int lowBound, int upperBound, int mid);

int main()
{
	return 0;
}

void mergeSort(int list[MAX], int lowBound, int upperBound)
{
	int mid;

	if (lowBound < upperBound)
	{
		mid = (lowBound + upperBound) / 2;
		mergeSort(list, lowBound, mid);
		mergeSort(list, (mid + 1), upperBound);
		merge(list, lowBound, upperBound, mid);
	}
}

void merge(int list[MAX], int lowBound, int upperBound, int mid)
{
	
}