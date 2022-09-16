#define NULL (void*)0
#include <stdlib.h>
typedef struct 
{
	int id,year,c1id,c1g,c2id,c2g,c3id,c3g;
}entry;
typedef struct node
{
    entry value;
    node * nxt;
}node;



