#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    node *next;
};
struct queue
{
    node *front;
    node *rear;
    queue()
    {
        front = (node*)malloc(sizeof(node));
        front = NULL;
        rear = (node*)malloc(sizeof(node));
        rear = NULL;
    }
    void enqueue(int a)
    {
        node *p = (node*)malloc(sizeof(node));
        p->val =a;
        p->next = NULL;
        if(rear == NULL)
        {
            front = rear = p;
        }
        else
        {
            rear->next = p;
            rear = p;
        }
    }
    void dequeue()
    {
        if(front == NULL)
        {
            printf("Empty queue\n");
        }
        else
        {
            node *p = front;
            front = front -> next;
            printf("\nDeleted element: %d\n", p->val);
            free(p);
        }
    }
    void print()
    {
        if(front == NULL)
            printf("Empty queue\n");
        else
        {
            node *q = front;
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
    queue s;
    int n,c,d;
    while(1)
    {
        scanf("%d",&n);
        if(n==1)
            s.print();
        else if(n==2)
        {
            scanf("%d",&c);
            s.enqueue(c);
        }
        else if(n==3)
        {
            s.dequeue();
        }
    }
}
