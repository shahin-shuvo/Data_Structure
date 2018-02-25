#include<bits/stdc++.h>
using namespace std;
void pmtt(char ar[] , int i , int n);
void print(char ar[] , int n)
{
    if(n==0)
        return ;
    print(ar, n-1);
    cout<<ar[n-1]<<" ";
}

int k;
void pmtt( char ar[] , int i,int n)
{
    if(i==n)
    {
        print(ar, n);
        cout<<endl;
        k--;
        return;
    }
    for(int j = i ; j < n ; j++)
    {
        if(k==0) break;
        swap(ar[i], ar[j]);
        pmtt(ar , i+1 , n);
        swap(ar[i],ar[j]);
    }
}

void perm(int n)
{
    char ar[n+1];
    cin>>k;
    for(int i = 0 ; i<n ; i++)
        ar[i]=65+i;
    pmtt(ar , 0, n);
}

int main()
{
    int n;
    cin>>n;
    perm(n);
    return 0;
}

