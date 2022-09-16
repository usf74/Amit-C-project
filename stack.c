//#pragma once
extern stack db;
typedef struct 
{
	int id,year,c1id,c1g,c2id,c2g,c3id,c3g;
}sdb;
typedef struct 
{
    sdb arr[10]; 
    int sp; //stack pointer
}stack;

int isempty(void)
{
    if (db -> sp==-1)
        return 1;
    return 0;
}
int isfull(void)
{
    if (db->sp>=9)
        return 1;
    return 0;
}
sdb pop ()
{
    
}
void stackinit(stack* db)
{
    db->sp=-1;
    return;
}
int push(sdb value)
{
    if (isfull(db))
        return 0;
    db->sp++;
    db->arr[db->sp]=value;
    return 1;
}