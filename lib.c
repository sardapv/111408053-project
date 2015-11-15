/*--------------------------------------------------------------------------*/
/* 
   Copyright (C) 2015  PRANAV SARDA saradpv14.it@coep.ac.in

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/
/*--------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
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
			printf(RED"UNABLE TO OPEN"RESET);
			exit(1);
		}
	}

	while(1)
	{
		system("clear");/*taking input*/
		printf("\n\t\t\t\t\t"BOLDGREEN"------- ACCESS GRANTED -------\n\n"RESET);
		printf("\n\n\n\t\t\t\t"BOLDCYAN"ENTER YOUR NAME : "RESET YELLOW);
		scanf(" %[^\n]",lib.usename);
		printf("\n\n\t\t\t\t"BOLDYELLOW "------------------- "BOLDMAGENTA"FILL DETAILS OF THE BOOK "BOLDYELLOW"----------------\n\n"RESET);
		printf("\n\t\t\t\t"BOLDCYAN"BOOK NAME/TITLE :"RESET YELLOW);
		scanf(" %[^\n]",lib.bookname);
		printf("\n\t\t\t\t"BOLDCYAN"WRITER/AUTHOR :"RESET YELLOW);
		scanf(" %[^\n]",lib.writer);
		printf("\n\t\t\t\t"BOLDCYAN"BOOK NUMBER :"RESET YELLOW);
		scanf(" %d",&lib.book_no);
		printf("\n\t\t\t\t"BOLDCYAN"CATEGORY/TYPE :"RESET YELLOW);
		scanf(" %[^\n]",lib.category);
		printf("\n\t\t\t\t"BOLDCYAN"DATE : "RESET YELLOW);
		scanf(" %d %d %d", &lib.dd, &lib.mm, &lib.yy);
		if((checkdate(lib.dd, lib.mm, lib.yy)) == 1) {
			printf("\n\t\t\t\t"BOLDRED"Enter date again !! : "RESET GREEN);
			scanf(" %d %d %d", &lib.dd, &lib.mm, &lib.yy);
		}
		fwrite(&lib,sizeof(lib),1,f);
		printf("\n\n\n\t\t\t\t\t"BOLDGREEN"Enter key Y to exit : "RESET GREEN);
		scanf(" %c",&esc);
		if(esc == 'Y' || esc == 'y') {
			shortinfo(lib);
			fclose(f);	
			return;		
		}
		shortinfo(lib); /*short info like receipt*/	
	}
	fclose(f);
}
#define YEAR 2015
#define MONTH 12
int checkdate(int day, int month, int year) {/*program ro check ifdate  is  correct or not*/
	int flag = 0;
	int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	/* year should not be greater than current year */
	if (year > YEAR || year <= 0 || year < YEAR) {
		printf("\n\t\t\t\t"BOLDRED"Invalid Date !!\n"RESET);
		return 1;
	}
	/* only 12 months in a year */
	if (month > MONTH || month <= 0) {
		printf("\n\t\t\t\t"BOLDRED"Invalid Date !!\n"RESET);
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
			printf("\n\t\t\t\t"BOLDRED"Invalid Date !!\n"RESET);
			return 1;
		}
	}
	/* check whethe day is valid or not */
	if (day > daysInMonth[month - 1]) {
		printf("\n\t\t\t\t"BOLDRED"Invalid Date !!\n"RESET);
		return 1;
	}
	else 
		return 2;
}
void Password() { /*password to authorise*/
	system("clear");
	char stat[32]="PASSWORD PROTECTED";
	int i = 0,  j;
	printf(BOLDCYAN"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t!!!!! "RESET);
	while(stat[i] != '\0') {
		printf(BOLDRED "%c " RESET, stat[i]);
		i++;
	}
	printf(BOLDCYAN"!!!!!\n"RESET);
	char ch,pass[32];
	char password[8] = "pranav";
	printf("\n\n\t\t\t\t"GREEN"   Enter Password : "RESET);
	char *passp = pass;
	passp = getpass(""); /*unistd.h function ..anything typedis not  echoed on screen*/
	if(strcmp(passp,password) == 0) 
	{
		return;
	}
	else {
		system("clear");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t"BOLDRED"X X X X X ACCESS DENIED X X X X X "RESET GREEN"__ RE-ENTER PASSWORD\n" RESET);
		sleep(1);
		Password();
	}
}

void shortinfo(struct lib lib) { /*little info like receipt given to user*/
	system("clear");	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t"BOLDCYAN"Book information added successfully !! Here are your details : \n"RESET);
	printf("\n\t\t\t\t"YELLOW"Book Info has been added by Mr./Ms./Mrs. "BOLDMAGENTA"%s" RESET, lib.usename);
	printf("\n\n\t\t\t\t"YELLOW"DATE : "BOLDMAGENTA"%d-%d-%d"RESET,lib.dd, lib.mm, lib.yy); 
	printf("\n\n\t\t\t\t"YELLOW"BOOK NUMBER : "BOLDMAGENTA"%d"RESET, lib.book_no);
	printf("\n\n\t\t\t\t"YELLOW"BOOK : "BOLDMAGENTA"%s\n" RESET, lib.bookname);
	sleep(2);
	return;
}

void display_book(struct lib lib)
{
	system("clear");	
	int c,s = 0,num = 1;
	FILE *ft;
	f = fopen(filename,"r");
	if(f==NULL) {
		printf("\n\t\t"RED"Unable to open file!!"RESET);
		exit(1);
	}
	/*asking to select parameter by which books can be displayed*/
	printf("\n\n\n\n\t\t\t"BOLDWHITE"DISPLAY ON PARAMETER : ? CHOOSE FROM FOLLOWING\n\n\n\t\t\t"BOLDMAGENTA"1.Only TITLE/NAME of book\n\n"RESET);
	printf("\t\t\t"BOLDMAGENTA"2.BOOK NAME along with AUTHOR/WRITER of the book\n\n\t\t\t3.BOOK NAME along with BOOK NUMBER\n\n\t\t\t4.CATEGORY\n\n\t\t\t5.EVERY DETAIL\n"RESET);
	printf(BOLDCYAN"\n\n\t\t\t\t\t\t Your Choice : "RESET);
	scanf(" %d", &c);
	switch(c) {
		case 1 : /*show list of books with book names only*/
			system("clear");
			printf(GREEN"Here are your BOOKS : -->\n\n"RESET);
			printf(BOLDCYAN"\tSr.no\t\t\t* BOOK NAME *\n\n	"RESET);
			while((fread(&lib,sizeof(lib),1,f)) == 1) {
				printf(RED"\n\t* %d *"RESET, num);
				printf(YELLOW"\t\t\t%s\n"RESET, lib.bookname);
				num++;
				s = 0;	
			}

			break;

		case 2 :/*show list of books with book names with author */
			system("clear");
			printf(GREEN"Here are your BOOKS : -->\n\n"RESET);
			printf(BOLDCYAN"\tSr.no\t\t\t* BOOK NAME * \t\t * AUTHOR *\n\n"RESET);
			while((fread(&lib,sizeof(lib),1,f)) == 1) {
				printf(RED"\n\t( %d )"RESET, num);
				printf(YELLOW"\t\t\t%s\t\t\t%s\n"RESET, lib.bookname, lib.writer);
				num++;
				s = 0;	
			}
			break;

		case 3 :/*show list of books with book names and book number*/
			system("clear");
			printf(GREEN"Here are your BOOKS : -->\n\n"RESET);
			printf(BOLDCYAN"\tSr.no\t\t\t* BOOK NAME * \t\t * BOOK NUM *\n\n"RESET);
			while((fread(&lib,sizeof(lib),1,f)) == 1) {
				printf(RED"\n\t( %d )"RESET, num);
				printf(YELLOW"\t\t\t%s\t\t\t%d\n"RESET, lib.bookname, lib.book_no);
				num++;
				s = 0;	
			}

			break;
		case 4:
			/*category wise book display*/
			system("clear");
			if((f=fopen(filename,"r"))==NULL)
			{
				printf(RED"\n\t\tUnable to open file!!"RESET);
				exit(1);
			}
			if((ft=fopen(filename,"r"))==NULL)
			{
				printf(RED"\n\t\tUnable to open file!!"RESET);
				exit(1);
			}
			printf(GREEN"Here are your BOOKS : -->\n\n"RESET);
			struct lib temp;
			while((fread(&lib,sizeof(lib),1,f)) == 1)
			{
				printf(RED"\n\t\t*%d*"RESET, num);
				printf(BOLDGREEN"\t\t %s \n"RESET,lib.category);
				while(fread(&temp,sizeof(temp),1,ft) == 1)
				{
					if((strcmp(lib.category,temp.category)) == 0) {
						printf(BOLDCYAN"\n\t\tTITLE : %s\t AUTHOR : %s\n"RESET , temp.bookname, temp.writer);
						s = 0;
					}

					if(s != 0)
						printf(BOLDRED"\n\n\t\t***NO BOOK OF THESE CATEGORY***"RESET);
				}
				rewind(ft);
				num++;
			}
			break;
		case 5:/*show everything about records*/
			system("clear");

			if((f=fopen(filename,"r"))==NULL)
			{
				printf(RED"\n\t\tUnable to open file!!"RESET);
				exit(1);
			}
			printf(GREEN"\n\t\tBOOKS AVAILABLE IN LIBRARY ARE --> \n\n"RESET);	
			printf(BOLDCYAN"Sr.no\t\tBOOK NAME:\tAUTHOR/WRITER:\tBOOK NUMBER:\tCATEGORY:\n\n"RESET);
			while((fread(&lib,sizeof(lib),1,f)) == 1)
			{
				printf(RED"\n(%d)\t\t"RESET, num);
				printf(YELLOW"%s\t\t%s\t\t%d\t\t%s\n"RESET,lib.bookname,lib.writer,lib.book_no ,lib.category);
				num++;
				s = 0;	
			}
			if (s == 0)
				return;
			else{
				printf(GREEN"\n\t\tBOOKS AVAILABLE IN LIBRARY ARE -->"RESET);
				printf(RED"\n\n\t\t***SORRY!! NO BOOK IS AVAILABLE***"RESET);
				fclose(f);
			}
			break;	
		default:
			printf(BOLDRED"\n\t\t\t\t!! WRONG ENTRY !!"RESET);
			printf(BOLDRED"\n\t\t\tChoose from 1 2 3 4 only"RESET);
			break;
	}
	fclose(f);
}

