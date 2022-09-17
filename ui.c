#include "ui.h"

void printentry(uint8 id)
{
    short year;
    uint8 grades[3], subjects[3];
    if (SDB_readentry(id, &year, subjects, grades))
    {
        printf("Student ID: %d\n", id);
        printf("Student year: %d", year);
        for (uint8 i = 0;i < 3;i++)
        {
            printf("\nSubject ID: %d\tGrade: %d", subjects[i], grades[i]);
        }
    }
    else
    {
        printf("Error cant find entry\n");
    }
    return;
}

/*void printentry(uint8 id)
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
    return;
}*/
void printidlist(uint8* list, uint8* count)
{
    printf("ID List:\n");
    for (uint8 i = 0;list[i] != 0;i++)
        printf("%d\n",list[i]);
    printf("Count= %d\n", *count);
    return;
}
void printsize(void)
{
    printf("List size is %d\n", SDB_getusedsize());
    return;
}
void printfull(void)
{
    if (SDB_isfull())
        printf("DB is full");
    else
        printf("DB is NOT full");
    return;
}
void printidexist(uint8 id)
{
    if (SDB_isidexist(id))
        printf("ID Exists!\n");
    else
        printf("ID Does NOT exist");
    return;
}
void add(void)
{
    uint8 id,grades[3],subjects[3];
    short year;
    printf("Enter ID\n");
    scanf("%d", &id); fflush(stdin);
    printf("Enter year\n");
    scanf("%d", &year); fflush(stdin);
    for (uint8 i = 0;i < 3;i++)
    {
        printf("Enter subject ID %d\n", i);
        scanf("%d", &subjects[i]); fflush(stdin);
        printf("Enter grade\n");
        scanf("%d", &grades[i]); fflush(stdin);
        if(!(grades[i]<=100))
            while (!(grades[i] <= 100))
            {
                printf("Invalid number enter again\n");
                scanf("%d", &grades[i]); fflush(stdin);
            }
        if (SDB_addentry(id, year, subjects, grades))
            printf("Added succesfully\n");
        else
            printf("Error failed to add entry");
    }
    return;
}
void del(void)
{
    uint8 id;
    printf("Enter id");
    scanf("%d", &id);
    SDB_DeleteEntry(id);
    return;
}

