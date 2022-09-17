#include "LinkedList.h"
#include <stdio.h>
int main()
{
	uint8 id = 69, so[3], ga[3];
	int i = 0;
	uint8 count, list[11];
	short year;
	SDB_init();
	uint8 subjects[3] = { 5,7 }, grades[3] = { 69,100 };
	SDB_addentry(1, 2001, subjects, grades);
	uint8 sub[] = { 5,2,5 }, gr[] = { 9,8,3 };
	SDB_addentry(69, 2011, sub, gr);
	uint8 s[] = { 81,45,75 }, g[] = { 48,28,45 };
	SDB_addentry(100, 2069, s, g);
	//SDB_DeleteEntry(1);
	//printIDentry(1);
	//printf("\n\n");
	//printIDentry(69);
	//printf("\n\n");
	//printIDentry(100);
	SDB_readentry(1, &year, so, ga);
	SDB_getidlist(&count, list);
	while (list[i] != 0)
	{
		printf("%d\n", list[i]);
		i++;
	}

	printf("%d\n", count);

	return 1;
}
