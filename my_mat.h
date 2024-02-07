#ifndef MY_MAT_H
#define MY_MAT_H
/*define for Section B*/
#define SIZE 10            // 10 represents the matrix size
#define INF 1000000        // A variable that represents that a path between vertices does not exist
/*define for Section B*/
#define MAX_CAP 20         // Maximum weight to carry in a knapsack  
#define N 5                // nubmer of products
#define FALSE 0
#define TRUE 1


/*****************************************/
/***Functions declaration for section A***/
/*****************************************/

// Main functions Declaration
void setMatrix(int[SIZE][SIZE]);
void isPath(int[SIZE][SIZE], int, int);
void shortestPath(int[SIZE][SIZE], int, int);

// Auxiliary Functions Declaration
void floydWarshall(int[SIZE][SIZE]); 



/*****************************************/
/***Functions declaration for section B***/
/*****************************************/

// Functions Declaration
int knapSack(int[], int[], int[]);
int max(int, int);


#endif
