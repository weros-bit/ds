
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int regno;
    char name[30];
    struct node *next;
};

void add_student(struct node *head)
{
    struct node *ptr, *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter registration number and name: ");
    scanf("%d %29s", &newnode->regno, newnode->name);

    newnode->next = NULL;
    ptr = head;

    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = newnode;

    printf("Student added successfully.\n");
}

void remove_student(struct node *head)
{
    struct node *ptr, *temp;
    int regno;

    printf("Enter registration number to remove: ");
    scanf("%d", &regno);

    ptr = head;

    while(ptr->next != NULL &&
          ptr->next->regno != regno)
        ptr = ptr->next;

    if(ptr->next == NULL)
    {
        printf("Student not found.\n");
        return;
    }

    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);

    printf("Student removed successfully.\n");
}

void display(struct node *head)
{
    struct node *temp;

    temp = head->next;

    if(temp == NULL)
    {
        printf("No students registered.\n");
        return;
    }

    while(temp != NULL)
    {
        printf("%d %s\n", temp->regno, temp->name);
        temp = temp->next;
    }
}

void count_students(struct node *head)
{
    struct node *temp;
    int count = 0;

    temp = head->next;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Total participants: %d\n", count);
}

void sort_list(struct node *head)
{
    struct node *ptr, *temp;
    int reg;
    char name[30];

    for(ptr = head->next; ptr != NULL; ptr = ptr->next)
    {
        for(temp = ptr->next; temp != NULL; temp = temp->next)
        {
            if(ptr->regno > temp->regno)
            {
                reg = ptr->regno;
                ptr->regno = temp->regno;
                temp->regno = reg;

                strcpy(name, ptr->name);
                strcpy(ptr->name, temp->name);
                strcpy(temp->name, name);
            }
        }
    }

    printf("List sorted successfully.\n");
}

void reverse_list(struct node *head)
{
    struct node *ptr, *temp, *prev;

    prev = NULL;
    ptr = head->next;

    while(ptr != NULL)
    {
        temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }

    head->next = prev;

    printf("List reversed successfully.\n");
}

int main()
{
    struct node *head;
    int ch;

    head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;

    do
    {
        printf("\n1. Add Student");
        printf("\n2. Remove Student");
        printf("\n3. Display List");
        printf("\n4. Count Participants");
        printf("\n5. Sort List");
        printf("\n6. Reverse List");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                add_student(head);
                break;

            case 2:
                remove_student(head);
                break;

            case 3:
                display(head);
                break;

            case 4:
                count_students(head);
                break;

            case 5:
                sort_list(head);
                break;

            case 6:
                reverse_list(head);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(ch != 0);

    while(head->next != NULL)
    {
        struct node *temp = head->next;
        head->next = temp->next;
        free(temp);
    }

    free(head);

    return 0;
}
