#include<bits/stdc++.h>
using namespace std;
void pmtt(int ar[] , int i , int n);
void print(int ar[] , int n)
{
    if(n==0)
        return ;
    print(ar, n-1);
    cout<<ar[n-1]<<" ";
}

void loop(int ar[] , int i, int j , int n)
{
    if(j==n)
        return;
    swap(ar[i],ar[j]);
    pmtt(ar, i+1 , n);
    swap(ar[i], ar[j]);
    loop(ar, i ,  j+1 ,  n);

}

void pmtt( int ar[] , int i,int n)
{
    if(i==n)
    {
        print(ar, n);
        cout<<endl;
        return;
    }
    //loop(ar, i,i, n );
    for(int j = i ; j < n ; j++)
    {
        swap(ar[i], ar[j]);
        pmtt(ar , i+1 , n);
        swap(ar[i],ar[j]);
    }
}

void perm(int n)
{
    int ar[n+1];
    for(int i = 0 ; i<n ; i++)
        ar[i]=i+1;
    pmtt(ar , 0, n);
}

int main()
{
    int n;
    cin>>n;
    perm(n);
    return 0;
}
