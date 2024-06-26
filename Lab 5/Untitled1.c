#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define max 20

char stack[max];
int top = -1;
int isEmpty()
{
    return top == -1;
}
int isFull()
{
    return top == max - 1;
}
char peek()
{
    return stack[top];
}
char pop()
{
    if(isEmpty())
        return -1;

    char ch = stack[top];
    top--;
    return(ch);
}
void push(char oper)
{
    if(isFull())
        printf("Stackoverflow");

    else{
        top++;
        stack[top] = oper;
    }
}
int checkOpr(char ch)
{
    return(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z');
}
int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}
int convert(char* expression)
{
    int i, j;
    for (i=0,j=-1;expression[i];++i)
    {
       if (checkOpr(expression[i]))
            expression[++j] = expression[i];
        else if (expression[i] == '(')
            push(expression[i]);
        else if (expression[i] == ')')
        {
            while (top>-1 && stack[top] != '(')
                expression[++j] = pop();
            //if (!isEmpty() && peek() != '(')
              //  return -1;
            //else
              //  pop();
        }
        else
        {
            while (top>-1 && precedence(expression[i]) <= precedence(stack[top]))
                expression[++j] = pop();
            push(expression[i]);
        }
    }
    while (top>-1)
        expression[++j] = pop();
    expression[++j] = '\0';
    printf( "%s", expression);
}

int main()
{
char expression[max];
printf("Enter the equation:");
gets(expression);
convert(expression);
return 0;
}
