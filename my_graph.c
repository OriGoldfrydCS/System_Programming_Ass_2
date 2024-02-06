#include "my_mat.h"
#include <stdio.h>
#include <ctype.h>

int main() 
{
    int matrix[SIZE][SIZE]; // A variable that represents a matrix 10*10
    char action;            // A variable for the user's choice ('A'-'D') 
    int i, j;               // A variable for column and row in the matrix

    while(1) 
    {
        scanf(" %c", &action);

        action = toupper(action);   // Convert the input character to uppercase (if needed)


        if(action == 'D')          // 'D' means terminate the program
        {
            break;
        }

        switch(action) 
        {
            case 'A':                         // 'A' means ask the user to insert the matrix values 
                setMatrix(matrix);
                break;
            case 'B':                         // 'B' means ask the user to insert two values (i, j); and prints "True" if there is a path from i to j. Otherwise, print "False"
                scanf("%d %d", &i, &j);
                isPath(matrix, i, j);
                break;
            case 'C':                         // 'C' means ask the user to insert two values (i, j); and prints the shortest path from i to j. If it does not exist prints -1
                scanf("%d %d", &i, &j);
                shortestPath(matrix, i, j);
                break;
            default:                          // Default case: if the user type none of the valid options
                printf("Invalid action. Please choose A, B, C or D\n");
        }
    }

    return 0;
}
