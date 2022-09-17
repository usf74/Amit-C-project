#include "PrintLib.h"
int main()
{
	uint8 c;
	while (1)
	{
		printf("Enter desired operation\n1 - Add entry\n2 - Read entry\n3 - Delete entry\n4 - Get ID list\n5 - Get list size\n6 - Does ID exist\n7 - Is list full\n");
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
			uint8  count,  list[11];
			printidlist(list,&count);
			break;
		case 5:
			printsize();
			break;
		case 6:
			printf("Enter ID\n");
			scanf("%d", &id);
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
