#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void print(int n)
{
    if(n==0) return;
    else
    {
        cout<<n<<endl;
        print(n-1);
    }
}
main()
{
    int n;
    cin>>n;
    print(n);

}

