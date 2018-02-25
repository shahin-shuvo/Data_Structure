#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int selection22(int a[],int n);
void selection(int a[],int n);

int selection22(int a[],int n)
{
    if(n==0)
        return 0;
    int x=selection22(a,n-1);
    if(a[n]>a[x])
        x=n;
    return x;
}

void selection(int a[],int n)
{
    if(n<0)
        return;

    int x=selection22(a,n);
        swap(a[n],a[x]);
    selection(a,n-1);

}


 int main()
 {
     int a[1000],n,i;
     cin>>n;

     for(i=0;i<n;i++)
        cin>>a[i];

    selection(a,n-1);

    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
 }

