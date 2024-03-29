#include <stdio.h>
#include "my_mat.h"

/*****************************/
/***Functions for section A***/
/*****************************/

/*This function sets the adjacency matrix of the graph by the user (Section A.1)*/
void setTable(int table[SIZE][SIZE]) 
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            scanf("%d", &table[i][j]);
            if(table[i][j] == 0 && i != j)      // If input is 0, and i unequal to j: no path between i and j          
            {                                   // We will define that case with MAX_INT
                table[i][j] = INF;
            }
        }
    }
    floydAlgo(table);
}

/*This auxiliary function implements the Floyd-Warshall algorithm (auxiliary function for getTable)*/
void floydAlgo(int table[SIZE][SIZE]) 
{
    for (int k = 0; k < SIZE; k++)             // Iterate through all possible intermediate vertices
    {           
        for (int i = 0; i < SIZE; i++)         // Iterate through all possible source vertices
        {       

            for (int j = 0; j < SIZE; j++)     // Iterate through all possible destination vertices
            {
                if (table[i][k] != INF && table[k][j] != INF && table[i][k] + table[k][j] < table[i][j])    // If vertex k is on the shortest path from vertex i to vertex j,
                                                                                                            // then update the value of table[i][j]
                {
                    table[i][j] = table[i][k] + table[k][j];
                }
            }
        }
    }
}

/*This function checks if there's a route between vertex i and vertex j (Section A.2)*/
void isPath(int table[SIZE][SIZE], int i, int j) 
{
    if (table[i][j] != INF && i != j)       // Ensure a path exists and it is not a self-loop
    { 
        printf("True\n");
    } 
    else 
    {
        printf("False\n");
    }
}

/*This function prints the shortest path length between vertex i and vertex j (Section A.3)*/
void shortestPath(int table[SIZE][SIZE], int i, int j) 
{
    if (table[i][j] != INF && i != j)           // Check for a valid path that's not a self-loop
    {        
        printf("%d\n", table[i][j]);
    } 
    else 
    {
        printf("-1\n");                         // No path exists or self-loop
    }
}



/*****************************/
/***Functions for section B***/
/*****************************/

/*This function returns the maximum total value that can be achieved within the MAX_CAP using Dynamic Programmin,
and modifies the selected_bool[] array to indicate which items contribute to this maximum value*/
int knapsack(int weights[], int values[], int selected_bool[]) {
    int p;                      // p represents a product
    int w;                      // w represents a weight of the product
    int DP[N+1][MAX_CAP+1];     // DP table with (n+1) rows and (MAX_CAP+1) columns, to consider the options the no product or weight taken

    // Initialize the DP table
    for (p = 0; p <= N; p++)                // Iterate through each product (including the option that no products taken)
    {
        for (w = 0; w <= MAX_CAP; w++)      // Iterate through all possible capacities of a specific product from 0 to MAX_CAP
        {
            if (p == 0 || w == 0)
                DP[p][w] = 0;                // Base case: if no products or weight is 0, profit is 0
            else if (weights[p-1] <= w)      // If weight of the p'th product is less than or equal to 'w',
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

    for (p = N; p > 0 && result > 0; p--)       // Check if the value comes from (DP[p-1][w]) or (values[p-1] + DP[p-1][w-weights[p-1]])
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

/*This auxiliary function finds the maximum of two integers*/ 
int max(int x, int y) 
{ 
    if(x > y)
    {
        return x;
    }   
    return y; 
}