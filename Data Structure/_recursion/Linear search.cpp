#include<bits/stdc++.h>
int linear_search(int a[],int n,int x,int i)
{
    if(i==n) return -1;
    if(a[i]==x) return i;
    linear_search(a,n,x,i+1);
}
main()
{
    int a[100],i,x,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&x);
    int l = linear_search(a,n,x,0);
    if(l==-1)
        printf("Not Found\n");
    else
    printf("%d is found in location %d\n",x,l);
}
