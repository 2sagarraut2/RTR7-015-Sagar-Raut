#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Hello World!\n");
    printf("Number of command line arguments = %d\n\n", argc);

    printf("Command line arguments passed to this program are:\n");

    for (int SR_i = 0; SR_i < argc; SR_i++)
    {
        printf("Command line argument number %d = %s\n", (SR_i + 1), argv[SR_i]);
    }

    return 0;
}