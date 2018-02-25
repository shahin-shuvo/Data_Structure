#include<stdio.h>
#define MAX 5
int top;
void display(int stack [])
{
    int i;
    if(top == -1) printf("\nEmpty Stack\n");
    else
        for(i=top; i>=0 ; i--)
        {
            printf ("\n--------\n|%3d   |\n--------",stack[i]);
        }
    printf ("\n");
}
void push(int stack[],int a)
{
    if(top == MAX-1)
        printf("\nStack Over Flow!!!!!!\n\n");
    else
    {
        top++;
        stack[top]=a;
    }
}
void pop(int stack[])
{
    if(top == -1) printf("\nEmpty Stack\n");
    else
    {
        printf("Your poped element = %d\n",stack[top]);
        top--;
        if(top == -1) printf("Now Your Stack is Empty\n");
    }
    printf("\n");
}
void Top(int stack[])
{
    if(top == -1) printf("\nEmpty Stack\n");
    else printf("Your Top is\n ------\n|%3d   |\n ------\n",stack[top]);
}
main()
{
    top = -1;
    int stack[MAX];
    int t,a;
    while(t != 0 )
    {
        printf ("\n0.Exit\n");
        printf ("1.PUSH  in the Stack\n");
        printf ("2.POP   from the Stack\n");
        printf ("3.Display\n");
        printf ("4.Get Top\n");
        printf ("Your Choice: ");
        scanf("%d", &t);
        if(t == 1)
        {
            printf("\nEnter element to push : ");
            scanf("%d",&a);
            push(stack,a);
            display(stack);
        }
        else if (t == 2)
            pop(stack);
        else if (t == 3)
            display(stack);
            else if (t == 4)
            Top(stack);
    }
}
