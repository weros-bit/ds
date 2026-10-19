
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
    if (rear == 4)
    {
        printf("Queue Overflow! Print queue is full.\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;

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

    front++;

    if (front > rear)
        front = rear = -1;
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

    for (i = front; i <= rear; i++)
    {
        printf("Job ID: %d\n", q[i].id);
        printf("Document Title: %s\n", q[i].title);
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