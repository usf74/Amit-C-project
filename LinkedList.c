#include "LinkedList.h"
node sdb[10];
void SDB_init(void)
{
    sdb -> nxt = -1;  // -1 to indicate no elements at all
    return;
}
uint8 SDB_getidindex(uint8 id)
{
    for (uint8 i=0; i<10 && sdb[i].nxt!=NULL; i++)
        if (sdb[i].value.id==id)
            return i;
    return(255); //can't find entry
}
//Required functions
uint8 SDB_getusedsize(void)    //prob done
{
    if (sdb->nxt==-1)   // for no entries case
        return 255;
    uint8 count=0;    // array indexing style
    while (sdb[count].nxt!=NULL)
        count++;    
    return ++count; //return normal index
}
uint8 SDB_isidexist(uint8 id)   //prob done
{
    for (uint8 i=0; i<10 && sdb[i].nxt!=NULL; i++)
            if ((sdb[i].value.id) ==id)
                return 1;
    return 0;
}
uint8 SDB_isfull(void)
{
    if (SDB_getusedsize==10)    //=10 or 9???
        return 1;
    return 0;
}
void SDB_getidlist(uint8* count,uint8* list)   
{
    if (sdb->nxt==-1)
    {
        *count=255;
        return;
    }
    for (*count=0; *count < 10 && sdb[*count].nxt!=NULL; *count++)
         list[*count]=sdb[*count].value.id; // add null char to mark end????
    *count++;
    return;
}
uint8 SDB_readentry(uint8 id, uint8* year, uint8* subjects, uint8* grades)
{
    uint8 index=SDB_getidindex(id);
    if (index==255)
        return 0;
    *year=sdb[index].value.year;
    for (uint8 i=0; i<3; i++)
    {
        subjects[i]=sdb[index].value.subjects[i];
        grades[i]=sdb[index].value.grades[i];
    }
    return 1;
}
uint8 SDB_AddEntry(uint8 id, uint8 year, uint8* subjects, uint8* grades)
{
    uint8 index;
    for (index=0; index<10 && sdb[index].nxt!=NULL; index++);
    index++;
    sdb[index].value.id=id;  //return 0 for failed allocation
    for (uint8 i=0; i<3; i++)
    {
        sdb[index].value.subjects[i]=subjects[i];
        sdb[index].value.grades[i]=grades[i];
    }
    return 1;
}
void SDB_DeleteEntry(uint8 id)
{
    //add at last and end?
}