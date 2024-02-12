#ifndef MY_MAT_H
#define MY_MAT_H

/*Defines for Section A*/
#define MAX_STRING_LENGTH 20   // 20 represents the max string length for product's name
#define SIZE 10                // 10 represents the table size
#define INF 1000000            // A variable that represents that a path between vertices does not exist
/*Defines for Section B*/
#define MAX_CAP 20         // Maximum weight to carry in a knapsack  
#define N 5                // nubmer of products
#define FALSE 0
#define TRUE 1


/*****************************************/
/***Functions declaration for section A***/
/*****************************************/

// Main functions Declaration
void setTable(int[SIZE][SIZE]);
void isPath(int[SIZE][SIZE], int, int);
void shortestPath(int[SIZE][SIZE], int, int);

// Auxiliary Functions Declaration
void floydAlgo(int[SIZE][SIZE]); 



/*****************************************/
/***Functions declaration for section B***/
/*****************************************/

// Main function Declaration
int knapsack(int[], int[], int[]);

// Auxiliary Function Declaration
int max(int, int);


#endif
