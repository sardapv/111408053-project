/*Library management*/
struct lib {
	char usename[32];
	char bookname[32];
	char writer[32];
	char category[32];
	int book_no;
	int issueddd, issuedmm, issuedyy;
	int duedd, duemm, dueyy;
}lib;
void Password();
void display_book();/*display book details*/

void addbook();/*add book information*/

void delete_book();/*delete  book info/records on by user given key eg.authorname, book no, */

void search();/*search  book info/records by user given key eg.authorname, book no, */

void edit_info();/*edit  book info/records by user given key eg.authorname, book no, */

void issuerecord(struct lib); /*Receipt*/