void delete_book(struct lib lib) {/*cases with title,writer,booknumbr*/
	FILE *fp,*newf;
	char name[32];
	int s ,c,no;
	system("clear");/*asking to select parameter by which books can be searched and then deleted*/
	printf("\n\n\n\n\t\t\t"BOLDWHITE"DELETE ON PARAMETER :  ? CHOOSE FROM FOLLOWING\n\n\n\t\t\t"BOLDMAGENTA"1.TITLE/NAME of book\n\n"RESET);
	printf(BOLDMAGENTA"\t\t\t2.AUTHOR/WRITER of the book\n\n\t\t\t3.BOOK NUMBER\n"RESET);
	printf(BOLDCYAN"\n\n\t\t\t\t\t\t Your Choice:"RESET);
	scanf(" %d", &c);
	switch(c){
		case 1:/*search by name and then delete*/
			printf(CYAN"\n\t\t\t\tWHAT IS NAME OF THE BOOK ? : "RESET);
			scanf(" %[^\n]",name);
			fp=fopen(filename,"rb+");
			if(fp==NULL)
			{
				printf(RED"\n\t\tUnable to open file!!"RESET);
				exit(1);
			}

			newf=fopen("newfile","wb");
			if(newf==NULL)
				exit(1);
			s=1;
			/*open new file newf search for item to be deleted then if item doesn't match then write in new file else skip and 				continue ..at last remove file f and close new file..rename newf with filename of f*/
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
				printf(BOLDGREEN"\n\t\t\t\tBOOK INFORMATION DELETED\n"RESET);
			else
				printf(BOLDRED"\n\n\t\t\t\tRECORD NOT FOUND !!\n"RESET);
			break;	

		case 2:
			printf(CYAN"\n\t\t\t\tWHO IS THE AUTHOR OF BOOK : "RESET);
			scanf(" %[^\n]",name);
			fp=fopen(filename,"rb+");
			if(fp==NULL)
			{
				printf(RED"\n\t\tUnable to open file!!"RESET);
				return;
			}
			newf=fopen("newfile","wb");
			if(newf==NULL)
			{
				printf(RED"\n\t\tUnable to open file!!"RESET);
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
				printf(BOLDGREEN"\n\t\t\t\tBOOK INFORMATION DELETED\n"RESET);
			else
				printf(BOLDRED"\n\n\t\t\t\tRECORD NOT FOUND !!\n"RESET);

			fclose(fp);
			fclose(newf);

			break;
		case 3:
			printf(CYAN"\n\t\t\t\tWHAT IS BOOK NUMBER(ACCESS NUMBER) : "RESET);
			scanf(" %d",&no);
			fp=fopen(filename,"rb+");
			if(fp==NULL)
			{
				printf(RED"\n\t\tUnable to open file!!"RESET);
				return;
			}
			newf=fopen("newfile","wb");
			if(newf==NULL)
			{	printf(RED"\n\t\tUnable to open file!!"RESET);
				return;
			}
			s=1;
			while(fread(&lib,sizeof(lib),1,fp)==1)
			{
				if(lib.book_no == no) /*compare and if equal then do with newf*/
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
				printf(BOLDGREEN"\n\t\t\t\tBOOK INFORMATION DELETED\n"RESET);
			else
				printf(BOLDRED"\n\n\t\t\t\tRECORD NOT FOUND !!\n"RESET);

			fclose(fp);
			fclose(newf);
			break;	

		default:
			printf(BOLDRED"Choose from 1 2 3 only"RESET);
			break;
	}
}
void search(struct lib lib) {/*cases with title,writer,booknumbr,category*/
	FILE *f;
	int s = 0, num = 1, c,count =1;
	char name[100],nam[100],z,tname[100];
	int no,i=0;
	if((f=fopen(filename,"rb")) == NULL)
	{
		printf(RED"\n\t\tUnable to open file!!"RESET);
		exit(1);
	}
	/*asking to select parameter by which books can be searched*/
	printf("\n\n\n\n\t\t\t"BOLDWHITE"SEARCH ON PARAMETER : ? CHOOSE FROM FOLLOWING\n\n\n\t\t\t"BOLDMAGENTA"1.TITLE/NAME of book\n\n"RESET);
	printf(BOLDMAGENTA"\t\t\t2.AUTHOR/WRITER of the book\n\n\t\t\t3.BOOK NUMBER\n\n\t\t\t4.CATEGORY\n"RESET);
	printf(BOLDCYAN"\n\n\t\t\t\t\t\t Your Choice : "RESET);
	scanf(" %d", &c);
	switch(c)
	{
		case 1 :
			printf(CYAN"\n\t\t\tWHAT IS NAME OF THE BOOK ? :"RESET"\n\n\t\t\t\t");
			scanf(" %[^\n]",name);
			s=1;
			while((fread(&lib,sizeof(lib),1,f)) == 1) {

				if((strcmp(lib.bookname,name)) == 0) {\
					/*start reading file  if item(parameter) matches then it is present print it*/
					s=0 ;
				}
				else
					continue;
				if(s != 1) {
					printf(GREEN"\tBOOK FOUND --> *%d*", count);
					printf(BOLDCYAN"\n\n\t\t\tTITLE : "YELLOW"%s"BOLDCYAN"\n\n\t\t\tAUTHOR : "YELLOW"%s" RESET, 	lib.bookname, lib.writer);
					printf(BOLDCYAN"\n\n\t\t\tBOOK NUMBER (ACCESS NUMBER) : "YELLOW"%d"RESET , lib.book_no);
					printf(BOLDCYAN"\n\n\t\t\tCATEGORY : "YELLOW"%s\n\n"RESET ,lib.category);
					i++;
					count++;
				}
			}

			if(s == 1 || i == 0) /*if not found*/
				printf(BOLDRED"\n\n\t\t\t\t***SORRY!! NO BOOK IS AVAILABLE***"RESET);
			break;

		case 2 :
			printf(CYAN"\n\t\t\tWHO IS THE AUTHOR OF BOOK :"RESET"\n\n\t\t\t\t");
			scanf(" %[^\n]",name);
			s=1;
			while(fread(&lib,sizeof(lib),1,f)==1)
			{
				if((strcmp(lib.writer,name))==0)
					s=0 ;
				else
					continue;
				if(s != 1) {
					printf(GREEN"\tBOOK FOUND --> *%d*", count);
					printf(BOLDCYAN"\n\n\t\t\tTITLE : "YELLOW"%s"BOLDCYAN"\n\n\t\t\tAUTHOR : "YELLOW"%s" RESET, 	lib.bookname, lib.writer);
					printf(BOLDCYAN"\n\n\t\t\tBOOK NUMBER (ACCESS NUMBER) : "YELLOW"%d"RESET , lib.book_no);
					printf(BOLDCYAN"\n\n\t\t\tCATEGORY : "YELLOW"%s\n\n"RESET ,lib.category);
					i++;
					count++;
				}
			}

			if(s == 1 || i == 0)
				printf(BOLDRED"\n\n\t\t***SORRY!! NO BOOK IS AVAILABLE***"RESET);
			break;

		case 3 :
			printf(CYAN"\n\t\t\tWHAT IS BOOK NUMBER(ACCESS NUMBER) ?:"RESET" \n\n\t\t\t\t");
			scanf(" %d",&no);
			s=1;
			while(fread(&lib,sizeof(lib),1,f)==1)
			{

				if(lib.book_no == no)
					s=0 ;
				else
					continue;
				if(s != 1) {
					printf(GREEN"\tBOOK FOUND --> *%d*", count);
					printf(BOLDCYAN"\n\n\t\t\tTITLE : "YELLOW"%s"BOLDCYAN"\n\n\t\t\tAUTHOR : "YELLOW"%s" RESET, 	lib.bookname, lib.writer);
					printf(BOLDCYAN"\n\n\t\t\tBOOK NUMBER (ACCESS NUMBER) : "YELLOW"%d"RESET , lib.book_no);
					printf(BOLDCYAN"\n\n\t\t\tCATEGORY : "YELLOW"%s\n\n"RESET ,lib.category);
					i++;
					count++;
				}
			}
			if(s == 1 || i == 0)
				printf(BOLDRED"\n\n\t\t***SORRY!! NO BOOK IS AVAILABLE***"RESET);
			break;

		case 4:


			if((f=fopen(filename,"r"))==NULL)
			{
				printf(RED"\n\t\tUnable to open file!!"RESET);
				exit(1);
			}
			printf(GREEN"\n\t\tBOOKS ARE ARRANGED IN FOLLOWING CATEGORIES  --> \n"RESET);
			while((fread(&lib,sizeof(lib),1,f)) == 1)
			{
				printf(RED"\n\t\t*%d*"RESET, num);
				printf(YELLOW"\t\t %s \n"RESET,lib.category);
				num++;
				s = 0;	
			}
			rewind(f);

			printf(CYAN"\n\n\t\t\tWHAT IS THE CATEGORY OF BOOK TO BE SEARCHED ? "RESET": \n\n\t\t\t\t");

			scanf(" %[^\n]",name);
			s=1;
			while(fread(&lib,sizeof(lib),1,f) == 1)
			{
				if((strcmp(lib.category,name)) == 0)
					s=0 ;
				else
					continue;
				if(s != 1) {
					printf(GREEN"\tBOOK FOUND --> *%d*", count);
					printf(BOLDCYAN"\n\n\t\t\tTITLE : "YELLOW"%s"BOLDCYAN"\n\n\t\t\tAUTHOR : "YELLOW"%s" RESET, 	lib.bookname, lib.writer);
					printf(BOLDCYAN"\n\n\t\t\tBOOK NUMBER (ACCESS NUMBER) : "YELLOW"%d"RESET , lib.book_no);
					printf(BOLDCYAN"\n\n\t\t\tCATEGORY : "YELLOW"%s\n\n"RESET ,lib.category);
					i++;
					count++;
				}
			}

			if(s == 1 || i == 0)
				printf(BOLDRED"\n\n\t\t***SORRY!! NO BOOK IS AVAILABLE***"RESET);

			break;

		default:
			printf(BOLDRED"\n\t\t\t\t!! WRONG ENTRY !!"RESET);
			printf(RED"\n\t\t\tChoose from 1 2 3 4 only"RESET);
			break;
	}
	fclose(f);
}
void edit_info(struct lib lib) {
	system("clear");
	char name[100];
	struct lib lib1;
	FILE *newf;

	int c,p,s = 1;
	if((f=fopen(filename,"rb+"))==NULL)
	{
		printf(RED"\n\t\tUnable to open file!!"RESET);
		exit(1);
	}
	printf("\n\n\n\n\t\t\t"BOLDWHITE"WHAT DO YOU KNOW ABOUT BOOK TO BE MODIFIED : ? CHOOSE FROM FOLLOWING\n\n\n\t\t\t"BOLDMAGENTA"1.TITLE/NAME of book\n\n"RESET);
	printf(BOLDMAGENTA"\t\t\t2.BOOK NUMBER\n"RESET);
	printf(BOLDCYAN"\n\n\t\t\t\t\t\t Your Choice : "RESET);
	scanf(" %d", &c);

	switch(c) {
		/*save original passed lib to lib and take new lib1  then store in lib1 if item found while searching..
		  open new file and rewind f then if matched then write new records intaken  to newfile  newf and continue else write lib i.e 		struct from file f to newf*...remove f rename newf close newf ..new file is modified*/

		case 1 :
			system("clear");
			printf(YELLOW"\n\n\t\t\t\t\tWhat is Name/Title of the book ? : "RESET);

			scanf(" %[^\n]",name);
			while(fread(&lib1,sizeof(lib1),1,f)==1)
			{     i=1;
				if((strcmp(lib1.bookname,name))==0)
				{
					lib=lib1;
					printf("\n\t\t\t\t"BOLDGREEN"ENTER NEW RECORD "RESET);
					printf("\n\n\n\t\t\t\t"BOLDCYAN"ENTER YOUR NAME : "RESET YELLOW);

					scanf(" %[^\n]",lib1.usename);
					printf("\n\n\t\t\t\t"BOLDYELLOW "------------------- "BOLDMAGENTA"FILL DETAILS OF THE BOOK "BOLDYELLOW"----------------\n\n"RESET);
					printf("\n\t\t\t\t"BOLDCYAN"BOOK NAME/TITLE :"RESET YELLOW);
					scanf(" %[^\n]",lib1.bookname);
					printf("\n\t\t\t\t"BOLDCYAN"WRITER/AUTHOR :"RESET YELLOW);
					scanf(" %[^\n]",lib1.writer);
					printf("\n\t\t\t\t"BOLDCYAN"BOOK NUMBER :"RESET YELLOW);
					scanf(" %d",&lib1.book_no);
					printf("\n\t\t\t\t"BOLDCYAN"CATEGORY/TYPE :"RESET YELLOW);
					scanf(" %[^\n]",lib1.category);
					printf("\n\t\t\t\t"BOLDCYAN"DATE : "RESET YELLOW);
					scanf(" %d %d %d", &lib1.dd, &lib1.mm, &lib1.yy);
					if((checkdate(lib1.dd, lib1.mm, lib1.yy)) == 1) {
						printf("\n\t\t\t\t"BOLDRED"Enter date again !! : "RESET GREEN);
						scanf(" %d %d %d", &lib1.dd, &lib1.mm, &lib1.yy);
					}
					system("clear");
					printf(BOLDYELLOW"Old Record : "RESET);
					printf(BOLDCYAN"\nBOOK NAME:\tAUTHOR/WRITER:\tBOOK NUMBER:\tCATEGORY:\n\n"RESET);
					printf(YELLOW"%s\t\t%s\t\t%d\t\t%s\n"RESET,lib.bookname,lib.writer,lib.book_no ,lib.category);
					printf(BOLDGREEN"\nNew Record : "RESET);
					printf(BOLDCYAN"\nBOOK NAME:\tAUTHOR/WRITER:\tBOOK NUMBER:\tCATEGORY:\n\n"RESET);
					printf(YELLOW"%s\t\t%s\t\t%d\t\t%s\n"RESET,lib1.bookname,lib1.writer,lib1.book_no ,lib1.category);	
					sleep(3);
					rewind(f);
					newf=fopen("newfile","wb");
					if(newf==NULL)
						exit(1);

					while(fread(&lib,sizeof(lib),1,f)==1)
					{
						if((strcmp(lib.bookname,name))==0)
						{
							fwrite(&lib1,sizeof(lib1),1,newf);
							s = 0;
							continue;
						}
						else
							fwrite(&lib,sizeof(lib),1,newf);
					}

					remove(filename);
					rename("newfile",filename);
					if( s == 0)
						printf(BOLDGREEN"\n\n\t\t\t\tRECORD EDITED SUCCESSFULLY\n"RESET);
					else 
						printf(BOLDRED"\n\n\t\t\t\tNO SUCH RECORD EXIST TO MODIFY\n"RESET);	
					break;
				}
				i++;
			}
			fclose(newf);
			break;
		case 2 :
			system("clear");
			printf(YELLOW"\n\n\t\t\t\t\tWhat is Book Number (Accession Number) ? : "RESET);

			scanf(" %d",&p);
			rewind(f);
			while(fread(&lib1,sizeof(lib1),1,f)==1)
			{     i=1;
				if(lib1.book_no == p)
				{
					lib=lib1;
					printf("\n\t\t\t\t"BOLDGREEN"ENTER NEW RECORD "RESET);
					printf("\n\n\n\t\t\t\t"BOLDCYAN"ENTER YOUR NAME : "RESET YELLOW);
					scanf(" %[^\n]",lib1.usename);
					printf("\n\n\t\t\t\t"BOLDYELLOW "------------------- "BOLDMAGENTA"FILL DETAILS OF THE BOOK "BOLDYELLOW"----------------\n\n"RESET);
					printf("\n\t\t\t\t"BOLDCYAN"BOOK NAME/TITLE :"RESET YELLOW);
					scanf(" %[^\n]",lib1.bookname);
					printf("\n\t\t\t\t"BOLDCYAN"WRITER/AUTHOR :"RESET YELLOW);
					scanf(" %[^\n]",lib1.writer);
					printf("\n\t\t\t\t"BOLDCYAN"BOOK NUMBER :"RESET YELLOW);
					scanf(" %d",&lib1.book_no);
					printf("\n\t\t\t\t"BOLDCYAN"CATEGORY/TYPE :"RESET YELLOW);
					scanf(" %[^\n]",lib1.category);
					printf("\n\t\t\t\t"BOLDCYAN"DATE : "RESET YELLOW);
					scanf(" %d %d %d", &lib1.dd, &lib1.mm, &lib1.yy);
					if((checkdate(lib1.dd, lib1.mm, lib1.yy)) == 1) {
						printf("\n\t\t\t\t"BOLDRED"Enter date again !! : "RESET GREEN);
						scanf(" %d %d %d", &lib1.dd, &lib1.mm, &lib1.yy);
					}
					system("clear");
					printf(BOLDYELLOW"Old Record : "RESET);
					printf(BOLDCYAN"\nBOOK NAME:\tAUTHOR/WRITER:\tBOOK NUMBER:\tCATEGORY:\n\n"RESET);
					printf(YELLOW"%s\t\t%s\t\t%d\t\t%s\n"RESET,lib.bookname,lib.writer,lib.book_no ,lib.category);
					printf(BOLDGREEN"\nNew Record : "RESET);
					printf(BOLDCYAN"\nBOOK NAME:\tAUTHOR/WRITER:\tBOOK NUMBER:\tCATEGORY:\n\n"RESET);
					printf(YELLOW"%s\t\t%s\t\t%d\t\t%s\n"RESET,lib1.bookname,lib1.writer,lib1.book_no ,lib1.category);	
					sleep(3);
					rewind(f);
					newf=fopen("newfile","wb");
					if(newf==NULL)
						exit(1);
					while(fread(&lib,sizeof(lib),1,f)==1)
					{
						if(lib.book_no == p)
						{
							fwrite(&lib1,sizeof(lib1),1,newf);
							s = 0;
							continue;
						}
						else
							fwrite(&lib,sizeof(lib),1,newf);
					}

					remove(filename);
					rename("newfile",filename);
					if(s == 0)
						printf(BOLDGREEN"\n\n\t\t\t\tRECORD EDITED SUCCESSFULLY\n"RESET);
					else 
						printf(BOLDRED"\n\n\t\t\t\tNO SUCH RECORD EXIST TO MODIFY\n"RESET);
					break;
				}
				i++;
			}
			fclose(newf);
			break;	
		default : 
			printf(BOLDRED"\n\t\t\t\t!! WRONG ENTRY !!"RESET);
			printf(RED"\n\t\t\tChoose from   1 OR 2   only"RESET);
			break;
	}

	return;
}		
void exitp() {
	/*exiting function with little delay*/
	printf("\n\n\n\t\t\t\t\t\t"BOLDRED"!!   Closing Application   !! \n\n\t\t\t\t\t\t\t"BOLDGREEN"!! THANK YOU !!\n\n\n"RESET);
	sleep(2);
	system("clear");
	exit(1);
}
