#include<stdio.h>
#include<string.h>
#include"lib.h"
#include<stdlib.h>
char filename[30];
int main() {
	int cho;
	char check,c,esc;
	
	system("clear");
	strcpy(filename,"pranav");
	while(1)
	{    	
		system("clear");
		printf(BOLDYELLOW"\n\n\n\n\n\t\t\t\t\t----------------------*******---------------------"RESET);
		printf(BOLDCYAN"\n\n\n\t\t\t\tHello !! Welcome to PRANAV's Library --- choose from the following menu"RESET);
		printf(YELLOW"\n\n\n\t\t\t\t\t1.Add Book Information"RESET);
		printf(YELLOW"\n\n\t\t\t\t\t2.Display Book Information"RESET);
		printf(YELLOW"\n\n\t\t\t\t\t3.Delete Book Information"RESET);
		printf(YELLOW"\n\n\t\t\t\t\t4.Search a Book "RESET);
		printf(YELLOW"\n\n\t\t\t\t\t6.Edit available book Information"RESET);
		printf(YELLOW"\n\n\t\t\t\t\t7.Exit from this menu"RESET);
		printf(BOLDYELLOW"\n\n\n\n\n\t\t\t\t\t----------------------*******---------------------"RESET);
		printf(BOLDCYAN"\n\n\t\t\t\t\t\t Your Choice:"RESET);
		scanf("%d",&cho);
		switch(cho)
		{
			case 1:
					Password();
					addbook();
					break;
			case 2:
					display_book(lib);
					sleep(2);
					break;
			case 3:
					Password();			
					delete_book(lib);
					sleep(2);
					break;
			case 4:
					search(lib);
					sleep(2);
					break;
			case 6:
					Password();
					edit_info(lib);
					break;
			case 7:
					exitp();
			default:
					printf(BOLDRED"\n\t\t\t\tChoose from following choices only \n"RESET);
					printf(RED"\t\t\tEnter 1 2 3 4 5 6 7"RESET);
		}
	}
}

