#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int hi,int lo)
{
    int p,q,i,j,temp[100];
    int mid = (hi+lo)/2;
    i=lo;
    j=mid+1;
    for(p=lo; p<=hi; p++)
    {
            if(i==mid+1)
                temp[p]=a[j++];
            else if(j==hi+1)
                temp[p]=a[i++];
            else if(a[i]>a[j])
                temp[p]=a[j++];
            else
                temp[p]=a[i++];
    }
    for(i=lo;i<=hi;i++)
        a[i]=temp[i];

}
void merge_sort(int a[],int lo,int hi)
{
    if(hi==lo) return;
    int mid = (hi+lo)/2;
    merge_sort(a,lo,mid);
    merge_sort(a,mid+1,hi);
    merge(a,hi,lo);
}
main()
{

    int a[100],i,j,n;
    scanf("%d",&n);
    for(i = 0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    merge_sort(a,0,n-1);
    for(i=0;i<n;i++)
        cout<<a[i]<<" "<<endl;

}
