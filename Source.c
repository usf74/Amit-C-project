#include <stdio.h>
#include "LinkedList.h"

int main()
{	
	SDB_init();
	uint8 subjects[3]={5,7} , grades[3]={69,100};
	SDB_AddEntry(1,100,subjects,grades);
	printidentry(1);
	return 1;
}
