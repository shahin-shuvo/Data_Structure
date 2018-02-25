#include<bits/stdc++.h>
using namespace std;
int linear(int a[],int n,int x)
{

    if(n==-1)
        return -1;
    if(x==a[n])
       return n;
    linear(a,n-1,x);

}
main()
{
    int a[100],n,i,x;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>x;

    cout<<linear(a,n-1,x)<<endl;
}
