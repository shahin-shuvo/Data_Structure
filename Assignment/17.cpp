#include<bits/stdc++.h>
using namespace std;
void bubble_sort(int a[],int n)
{
    if(n==0)
        return;
    for(int i=0;i<n;i++)
        if(a[i]>a[i+1])
        swap(a[i],a[i+1]);
    bubble_sort(a,n-1);
}
main()
{
    int n,a[199],i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    bubble_sort(a,n-1);
    for(i=0;i<n;i++)
        cout<<a[i]<<" "<<endl;

}
