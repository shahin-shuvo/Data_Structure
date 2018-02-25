#include<iostream>
using namespace std;
void insertion_helper(int ara[],int hi,int i)
{
    if(i<0)
        return;
    if(ara[i]>ara[hi])
        swap(ara[i],ara[hi]);
    insertion_helper(ara,hi,i-1);
}
void insertion(int ara[],int hi)
{
    if(hi<0)
        return;
      insertion_helper(ara,hi,hi-1);
      insertion(ara,hi-1);
}

int main()
{
    int ara[1000],i,n;

    cin>>n;

    for(i=0; i<n; i++)
        cin>>ara[i];

    insertion(ara,n-1);

    for(i=0; i<n; i++)
        cout<<ara[i]<<" ";

    return 0;
}


