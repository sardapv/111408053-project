/*Library management*/
struct lib {
	char usename[32];
	char bookname[32];
	char writer[32];
	char category[32];
	int book_no;
	int dd, mm, yy;
}lib;

void Password();/*Password protection*/

void display_book(struct lib);/*display book details*/

void addbook();/*add book information*/

void delete_book(struct lib);/*delete  book info/records on by user given key eg.authorname, book no, */

void search(struct lib);/*search  book info/records by user given key eg.authorname, book no, */

void edit_info(struct lib);/*edit  book info/records by user given key eg.authorname, book no, */

void shortinfo(struct lib); /*short information on what added*/

int checkdate(int day, int month, int year);
