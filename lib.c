#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ncurses.h>
#include"lib.h"

FILE *f,*fp;
int i;

int count;
char filename[30];

void addbook() {  
	system("clear");
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
		printf("\n\t\t\tENTER YOUR NAME : ");
		scanf(" %[^\n]",lib.usename);
		printf("\n\t\t\t------------------- FILL DETAILS OF THE BOOK ----------------\n\n");
		printf("\n\t\t\tBOOK NAME/TITLE :");
		scanf(" %[^\n]",lib.bookname);
		printf("\n\t\t\tWRITER/AUTHOR :");
		scanf(" %[^\n]",lib.writer);
		printf("\n\t\t\tBOOK NUMBER :");
		scanf(" %d",&lib.book_no);
		printf("\n\t\t\tCATEGORY/TYPE :");
		scanf(" %[^\n]",lib.category);
		printf("\n\t\t\tDATE : ");
		scanf(" %d %d %d", &lib.dd, &lib.mm, &lib.yy);
		if((checkdate(lib.dd, lib.mm, lib.yy)) == 1) {
			printf("\n\t\t\tEnter date again !! : ");
			scanf(" %d %d %d", &lib.dd, &lib.mm, &lib.yy);
		}
		fwrite(&lib,sizeof(lib),1,f);
		printf("\n\n\n\t\t\t\tEnter key Y to exit : ");
		scanf(" %c",&esc);
		if(esc == 'Y' || esc == 'y') {
			shortinfo(lib);
			fclose(f);	
			return;		
		}
	shortinfo(lib);	
	}
	fclose(f);
}
#define YEAR 2015
#define MONTH 12
int checkdate(int day, int month, int year) {
	int flag = 0;
	int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	/* year should not be greater than current year */
	if (year > YEAR || year <= 0 || year < YEAR) {
		printf("\n\t\t\tInvalid Date !!\n");
		return 1;
	}
	/* only 12 months in a year */
	if (month > MONTH || month <= 0) {
		printf("\n\t\t\tInvalid Date !!\n");
		return 1;
	}
	/* leap year check if month is february */
	if (month == 2) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				flag = 1;
			}
		}
		else if (year % 4 == 0) {
			flag = 1;
		}
		if (day > (daysInMonth[month - 1] + flag)) {
			printf("\n\t\t\tInvalid Date !!\n");
			return 1;
		}
	}
	/* check whethe day is valid or not */
	if (day > daysInMonth[month - 1]) {
		printf("\n\t\t\tInvalid Date !!\n");
		return 1;
	}
	else 
		return 2;
}
void Password() {
	system("clear");
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
		printf("\n\t\tXXXXX ACCESS DENIED XXXXX __ RE-ENTER PASSWORD");
		Password();
	}
}

void shortinfo(struct lib lib) {
	system("clear");	
	printf("\n\t\t\tBook information added successfully !! Here are your details : \n");
	printf("\n\t\tBook Info has been added by Mr./Ms./Mrs. %s", lib.usename);
	printf("\n\n\t\tDATE : %d-%d-%d",lib.dd, lib.mm, lib.yy); 
	printf("\n\n\t\tBOOK NUMBER : %d", lib.book_no);
	printf("\n\n\t\tBOOK : %s", lib.bookname);
	return;
}

