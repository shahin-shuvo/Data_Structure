#include<stdio.h>

main()
{
    int lo,hi,mid,n,i,a[100],x,flag = 0;
    scanf("%d",&n);
    for(i = 0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&x);
    lo = 0;
    hi = n-1;
    while(1)
    {
        mid = (lo+hi)/2;
        if(a[mid] > x)
            hi = mid-1;
        else if(a[mid] < x)
            lo = mid+1;
        else if(a[mid] == x)
        {
           printf("%d is found in location %d\n",x,mid);
           flag = 1;
           break;
        }
    }
    if(flag == 0)
        printf("Not Found\n");
}
