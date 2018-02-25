#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

struct heap
{
    int array[100],n=0;
    void insert_function(int num)
    {
        n++;
        array[n] = num;
        int index = n;
        while(index>1 && array[index]>array[index/2])
        {
            swap(array[index],array[index/2]);
            index = index/2;
        }
    }

    void display()
    {
        if(n==0)
        {
            cout<<"Empty Heap"<<endl;
            return;
        }
        for (int i = 1; i <= n; i++)
            printf("%d ", array[i]);
        printf("\n");
    }

    void delet()
    {
        int left,right,i,temp,parent;
        swap(array[1],array[n]);
        n--;
        i = 1;//parent
        while(i<=n)
        {
            left = 2*i;
            right = 2*i+1;
            if(array[left]>array[right])
                temp = array[left];
            else temp = array[right];
            if(temp>array[i])
            {
                swap(array[i],temp);
            }
            else break;
            i++;
        }
    }

};
main()
{
    int num,choice;
    heap h;
    printf("1.Insert the element \n");
    printf("2.Delete the element \n");
    printf("3.Display all elements \n");
    printf("4.Quit \n");
    while(1)
    {
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            cin>>num;
            h.insert_function(num);
            break;
        case 2:
            h.delet();
            break;
        case 3:
            h.display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice.\n");
        }
    }
}
