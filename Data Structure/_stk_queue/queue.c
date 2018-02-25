#include<stdio.h>
#define MAX 3
int rear = -1,front = -1;
struct queue
{
    int data[MAX];
    int rear;
    int front;
} q;
void enqueue()
{
    int num;
    scanf("%d",&num);
    if(q.rear <= MAX-1)
    {
        q.data[q.rear] = num;
        q.rear++;

    }
    else printf("Queue is full\n");
}
void dequeue()
{
    if(q.front == q.rear )
        printf("Underflow!!\n");
    else
    {
        printf("Dequeueed element: %d\n",q.data[q.front]);
        q.front++;
    }
}
void display()
{
    int i;
    printf("Queue is : ");
    for(i=0; i<q.rear; i++)
    {
        printf("%d  ",q.data[i]);
        if(i== q.rear-1)
            printf("\n");
    }
}
main()
{
    int t;
    while(scanf("%d",&t) == 1)
    {
        if(t==1)
        {
            enqueue();
        }
        else if(t==2)
        {
            display();
        }
        else if(t==3)
        {
            dequeue();
        }

    }

}