void display_book(struct lib lib)
{
	system("clear");	
	int c,s = 0,num = 1;
	FILE *ft;
	f = fopen(filename,"r");
	if(f==NULL) {
		printf("\n\t\tUnable to open file!!");
		exit(1);
	}

	printf("\n\n\n\n\t\t\tDISPLAY ON PARAMETER : ? CHOOSE FROM FOLLOWING\n\n\n\t\t\t1.Only TITLE/NAME of book\n\n");
	printf("\t\t\t2.BOOK NAME along with AUTHOR/WRITER of the book\n\n\t\t\t3.BOOK NAME along with BOOK NUMBER\n\n\t\t\t5.EVERY DETAIL\n");
	scanf(" %d", &c);
	switch(c) {
		case 1 :
			system("clear");
			printf("Here are your BOOKS : -->\n");
			while((fread(&lib,sizeof(lib),1,f)) == 1) {
				printf("\n\t\t* %d *", num);
				printf("\t\tBOOK NAME : %s", lib.bookname);
				num++;
				s = 0;	
			}

			break;

		case 2 :
			system("clear");
			printf("Here are your BOOKS : -->\n\n");
			printf("\tSr.no\t\t\t* BOOK NAME * \t\t * AUTHOR *\n\n");
			while((fread(&lib,sizeof(lib),1,f)) == 1) {
				printf("\t( %d )", num);
				printf("\t\t\t%s\t\t\t%s\n", lib.bookname, lib.writer);
				num++;
				s = 0;	
			}

			break;

		case 3 :
			system("clear");
			printf("Here are your BOOKS : -->\n\n");
			printf("\tSr.no\t\t\t* BOOK NAME * \t\t * BOOK NUM *\n\n");
			while((fread(&lib,sizeof(lib),1,f)) == 1) {
				printf("\t( %d )", num);
				printf("\t\t\t%s\t\t\t%d\n", lib.bookname, lib.book_no);
				num++;
				s = 0;	
			}

			break;
		case 4:


			if((f=fopen(filename,"r"))==NULL)
			{
				printf("\n\t\tUnable to open file!!");
				exit(1);
			}
			if((ft=fopen(filename,"r"))==NULL)
			{
				printf("\n\t\tUnable to open file!!");
				exit(1);
			}
			printf("\n\t\tHere are your books  --> \n");
			struct lib temp;
			while((fread(&lib,sizeof(lib),1,f)) == 1)
			{
				printf("\n\t\t*%d*", num);
				printf("\t\t %s \n",lib.category);
				while(fread(&temp,sizeof(temp),1,ft) == 1)
				{
					if((strcmp(lib.category,temp.category)) == 0) {
						printf("\n\t\tTITLE : %s\t AUTHOR : %s\n" , temp.bookname, temp.writer);
						s = 0;
					}

					if(s != 0)
						printf("\n\n\t\t***NO BOOK OF THESE CATEGORY***");
				}
				rewind(ft);
				num++;
			}
			break;
		case 5:
			system("clear");

			if((f=fopen(filename,"r"))==NULL)
			{
				printf("\n\t\tUnable to open file!!");
				exit(1);
			}
			printf("\n\t\tBOOKS AVAILABLE IN lib ARE --> \n\n");	
			printf("Sr.no\t\tBOOK NAME:\tAUTHOR/WRITER:\tBOOK NUMBER:\tCATEGORY:\n\n");
			while((fread(&lib,sizeof(lib),1,f)) == 1)
			{
				printf("(%d)\t\t", num);
				printf("%s\t\t%s\t\t%d\t\t%s\n",lib.bookname,lib.writer,lib.book_no ,lib.category);
				num++;
				s = 0;	
			}
			if (s == 0)
				return;
			else{
				printf("\n\t\tBOOKS AVAILABLE IN lib ARE -->");
				printf("\n\n\t\t***SORRY!! NO BOOK IS AVAILABLE***");
				fclose(f);
			}
			break;	
		default:
			printf("\n\t\t\t\t!! WRONG ENTRY !!");
			printf("\n\t\t\tChoose from 1 2 3 4 only");
			break;
	}
	fclose(f);
}

