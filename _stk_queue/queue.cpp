#include<stdio.h>
#define max 3
struct one
{
    int front = -1;
    int rear = -1;
    int b[max];
    int a;
    void print()
    {
        if(Isempty())
            printf("Empty\n");
        else
        {

            for (int i = front+1; i<=rear ; i = (i+1))
            {
                printf("%d ",b[i]);
            }
            printf("\n");
        }
    }
    void enqueue(int a)
    {
        if(Isfull())
            printf("Overflow\n");
        else
        {
            rear = (rear+1)%max;
            b[rear] = a;
        }
    }
    void dequeue()
    {
        if(Isempty())
            printf("Underflow\n");
        else
        {
            front = (front+1)% max;
            printf("Dequeued element : %d\n",b[front]);
        }
    }
    int Isempty()
    {
        if(rear == -1)
            return 1;
        else
            return 0;
    }
    int Isfull()
    {
        if((rear == front-1 ) || (front == 0 && rear == max-1))
            return 1;
        else
            return 0;
    }
};
main()
{
    one s,p;
    int n,a;

    while(1)
    {
        scanf("%d",&n);
        if(n==1)
            s.print();
        else if(n==2)
        {
            scanf("%d",&a);
            s.enqueue(a);
        }
        else if(n==3)
            s.dequeue();
    }
}

