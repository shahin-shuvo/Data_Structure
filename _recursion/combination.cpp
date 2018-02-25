#include<bits/stdc++.h>
using namespace std;
void cmb(int n , int k);
void nation(int ar[], int i , int j , int n , int k);
void print(int ar[] , int k)
{
    if(k==0)
        return;
    print(ar , k-1);
    cout<<ar[k-1]<<" ";
}
/*void loop(int ar[] ,int i , int l, int n , int k)
{
    if(l>n)
        return;
        ar[i] = l;
    nation(ar , i+1 ,l+1, n, k );
    loop(ar , i , l+1 , n , k);
}*/
void nation(int ar[] , int i ,int j, int n , int k)
{
   if(i==k)
    {
        print(ar,  k);
        cout<<endl;
        return;
    }
   // loop(ar, i , j , n, k);
   for(int l = j ; l<= n ; l++)
   {
       ar[i] = l;
       nation(ar, i+1 , l+1 , n, k);
   }
}
void cmb(int n , int k)
{
    int ar[k+1];
    nation( ar , 0 ,1, n, k);
}


int main()
{
    int n, k;
    cin>>n>>k;
    cmb(n, k);
}
