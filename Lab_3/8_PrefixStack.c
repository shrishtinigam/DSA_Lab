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

int main()
{
    char str[30] = "-+*23*549";
    printf("Prefix evaluation of %s is %d\n", str, Prefix(str));
    char str2[30] = "-+8/632";
    printf("Prefix evaluation of %s is %d\n", str2, Prefix(str2));
}