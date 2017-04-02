NAME : PRANAV VINOD SARDA
MIS : 111408053
TITLE : LIBRARY MANAGEMENT PROGRAM
SUGGESTED : TERMINAL FULL SCREEN SIZE WITH 'WHITE ON BLACK' COLOUR PREFERENCE
PASSWORD PROTECTION : password = 'pranav'

program deals with binary file , password protected

* DISPLAY :
	do : open file in rb mode,key input,display list with key only ,read file,store in struct ,print key component of struct
	case (given key) : 
 		keys are 
		bookname: 
		bookname with writer:
		bookname with book number:
		every detail: 
* ADD :
	do :take input,store in struct, write structure in file,next time open in append mode

* DELETE :
 	do : open file with rb mode then open new file newf in wb mode then search  for the key ,if no match, then print data in struct in new file and if key matched, then skip and continue  this till end,data matched with key will not be written,delete old file,rename this file  with old file,done, 
 	case (given key) : 
 		keys are 
		bookname:
		writer:
		book number:
 		
* SEARCH :
	do : open file with rb mode and start reading from beginning ,if key matched, print it, else continue searching
	case (given key) : 
 		keys are 
		bookname:
		writer:
		book number:
* EDIT :
 	do : open file with rb mode then open new file newf in wb mode then search  for the key ,if no match, then print data in 	struct in new file and if key matched, then print new record in new file,.data which is to be modified is replaced by new data and hence written in new,. and continue this till end,delete old file,rename this file  with old file,done, 
  	case (given key) : 
 		keys are 
		bookname:
		book number:
