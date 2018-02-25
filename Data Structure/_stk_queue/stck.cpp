#include<stdio.h>
struct one
{
    int top = 0;
    int b[30];
    int a;
    void print()
    {
        if(top == 0)
            printf("Empty Stack\n");
        else
        {
            for (int i = 0;i<top ; i++)
            {
                printf("%d",b[i]);
                if(i == top-1)
                    printf("\n");
                else printf(" ");
            }
        }
    }
    void push(int a)
    {
        if(top == 30)
            printf("Stack Full\n");
        else
        {
        b[top] = a;
        top++;
        }
    }
    int pop()
    {
        if(top == 0)
            printf("Stack is empty\n");
        else
        {
            top--;
            printf("Poped element : %d\n",b[top]);

        }

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
            s.push(a);
        }
        else if(n==3)
            s.pop();
    }
}
