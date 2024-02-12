#include <stdio.h>
#include <ctype.h>
#include "my_mat.h"

int main() 
{
    int table[SIZE][SIZE];  // A variable that represents a table 10*10
    char action;            // A variable for storing the user's choice ('A'-'D') 
    int i, j;               // A variable for columns and rows in the table

    while(TRUE) 
    {
        if(scanf(" %c", &action) == EOF || action == 'D')  // 'D' and EOF mean terminate the program ' 
        {
            break;
        }

        action = toupper(action);             // Convert the input character to uppercase (to prevent misunderstandings)     

        switch(action) 
        {
            case 'A':                         // 'A' means ask the user to insert the table values 
                setTable(table);
                break;
            case 'B':                         // 'B' means ask the user to insert two values (i, j); and prints "True" if a path from i to j exists. Otherwise, print "False"
                scanf("%d %d", &i, &j);
                isPath(table, i, j);
                break;
            case 'C':                         // 'C' means ask the user to insert two values (i, j); and prints the shortest path from i to j. If does not exist print -1
                scanf("%d %d", &i, &j);
                shortestPath(table, i, j);
                break;
            default:                          // Default case: if the user type none of the valid options
                printf("Invalid action! Please choose A, B, C or D\n");
        }
    }

    return 0;
}