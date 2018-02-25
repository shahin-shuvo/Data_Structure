#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void print(int a[],int n)
{
    if(n<0) return;
    else
    {
        cout<<a[n]<<endl;
        print(a,n-1);
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

