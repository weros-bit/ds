
#include <stdio.h>

struct job
{
    int id;
    char title[50];
};

struct job q[5];
int front = -1, rear = -1;

void enqueue()
{
    if ((rear + 1) % 5 == front)
    {
        printf("Queue Overflow! Print queue is full.\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % 5;

    printf("Enter Job ID: ");
    scanf("%d", &q[rear].id);

    printf("Enter Document Title: ");
    scanf("%49s", q[rear].title);

    printf("Print job added successfully.\n");
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow! No print jobs available.\n");
        return;
    }

    printf("\nProcessing Print Job:\n");
    printf("Job ID: %d\n", q[front].id);
    printf("Document Title: %s\n", q[front].title);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % 5;
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("No Pending Print Jobs.\n");
        return;
    }

    printf("\nPrint Jobs in Queue:\n");

    i = front;

    while (1)
    {
        printf("Job ID: %d\n", q[i].id);
        printf("Document Title: %s\n", q[i].title);

        if (i == rear)
            break;

        i = (i + 1) % 5;
    }
}

int main()
{
    int ch;

    do
    {
        printf("\n--- PRINTER QUEUE MANAGER ---\n");
        printf("1. Enqueue Print Job\n");
        printf("2. Dequeue Print Job\n");
        printf("3. Display Print Jobs\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice.\n");
        }
    } while (ch != 4);

    return 0;
}
