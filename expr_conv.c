
#include <stdio.h>
#include <string.h>

char stack[20];
char strstack[20][20];
int top = -1;

void push(char ch)
{
    top++;
    stack[top] = ch;
}

char pop()
{
    char ch = stack[top];
    top--;
    return ch;
}

void pushstr(char str[20])
{
    top++;
    strcpy(strstack[top], str);
}

void popstr(char str[20])
{
    strcpy(str, strstack[top]);
    top--;
}

int icp(char ch)
{
    if(ch == '^')
        return 4;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '(')
        return 4;
    else
        return 0;
}

int isp(char ch)
{
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '(')
        return 0;
    else
        return -1;
}

void infix_postfix(char infix[20])
{
    int i, k = 0;
    char ch, postfix[20];

    top = -1;

    for(i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if(ch == '(')
            push(ch);

        else if(ch == ')')
        {
            while(top != -1 && stack[top] != '(')
                postfix[k++] = pop();

            if(top != -1)
                pop();
        }

        else if(ch == '+' || ch == '-' ||
                ch == '*' || ch == '/' || ch == '^')
        {
            while(top != -1 && isp(stack[top]) >= icp(ch))
                postfix[k++] = pop();

            push(ch);
        }
        else
            postfix[k++] = ch;
    }

    while(top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("Postfix: %s\n", postfix);
}

void prefix_postfix(char prefix[20])
{
    int i, len;
    char ch, op1[20], op2[20], temp[20];

    top = -1;

    for(i = strlen(prefix) - 1; i >= 0; i--)
    {
        ch = prefix[i];

        if(ch == '+' || ch == '-' ||
           ch == '*' || ch == '/' || ch == '^')
        {
            popstr(op1);
            popstr(op2);

            strcpy(temp, op1);
            strcat(temp, op2);

            len = strlen(temp);
            temp[len] = ch;
            temp[len + 1] = '\0';

            pushstr(temp);
        }
        else
        {
            temp[0] = ch;
            temp[1] = '\0';
            pushstr(temp);
        }
    }

    popstr(temp);

    printf("Postfix: %s\n", temp);
}

int main()
{
    int ch;
    char infix[20], prefix[20];

    printf("1. Infix to Postfix\n");
    printf("2. Prefix to Postfix\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    if(ch == 1)
    {
        printf("Enter infix expression: ");
        scanf("%19s", infix);

        infix_postfix(infix);
    }
    else if(ch == 2)
    {
        printf("Enter prefix expression: ");
        scanf("%19s", prefix);

        prefix_postfix(prefix);
    }
    else
        printf("Invalid choice");

    return 0;
}
