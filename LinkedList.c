#include "LinkedList.h"
node sdb[10];
void SDB_init(void)
{
    sdb -> nxt = NULL;
    return;
}
/*
ARRAY ELEMENT CHOOSING ERROR*/
int SDB_getusedsize(void)
{
    int count=0;
    while (sdb->nxt!=NULL)
        count++;    //does not abide 0-1 case. check again
    return count;
}
int SDB_isidexist(int id)
{
    while (sdb->nxt!=NULL)
            if (sdb-> value ->id ==id)
                return 1;
    return 0;
}