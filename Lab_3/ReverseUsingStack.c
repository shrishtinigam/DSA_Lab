// ReverseUsingStack.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Stack {
    int top;
    unsigned max;
    char * array;
}Stack;

Stack * createStack(unsigned max)
{
    Stack * stack = (Stack *) malloc(sizeof(Stack));
    stack->max = max;
    stack->top = -1;
    stack->array = (char *) malloc(stack->max * sizeof(char));
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


void push (Stack * stack, char x)
{
    if(isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->top = stack->top + 1;
    stack->array[stack->top] = x;
    // printf("%c pushed to stack\n", x);
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

int main()
{
    Stack * stack_1 = createStack(10);
    printf("Enter a string of length less than 10 that you want to reverse.\n");
    char str[11];
    scanf("%s", str);
    for(int i = 0; i < strlen(str); i++)
    {
        push(stack_1, str[i]);
    }
    for(int i = 0; i < strlen(str); i++)
    {
        char x = pop(stack_1);
        printf("%c\n", x);
    }
}