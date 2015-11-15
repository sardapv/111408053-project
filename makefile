project : main.o lib.o
	cc main.o lib.o -o project 
main.o : main.c lib.h
	cc main.c -c
lib.o : lib.c lib.h
	cc lib.c -c
clean :
	rm -rf *o project
