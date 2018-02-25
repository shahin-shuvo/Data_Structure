#include<stdio.h>
struct one
{
    int top = -1;
    int b[30];
    int a;
    void print()
    {
        if(top == -1)
            printf("Empty Stack\n");
        else
        {
            for (int i = 0;i<=top ; i++)
            {
                printf("%d",b[i]);
                if(i == top)
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
        top++;
        b[top] = a;
        }
    }
    int pop()
    {
        if(top == -1)
            printf("Stack is empty\n");
        else
        {
            printf("Poped element : %d\n",b[top]);
             top--;

        }

    }
};
main()
{
    one s;
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
