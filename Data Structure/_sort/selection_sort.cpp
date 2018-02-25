#include<bits/stdc++.h>
int min(int a[],int i,int n)
{
    int minimum = INT_MAX;
    int k,store;
    for(k=i;k<n;k++)
    {
        if(a[k]< minimum)
        {
           minimum = a[k] ;
           store = k;
        }
    }
    return store;
}
void selection(int a[],int n)
{
   int  j,i,temp;
   for(i=0;i<n;i++)
   {
       j = min(a,i,n);
       if(a[i]>a[j])
       {
           temp = a[i];
           a[i]  = a[j];
           a[j] = temp;
       }
   }
   for(i = 0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

main()
{
   int a[100],i,j,n;
   scanf("%d",&n);
   for(i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selection(a,n);
}
