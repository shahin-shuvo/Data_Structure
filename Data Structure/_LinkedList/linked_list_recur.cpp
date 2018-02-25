#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    node *next;
};
struct list
{
    node *head;
    list()
    {
        head = (node*)malloc(sizeof(node));
        head = NULL;
    }

    void print(node *q)
    {

        if(head == NULL)
            printf("Empty");
        else
        {
            if(q==NULL) return;
            printf("%d ",q->val);
            print(q->next);
        }
    }
    void insert_first(int a,node *q)
    {
        node *p = (node*)malloc(sizeof(node));
        p->val =a;
        if(q == NULL)
        {
            p->next = NULL;
        }
        else
            p->next = q;
        head = p;
    }
    void insert_last(node *q,int a)
    {
        node *p = (node*)malloc(sizeof(node));
        p->val =a;
        p->next = NULL;
        if(head==NULL)
        {

            head = p;
        }
        else
        {
            if(q->next == NULL)
            {
                q->next = p;
                return;
            }
            insert_last(q->next,a);
        }
    }
    void insert_after(node *q,int c,int d)
    {
        node *p = (node*)malloc(sizeof(node));
        p->val =d;
        p->next = NULL;
        if(q->val == c)
        {
            p->next = q->next;
            q->next  = p;
            return ;

        }
        insert_after(q->next,c,d);

    }
    void insert_before(node *q,int c,int d)
    {
        node *p = (node*)malloc(sizeof(node));
        p->val =d;
        p->next = NULL;
        if(head->val ==c)
        {
            p->next = q;
            head = p;
            return;
        }
        if(q->next->val == c)
        {
            p->next = q->next;
            q->next  = p;
            return ;

        }
        insert_before(q->next,c,d);

    }
    void delete_node(node *q,int c)
    {
        if(head == NULL)
        {
            printf("Empty\n");
            return;
        }
        if(head->val = c)
        {
            head= head->next;
            return;
        }
        if(q->next->val == c)
        {
            q->next = q->next->next;
            return ;

        }
        delete_node(q->next,c);
    }
    void delete_first()
    {
        if(head == NULL)
        {
            printf("Empty\n");
            return;
        }
        else
        {
            head = head->next;
        }
    }
    void delete_last(node *q)
    {
        if(head == NULL)
        {
            printf("Empty\n");
            return;
        }
        if(head->next == NULL)
        {
            head = NULL;
            return;
        }
        if(q->next->next==NULL)
        {
            q->next = NULL;
            return;
        }
        delete_last(q->next);
    }

};


main()
{
    list s;

    int n,c,d;
    while(1)
    {
        scanf("%d",&n);
        if(n==1)
        {
            s.print(s.head);
            printf("\n");
        }

        else if(n==2)
        {
            scanf("%d",&c);
            s.insert_first(c,s.head);
        }
        else if(n==3)
        {
            scanf("%d",&c);
            s.insert_last(s.head,c);
        }
        else if(n==4)
        {
            scanf("%d %d",&c,&d);
            s.insert_after(s.head,c,d);
        }
        else if(n==5)
        {
            scanf("%d %d",&c,&d);
            s.insert_before(s.head,c,d);
        }
        else if(n==6)
        {
            scanf("%d",&c);
            s.delete_node(s.head,c);
        }
        else if(n==7)
        {
            s.delete_first();
        }
        else if(n==8)
        {
            s.delete_last(s.head);
        }
    }

}

