#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int **ptr_iArray = NULL;

    int SR_i, SR_j;
    int num_rows, num_columns;

    printf("\n\n");
    printf("Enter number of rows\n");
    scanf("%d", &num_rows);

    printf("Enter number of columns\n");
    scanf("%d", &num_columns);

    printf("\n\n");
    printf("memory allocation for 2D integer array\n");
    ptr_iArray = (int **)malloc(sizeof(int *) * num_rows);

    if (ptr_iArray == NULL)
    {
        printf("Memory allocatio for %d rows failed!\n", num_rows);
    }
    else
    {
        printf("Memory allocation for %d rows is successful!\n", num_rows);
    }

    for (SR_i = 0; SR_i < num_rows; SR_i++)
    {
        ptr_iArray[SR_i] = (int *)malloc(sizeof(int) * num_columns);

        if (ptr_iArray[SR_i] == NULL)
        {
            printf("Memory allocatio for %d rows failed!\n", num_rows);
        }
        else
        {
            printf("Memory allocation for %d rows is successful!\n", num_rows);
        }
    }

    // filling up values
    for (SR_i = 0; SR_i < num_rows; SR_i++)
    {
        for (SR_j = 0; SR_j < num_columns; SR_j++)
        {
            ptr_iArray[SR_i][SR_j] = (SR_i * 1) + (SR_j * 1);
        }
    }

    for (SR_i = 0; SR_i < num_rows; SR_i++)
    {
        printf("Base address of row %d = ptr_iArray[%d] = %p \t at address : %p\n", SR_i, SR_i, ptr_iArray[SR_i], &ptr_iArray[SR_i]);
    }

    printf("\n\n");

    for (SR_i = 0; SR_i < num_rows; SR_i++)
    {
        for (SR_j = 0; SR_j < num_columns; SR_j++)
        {
            printf("ptr_iArray[%d][%d] = %d \t at address %p\n", SR_i, SR_j, ptr_iArray[SR_i][SR_j], &ptr_iArray[SR_i][SR_j]);
        }
        printf("\n");
    }

    for (SR_i = (num_rows - 1); SR_i >= 0; SR_i--)
    {
        if (ptr_iArray[SR_i])
        {
            free(ptr_iArray[SR_i]);
            ptr_iArray[SR_i] = NULL;
            printf("memory allocated for %d rows has been released!\n", SR_i);
        }
    }

    if (ptr_iArray)
    {
        free(ptr_iArray);
        ptr_iArray = NULL;
        printf("Memory allocated for ptr_iArray has been released\n");
    }

    printf("\n\n--End--\n\n");
    return (0);
}