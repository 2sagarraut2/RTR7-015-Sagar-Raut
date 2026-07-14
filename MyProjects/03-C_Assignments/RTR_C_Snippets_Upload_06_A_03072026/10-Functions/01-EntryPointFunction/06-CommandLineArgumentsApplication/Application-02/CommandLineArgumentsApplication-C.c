#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
    int i;
    int SR_num;
    int SR_sum = 0;

    if (argc != 4)
    {
        printf("\n\n");

        printf("Invalid usage, exiting now\n\n");

        printf("Usage: CommandLineArgumentsApplication <first name> <middle name> <surname>...\n\n");

        exit(0);
    }

    printf("\n\n");
    printf("Full name entered is: \n\n");
    for (i = 1; i < argc; i++)
    {
        printf("%s ", argv[i]);
    }

    printf("\n\n");

    return 0;
}