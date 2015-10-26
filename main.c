#include<stdio.h>
#include<string.h>
#include"lib.h"
#include<stdlib.h>
char filename[30];
int main()
{
	int choice;
	char check;

	strcpy(filename,"pranav");
	while(1)
	{     printf("\n\n\n\n\n\t\t------------*******----------");
		printf("\n\n\n\tHello !! Welcome to Library --- choose from the following menu");
		printf("\n\n\n\t\t1.Add Book Information");
		printf("\n\n\t\t2.Display Book Information");
		printf("\n\n\t\t3.Delete Book Information");
		printf("\n\n\t\t4.Search a Book ");
		printf("\n\n\t\t6.Edit available book Information");
		printf("\n\n\t\t7.Exit from this menu");
	printf("\n\n\n\n\n\t\t------------*******----------");
		printf("\n\n\n\n\t\t\t Your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					Password();
					addbook();					
					break;
				}
			case 2:
				{
					Password();
					display_book();
					break;
				}
			case 3:
					Password();			
					delete_book();
					break;
			case 4:
		//			search();
					break;
			case 6:
		//			edit_info();
					break;
			case 7:
				exit(0);
			default:
				printf("\n\t\tChoose from following choices only \n");
				printf("\t\tENter 1 2 3 4 5 6 7");
		}
	}
}

