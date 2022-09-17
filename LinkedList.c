#include "LinkedList.h"
//node sdb[10];
node* hp;
void SDB_init(void)  //done
{
    hp = NULL;  // NULL to indicate no elements at all
    return;
}
node* SDB_getidaddress(uint8 id)   //done
{
    if (hp == NULL)
        return NULL;
    node* ptr = hp;
    while(1)
    {
        if ((ptr->value.id == id))
            return ptr;
        if (ptr->nxt == NULL)
            break;
        ptr = ptr->nxt;
    }
    return(NULL); //can't find entry
}
//Required functions
uint8 SDB_getusedsize(void)
{
    node* ptr = hp;
    if (hp == NULL)   // for no entries case
        return 0;
    uint8 count = 1;
    while (ptr->nxt != NULL)
    {
        count++;
        ptr = ptr->nxt;
    }
    return count;
}
uint8 SDB_isidexist(uint8 id)  //done
{
    node* ptr = hp;
    if (hp == NULL)  //List is empty
        return 0;
    while (1)
    {
        if ((ptr->value.id == id))
            return 1;
        if (ptr->nxt == NULL)
            break;
        ptr = ptr->nxt;
    }
    return(0); //can't find entry
}
uint8 SDB_isfull(void) //done
{
    if (SDB_getusedsize() == 10)
        return 1;
    return 0;
}
void SDB_getidlist(uint8* count, uint8* list)   //done
{
    *count = 0;
    if (hp == NULL)  //no entry case
        return;
    node* ptr = hp;
    while(1)
    {
        list[*count] = ptr->value.id;
        ptr = ptr->nxt;
        ++* count;
        if (ptr->nxt == NULL)
        {
            list[*count] = ptr->value.id;
            break;
        }
    }
    list[++*count]=0; // a number to mark end of list for printing 
    return;
}
uint8 SDB_readentry(uint8 id, short* year, uint8* subjects, uint8* grades)//done
{
    node* ptr = SDB_getidaddress(id);

    if (ptr == NULL)
        return 0;

    *year = ptr->value.year;
    for (uint8 i = 0; i < 3; i++)
    {
        subjects[i] = ptr->value.subjects[i];
        grades[i] = ptr->value.grades[i];
    }
    return 1;
}
uint8 SDB_addentry(uint8 id, short year, uint8* subjects, uint8* grades)//done
{
    if (SDB_getusedsize() == 10)
        return 0;
    node* ptr;
    if (hp == NULL)
    {
        hp = (node*)malloc(nodesize);
        if (hp == NULL)  //malloc failed
            return 0;
        ptr = hp;
    }
    else
    {
        for (ptr = hp; ptr->nxt != NULL; ptr = ptr->nxt);
        ptr->nxt = (node*)malloc(nodesize);
        if (ptr->nxt == NULL)  //malloc failed
            return 0;
        ptr = ptr->nxt;
    }

    ptr->value.id = id;
    ptr->value.year = year;
    ptr->nxt = NULL;
    for (uint8 i = 0; i < 3; i++)
    {
        ptr->value.subjects[i] = subjects[i];
        ptr->value.grades[i] = grades[i];
    }
    return 1;
}
void SDB_DeleteEntry(uint8 id)//done
{
    node* ptr;
    ptr = SDB_getidaddress(id);
    //3 cases for deletion: first,last,or middle element
    if (ptr == hp)
    {
        hp = ptr->nxt;
        free(ptr);
    }
    else if (ptr->nxt == NULL)
    {
        node* ptr2 = hp;
        while (ptr2->nxt != ptr)
            ptr2 = ptr2->nxt;
        ptr2->nxt = NULL;
        free(ptr);
    }
    else
    {
        node* ptr2 = hp;
        while (ptr2->nxt != ptr)
            ptr2 = ptr2->nxt;
        ptr2->nxt = ptr->nxt;
        free(ptr);
    }
}
void printIDentry(uint8 id)//done
{
    node* ptr = SDB_getidaddress(id);
    if (ptr == NULL)
    {
        printf("Error cant find entry");
        return;
    }
    printf("Student ID: %d\n", ptr->value.id);
    printf("Student year: %d", ptr->value.year);
    for (uint8 i = 0;i < 3;i++)
    {
        printf("\nSubject ID: %d\tGrade: %d", ptr->value.subjects[i], ptr->value.grades[i]);
    }
}