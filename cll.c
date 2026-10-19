
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff, exp;
    struct node *next;
};

struct node* create()
{
    struct node *head, *ptr, *newnode;
    int n, i;

    head = NULL;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &newnode->coeff, &newnode->exp);

        if(head == NULL)
        {
            head = newnode;
            newnode->next = head;
        }
        else
        {
            ptr = head;

            while(ptr->next != head)
                ptr = ptr->next;

            ptr->next = newnode;
            newnode->next = head;
        }
    }

    return head;
}

void display(struct node *head)
{
    struct node *temp;

    if(head == NULL)
    {
        printf("0\n");
        return;
    }

    temp = head;

    do
    {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;

        if(temp != head)
            printf(" + ");

    } while(temp != head);

    printf("\n");
}

struct node* add(struct node *head1, struct node *head2)
{
    struct node *head3 = NULL;
    struct node *t1, *t2, *t3, *newnode;
    int coeff;

    if(head1 == NULL)
        return head2;

    if(head2 == NULL)
        return head1;

    t1 = head1;

    do
    {
        t2 = head2;

        while(t2->exp != t1->exp && t2->next != head2)
            t2 = t2->next;

        if(t2->exp == t1->exp)
            coeff = t1->coeff + t2->coeff;
        else
            coeff = t1->coeff;

        if(coeff != 0)
        {
            newnode = (struct node*)malloc(sizeof(struct node));
            newnode->coeff = coeff;
            newnode->exp = t1->exp;

            if(head3 == NULL)
            {
                head3 = newnode;
                newnode->next = head3;
            }
            else
            {
                t3 = head3;

                while(t3->next != head3)
                    t3 = t3->next;

                t3->next = newnode;
                newnode->next = head3;
            }
        }

        t1 = t1->next;

    } while(t1 != head1);

    t2 = head2;

    do
    {
        t1 = head1;

        while(t1->exp != t2->exp && t1->next != head1)
            t1 = t1->next;

        if(t1->exp != t2->exp && t2->coeff != 0)
        {
            newnode = (struct node*)malloc(sizeof(struct node));
            newnode->coeff = t2->coeff;
            newnode->exp = t2->exp;

            if(head3 == NULL)
            {
                head3 = newnode;
                newnode->next = head3;
            }
            else
            {
                t3 = head3;

                while(t3->next != head3)
                    t3 = t3->next;

                t3->next = newnode;
                newnode->next = head3;
            }
        }

        t2 = t2->next;

    } while(t2 != head2);

    return head3;
}

int main()
{
    struct node *head1, *head2, *head3;

    printf("First polynomial:\n");
    head1 = create();

    printf("Second polynomial:\n");
    head2 = create();

    printf("First polynomial: ");
    display(head1);

    printf("Second polynomial: ");
    display(head2);

    head3 = add(head1, head2);

    printf("Resultant polynomial: ");
    display(head3);

    return 0;
}