void delete_book(struct lib lib) {
	FILE *fp,*newf;
	char name[32];
	int s ,c,no;
	system("clear");
	printf("\n\n\n\n\t\t\tDELETE ON PARAMETER :  ? CHOOSE FROM FOLLOWING\n\n\n\t\t\t1.TITLE/NAME of book\n\n");
	printf("\t\t\t2.AUTHOR/WRITER of the book\n\n\t\t\t3.BOOK NUMBER\n");
	scanf(" %d",&c);
	switch(c){
		case 1:
			printf("\nWHAT IS NAME OF THE BOOK ? :\n\n\t\t\t\t");
			scanf(" %[^\n]",name);
			fp=fopen(filename,"rb+");
			if(fp==NULL)
			{
				printf("\n\t\tUnable to open file!!");
				exit(1);
			}

			newf=fopen("newfile","wb");
			if(newf==NULL)
				exit(1);
			s=1;
			while(fread(&lib,sizeof(lib),1,fp)==1)
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
				printf(" RECORD NOT FOUND !!");
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
			s=1;
			while(fread(&lib,sizeof(lib),1,fp)==1)
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
				printf(" RECORD NOT FOUND !!");

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
			s=1;
			while(fread(&lib,sizeof(lib),1,fp)==1)
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
				printf(" RECORD NOT FOUND !!");

			fclose(fp);
			fclose(newf);
			break;	

		default:
			printf("Choose from 1 2 3 only");
			break;
	}
}
void search(struct lib lib) {
	FILE *f;
	int s = 0, num = 1, c,count =1;
	char name[100],nam[100],z,tname[100];
	int no,i=0;
	if((f=fopen(filename,"rb")) == NULL)
	{
		printf("\n\t\tUnable to open file!!");
		exit(1);
	}
	printf("\n\n\n\n\t\t\tSEARCH ON PARAMETER : ? CHOOSE FROM FOLLOWING\n\n\n\t\t\t1.TITLE/NAME of book\n\n");
	printf("\t\t\t2.AUTHOR/WRITER of the book\n\n\t\t\t3.BOOK NUMBER\n\n\t\t\t4.CATEGORY\n");
	scanf(" %d",&c);
	switch(c)
	{
		case 1 :
			printf("\n\t\t\tWHAT IS NAME OF THE BOOK ? :\n\n\t\t\t\t");
			scanf(" %[^\n]",name);
			s=1;
			while((fread(&lib,sizeof(lib),1,f)) == 1) {

				if((strcmp(lib.bookname,name)) == 0) {
					s=0 ;
				}
				else
					continue;
				if(s != 1) {
					printf("\tBOOK FOUND --> *%d*", count);
					printf("\n\n\t\t\tTITLE : %s\n\n\t\t\tAUTHOR : %s" , lib.bookname, lib.writer);
					printf("\n\n\t\t\tBOOK NUMBER (ACCESS NUMBER) : %d" , lib.book_no);
					printf("\n\n\t\t\tCATEGORY : %s\n\n" ,lib.category);
					i++;
					count++;
				}
			}

			if(s == 1 || i == 0)
				printf("\n\n\t\t***SORRY!! NO BOOK IS AVAILABLE***");
			break;

		case 2 :
			printf("\n\t\t\tWHO IS THE AUTHOR OF BOOK :\n\n\t\t\t\t");
			scanf(" %[^\n]",name);
			s=1;
			while(fread(&lib,sizeof(lib),1,f)==1)
			{
				if((strcmp(lib.writer,name))==0)
					s=0 ;
				else
					continue;
				if(s != 1) {
					printf("\tBOOK FOUND --> *%d*", count);
					printf("\n\n\t\t\tTITLE : %s\n\n\t\t\tAUTHOR : %s" , lib.bookname, lib.writer);
					printf("\n\n\t\t\tBOOK NUMBER (ACCESS NUMBER) : %d" , lib.book_no);
					printf("\n\n\t\t\tCATEGORY : %s\n\n" ,lib.category);
					i++;
					count++;
				}
			}

			if(s == 1 || i == 0)
				printf("\n\n\t\t***SORRY!! NO BOOK IS AVAILABLE***");
			break;

		case 3 :
			printf("\n\t\t\tWHAT IS BOOK NUMBER(ACCESS NUMBER) ?: \n\n\t\t\t\t");
			scanf(" %d",&no);
			s=1;
			while(fread(&lib,sizeof(lib),1,f)==1)
			{

				if(lib.book_no == no)
					s=0 ;
				else
					continue;
				if(s != 1) {
					printf("\tBOOK FOUND --> *%d*", count);
					printf("\n\n\t\t\tTITLE : %s\n\n\t\t\tAUTHOR : %s" , lib.bookname, lib.writer);
					printf("\n\n\t\t\tBOOK NUMBER (ACCESS NUMBER) : %d" , lib.book_no);
					printf("\n\n\t\t\tCATEGORY : %s\n\n" ,lib.category);
					i++;
					count++;
				}
			}
			if(s == 1 || i == 0)
				printf("\n\n\t\t***SORRY!! NO BOOK IS AVAILABLE***");
			break;

		case 4:


			if((f=fopen(filename,"r"))==NULL)
			{
				printf("\n\t\tUnable to open file!!");
				exit(1);
			}
			printf("\n\t\tBOOKS ARE ARRANGED IN FOLLOWING CATEGORIES  --> \n");
			while((fread(&lib,sizeof(lib),1,f)) == 1)
			{
				printf("\n\t\t*%d*", num);
				printf("\t\t %s \n",lib.category);
				num++;
				s = 0;	
			}
			rewind(f);

			printf("\n\n\t\t\tWHAT IS THE CATEGORY OF BOOK TO BE SEARCHED ? : \n\n\t\t\t\t");

			scanf(" %[^\n]",name);
			s=1;
			while(fread(&lib,sizeof(lib),1,f) == 1)
			{
				if((strcmp(lib.category,name)) == 0)
					s=0 ;
				else
					continue;
				if(s != 1) {
					printf("\tBOOK FOUND --> *%d*", count);
					printf("\n\n\t\t\tTITLE : %s\n\n\t\t\tAUTHOR : %s" , lib.bookname, lib.writer);
					printf("\n\n\t\t\tBOOK NUMBER (ACCESS NUMBER) : %d" , lib.book_no);
					printf("\n\n\t\t\tCATEGORY : %s\n\n" ,lib.category);
					i++;
					count++;
				}
			}

			if(s == 1 || i == 0)
				printf("\n\n\t\t***SORRY!! NO BOOK IS AVAILABLE***");

			break;

		default:
			printf("\n\t\t\t\t!! WRONG ENTRY !!");
			printf("\n\t\t\tChoose from 1 2 3 4 only");
			break;
	}
	fclose(f);
}

