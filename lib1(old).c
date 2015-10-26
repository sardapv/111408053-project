#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lib.h"

FILE *f,*fp;
int i;

int count;
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
		printf("\n\n\n\n\t\t\t Your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					addbook();
					break;
				}
			case 2:
				{
					//	display_book();
					break;
				}
			case 3:
				//			delete_book();

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

void addbook() {  

	//	Password(); /*to be done properly */	
	char esc;
	if((f=fopen(filename,"w"))==NULL) {
		if((f=fopen(filename,"ab+"))==NULL)
		{
			if((f=fopen(filename,"wb+"))==NULL)
			{
				printf("UNABLE TO OPEN");
				exit(1);
			}
		}
	}
	while(1)
	{
		printf("\t\t\tENTER YOUR 1st NAME :");
		scanf(" %s",lib.usename);
		printf("\t\t\tFILL DETAILS OF THE BOOK:\n");
		printf("\n\t\t\tBOOK NAME/TITLE :");
		scanf(" %s",lib.bookname);
		printf("\n\t\t\tWRITER/AUTHOR :");
		scanf(" %s",lib.writer);
		printf("\n\t\t\tBOOK NUMBER :");
		scanf(" %d",&lib.book_no);
		printf("\n\t\t\tCATEGORY/TYPE :");
		scanf(" %s",lib.category);
		printf("\n\t\t\tISSUING DATE:");
		scanf(" %d %d %d", &lib.issueddd, &lib.issuedmm, &lib.issuedyy);
		if(lib.issueddd < 0 || lib.issuedmm > 12) {
			printf("\n\t\t\tINVALID MONTH.. Enter again :");
			scanf("%d", &lib.issuedmm);
		}
		if(lib.issueddd < 0 || lib.issueddd > 31) {
			printf("\n\t\t\tINVALID DATE.. Enter again :");
			scanf("%d", &lib.issueddd);
		}
		printf("\n\t\t\t(When will u return)RETURNING DATE:");
		scanf(" %d %d %d", &lib.duedd, &lib.duemm, &lib.dueyy);
		fwrite(&lib,sizeof(lib),1,f);
		printf("\n\n\n\t\t\t\tEnter key E to exit : ");
		scanf(" %c",&esc);
		if(esc == 'E' || esc == 'e'){
			//issuerecord(lib);			
			break;
		}
	}
	fclose(f);
}
/*void Password() 
  {
  char d[25]="\nPassword Protected \n";
  int i = 0,  j;
  while(d[i] != '\0') {
  putchar(d[i]);
  i++;
  }
  char ch,pass[10];
  char password[25] = "pranav'";
  i=0,j;
  printf("Enter Password:");
  while(password[i] != '\0')
  {
  ch=getchar();//putchar('*');
  pass[i] = ch;
  i++;

  }
  pass[i] = '\0';
  while(password[i] != '\0') {
  if(pass [i] == password[i]) 
  {
  i++;	
  continue;
  }
  else
  break;
  printf("Password match");
  return;
  }
  printf("\aWarning!! Incorrect Password");

  Password();
  }*/

/*void issuerecord(struct lib)  {
  printf("Here is ur receipt \n");
  printf("\n\t\tBook has taken by Mr./Ms./Mrs. %s", lib.usename);
  printf("\n\n\t\tIssued Date : %d-%d-%d",lib.issueddd, lib.issuedmm, lib.issuedyy); 
  printf("\n\n\t\tLast Returning Date : %d-%d-%d",lib.duedd, lib.duemm, lib.dueyy);
  return;
  }*/

