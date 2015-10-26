#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lib.h"

FILE *f,*fp;
int i;

int count;
char filename[30];

void addbook() {  
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
		scanf(" %[^\n]",lib.usename);
		printf("\t\t\tFILL DETAILS OF THE BOOK:\n");
		printf("\n\t\t\tBOOK NAME/TITLE :");
		scanf(" %[^\n]",lib.bookname);
		printf("\n\t\t\tWRITER/AUTHOR :");
		scanf(" %[^\n]",lib.writer);
		printf("\n\t\t\tBOOK NUMBER :");
		scanf(" %d",&lib.book_no);
		printf("\n\t\t\tCATEGORY/TYPE :");
		scanf(" %[^\n]",lib.category);
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
		printf("\n\t\t\tRETURNING DATE:");
		scanf(" %d %d %d", &lib.duedd, &lib.duemm, &lib.dueyy);
		fwrite(&lib,sizeof(lib),1,f);
		printf("\n\n\n\t\t\t\tEnter key E to exit : ");
		scanf(" %c",&esc);
		if(esc == 'E' || esc == 'e'){
			issuerecord(lib);			
			break;
		}issuerecord(lib);
	}
	fclose(f);
}
void Password() 
  {
  char stat[32]="\n\n\t\tPassword Protected \n";
  int i = 0,  j;
  while(stat[i] != '\0') {
  putchar(stat[i]);
  i++;
  }
  char ch,pass[32];
  char password[8] = "pranav";
  printf("\n\t\tEnter Password:");
scanf("%s", pass);
 if(strcmp(pass,password) == 0) 
  {
  printf("\n\t\t---- ACCESS GRANTED ----\n\n");
  return;
  }
else {
  printf("\n\t\tXXXXX ACCESS DENIED XXXXX __ RE-ENTER PASSWORD ");
  Password();
}
}

void issuerecord(struct lib lib)  {
  printf("\n\t\t\tHere is ur receipt \n");
  printf("\n\t\tBook has taken by Mr./Ms./Mrs. %s", lib.usename);
  printf("\n\n\t\tIssued Date : %d-%d-%d",lib.issueddd, lib.issuedmm, lib.issuedyy); 
  printf("\n\n\t\tLast Returning Date : %d-%d-%d",lib.duedd, lib.duemm, lib.dueyy);
  return;
  }

void display_book()
{
int s = 0, num = 1;	
if((f=fopen(filename,"r"))==NULL)
	{
		printf("\n\t\tUnable to open file!!");
		exit(1);
	}
	printf("\n\t\tBOOKS AVAILABLE IN LIBRARY ARE --> \n");	
	while((fread(&lib,sizeof(lib),1,f)) == 1)
	{
	printf("\n\t\t* %d *", num);
	printf("\n\n\t\tBOOK NAME:%s\
	\n\n\t\tAUTHOR/WRITER:%s\
	\n\n\t\tBOOK NUMBER:%d\
	\n\n\t\tCATEGORY:%s\n",lib.bookname,lib.writer,lib.book_no ,lib.category);
	num++;
	s = 0;	
	}
	if (s == 0)
	return;
	else{
	printf("\n\t\tBOOKS AVAILABLE IN LIBRARY ARE -->");
	printf("\n\n\t\t***SORRY!! NO BOOK IS AVAILABLE***");
	fclose(f);
}
}

void delete_book()
{
	FILE *fp,*newf;
	int s = 1;
	char name[32];
	printf("\nEnter the name of the book to be deleted:\n\n\t\t\t\t");
	scanf(" %[^\n]",name);
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("\n\t\tUnable to open file!!");
		return;
	}
	newf=fopen("newfile","w");
	if(newf==NULL)
	{
		printf("\n\t\tUnable to open file!!");
		return;
	}
	
	while(fread(&lib,sizeof(lib),1,f)==1)
	{
		if((strcmp(lib.bookname,name))==0)
		{
			s=0;
			continue;
		}
		else
			fwrite(&lib,sizeof(lib),1,newf);
	}
	if(s==0)
		printf(" BOOK INFORMATION DELETED");
	else
		printf("NOT FOUND !!");	
	remove(filename);
	rename("newfile",filename);
	fclose(fp);
	fclose(newf);
}
