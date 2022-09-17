//#define NULL (void*)0
#include <stdlib.h>
typedef unsigned char uint8;
typedef struct 
{
	uint8 id,year,subjects[3],grades[3];
}entry;
typedef struct node
{
    entry value;
    node * nxt;
}node;



