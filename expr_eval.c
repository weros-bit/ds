
#include <stdio.h>
#include <ctype.h>

int stack[20];
int top = -1;

void push(int n)
{
    top++;
    stack[top] = n;
}

int pop()
{
    int n = stack[top];
    top--;
    return n;
}

int evaluate(char postfix[20])
{
    int i, a, b;
    char ch;

    top = -1;

    for(i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        if(isdigit(ch))
        {
            push(ch - '0');
        }
        else if(ch == '+' || ch == '-' ||
                ch == '*' || ch == '/')
        {
            b = pop();
            a = pop();

            if(ch == '+')
                push(a + b);
            else if(ch == '-')
                push(a - b);
            else if(ch == '*')
                push(a * b);
            else if(ch == '/')
                push(a / b);
        }
    }

    return pop();
}

int main()
{
    char postfix[20];
    int result;

    printf("Enter postfix expression: ");
    scanf("%19s", postfix);

    result = evaluate(postfix);

    printf("Result = %d\n", result);

    return 0;
}
