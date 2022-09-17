#include "LinkedList.h"
#include <stdio.h>
int main()
{	
	SDB_init();
	uint8 subjects[3]={5,7} , grades[3]={69,100};
	SDB_addentry(1,2001,subjects,grades);
	printIDentry(1);
	return 1;
}
