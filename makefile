# General macros
CC = gcc
AR = ar
FLAGS = -Wall -g

# Default target: compile all programs and library
all: my_graph my_Knapsack

# Program files compiling rules
my_graph: my_graph.o my_mat.a
	$(CC) $(FLAGS) my_graph.o my_mat.a -o my_graph -lm

my_Knapsack: my_Knapsack.o my_mat.a
	$(CC) $(FLAGS) my_Knapsack.o my_mat.a -o my_Knapsack -lm

# Object files compiling rule for section A
my_graph.o: my_graph.c 
	$(CC) $(FLAGS) -c my_graph.c -fPIC

# Object files compiling rule for section B
my_Knapsack.o: my_Knapsack.c
	$(CC) $(FLAGS) -c my_Knapsack.c -fPIC

# Object file for library mat.c
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

# Static library
my_mat.a: my_mat.o
	$(AR) -rcs my_mat.a my_mat.o

# Clean-up
clean:
	rm -f *.o *.a my_graph my_Knapsack

.PHONY: all clean