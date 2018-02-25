#include<bits/stdc++.h>
#define SIZE 100
using namespace std;
struct student
{
    char nam[100] ;
    int roll;
    int marks;
    int c;
};
struct heap
{
    student b[SIZE];
    student a[SIZE];
    int index,n=0,m;


    void insert(student st)
    {
        n++;
        a[n] = st;
        int i= n;
        while(i>1 && a[i].marks>a[i/2].marks)
        {
            swap(a[i],a[i/2]);
            i = i/2;
        }
    }

    void display()
    {
        for(int i=1; i<=n; i++)
        {
            cout<<a[i].nam<<" "<<a[i].roll<<" "<<a[i].marks<<endl;
        }
    }
    student getstd(char n[],int r,int m)
    {
        student st;
        strcpy(st.nam, n);
        st.roll = r;
        st.marks = m;
        return st;
    }
    student delet()
    {
        int i = 1;
        student root = a[1];
        a[i] = a[n--];
        while((2*i)<=n)
        {
            int small = 2*i;
            if(((2*i)+1)<=n && a[2*i+1].marks>a[small].marks)
            {
                small = 2*i +1 ;
            }
            if(a[small].marks>a[i].marks)
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
        student st;
        while(n!=0)
        {
            st = delet();
            cout<<st.nam<<" "<<st.roll<<" "<<st.marks<<endl;
        }
    }
    void Rank()
    {
        int i,k,flag = n;
        int j = 1,m=1;
        for( i = 1; i<=flag; i++)
        {
            b[i]=delet();
        }
        cout<<"Rank "<<m<<": ";
        cout<<b[j].nam<<" "<<b[j].roll<<" "<<b[j].marks<<endl;
        for(j=2;j<=flag;j++)
        {
            if(b[j].marks<b[j-1].marks) m++;
            cout<<"Rank "<<m<<": ";

            cout<<b[j].nam<<" "<<b[j].roll<<" "<<b[j].marks<<endl;
        }
    }


};
main()
{
    heap h;
    student st;
    int choice,num;
    char n[50];
    int r;
    int m;

    cout<< "1 for Insert."<<endl;
    cout<<"2 for Delete."<<endl;
    cout<<"3 for Display."<<endl;
    cout<<"4 for HeapSort."<<endl;
    cout<<"5 for Rank."<<endl;
    FILE *file;
    file = fopen("aa.txt", "r");
    while(1)
    {
        cin>>choice;
        switch(choice)
        {
        case 1:
            cin>>n;
            cin>>r;
            cin>>m;
            st = h.getstd(n,r,m);
            h.insert(st);
            break;

        case 2:
            if(h.n==0) cout<<"Now Heap is Empty."<<endl;

            else
            {
                st = h.delet();
                cout<<st.nam<<" "<<st.roll<<" "<<st.marks<<endl;
            }
            break;

        case 3:
            h.display();
            break;
        case 4:
            h.heapSort();
            break;
        case 5:
            h.Rank();
            break;

        }
    }
}

