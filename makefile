# General macros
CC = gcc
FLAGS = -Wall -g

# Target
all: my_graph my_Knapsack

# Program files compiling rules
my_graph: my_graph.o my_mat.o
	$(CC) $(FLAGS) my_graph.o my_mat.o -o my_graph

my_Knapsack: my_Knapsack.o my_mat.o
	$(CC) $(FLAGS) my_Knapsack.o my_mat.o -o my_Knapsack

# Object files compiling rules for section A
my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c my_graph.c -lm

# Object files compiling rules for section B
my_Knapsack.o: my_Knapsack.c my_mat.h
	$(CC) $(FLAGS) -c my_Knapsack.c

# Obhect file for library
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

# Clean-up
clean:
	rm -f *.o *.a my_graph my_Knapsack