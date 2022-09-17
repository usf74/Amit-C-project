#include "LinkedList.h"
#include <stdio.h>
//node sdb[10];
node* hp,* ptr;
void SDB_init(void)
{
    hp=(node*)malloc(nodesize);
    hp -> nxt = NULL;  // NULL to indicate no elements at all
    return;
}
node* SDB_getidaddress(uint8 id)
{
    ptr=hp;
    if(ptr->nxt==NULL)
        return NULL;  //no Entry case
    for (uint8 i=0; ptr->nxt!=NULL; i++)
    {
        if ((ptr->value.id==id))
            return ptr;
        ptr=ptr->nxt;
    }
    return(NULL); //can't find entry
}
//Required functions
uint8 SDB_getusedsize(void)
{
    ptr=hp;
    if (ptr->nxt==NULL)   // for no entries case
        return 255;
    uint8 count=0;    // array indexing style
    while (ptr->nxt!=NULL)
    {
        count++;
        ptr=ptr -> nxt;
    }   
    count++;
    return count; //return normal index
}
uint8 SDB_isidexist(uint8 id)   
{
    ptr=hp;
    for (uint8 i=0; ptr->nxt!=NULL ; i++)
    {
        if ((ptr->value.id) == id)
            return 1;
        ptr=ptr -> nxt;   
    }
    return 0;
}
uint8 SDB_isfull(void)
{
    if (SDB_getusedsize()==10)
        return 1;
    return 0;
}
void SDB_getidlist(uint8* count,uint8* list)   
{
    if (ptr->nxt==NULL)
    {
        *count=255;
        return;
    }
    ptr=hp;
    for (*count=0; ptr->nxt!=NULL; *count++)
    {
        list[*count]=ptr->value.id; 
        ptr=ptr -> nxt;
    }
    *count++;
    return;
}
uint8 SDB_readentry(uint8 id, uint8* year, uint8* subjects, uint8* grades)
{
    ptr=SDB_getidaddress(id);

    if (ptr==NULL)
        return 0;
    
    *year=ptr -> value.year;
    for (uint8 i=0; i<3; i++)
    {
        subjects[i]=ptr-> value.subjects[i];
        grades[i]=ptr ->value.grades[i];
    }
    return 1;
}
uint8 SDB_AddEntry(uint8 id, uint8 year, uint8* subjects, uint8* grades)
{
    for ( ptr=hp; ptr -> nxt!=NULL; ptr=ptr -> nxt);

    ptr->nxt=(node*) malloc(nodesize);
    if (ptr->nxt==NULL || SDB_getusedsize()==10)
        return 0;
    
    ptr= ptr->nxt;
    ptr->nxt=NULL;

    ptr-> value.id=id;
    for (uint8 i=0; i<3; i++)
    {
        ptr-> value.subjects[i]=subjects[i];
        ptr-> value.grades[i]=grades[i];
    }
    return 1;
}
void SDB_DeleteEntry(uint8 id)
{
    ptr=SDB_getidaddress(id);
    //3 cases for deletion: first,last,or middle element
    if (ptr==hp)
    {
        hp=ptr->nxt;
        free(ptr);
    }
    else if(ptr->nxt==NULL)
    {
        node* ptr2=hp;
        while(ptr2->nxt!=ptr)
            ptr2=ptr2->nxt;
        ptr2->nxt=NULL;
        free(ptr);
    }
    else
    {
        node* ptr2=hp;
        while(ptr2->nxt!=ptr)
            ptr2=ptr2->nxt;
        ptr2->nxt-ptr->nxt;
        free(ptr);
    }
}
void printidentry(uint8 id)
{
    ptr=SDB_getidaddress(id);
    printf("%d",ptr->value.id);
    for (uint8 i=0;i<3;i++)
    {
        printf("Subject ID: %d\nGrade: %d",ptr->value.subjects[i],ptr->value.grades[i]);
    }
}