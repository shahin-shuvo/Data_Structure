#include<bits/stdc++.h>
using namespace std;
int a[1000],size=0;
bool hasParent(int childIndex)
{
    return childIndex>0;
}
bool hasLeftChild(int ParentIndex)
{
    return (2*ParentIndex+1)<size;
}
bool hasRightChild(int ParentIndex)
{
    return (2*ParentIndex+2)<size;
}
int getParentIndex(int childIndex)
{
    return (childIndex-1)/2;
}
int getLeftChildIndex(int ParentIndex)
{
    return (2*ParentIndex+1);
}
int getRightChildIndex(int ParentIndex)
{
    return (2*ParentIndex+2);
}
void heapIfyUp()
{
    int currentIndex=size-1;
    while(hasParent(currentIndex)==true)
    {
        if(a[currentIndex]<a[getParentIndex(currentIndex)])
            swap(a[currentIndex],a[getParentIndex(currentIndex)]);
        else
            break;
        currentIndex=getParentIndex(currentIndex);
    }
}
void insert(int val)
{
    a[size++]=val;
    heapIfyUp();
}
int extractMin()
{
    int currentIndex=0;
    int root=a[0];
    a[currentIndex]=a[size-1];
    size--;
    while(hasLeftChild(currentIndex)==true)
    {
        int smallerChildIndex=getLeftChildIndex(currentIndex);
        if(hasRightChild(currentIndex) && a[smallerChildIndex]>a[getRightChildIndex(currentIndex)])
            smallerChildIndex=getRightChildIndex(currentIndex);
        if(a[currentIndex]>a[smallerChildIndex])
            swap(a[currentIndex],a[smallerChildIndex]);
        else break;
        currentIndex=smallerChildIndex;
    }
    return root;
}
int getMin()
{
    return a[0];
}
void heapSort()
{
    while(size!=0)
        cout<<extractMin()<<" ";
}
main()
{
    int n,x;
    while(1)
    {
        scanf("%d",&n);
        if(n==1)
        {

            cin>>x;
            insert(x);
        }
        else if(n==2)
        {
            extractMin();
        }
        else if(n==3)
            printf("%d",getMin());
        else
            heapSort();
    }
}
