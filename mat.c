
#include <stdio.h>

void input(int a[10][10], int r, int c)
{
    int i, j;

    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
}

void display(int a[10][10], int r, int c)
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%d ", a[i][j]);

        printf("\n");
    }
}

void addition(int a[10][10], int b[10][10],
              int r, int c)
{
    int i, j, result[10][10];

    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            result[i][j] = a[i][j] + b[i][j];

    printf("Addition:\n");
    display(result, r, c);
}

void subtraction(int a[10][10], int b[10][10],
                 int r, int c)
{
    int i, j, result[10][10];

    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            result[i][j] = a[i][j] - b[i][j];

    printf("Subtraction:\n");
    display(result, r, c);
}

void multiplication(int a[10][10], int b[10][10],
                    int r1, int c1, int c2)
{
    int i, j, k, result[10][10];

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            result[i][j] = 0;

            for(k = 0; k < c1; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
    }

    printf("Multiplication:\n");
    display(result, r1, c2);
}

void transpose(int a[10][10], int r, int c)
{
    int i, j, result[10][10];

    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            result[j][i] = a[i][j];

    printf("Transpose:\n");
    display(result, c, r);
}

int main()
{
    int a[10][10], b[10][10];
    int r1, c1, r2, c2, ch;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter first matrix:\n");
    input(a, r1, c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d%d", &r2, &c2);

    printf("Enter second matrix:\n");
    input(b, r2, c2);

    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Transpose");
    printf("\nEnter choice: ");
    scanf("%d", &ch);

    switch(ch)
    {
        case 1:
            if(r1 == r2 && c1 == c2)
                addition(a, b, r1, c1);
            else
                printf("Addition not possible");
            break;

        case 2:
            if(r1 == r2 && c1 == c2)
                subtraction(a, b, r1, c1);
            else
                printf("Subtraction not possible");
            break;

        case 3:
            if(c1 == r2)
                multiplication(a, b, r1, c1, c2);
            else
                printf("Multiplication not possible");
            break;

        case 4:
            transpose(a, r1, c1);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}
