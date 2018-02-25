#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void print(int n)
{
    if(n==0) return;
    else
    {
        print(n-1);
        cout<<n<<endl;
    }
}
main()
{
    int n;
    cin>>n;
    print(n);

}
