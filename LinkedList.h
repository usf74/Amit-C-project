#include <stdlib.h>
#include <stdio.h>
#define nodesize 24 //node struct size
typedef unsigned char uint8;
//Structs
typedef struct
{
    uint8 id, subjects[3], grades[3];
    short year;
}entry;
typedef struct node
{
    entry value;
    struct node* nxt;
}node;
//Prototypes
void SDB_init(void);
node* SDB_getidaddress(uint8 id);
uint8 SDB_getusedsize(void);
uint8 SDB_isidexist(uint8 id);
uint8 SDB_isfull(void);
void SDB_getidlist(uint8* count, uint8* list);
uint8 SDB_readentry(uint8 id, short* year, uint8* subjects, uint8* grades);
uint8 SDB_addentry(uint8 id, short year, uint8* subjects, uint8* grades);
void SDB_DeleteEntry(uint8 id);
void printIDentry(uint8 id);

