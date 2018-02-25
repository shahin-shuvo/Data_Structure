#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    node *next;
    node *prev;
};

struct doubly
{
    node *head;
    node *tail;
    doubly()
    {
        head = (node*)malloc(sizeof(node));
        head->val = 1;
        head->next = NULL;
        head->prev = NULL;

        tail = (node*)malloc(sizeof(node));
        tail = head;
    }
    void print()
    {
        node *q = head;
        while(q!= NULL)
        {
            printf("%d ",q->val);
            q = q->next;
        }
        printf("\n");

    }
    void insert_before_after(int d,int x)
    {
        node *c = head;
        node *p = (node*)malloc(sizeof(node));
        p->val = x;
        if(head==tail)
        {
            p->next = NULL;
        tail->next = p;
        p->prev = tail;
        tail = p;

        node *v = (node*)malloc(sizeof(node));
        v->val = x ;
        head->prev = v;
        v->next = head;
        head = v;
        }
        else if(head->val == d && head!= tail)
        {
        node *v = (node*)malloc(sizeof(node));
        v->val = x ;
        v->next = head->next;
        v->prev = head;
        head->next = v;

        p->next = head ;
        p->prev = NULL;
        head = p;
        }

        else
        {
        while(c->val != d)
        {
            c = c->next;
        }
        p->next = c->next;
        p->prev = c;
        c->next = p;

        node *p1 = (node*)malloc(sizeof(node));
        p1->val = x;
        node *c1 = head;
        while(c1->next->val != d)
        {
            c1 = c1->next;
        }
        p1->next = c1->next;
        p1->prev = c1;
        c1->next = p1;



        }



    }
};
main()
{
    doubly s;
    int n,d;
    int x;
    while(1)
    {
        scanf("%d",&n);
        if(n==1)
            s.print();
        else if(n==2)
        {
            scanf("%d %d",&d,&x);
            s.insert_before_after(d,x);
        }
    }
}
