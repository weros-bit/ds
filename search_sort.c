
#include <stdio.h>

struct student
{
    int roll;
    char name[30];
};

void display(struct student s[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d %s\n", s[i].roll, s[i].name);
}

void linearSearch(struct student s[], int n, int key)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(s[i].roll == key)
        {
            printf("Student found: %s\n", s[i].name);
            return;
        }
    }

    printf("Student not found\n");
}

void insertionSort(struct student s[], int n)
{
    int i, j;
    struct student temp;

    for(i = 1; i < n; i++)
    {
        temp = s[i];
        j = i - 1;

        while(j >= 0 && s[j].roll > temp.roll)
        {
            s[j+1] = s[j];
            j--;
        }

        s[j+1] = temp;
    }
}

void selectionSort(struct student s[], int n)
{
    int i, j, min;
    struct student temp;

    for(i = 0; i < n-1; i++)
    {
        min = i;

        for(j = i+1; j < n; j++)
            if(s[j].roll < s[min].roll)
                min = j;

        temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }
}

void bubbleSort(struct student s[], int n)
{
    int i, j;
    struct student temp;

    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(s[j].roll > s[j+1].roll)
            {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

void shellSort(struct student s[], int n)
{
    int gap, i, j;
    struct student temp;

    for(gap = n/2; gap > 0; gap /= 2)
    {
        for(i = gap; i < n; i++)
        {
            temp = s[i];
            j = i;

            while(j >= gap && s[j-gap].roll > temp.roll)
            {
                s[j] = s[j-gap];
                j -= gap;
            }

            s[j] = temp;
        }
    }
}

void binarySearch(struct student s[], int n, int key)
{
    int low = 0, high = n-1, mid;

    while(low <= high)
    {
        mid = (low + high)/2;

        if(s[mid].roll == key)
        {
            printf("Student found: %s\n", s[mid].name);
            return;
        }
        else if(s[mid].roll < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Student not found\n");
}

int main()
{
    struct student s[50];
    int n, i, ch, key;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if(n < 1 || n > 50)
    {
        printf("Invalid number of students\n");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("Enter roll number and name: ");
        scanf("%d %29s", &s[i].roll, s[i].name);
    }

    printf("\n1. Linear Search");
    printf("\n2. Binary Search");
    printf("\n3. Insertion Sort");
    printf("\n4. Selection Sort");
    printf("\n5. Shell Sort");
    printf("\n6. Bubble Sort");
    printf("\nEnter choice: ");
    scanf("%d", &ch);

    switch(ch)
    {
        case 1:
            printf("Enter roll number: ");
            scanf("%d", &key);
            linearSearch(s, n, key);
            break;

        case 2:
            insertionSort(s, n);
            printf("Enter roll number: ");
            scanf("%d", &key);
            binarySearch(s, n, key);
            break;

        case 3:
            insertionSort(s, n);
            display(s, n);
            break;

        case 4:
            selectionSort(s, n);
            display(s, n);
            break;

        case 5:
            shellSort(s, n);
            display(s, n);
            break;

        case 6:
            bubbleSort(s, n);
            display(s, n);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}
