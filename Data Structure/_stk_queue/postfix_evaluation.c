#include<stdio.h>
int top = -1,i;
int stack[100];
char s[100];
void push(int a)
{
    top++;
    stack[top]=a;
}
int empty()
{
    if(top == -1)
        return 1;
    else return 0;
}
int pop()
{
    if(empty())
        return 0;

    else
    {
        return stack[top--];
    }
}

void postfix()
{
    int j=0;
    char c;
    int a,b;
    int l= strlen(s);
    for(i=0; i<l; i++)
    {
        c = s[i];

        if(isdigit(c))
            push(c-'0');

        else if( c == ',')
           continue;
        else
        {
           a = pop();
           b = pop();
            switch(c)
            {
            case '+':
                push(b+a);
                break;
            case '-':
                push(b-a);
                break;
            case '*':
                push(b*a);
                break;
            case '/':
                push(b/a);
                break;
            }


        }
    }
}

main()
{
    scanf("%s",s);
    postfix();
    printf("%d\n",stack[top]);
}
