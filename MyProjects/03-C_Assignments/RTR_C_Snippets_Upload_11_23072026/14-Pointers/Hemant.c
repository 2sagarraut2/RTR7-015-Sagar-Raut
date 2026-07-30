#include <stdio.h>
#include <string.h>
#define MAX_STRING_LEMGTH 512

int main(void)
{
    char *SR_customStrlen(char *str);

    char hbArray_original[MAX_STRING_LEMGTH];

    // code
    // string input
    printf("\n");
    printf("Enter A string : \n");
    fgets(hbArray_original, MAX_STRING_LEMGTH, stdin);
    printf("\n");
    printf("The original string entered by you (SR_i.e : 'hbArray_original[]' is : \n)");
    printf("%s\n", hbArray_original);

    // string output
    printf("\n");
    printf("The reversed string (SR_i.e :'hbArray_Reverse[]' is : \n)");
    printf("%s\n", SR_customStrlen(hbArray_original));
    return (0);
}

char *SR_customStrlen(char *str)
{

    if (!str)
        return NULL;

    int SR_i = 0;
    int SR_j = strlen(str) - 1;

    while (SR_i < SR_j)
    {
        char temp = str[SR_i];
        str[SR_i] = str[SR_j];
        str[SR_j] = temp;
        SR_i++;
        SR_j--;
    }

    return str;
}