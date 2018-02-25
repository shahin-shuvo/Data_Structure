#include<stdio.h>
void printNumber(int a, int position)
{
    if( position < 0)
    {
        printf("%d\n",a);
        return;
    }
    printNumber(a, position - 1);
    printNumber(a|(1<<position), position - 1);
}
int main()
{
   printNumber(0,4);
}
