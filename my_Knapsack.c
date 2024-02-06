#include <stdio.h>
#include "my_mat.h"

int main() 
{
    char productsArray[] = {'A', 'B', 'C', 'D', 'E'};
    int values[N];
    int weights[N];
    int selected_bool[N];   // An array for track the selection status of each product

    for(int i = 0; i < N; i++) {
        printf("Insert value for product %c: ", productsArray[i]);
        scanf("%d", &values[i]);  

        printf("Insert weight for product %c: ", productsArray[i]);
        scanf("%d", &weights[i]);  
    }

    int maxProfit = knapSack(weights, values, selected_bool);  // Call the knapSack function

    printf("Maximum profit: %d\n", maxProfit);
    printf("Items that give the maximum profit: ");
    for (int i = N-1; i >= 0; i--) 
    {
        if (selected_bool[i] == TRUE) {
            printf("%c ", productsArray[i]);  // Print the selected products
        }
    }
    printf("\n");

    return 0;
}