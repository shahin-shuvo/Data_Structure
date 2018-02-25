#include<bits/stdc++.h>
#define SIZE 100
using namespace std;
struct heap
{
    int a[SIZE];
    int index,n=0;


    void insert(int num)
    {
        n++;
        a[n] = num;
        int i= n;
        while(i>1 && a[i]<a[i/2])
        {
            swap(a[i],a[i/2]);
            i = i/2;
        }
    }
    void display()
    {
        for(int i=1; i<=n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    int delet()
    {
        int i = 1;
        int root = a[1];
        a[i] = a[n--];
        while((2*i)<=n)
        {
            int small = 2*i;
            if(((2*i)+1)<=n && a[2*i+1]<a[small])
            {
               small = 2*i +1 ;
            }
            if(a[small]<a[i])
            {
                swap(a[small],a[i]);
            }
            else break;
            i = small;
        }
        return root;

    }
    void heapSort()
    {
        while(n!=0)
        {
            cout<<delet()<<" ";
        }
        cout<<endl;
    }

};
main()
{
    heap h;
    int choice,num;
    cout<< "1 for Insert."<<endl;
    cout<<"2 for Delete."<<endl;
    cout<<"3 for Display."<<endl;
    cout<<"4 for HeapSort."<<endl;
    while(1)
    {
        cin>>choice;
        switch(choice)
        {
        case 1:
            cin>>num;
            h.insert(num);
            break;

        case 2:
            if(h.n==0) cout<<"Now Heap is Empty."<<endl;

            else cout<<h.delet()<<endl;
            break;
        case 3:
            h.display();
            break;
        case 4:
            h.heapSort();
            break;
        }
    }
}
