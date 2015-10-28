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
	if((f=fopen(filename,"ab+"))==NULL)
	{
		if((f=fopen(filename,"wb+"))==NULL)
		{
			printf("UNABLE TO OPEN");
			exit(1);
		}
	}
	while(1)
	{
		printf("\t\t\tENTER YOUR 1st NAME :");
		scanf(" %[^\n]",lib.usename);
		printf("\t\t\tFILL DETAILS OF THE BOOK:\n\n");
		printf("\n\t\t\tBOOK NAME/TITLE :");
		scanf(" %[^\n]",lib.bookname);
		printf("\n\t\t\tWRITER/AUTHOR :");
		scanf(" %[^\n]",lib.writer);
		printf("\n\t\t\tBOOK NUMBER :");
		scanf(" %d",&lib.book_no);
		printf("\n\t\t\tCATEGORY/TYPE :");
		scanf(" %[^\n]",lib.category);
		printf("\n\t\t\tDATE:");
		scanf(" %d %d %d", &lib.issueddd, &lib.issuedmm, &lib.issuedyy);
		fwrite(&lib,sizeof(lib),1,f);
		printf("\n\n\n\t\t\t\tEnter key E to exit : ");
		scanf(" %c",&esc);
		if(esc == 'E' || esc == 'e'){
			shortinfo(lib);			
			break;
		}shortinfo(lib);
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

void shortinfo(struct lib lib)  {
	printf("\n\t\t\tBook information added successfully !! Here are your details : \n");
	printf("\n\t\tBook Info has been added by Mr./Ms./Mrs. %s", lib.usename);
	printf("\n\n\t\tDATE : %d-%d-%d",lib.issueddd, lib.issuedmm, lib.issuedyy); 
	printf("\n\n\t\tBOOK NUMBER : %d", lib.book_no);
	printf("\n\n\t\tBOOK : %s", lib.bookname);
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
	char name[32];
	int s ,c,no;

	printf("\n\n\n\n\t\t\tDELETE ON PARAMETER :  ? CHOOSE FROM FOLLOWING\n\n\n\t\t\t1.TITLE/NAME of book\n\n");
	printf("\t\t\t2.AUTHOR/WRITER of the book\n\n\t\t\t3.BOOK NUMBER\n");
	scanf(" %d",&c);
	switch(c){
		case 1:
			printf("\nWHAT IS NAME OF THE BOOK :\n\n\t\t\t\t");
			scanf(" %[^\n]",name);
			fp=fopen(filename,"rb+");
			if(f==NULL)
			{

				printf("\n\t\tUnable to open file!!");
				exit(1);
			}

			newf=fopen("newfile","wb");
			if(newf==NULL)
				exit(1);
		s=1;
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

			remove(filename);
			rename("newfile",filename);
			fclose(fp);
			fclose(newf);
			if(s==0)
				printf(" BOOK INFORMATION DELETED");
			else
				printf(" Record Deleted");
		break;	
		
			case 2:
			printf("\nWHO IS THE AUTHOR OF BOOK :\n\n\t\t\t\t");
			scanf(" %[^\n]",name);
			fp=fopen(filename,"rb+");
			if(fp==NULL)
			{
				printf("\n\t\tUnable to open file!!");
				return;
			}
			newf=fopen("newfile","wb");
			if(newf==NULL)
			{
				printf("\n\t\tUnable to open file!!");
				return;
			}

			while(fread(&lib,sizeof(lib),1,f)==1)
			{
				if((strcmp(lib.writer,name))==0)
				{
					s=0;
					continue;
				}
				else
					fwrite(&lib,sizeof(lib),1,newf);
			}
			remove(filename);
			rename("newfile",filename);
			if(s==0)
				printf(" BOOK INFORMATION DELETED");
			else
				printf(" Record Deleted");
			
			fclose(fp);
			fclose(newf);
			break;
		case 3:
			printf("\nWHAT IS BOOK NUMBER(ACCESS NUMBER) : \n\n\t\t\t\t");
			scanf(" %d",&no);
			fp=fopen(filename,"rb+");
			if(fp==NULL)
			{
				printf("\n\t\tUnable to open file!!");
				return;
			}
			newf=fopen("newfile","wb");
			if(newf==NULL)
			{	printf("\n\t\tUnable to open file!!");
				return;
			}

			while(fread(&lib,sizeof(lib),1,f)==1)
			{
				if(lib.book_no == no)
				{
					s=0;
					continue;
				}
				else
					fwrite(&lib,sizeof(lib),1,newf);
			}
			remove(filename);
			rename("newfile",filename);
			if(s==0)
				printf(" BOOK INFORMATION DELETED");
			else
				printf(" Record Deleted");

			fclose(fp);
			fclose(newf);
			break;	

		default:
			printf("Choose from 1 2 3 only");
			break;
	}

}
