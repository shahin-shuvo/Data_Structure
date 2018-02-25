#include<bits/stdc++.h>
main()
{
    int a[100],c[100],i,j,x,n,k=0;
    scanf("%d",&n);
    int b[100];
    memset(c,0,sizeof(c));
    memset(b,0,sizeof(b));
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>k)
            k=a[i];
        c[a[i]]++;
    }
    for (i=1; i<=k ; i++)	// cumulative sum
        c[i] = c[i] + c[i-1];
    for(j=n;j>=1;j--)
    {
        b[c[a[j]]]=a[j];
        c[a[j]]--;
    }
    for(i=1;i<=n;i++)
        printf("%d ",b[i]);

}
