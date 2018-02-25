#include<stdio.h>
#include<string.h>
char stack[100];
char s[100],p[100];
int top = -1;
void push(char a)
{
    top++;
    stack[top] = a;
}
char pop()
{
    if(Isempty())
        return 0;
    else
        return stack[top--];
}
int Isempty()
{
    if(top==-1)
        return 1;
    else return 0;
}
int priority(char x)
{
    switch(x)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;

    }
}
void conversion()
{
    int j=0,l,i;
    char c,next;
    l= strlen(s);
    for(i=0 ; i<l ; i++)
    {
        c = s[i];
        switch(c)
        {
        case'(':
            push(c);
            break;
        case')':
            while((next = pop())!='(')
            {
                p[j++] = next;
            }

            break;
        case'+':
        case'-':
        case'*':
        case'/':
            while(!Isempty() && priority(stack[top]) >= priority(c))
                p[j++] = pop();
            push(c);
            break ;
        default:
            p[j++] = c;
        }
    }

    while(!Isempty())
    {
        p[j++] = pop();
    }
}
main()
{
    scanf("%s",s);
    conversion();
    printf("%s\n",p);
}
