#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int odd(int a[],int n)
{
    if(n<0) return 0;

    if(a[n]%2==1)
         return 1+odd(a,n-1);
    else return odd(a,n-1);

}
main()
{
    int n,a[100];
    cin>>n;
    for(int i=0 ; i<n; i++)
        cin>>a[i];
    cout<<odd(a,n-1)<<endl;
}




