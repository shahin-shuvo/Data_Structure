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
            scanf("%d",&c);
            s.insert_last(c);
        }
        else if(n==4)
        {
            scanf("%d %d",&c,&d);
            s.insert_after(c,d);
        }
        else if(n==5)
        {
            scanf("%d %d",&c,&d);
            s.insert_before(c,d);
        }
        else if(n==6)
        {
            scanf("%d",&c);
            s.delete_val(c);
        }
        else if(n==7)
        {
            s.delete_first();
        }
        else if(n==8)
        {
            s.delete_last();
        }
    }

}
