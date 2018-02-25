#include<stdio.h>
int top = -1,i;
char stack[100];
char s[100];

void push()
{
    top++;
    stack[top]=s[i];
}
void pop()
{
    if(top== -1) return;
    top--;
}

main()
{


    scanf("%s",s);
    int l=strlen(s);
    for(i=0; i<l; i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            push(s[i]);
        }
        else if((s[i] == ')'&& stack[top] == '(') || (s[i] == '}' && stack[top] == '{' )|| (s[i] == ']' && stack[top] == '['))
        {
                pop();
        }
        else
        {
            printf("Illegal\n");
            return 0;
        }
    }

    if(top == -1) printf("Balanced\n");
    else printf("Illegal\n");
    return 0;

}


