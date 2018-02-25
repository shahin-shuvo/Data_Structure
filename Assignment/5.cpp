#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void print(int a[],int n)
{
    if(n<0) return;
    else
    {
        print(a,n-1);
        if(a[n]%3==0)
        cout<<a[n]<<endl;
    }
}
main()
{
    int n,a[100];
    cin>>n;
    for(int i=0 ;i<n;i++)
        cin>>a[i];
    print(a,n-1);

}


