#include<bits/stdc++.h>
using namespace std;

void permutation(int a[],int l,int h)
{

    if(l>h)
    {
        int i;
        for(i=0;i<=h;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i = l;i<=h;i++)
    {
        //cout<<"Call for i="<<i<<" "<<"l="<<l<<endl;
        swap(a[l],a[i]);
        permutation(a,l+1,h);
        //cout<<"Return for i="<<i<<" "<<"l="<<l<<endl;
        swap(a[l],a[i]);
    }
}

main()
{
    int n,i,a[100];
    cin>>n;
    for(i = 0;i<n;i++)
    {
        a[i] = i+1;
    }
    permutation(a,0,n-1);
}
