#include<bits/stdc++.h>
using namespace std;
int NcR(int n,int r)
{
    if(r==0) return 1;
    if(n<r) return 0;
    return NcR(n-1,r)+NcR(n-1,r-1);
}
main()
{
    int n,r;
    cin>>n>>r;
    if(NcR(n,r)==0)
        cout<<"Math Error"<<endl;
    else
        cout<<n<<"C"<<r<<" is : "<<NcR(n,r)<<endl;
}
