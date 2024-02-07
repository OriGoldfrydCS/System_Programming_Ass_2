#include "my_mat.h"
#include <stdio.h>

/*****************************/
/***Functions for section A***/
/*****************************/

/*This function sets the adjacency matrix of the graph by the user*/
void setMatrix(int matrix[SIZE][SIZE]) 
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            scanf("%d", &matrix[i][j]);
            if(matrix[i][j] == 0 && i != j)     // If input is 0, and i uneques to j: no path between i and j          
            {                                   // We will define that case with MAX_INT
                matrix[i][j] = INF;
            }
        }
    }
    floydWarshall(matrix);
}

/*This function implements the Floyd-Warshall algorithm (auxiliary function for getMatrix)*/
void floydWarshall(int matrix[SIZE][SIZE]) 
{
    for (int k = 0; k < SIZE; k++)             // Iterate through all possible intermediate vertices
    {           
        for (int i = 0; i < SIZE; i++)         // Iterate through all possible source vertices
        {       

            for (int j = 0; j < SIZE; j++)     // Iterate through all possible destination vertices
            {
                if (matrix[i][k] != INF && matrix[k][j] != INF && matrix[i][k] + matrix[k][j] < matrix[i][j])    /*If vertex k is on the shortest path from vertex i to vertex j,*/
                                                                                                                 /*then update the value of graph[i][j]*/
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
}

/*This function checks if there's a route between vertex i and vertex j*/
void isPath(int matrix[SIZE][SIZE], int i, int j) 
{
    if (matrix[i][j] != INF && i != j)       // Ensure there's a path and it's not a self-loop
    { 
        printf("True\n");
    } 
    else 
    {
        printf("False\n");
    }
}

/*This function prints the shortest path length between vertex i and vertex j*/
void shortestPath(int matrix[SIZE][SIZE], int i, int j) 
{
    if (matrix[i][j] != INF && i != j)          // Check for a valid path that's not a self-loop
    {        
        printf("%d\n", matrix[i][j]);
    } 
    else {
        printf("-1\n");                         // No path exists, or it's an invalid query for self-loop
    }
}



/*****************************/
/***Functions for section B***/
/*****************************/

/*This function solves the Integer Knapsack Problem using Dynamic Programmin*/

int knapSack(int weights[], int values[], int selected_bool[]) {
    int p;                      // p represents a product
    int w;                      // w represents a weight
    int DP[N+1][MAX_CAP+1];     // DP table with (n+1) rows and (MAX_CAP+1) columns, to consider the options the no product or weight taken

    // Initialize the DP table
    for (p = 0; p <= N; p++)                // Iterate through each product (including no products taken)
    {
        for (w = 0; w <= MAX_CAP; w++)      // Iterate through all possible capacities of a specific product from 0 to MAX_CAP
        {
            if (p == 0 || w == 0)
                DP[p][w] = 0;                // Base case: if no products or weight is 0, profit is 0
            else if (weights[p-1] <= w)      // If weight of the nth product is less than or equal to 'w',
                                             // consider the maximum of two cases:
                                             // 1. nth product included
                                             // 2. not included
                DP[p][w] = max(values[p-1] + DP[p-1][w-weights[p-1]], DP[p-1][w]);
            else
                DP[p][w] = DP[p-1][w];
        }
    }

    /*The maximum products that can be put in a knapsack for capacity MAX_CAP*/
    int result = DP[N][MAX_CAP];
    w = MAX_CAP;

    for (p = 0; p < N; p++)                     // Initialize all cell with FALSE
    {                                       
        selected_bool[p] = FALSE;
    }

    for (p = N; p > 0 && result > 0; p--)       // Check if the value comes from the top (K[i-1][w]) or from (values[i-1] + K[i-1][w-weights[i-1]])
    {    
                                                // If it comes from the latter, it means the product is included
        if(result == DP[p-1][w])
            continue;                           // This product is not included (Identical for selected_bool[p-1] = FALSE) 
        else 
        {
            selected_bool[p-1] = TRUE;          // The product is included
            result = result - values[p-1];      // Uptate the value
            w = w - weights[p-1];               // Update the weight lefts
        }
    }

    return DP[N][MAX_CAP]; 
}

/*This function finds the maximum of two integers*/ 
int max(int x, int y) 
{ 
    if(x > y)   return x;
    else        return y; 
}