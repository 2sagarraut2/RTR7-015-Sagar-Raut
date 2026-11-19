#include <stdio.h>

int queue[5];
int front = -1;
int rear = -1;

int main(void)
{

    // function declarations
    void enQueue(int);
    void deQueue();
    void display();

    enQueue(10);
    enQueue(20);
    enQueue(30);
    enQueue(40);
    enQueue(50);

    printf("After Enqueue");
    display();

    deQueue();

    printf("After Dequeue");
    display();

    return (0);
}

void enQueue(int value)
{
    if (rear == 4)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
}

void deQueue()
{
    if (front == -1 || rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("\nRemoved %d from queue\n\n", queue[front]);

        front++;
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

void display()
{
    printf("\nElements are \n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d\n", queue[i]);
    }
}