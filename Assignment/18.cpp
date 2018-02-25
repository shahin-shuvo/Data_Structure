#include<bits/stdc++.h>
using namespace std;
int min(int a[],int i,int n)
{
    if(n==i) return i;
    int x = min(a,i,n-1);
    int store = x;

    if(a[x]>a[n])
        store = n;
        return store;
}
void selection(int a[],int n)
{
   int  j,i,temp;
   for(i=0;i<n;i++)
   {
       j = min(a,i,n-1);
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

