#include<stdio.h>
#include<stdlib.h>
struct BST
{
    int a[1001];
    int sz;

    BST()
    {
        sz = 0  ;
        for(int i=0; i<1001; i++) a[i] = -1;
    }

    int left(int n)
    {
        return 2*n;
    }

    int right(int n)
    {
        return 2*n+1;
    }

    void insert_(int v, int k)
    {
        if(a[k]==v || k>1000) return;
        if(sz==0)
        {
            sz++;
            a[sz] = v;
            return;
        }
        int L = left(k);
        int R = right(k);

        if(v<a[k])
        {
            if(a[L]==-1)
            {
                a[L] = v;
                sz++;
                return;
            }
            else insert_(v, L);
        }
        else
        {
            if(a[R]==-1)
            {
                a[R] = v;
                sz++;
                return;
            }
            else insert_(v, R);
        }
    }

    void search_(int v, int k)
    {
        if(a[k]==v)
        {
            puts("Found");
            return;
        }
        if(a[k]==-1)
        {
            puts("NOT FOUND");
            return;
        }
        if(v<a[k]) search_(v, left(k));
        else search_(v, right(k));
    }

    void inOrder(int k)
    {
        if(a[k]==-1) return;
        int L = left(k);
        int R = right(k);
        inOrder(left(k));
        printf("%d ", a[k]);
        inOrder(right(k));
    }

};

int main()
{
    BST L;
    int tp, x;

    puts("##Menu##\n");
    puts("1. Press 1 to insert.\n");
    puts("2. Press 2 to search.\n");
    puts("3. Press 3 to print inOrder.\n\n");

    while(scanf("%d", &tp)==1)
    {
        if(tp==1)
        {
            scanf("%d", &x);
            L.insert_(x, 1);
        }
        else if(tp==2)
        {
            scanf("%d", &x);
            L.search_(x, 1);
        }
        else
        {
            L.inOrder(1);
            puts("");
        }
    }

    return 0;
}

