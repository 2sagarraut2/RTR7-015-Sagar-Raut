#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    void function_country(void);

    function_country();

    printf("\n---End---\n\n");

    return (0);
}

void function_country()
{
    void functionOfAMC(void);

    functionOfAMC();

    printf("\n\n");

    printf("I live in india");
}

void functionOfAMC(void)
{
    void functionSurname(void);

    functionSurname();
    printf("\n\n");

    printf("Of AstroMediComp.");
}

void functionSurname(void)
{
    void functionMiddleName(void);

    functionMiddleName();
    printf("\n\n");

    printf("Raut ");
}

void functionMiddleName(void)
{
    void functionFirstName(void);

    functionFirstName();
    printf("\n\n");

    printf("Sambhaji ");
}

void functionFirstName(void)
{

    void functionIs(void);

    functionIs();

    printf("\n\n");

    printf("Sagar ");
}

void functionIs(void)
{
    printf("\n\n");

    printf("Is ");
}

void functionName(void)
{
    void functionMy(void);

    functionMy();
    printf("\n\n");

    printf("Name ");
}

void functionMy(void)
{
    printf("\n\n");

    printf("My ");
}
