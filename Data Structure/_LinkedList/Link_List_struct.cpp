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
    int len;
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
    void k_th_del(int k)
    {
        node *p = head;
        int i = 1;
        while(i!=k)
        {
            p=p->next;
            i++;
            if(i>k)
            {
                printf("not found\n");
                return;
            }
        }
        if(p==head) delete_first();
        else if(p->next ==NULL) delete_last();
        else delete_val(p->val);
    }
    void increase(int i)
    {
        node *p = head;
        if(p==NULL) return;
        while(p!=NULL)
        {
            p->val = p->val+i;
            p=p->next;
        }
    }
    void reverse_list()
    {
        node *current_node,*next_node,*prev_node;
        current_node=head;
        next_node=NULL;
        prev_node=NULL;
        while(current_node!=NULL)
        {
            next_node=current_node->next;
            current_node->next = prev_node;
            prev_node = current_node;
            current_node = next_node;
        }
        head = prev_node;
    }
    node* swap_list(node *head)
    {
        if(head==NULL || head->next==NULL){
			return head;
		}
			//change the link for first 2 nodes and
			//make a recursive call to rest of the list.
			node *ptrOne = head;
			node *ptrTwo = head->next;
			node *ptrTwoNext = ptrTwo->next;
			ptrTwo->next = head;
			node *newhead = ptrTwo;
			ptrOne->next = swap_list(ptrTwoNext);
			return newhead;
	}
	node* swap_i_th_node(int i)
	{
        len = getLenth(head);
        if (i > len) {
			printf("\n INVALID NUMBER, No Swapping, k>length of list");
			return NULL;
		}
		if (2 * i - 1 == len) {
			printf(" Nodes are same from front and at the end, no swapping");
			return NULL; // both are same, No need for swaping
		}
		node *left=head;
		node *left_prev = NULL;
		int j = i;
		while (j > 1) {
			left_prev = left;
			left = left->next;
			j--;
		}
		// System.out.println("\nleft pointing at " + left.data);

		node *right = head;// move j=(len-i+1) from the start, which means i
							// nodes from the end
		node *right_prev = NULL;// in case i=len=> right will the first node =>
								// right_prev=NULL
		j = len - i + 1;
		while (j > 1) {
			right_prev = right;
			right = right->next;
			j--;
		}
		// System.out.println("right pointing at " + right.data);
		if (left_prev !=  NULL) {// if left_prev!=NUll=>left node is not the
					// first node, so left_prev will point to right node
			left_prev->next = right;
		}

		if (right_prev !=  NULL) {// if right_prev!=NUll=>right node is not the
		// first node, so right_prev will point to left node
			right_prev->next = left;
		}

		node *temp = left->next;// now just swap the left.next and right.next to
								// complete
		left->next = right->next;
		right->next = temp;

		if (i == 1)// change the head in case of i=1 or i=len.
			head = right;
		if (i == len)
			head = left;

		return head;
	}
	int getLenth(node *head)
	{
	    node* n = head;
		int coun = 0;
		while (n != NULL) {
			n = n->next;
			coun++;
		}
		return coun;
	}

};


main()
{
    list s;
    node *head;
    int n,c,d;
    while(1)
    {
        scanf("%d",&n);
        if(n==1)
            s.print();
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
        else if(n==4)
        {
            scanf("%d %d",&c,&d);
            s.insert_after(c,d);
        }
        else if(n==5)
        {
            scanf("%d %d",&c,&d);
            s.insert_before(c,d);
        }
        else if(n==6)
        {
            scanf("%d",&c);
            s.delete_val(c);
        }
        else if(n==7)
        {
            s.delete_first();
        }
        else if(n==8)
        {
            s.delete_last();
        }
        else if(n==9)
        {
            int k;
            scanf("%d",&k);
            s.k_th_del(k);
        }
        else if(n==10)
        {
            int k;
            scanf("%d",&k);
            s.increase(k);
        }
        else if(n==11)
        {
            s.reverse_list();
        }
        else if(n==12)
        {
            s.head = s.swap_list(s.head);
        }
        else if(n==13)
        {
            int k;
            scanf("%d",&k);
            s.swap_i_th_node(k);
        }
    }

}

