#this is comment 
#makefile is not in c

main.o: main.c
	gcc -c -o main.o main.c

statistic.o: statistic.c
	gcc -c -o statistic.o statistic.c
 
#wild card approach: every file
#this compiles each c file in object file
%.o: %.c
	gcc -c -o %@ %<


#this link the object into an exectuable
program: %(OBJ)
	gcc -o %@ %<


#to build the thing on the left check right
program: main.c statistic.c
	gcc -o program main.c statistic.c


# link them together if they change
#-o means: "output file name"
program: main.o statistic.o
	gcc -o program main.o statistic.o

#THIS IS A LIST OF C FILE THAT MAKE IT INTO OBJECT FILE
OBJ = main.o statistic.o 

Target = program

#wild card approach: every file
#this compiles each c file in object file
%.o: %.c
	gcc -c -o %@ %<


#this link the object into an exectuable
%(target): %(OBJ)
	gcc -o %@ %<