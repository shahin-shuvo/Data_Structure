#include<bits/stdc++.h>

void insertionsort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;


       while (arr[j] > key)
       {
           arr[j+1] = arr[j];
           j--;
       }
       arr[j+1] = key;
   }
}

main()
{
    int a[90],i,n,j,temp;
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    insertionsort(a,n);
    for(i = 0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
