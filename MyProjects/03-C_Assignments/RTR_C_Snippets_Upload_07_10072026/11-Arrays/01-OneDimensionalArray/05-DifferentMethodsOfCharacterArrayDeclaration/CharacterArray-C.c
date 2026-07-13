#include <stdio.h>

int main(void)
{
    char chArray_01[] = {'A', 'S', 'T', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P'};

    char chArray_02[9] = {'W', 'E', 'L', 'C', 'O', 'M', 'E', 'S'};

    char chArray_03[] = {'Y', 'O', 'U', '\0'};

    char chArray_04[] = "To";

    char chArray_05[] = "REAL TIME RENDERING BATCH OF 2026-27";

    char chArrayWithoutNULLTerminator[] = {'H', 'e', 'l', 'l', 'o'};

    printf("\n\n");

    printf("Size of chArray_01 : %lu\n\n", sizeof(chArray_01));
    printf("Size of chArray_01 : %lu\n\n", sizeof(chArray_02));
    printf("Size of chArray_01 : %lu\n\n", sizeof(chArray_03));
    printf("Size of chArray_01 : %lu\n\n", sizeof(chArray_04));
    printf("Size of chArray_01 : %lu\n\n", sizeof(chArray_05));

    printf("\n\n");

    printf("The Strings are : \n\n");
    printf("chArray_01 : %s\n\n", chArray_01);
    printf("chArray_01 : %s\n\n", chArray_02);
    printf("chArray_01 : %s\n\n", chArray_03);
    printf("chArray_01 : %s\n\n", chArray_04);
    printf("chArray_01 : %s\n\n", chArray_05);

    printf("\n\n");
    printf("size of chArrayWithoutNULLTerminator : %lu\n\n", sizeof(chArrayWithoutNULLTerminator));
    printf("chArrayWithoutNULLTerminator : %s\n\n", chArrayWithoutNULLTerminator);

    printf("\n\n--End--\n\n");
    return (0);
}