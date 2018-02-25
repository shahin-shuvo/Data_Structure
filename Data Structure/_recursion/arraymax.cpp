#include<bits/stdc++.h>
int maxval(int a[],int n,int m,int store)
{
    if(n<0) return store;
    else
        {
           if(a[n]>m)
           {
               m = a[n];
               store = n;
           }
           maxval(a,n-1,m,store);
        }
}
main()
{
    int a[100];
    int n,i;
    scanf("%d",&n);
    for(i = 0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%d\n",maxval(a,n-1,-1,-1));
}
