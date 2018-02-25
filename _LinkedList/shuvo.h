#ifndef SHUVO_H_INCLUDED
#define SHUVO_H_INCLUDED
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

    void print()
    {
        node *q = head;
        if(head == NULL)
            printf("Empty \n");
        else
        {
        while(q!= NULL)
        {
            printf("%d ",q->val);
            q = q->next;
        }
        printf("\n");
        }
    }
    void insert_first(int a)
    {
        node *p = (node*)malloc(sizeof(node));
        p->val =a;
        if(head == NULL)
        {
           p->next = NULL;
        }
        else
            p->next = head;
        head = p;
    }
    void insert_last(int a)
    {
        node *p = (node*)malloc(sizeof(node));
        p->val =a;
        p->next = NULL;
        node *v = head;
        while(v->next != NULL)
        {
            v = v->next;
        }
        v->next = p;
    }
    void insert_after(int a,int b)
    {
        node *p = (node*)malloc(sizeof(node));
        p->val =b;
        p->next = NULL;
        node *v = head;
        while(v->val != a)
        {
            v = v->next;
        }
        p->next = v->next ;
        v->next = p;

    }
    void insert_before(int a,int b)
    {
        node *p = (node*)malloc(sizeof(node));
        p->val =b;
        p->next = NULL;
        node *v = head;
        while(v->next->val != a)
        {
            v = v->next;
        }
        p->next = v->next ;
        v->next = p;

    }
    void delete_val(int v)
    {
        node *p = head;
        while(p->next->val!=v)
        {
            p=p->next;
        }
        p->next=p->next->next;
    }
    void delete_first()
    {
       if(head == NULL)
        {
           printf("Empty\n");
        }
        else
        {
           printf("Deleted Element ==>%d\n",head->val);
           head = head->next;
        }
    }
    void delete_last()
    {
        if(head == NULL)
            printf("Empty\n");

        else if(head->next==NULL)
        {
           printf("Deleted Element ==>%d\n",head->val);
           head = NULL;
        }
        else
        {
            node *p = head;
        while(p->next->next != NULL)
        {
            p = p->next;
        }
        printf("Deleted Element ==>%d\n",p->next ->val);
        p->next = p->next->next;
        }
    }
};


#endif // SHUVO_H_INCLUDED
