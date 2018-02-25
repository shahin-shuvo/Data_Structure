#include<bits/stdc++.h>
#include<time.h>
int binary(int a[],int hi,int lo,int x)
{
    int mid = hi+lo/2;
    if(x>a[hi]) return -1;
    if(a[mid]==x) return mid;
    else if(a[mid]>x)
        binary(a,mid-1,lo,x);  //  hi = mid-1;
    else if(a[mid]<x)
        binary(a,hi,mid+1,x);   //  lo = mid+1;
}

main()
{
    double st = clock();
    int lo,hi,mid,n,i,a[100],x,flag = 0;
    scanf("%d",&n);
    for(i = 0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&x);
    lo = 0;
    hi = n-1;
    mid = binary(a,hi,lo,x);
    if(mid==-1)
        printf("Not Found\n");
    else
    printf("%d is found in location %d\n",x,mid);
    double en = clock();
    printf("Total elapsed time = %.15lf\n",en/CLOCKS_PER_SEC);
}
