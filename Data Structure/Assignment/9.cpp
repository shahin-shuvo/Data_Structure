#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int sum_array(int a[],int n)
{
    if(n==0) return a[0];
    else return  a[n]+sum_array(a,n-1);


}
main()
{
    int n,a[100];
    cin>>n;
    for(int i=0 ; i<n; i++)
        cin>>a[i];
    cout<<sum_array(a,n-1)<<endl;
}


