#include "LinkedList.h"
//node sdb[10];
node* hp;
void SDB_init(void)
{
    hp = (node*)malloc(nodesize);
    hp->nxt = NULL;  // NULL to indicate no elements at all
    return;
}
node* SDB_getidaddress(uint8 id)
{
    node* ptr = hp;
    uint8 i = 0;
    do
    {
        if ((ptr->value.id == id))
            return ptr;
        ptr = ptr->nxt;
        i++;
    } while (ptr->nxt != NULL);
    return(NULL); //can't find entry
}
//Required functions
uint8 SDB_getusedsize(void)
{
    node* ptr = hp;
    if (ptr->nxt == NULL)   // for no entries case
        return 0;
    uint8 count = 0;    // array indexing style
    while (ptr->nxt != NULL)
    {
        count++;
        ptr = ptr->nxt;
    }
    count++;
    return count; //return normal index
}
uint8 SDB_isidexist(uint8 id)
{
    node* ptr = hp;
    for (uint8 i = 0; ptr->nxt != NULL; i++)
    {
        if ((ptr->value.id) == id)
            return 1;
        ptr = ptr->nxt;
    }
    return 0;
}
uint8 SDB_isfull(void)
{
    if (SDB_getusedsize() == 10)
        return 1;
    return 0;
}
void SDB_getidlist(uint8* count, uint8* list)
{
    node* ptr = hp;
    for (*count = 0; ptr->nxt != NULL; (*count)++)
    {
        list[*count] = ptr->value.id;
        ptr = ptr->nxt;
    }
    (*count)++;
    return;
}
uint8 SDB_readentry(uint8 id, short* year, uint8* subjects, uint8* grades)
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
uint8 SDB_addentry(uint8 id, short year, uint8* subjects, uint8* grades)
{
    if (SDB_getusedsize() == 10)
        return 0;
    node* ptr;
    for (ptr = hp; ptr->nxt != NULL; ptr = ptr->nxt);
    ptr->nxt = (node*)malloc(nodesize);
    if (ptr->nxt == NULL)
        return 0;

    if (hp != ptr)
        ptr = ptr->nxt;
    ptr->nxt = NULL;

    ptr->value.id = id;
    ptr->value.year = year;
    for (uint8 i = 0; i < 3; i++)
    {
        ptr->value.subjects[i] = subjects[i];
        ptr->value.grades[i] = grades[i];
    }
    return 1;
}
void SDB_DeleteEntry(uint8 id)
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
void printIDentry(uint8 id)
{
    node* ptr = SDB_getidaddress(id);
    printf("Student ID: %d\n", ptr->value.id);
    printf("Student year: %d", ptr->value.year);
    for (uint8 i = 0;i < 3;i++)
    {
        printf("\nSubject ID: %d\tGrade: %d", ptr->value.subjects[i], ptr->value.grades[i]);
    }
}