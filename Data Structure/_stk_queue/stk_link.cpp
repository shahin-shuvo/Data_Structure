#include<stdio.h>
#include<stdlib.h>
#include"shuvo.h"
main()
{
    list s;
    int t,a,b,c;
    while(1)
    {
        scanf("%d",&t);
        if(t==1)
            s.print();
        else if(t==2)
            {
                scanf("%d",&a);
                s.insert_first(a);
            }
        else if(t==3)
            {
                s.delete_first();
            }
    }


}
