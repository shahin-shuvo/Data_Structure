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
        head = NULL;

        tail = (node*)malloc(sizeof(node));
        tail = NULL;
    }
    void print_f()
    {
        node *q = head;
        if(head == NULL)
            printf("Empty \n");
        else
        {
        printf("Link List from forward : ");
        while(q!= NULL)
        {
            printf("%d ",q->val);
            q = q->next;
        }
        printf("\n");
        }
    }
    void print_b()
    {
        if(head == NULL)
            printf("Empty\n");
        else
        {
            printf("Link List from backward : ");
            node *p = tail;
            while(p != NULL)
            {
                printf("%d ",p->val);
                p = p->prev;
            }
            printf("\n");
        }
    }
    void insert_first(int a)
    {
        node *p = (node*)malloc(sizeof(node));
        p->val =a;
        p->prev = NULL;
        if(head == NULL)
        {
           p->next = NULL;
           tail = p;
        }
        else
        {
            head->prev = p;
            p->next = head;
        }

        head = p;
    }
    void insert_last(int a)
    {
        node *p = (node*)malloc(sizeof(node));
        p->val =a;
        p->next = NULL;
        tail->next = p;
        p->prev = tail;
        tail = p;
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
        printf("Deleted Element ==>%d\n",tail->val);

        tail = tail->prev;
        tail->next = NULL;

        }
    }
    void search_f(int x)
    {
        int pos = 1;
        node *p = head;
        while(p->val != x)
        {
            p = p->next;
            pos++;
        }
        printf("From forward %d is in node number %d\n",x,pos);
    }
    void search_b(int x)
    {
        int pos = 1;
        node *p = tail;
        while(p->val != x)
        {
            p = p->prev;
            pos++;
        }
        printf("From backward %d is in node number %d\n",x,pos);
    }

    node *reverseDLL(){
		node *current = head;
		node *temp = NULL;
		while(current!=NULL){
			temp = current->prev;   //swap the next and prev pointer
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}
		return temp->prev;
	}

};

main()
{
    doubly s;
    int n,c,d;
    int x;
    while(1)
    {
        scanf("%d",&n);
        if(n==1)
            s.print_f(); //print forward
        else if(n==2)
        {
            scanf("%d",&c);
            s.insert_first(c);
        }
        else if(n==3)
        {
            scanf("%d",&c);
            s.insert_last(c);
        }
        else if(n==7)
        {
            s.delete_first();
        }
        else if(n==8)
        {
            s.delete_last();
        }
        else if(n== 9)
        {
            s.print_b();  //print from backward
        }
        else if(n== 4)
        {
            scanf("%d",&x);
            s.search_f(x); //search from forward
        }
        else if(n== 5)
        {
            scanf("%d",&x);
            s.search_b(x); //search from backward
        }
        else if(n== 6)
        {
            s.head = s.reverseDLL(); //search from backward
        }
    }

}
