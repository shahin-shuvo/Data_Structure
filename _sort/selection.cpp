#include<bits/stdc++.h>
using namespace std;
int max(int a[],int n)
{
    if(n<0) return 0;
    int x = max(a,n-1);
    if(a[x]<a[n])
        x = n;
    return x;
}

void sort(int a[],int n)
{
    if(n==1) return ;
    int y = max(a,n-1);
    if(a[n-1]<a[y])
    swap(a[n-1],a[y]);
    sort(a,n-1);
}
main()
{
    int a[100],n,i;
    cin>>n;
    for( i = 0;i<n;i++)
        cin>>a[i];
   sort(a,n);
    for(i = 0;i<n;i++)
        cout<<a[i]<<" ";
}
