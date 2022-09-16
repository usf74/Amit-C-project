typedef struct 
{
	int id,year,c1id,c1g,c2id,c2g,c3id,c3g;
}sdb;
typedef struct 
{
    sdb db[10]; 
    int sp; //stack pointer
}stack;
void stackinit(stack* db);
int push(stack*db,sdb value);