/*Library management*/
struct lib {
	char usename[32];
	char bookname[32];
	char writer[32];
	char category[32];
	int book_no;
	int dd, mm, yy;
}lib;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m" 

void Password();/*Password protection*/

void display_book(struct lib);/*display book details*/

void addbook();/*add book information*/

void delete_book(struct lib);/*delete  book info/records on by user given key eg.authorname, book no, */

void search(struct lib);/*search  book info/records by user given key eg.authorname, book no, */

void edit_info(struct lib);/*edit  book info/records by user given key eg.authorname, book no, */

void shortinfo(struct lib); /*short information on what added*/

int checkdate(int day, int month, int year);

void exitp();
