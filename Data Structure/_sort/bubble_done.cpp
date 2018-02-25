#include<bits/stdc++.h>
using namespace std;
main()
{
    int a[100],n,i;
    int inner,outer;
    cin>>n;
    for( i = 0;i<n;i++)
        cin>>a[i];
    for(outer=n-1;outer>0;outer--)
    {
        for(inner = 0;inner<outer;inner++)
        {
            if(a[inner]>a[inner+1])
                swap(a[inner],a[inner+1]);
        }
    }
    for(i = 0;i<n;i++)
        cout<<a[i]<<" ";
}
