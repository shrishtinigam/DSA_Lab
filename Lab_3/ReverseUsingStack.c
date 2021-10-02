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

void printStack(Stack * stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is empty\n");
        return;
    }
    
    for(int i = 0; i < stack->top + 1; i++)
    {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

void push (Stack * stack, int x)
{
    if(isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->top = stack->top + 1;
    stack->array[stack->top] = x;
    printf("%d pushed to stack\n", x);
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
    Stack * stack_1 = createStack(6); // creating stack with max size 6
    // push numbers onto stack
    push(stack_1, 23);
    push(stack_1, 56);
    push(stack_1, 37);
    push(stack_1, 92);
    printf("The top element is: %d\n", peek(stack_1));
    push(stack_1, 102);
    push(stack_1, 42); 
    printf("Top is %d\n", stack_1->top);
    push(stack_1, 63); // stack overflow
    printf("Top is %d\n", stack_1->top);
    printStack(stack_1);
    printf("%d was popped off\n", pop(stack_1));
    printf("%d was popped off\n", pop(stack_1));
    printf("%d was popped off\n", pop(stack_1));
    printf("%d was popped off\n", pop(stack_1));
    printf("%d was popped off\n", pop(stack_1));
    printf("%d was popped off\n", pop(stack_1));
    printf("%d\n", pop(stack_1)); // stack underflow
    printf("Top is %d\n", stack_1->top);
    printStack(stack_1);
}