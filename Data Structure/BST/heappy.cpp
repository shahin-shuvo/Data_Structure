#include<bits/stdc++.h>
using namespace std;
struct Heap
{
    int arr[100];
    int last;
    Heap()
    {
        arr[100]= {0};
        last=0;
    }
    void insert_w(int n)
    {
        last++;
        arr[last]=n;
        int i=last;
        while(i>1 && arr[i]>arr[i/2])
        {
            swap(arr[i],arr[i/2]);
            i=i/2;
        }

    }
    void print()
    {

        for(int j=1; j<=last; j++)
        {
            cout<<arr[j]<<" -> ";

        }
        cout<<endl;
    }
    void delete_w()
    {

        swap(arr[1],arr[last]);
        arr[last]=0;
        last--;
        int paren=1;
        while(arr[2*paren])
        {
            if(arr[2*paren+1])
            {
                if(arr[2*paren]>arr[2*paren+1])
                {
                    if(arr[2*paren]>arr[paren])
                    {
                        swap(arr[2*paren],arr[paren]);
                        paren=2*paren;
                    }
                    else
                        break;
                }
                else
                {
                    if(arr[2*paren+1]>arr[paren])
                    {
                        swap(arr[2*paren+1],arr[paren]);
                        paren=2*paren+1;
                    }
                    else
                        break;
                }

            }
            else
            {
                if(arr[2*paren]>arr[paren])
            {
                swap(arr[2*paren],arr[paren]);
                    paren=2*paren+1;
                }
                else
                    break;
                }
        }
    }
};
int main()
{
    Heap s;
    int n,m;
    while(1)
    {
        cin>>n;
        if(n==1)
        {
            cin>>m;
            s.insert_w(m);
        }
        else if(n==2)
        {
            s.print();
        }
        else if(n==3)
        {
            s.delete_w();
        }

    }

}
