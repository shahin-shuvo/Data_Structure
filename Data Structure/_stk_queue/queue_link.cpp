#include<stdio.h>
#include<stdlib.h>
#include"shuvo.h"
main()
{
    list s;
    int n,c,d;
    while(1)
    {
        scanf("%d",&n);
        if(n==1)
            s.print();
        else if(n==2)
        {
            scanf("%d",&c);
            s.insert_first(c);
        }
        else if(n==3)
        {
            s.delete_last();
        }
    }
}
