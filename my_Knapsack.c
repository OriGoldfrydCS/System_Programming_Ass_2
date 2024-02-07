#include <stdio.h>
#include "my_mat.h"

int main() 
{
    char productsArray[N];
    int values[N];
    int weights[N];
    int selected_bool[N];   // An array for track the selection status of each product

    for(int i = 0; i < N; i++) {
        scanf(" %c", &productsArray[i]);
        scanf("%d", &values[i]);  
        scanf("%d", &weights[i]);  
    }

    int maxProfit = knapSack(weights, values, selected_bool);  // Call the knapSack function

    printf("Maximum profit: %d\n", maxProfit);
    printf("Selected items:");
    for (int i = 0; i < N; i++) 
    {
        if (selected_bool[i] == TRUE) {
            printf(" %c", productsArray[i]);  // Print the selected products
        }
    }

    return 0;
}