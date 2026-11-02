#include <stdio.h>

int stack[5];
int top = -1;
int poppedElement = 0;

int main()
{
    int pop();
    void push(int);

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);

    printf("\n\n");
    printf("Elements in stack:\n");
    for (int i = top; i >= 0; i--)
    {
        if (top == -1)
        {
            printf("Stack is Empty\n");
            return 0;
        }
        printf("stack[%d] = %d\n", i, stack[i]);
    }
    printf("\n\n");

    poppedElement = pop();
    printf("Popped %d\n", poppedElement);

    poppedElement = pop();
    printf("Popped %d\n", poppedElement);

    poppedElement = pop();
    printf("Popped %d\n", poppedElement);

    poppedElement = pop();
    printf("Popped %d\n", poppedElement);

    poppedElement = pop();
    printf("Popped %d\n", poppedElement);

    printf("\n\n");
    printf("Elements in stack:\n");
    for (int i = top; i >= 0; i--)
    {
        if (top == -1)
        {
            printf("Stack is Empty\n");
            return 0;
        }
        printf("stack[%d] = %d\n", i, stack[i]);
    }
    printf("\n\n");

    return 0;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return 0;
    }

    int deletedElement = stack[top];
    top--;
    return deletedElement;
}

void push(int element)
{

    top++;
    if (top > 4)
    {

        printf("Stack is full cannot insert element at %d index\n", top);
        top--;
        return;
    }

    stack[top] = element;
    printf("Inserted %d at %d index\n", element, top);
}