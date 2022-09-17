#include "ui.h"
int main()
{
	uint8 c,count,  list[11];;
	while (1)
	{
		printf("\nEnter desired operation\n1 - Add entry\n2 - Read entry\n3 - Delete entry\n4 - Get ID list\n5 - Get list size\n6 - Does ID exist\n7 - Is list full\n");
		scanf("%d", &c); fflush(stdin);
		switch (c)
		{
		case 1:
			add();
			break;
		case 2:
			printf("Enter ID\n");
			uint8 id;
			scanf("%d", &id);
			printentry(id);
			break;
		case 3:
			del();
			break;
		case 4:
			SDB_getidlist(&count, list);
			printidlist(list,&count);
			break;
		case 5:
			printsize();
			break;
		case 6:
			printf("Enter ID\n");
			scanf("%d", &id); fflush(stdin);
			printidexist(id);
			break;
		case 7:
			printfull();
			break;
		default:
			printf("invalid entry");
		}
	}
	return 1;
}
