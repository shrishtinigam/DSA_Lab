// 1_Stack.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    printf("%d pushed to stack\n", x);
}

int pop(Stack * stack)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    int item = stack->array[stack->top];
    stack->top = stack->top - 1;
    printf("%d was popped off the stack\n", item);
    return item;
}

int peek(Stack * stack)
{
    if(isEmpty(stack))
    {
        return INT_MIN;
    }
    return stack->array[stack->top];
}

// This function should not be available, but it is used here for illustration purposes
void printStack(Stack * stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Current stack: "); 
    for(int i = 0; i < stack->top + 1; i++)
    {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

int main()
{
    Stack * stack_1 = createStack(6); // creating stack with max size 6
    // push numbers onto stack
    push(stack_1, 23);
    printStack(stack_1);
    push(stack_1, 56);
    printStack(stack_1);
    push(stack_1, 37);
    printStack(stack_1);
    push(stack_1, 92);
    printStack(stack_1);
    printf("The top element is: %d\n", peek(stack_1));
    push(stack_1, 102);
    printStack(stack_1);
    push(stack_1, 42); 
    printStack(stack_1);
    printf("Top index is %d\n", stack_1->top);
    push(stack_1, 63); // stack overflow
    printf("Top index is %d\n", stack_1->top);
    printStack(stack_1);

    // popping numbers off the stack
    pop(stack_1);
    printStack(stack_1);
    pop(stack_1);
    printStack(stack_1);
    pop(stack_1);
    printStack(stack_1);
    pop(stack_1);
    printStack(stack_1);
    pop(stack_1);
    printStack(stack_1);
    pop(stack_1);
    printStack(stack_1);
    pop(stack_1); // stack underflow
    printf("Top index is %d\n", stack_1->top);
    printStack(stack_1);
}