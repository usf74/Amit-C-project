#include <stdio.h> 
// Basic shit
void swap(int* x, int* y)
{
	int swap;
	swap = *x;
	*x = *y;
	*y = swap;
	return;
}
void swapx(int* x, int* y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}
// Array toolbox
void bubsort(int* arr, int size)
{
	int i, j;
	for (i = 0;i < size - 1;i++)
	{
		for (j = 0;j < size - 1;j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr + j, arr + j + 1);
		}
	}
	return;
}
void selsort(int* arr, int size)
{
	int i, j, mini;
	for (i = 0; i < size - 1;i++)
	{
		mini = i;
		for (j = i + 1;j < size;j++)
		{
			if (arr[mini] > arr[j])
				mini = j;
		}
		//swap operation
		if (mini != i)  //lazem el condition k optimization w 34an yb2a esmo select sort
			swap(arr + i, arr + mini);
	}
	return;
}
void printarr(int* arr, int size)
{
	for (int i = 0;i < size;i++)
	printf("%3d", arr[i]);
	return;
}
int seqsearch(int* arr, int size, int key)
{
	for (int i = 0;i < size;i++)
		if (arr[i] == key)
			return i;
	return-1;
}
int binsearch(int* arr, int size, int key)
{
	int l = 0, r = size - 1, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (key > arr[mid])
			l = mid + 1;
		else if (key < arr[mid])
			r = mid - 1;
		else
			return mid; //key is equal, return index
	}
	return -1;  // key is not found
}
