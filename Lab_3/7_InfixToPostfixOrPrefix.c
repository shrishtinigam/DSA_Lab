#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
typedef struct Stack {
    int top;
    unsigned max;
    int * array;
}Stack;

Stack * createStack(unsigned max)
{
    Stack * stack = (Stack *) malloc(sizeof(Stack));
    stack->max = max;
    stack->top = -1;
    stack->array = (int *) malloc(stack->max * sizeof(int));
    return stack;
}

bool isFull(Stack * stack)
{
    return stack->top == stack->max - 1;
}

bool isEmpty(Stack * stack)
{
    return stack->top == -1;
}

void push (Stack * stack, int x)
{
    if(isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++(stack->top)] = x;
    //printf("%d pushed to stack\n", x);
}

int pop (Stack * stack)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

int peek(Stack * stack)
{
    if(isEmpty(stack))
    {
        return INT_MIN;
    }
    return stack->array[stack->top];
}

int Postfix(char str[])
{
    int len = strlen(str);
    Stack * stack_1 = createStack(len + 1);
    for(int i = 0; i < len; i++)
    {
        if(isdigit(str[i]))
        {
            push(stack_1, (int)str[i] - (int)'0');
        }
        else
        {
            int x = pop(stack_1);
            int y = pop(stack_1);
            if(str[i] == '+')
                push(stack_1, y + x);
            else if(str[i] == '-')
                push(stack_1, y - x);
            else if(str[i] == '*')
                push(stack_1, y * x);
            else if(str[i] == '/')
                push(stack_1, y / x);
        }
    }
    return pop(stack_1);
}

int Prefix(char str[])
{
    int len = strlen(str);
    Stack * stack_1 = createStack(len + 1);
    for(int i = len-1; i >= 0; i--)
    {
        if(isdigit(str[i]))
        {
            push(stack_1, (int)str[i] - (int)'0');
        }
        else
        {
            int x = pop(stack_1);
            int y = pop(stack_1);
            if(str[i] == '+')
                push(stack_1, x + y);
            else if(str[i] == '-')
                push(stack_1, x - y);
            else if(str[i] == '*')
                push(stack_1, x * y);
            else if(str[i] == '/')
                push(stack_1, x / y);
        }
    }
    return pop(stack_1);
}

bool Precedence(char a, char b)
{
    if((a == '*' || a == '/') && (b == '+' || b == '-')) // a has greater precedence
    {
        return true;
    }
    // both have same precedence or b has greater precedence
    return false;
}

int InfixViaPostfix(char str[])
{
    int len = strlen(str);
    char str2[30];
    Stack * stack_1 = createStack(30);
    int c = 0;
    for(int i = 0; i < len; i++)
    {
        if(isdigit(str[i]))
        {
            str2[c] = str[i];
            c++;
        }
        else
        {
            if(isEmpty(stack_1))
            {
                push(stack_1, str[i]);
            }
            else
            {
                if(Precedence(str[i], peek(stack_1)))
                {
                    push(stack_1, str[i]);
                }
                else
                {
                    while(!isEmpty(stack_1))
                    {
                        str2[c] = pop(stack_1);
                        c++;
                    }
                    push(stack_1, str[i]);
                }
            } 
        }
    }
    while(!isEmpty(stack_1))
    {
        str2[c] = pop(stack_1);
        c++;
    }
    //printf("%s\n", str2);
    return Postfix(str2);
}

int InfixViaPrefix(char str[])
{
    int len = strlen(str);
    char str1[30];
    int c1 = 0;
    for(int i = len - 1; i >= 0; i--)
    {
        str1[c1] = str[i];
        c1++;
    }
    char str2[30];
    Stack * stack_1 = createStack(30);
    int c = 0;
    for(int i = 0; i < len; i++)
    {
        if(isdigit(str1[i]))
        {
            str2[c] = str1[i];
            c++;
        }
        else
        {
            if(isEmpty(stack_1))
            {
                push(stack_1, str1[i]);
            }
            else
            {
                if(Precedence(str1[i], peek(stack_1)))
                {
                    push(stack_1, str1[i]);
                }
                else
                {
                    while(!isEmpty(stack_1))
                    {
                        str2[c] = pop(stack_1);
                        c++;
                    }
                    push(stack_1, str1[i]);
                }
            } 
        }
    }
    while(!isEmpty(stack_1))
    {
        str2[c] = pop(stack_1);
        c++;
    }
    c1 = 0;
    for(int i = len - 1; i >= 0; i--)
    {
        str1[c1] = str2[i];
        c1++;
    }
    //printf("%s\n", str1);
    return Prefix(str1);
}

int main()
{
    char str[30] = "4+5*3-2";
    printf("Evaluation of infix expression using Postfix evaluation %s is %d\n", str, InfixViaPostfix(str)); // 453*+2-
    printf("Evaluation of infix expression using Prefix evaluation %s is %d\n", str, InfixViaPrefix(str)); //+4-*532
}