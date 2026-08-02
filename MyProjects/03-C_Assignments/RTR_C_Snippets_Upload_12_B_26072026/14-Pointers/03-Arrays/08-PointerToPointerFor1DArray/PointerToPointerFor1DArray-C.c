#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    void SR_MyAlloc(int **ptr, unsigned int SR_numberOfElements);

    int *SR_piArray = NULL;
    unsigned int SR_numElements;
    int i;

    printf("Please enter number of elements for integer array\n");
    scanf("%u", &SR_numElements);

    printf("\n\n");
    SR_MyAlloc(&SR_piArray, SR_numElements);

    printf("Enter %u to elements for array\n", SR_numElements);
    for (i = 0; i < SR_numElements; i++)
    {
        scanf("%d", &SR_piArray[i]);
    }

    printf("\nElements entered by you for integer array are:\n");
    for (i = 0; i < SR_numElements; i++)
    {
        printf("%u\n", SR_piArray[i]);
    }

    printf("\n\n");
    if (SR_piArray)
    {
        free(SR_piArray);
        printf("Memory allocated has been successfully releasd");
    }

    printf("\n\n--End--\n\n");
    return (0);
}

void SR_MyAlloc(int **ptr, unsigned int SR_numberOfElements)
{
    *ptr = (int *)malloc(SR_numberOfElements * sizeof(int));

    if (*ptr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }

    printf("SR_MyAlloc() successfully allocate %lu bytes for integer array\n\n", (SR_numberOfElements * sizeof(int)));
}