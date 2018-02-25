#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int max_val(int a[],int n)
{
    if(n==0) return 0;
    int x = max_val(a,n-1);
    int store = n;
    if(a[x]>a[store])
         store= x;
    return store;


}
main()
{
    int n,a[100];
    cin>>n;
    for(int i=0 ; i<n; i++)
        cin>>a[i];
    cout<<max_val(a,n-1)<<endl;
}


