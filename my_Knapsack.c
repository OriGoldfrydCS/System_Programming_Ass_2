#include <stdio.h>
#include "my_mat.h"

int main() 
{
    char productsArray[N];  // An array for storing the N products
    int values[N];          // An array for storing the value i of product i in productsArray
    int weights[N];         // An array for storing the wight i of product i in productsArray
    int selected_bool[N];   // A boolean array for tracking the selection status of each product

    for(int i = 0; i < N; i++)      // Get the inputs from the user
    {
        scanf(" %c", &productsArray[i]);
        scanf("%d", &values[i]);  
        scanf("%d", &weights[i]);  
    }

    int maxProfit = knapsack(weights, values, selected_bool);  // Call the knapSack function (see in my_math.c)
                                                               // That fucntions return a table help us to maximize f(i)*v(i) to all N, where f belong to {0,1}
    printf("Maximum profit: %d\n", maxProfit);
    printf("Selected items:");
    for (int i = 0; i < N; i++) 
    {
        if (selected_bool[i] == TRUE) 
        {
            printf(" %c", productsArray[i]);  // Print the selected products that maximize the value (and subject to MAX_CAP) marked as True
        }
    }

    return 0;
}