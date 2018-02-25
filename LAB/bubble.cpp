#include<bits/stdc++.h>
using namespace std;
void swap_b(int a[],int n)
{
    if(n==1) return;
    if(a[n-2]>a[n-1])
        swap(a[n-1],a[n-2]);
    swap_b(a,n-1);
}
void bubble(int a[],int n)
{
    if(n==1) return ;
      bubble(a,n-1);
        swap_b(a,n);

}
main()
{
    int a[100],n,i;
    cin>>n;
    for( i = 0;i<n;i++)
        cin>>a[i];
   bubble(a,n);
    for(i = 0;i<n;i++)
        cout<<a[i]<<" ";
}
