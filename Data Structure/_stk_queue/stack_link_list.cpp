#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    node *next;
};
struct stack
{
    node *top;
    stack()
    {
        top = (node*)malloc(sizeof(node));
        top = NULL;
    }
    void push(int a)
    {
        node *p = (node*)malloc(sizeof(node));
        p->val =a;
        if(top == NULL)
        {
           p->next = NULL;
        }
        else
            p->next = top;
        top = p;
    }
    void pop()
    {
        if(top == NULL)
        {
           printf("Empty Stack\n");
        }
        else
        {
           printf("Popped Element ==>%d\n",top->val);
           top = top->next;
        }
    }
    void print()
    {
        if(top == NULL)
            printf("Empty Stack\n");
        else
        {
            node *q = top;
            while(q != NULL)
            {
                printf("%d ",q->val);
                q = q->next;
            }
            printf("\n");
        }
    }
};
main()
{
    stack s;
    int n,c,d;
    while(1)
    {
        scanf("%d",&n);
        if(n==1)
            s.print();
        else if(n==2)
        {
            scanf("%d",&c);
            s.push(c);
        }
        else if(n==3)
        {
            s.pop();
        }
    }
}
