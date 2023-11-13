#include <stdio.h>
#include <stdlib.h>
#define STUCK_SIZE 4

typedef struct main
{
    int data[STUCK_SIZE];
    int top;
} stack;
void reset(stack *stk)
{
    stk->top = -1;
    for (int i = 0; i < STUCK_SIZE; i++)
    {
        stk->data[i]=0;
    }    
}
void push(stack *stk, int key)
{
    if (stk->top == STUCK_SIZE - 1)
    {
        printf("Stack is full.\n");
    }
    else
    {
    }

    stk->data[++stk->top] = key;
}
int pop(stack *stk)
{
    if (stk->top == -1)
    {
        printf("Stack is empty.\n");
        return 0;
    }
    else
    {
        int x = stk->data[stk->top];
        stk->data[stk->top]=0;
        stk->top--;
        return x;
    }
}
void print(stack *stk){
    for (int i = 0; i < STUCK_SIZE; i++)
    {
        printf("%d. value %d\n",i+1,stk->data[i]);
    }
    
}

int main(int argc, char const *argv[])
{
    stack stk1;
    reset(&stk1);
    push(&stk1,7);
    push(&stk1,13);
    push(&stk1,89);
    print(&stk1);
    printf("------------------------------\n");
    printf("Push Last Value = 4\n");
    printf("------------------------------\n");
    push(&stk1,4);
    print(&stk1);
    printf("------------------------------\n");
    printf("Pop Last Value = 4\n");
    printf("------------------------------\n");
    pop(&stk1);
    print(&stk1);
    pop(&stk1);
    pop(&stk1);
    pop(&stk1);
    pop(&stk1);
    print(&stk1);
    return 0;
}
