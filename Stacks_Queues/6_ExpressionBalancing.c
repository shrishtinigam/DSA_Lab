// 6_ExpressionBalancing.c
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
        //printf("Stack Overflow\n");
        return;
    }
    stack->array[++(stack->top)] = x;
    // printf("%c pushed to stack at %d\n", x, stack->top);
}

int pop (Stack * stack)
{
    if(isEmpty(stack))
    {
        //printf("Stack Underflow\n");
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

bool match(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return true;
    else if (character1 == '{' && character2 == '}')
        return true;
    else if (character1 == '[' && character2 == ']')
        return true;
    return false;
}


int main()
{
    Stack * stack_1 = createStack(50);
    printf("Enter the expression:\n");
    char str[50];
    scanf("%s", str);
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            push(stack_1, str[i]);
        }
        else
        {
            char x = pop(stack_1);
            if(!match(x,str[i]))
            {
                printf("Not balanced.\n");
                return 0;
            }
        }
    }
    if(isEmpty(stack_1))
    {
        printf("Balanced.\n");
    }
    else
    {
        printf("Not balanced.\n");
    }
}