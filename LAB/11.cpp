#include<bits/stdc++.h>
using namespace std;
int binary(int a[],int hi,int lo,int x)
{
    if(lo>hi) return -1;
    int mid = (lo+hi)/2;
    if(a[mid]==x)
        return mid;
    else if(a[mid]>x)
        return binary(a,mid-1,lo,x);
    else
        return binary(a,hi,mid+1,x);
}
main()
{
    int a[100],n,hi,lo,i,x;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>x;
    hi = n-1;
    lo= 0;
    cout<<binary(a,hi,lo,x)<<endl;
}
