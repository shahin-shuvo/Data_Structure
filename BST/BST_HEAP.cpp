#include <bits/stdc++.h>
using namespace std;

struct student
{
    string name;

    int roll, marks, BatchId;

    student() {}

    student(string name, int roll, int marks, int BatchId)
    {
        this->name = name;
        this->roll = roll;
        this-> marks = marks;
        this->BatchId = BatchId;
    }

    bool operator<(const student &p) const{

        return (marks<=p.marks);
    }

    void printInfo()
    {
        cout<<"Name: "<<name<<"  \tRoll: "<<roll<<"    Marks: "<<marks<<"    Batch:  "<<BatchId<<endl;
    }

};

struct node
{
    student s;

    node *left;
    node *right;

    node(student st)
    {
        s = st;
        left=NULL;
        right=NULL;
    }
};


struct BST
{

    node *root;

    int HighestMarks,  batch;

    BST(){}

    BST(int _batch)
    {
        root = NULL;
        HighestMarks = -1;
        batch = _batch;
    }


    void insert_util(node *r, student s)
    {

        node *a = new node(s);

        if(r==NULL)  r = a;

        else if(s < r->s)
        {
            if(r->left!=NULL)   insert_util(r->left, s);

            else  r->left = a;
        }

        else
        {
            if(r->right!=NULL)    insert_util(r->right, s);

            else  r->right = a;
        }

        return;
    }


    void insert_info(student s)
    {
        HighestMarks = max(HighestMarks, s.marks);

        if(root==NULL)  root = new node(s);

        else insert_util(root, s);
    }


    void print_util(node *r)
    {
        if(r==NULL) return;

        print_util(r->left);

        r->s.printInfo();

        print_util(r->right);
    }


    void Print_Info()
    {
        if(root==NULL)
        {
            puts("Empty BST");
            return;
        }

        else print_util(root);
        puts("");
    }

};


struct Heap
{

    BST a[1000];

    int sz;

    Heap(){

        sz = 0;
    }

    void add(BST val)
    {
        a[++sz] = val;

        int cur = sz, par;

        while(1)
        {
            par = cur/2;

            if(par<=0)  break;

            if(a[par].HighestMarks<a[cur].HighestMarks)
            {
                swap(a[par], a[cur]);
                cur = par;
            }
            else break;
        }
        return;
    }


    BST deleteMax()
    {

        BST x = a[1];

        swap(a[1], a[sz--]);

        int cur = 1;

        while(1)
        {
            int Lt = cur<<1;
            int Rt = Lt+1;

            if(a[cur].HighestMarks<a[Lt].HighestMarks && Lt<=sz && a[Lt].HighestMarks>=a[Rt].HighestMarks && Rt<=sz)
            {
                swap(a[cur], a[Lt]);
                cur = Lt;
            }
            else if(a[cur].HighestMarks<a[Rt].HighestMarks && Rt<=sz && a[Rt].HighestMarks>=a[Lt].HighestMarks && Lt<=sz)
            {
                swap(a[cur],a[Rt]);
                cur = Rt;
            }

            else if(a[cur].HighestMarks<a[Lt].HighestMarks && Lt<=sz && Rt>sz)
            {
                swap(a[cur], a[Lt]);
                cur = Lt;
            }

            else break;
        }

        return x;
    }

    void print()
    {
            if(sz==0)
            {
                puts("Empty Heap");
            }

            else
            {

                BST x = deleteMax();

                cout<<"\nCurrent Best batch: "<<x.batch<<endl;
                puts("\nStudent info of this batch:\n");
                x.Print_Info();

                puts("");

            }

    }

};

int main()
{
    //freopen("input.txt", "r", stdin);

    string name;

    Heap H;

    int roll, marks, id;

    int type, no_of_students;

    while(1)
    {
        cout<<endl;
        cout<<"Press  1  to insert new batch."<<endl;
        cout<<"Press  2  to print best batch."<<endl;
        cout<<"Press  3  to exit."<<endl<<endl;;

        cin>>type;

        if(type==1)
        {
            cout<<"Enter batch id:\n";
            cin>>id;

            BST b = BST(id);

            cout<<"Enter number of students:\n";
            cin>>no_of_students;

            cout<<"Enter name, roll and marks of students\n"<<endl;

            while(no_of_students--)
            {
                cin>>name>>roll>>marks;

                student x = student(name, roll, marks, id);

                b.insert_info(x);
            }

            H.add(b);

        }

        else if(type==2)
        {
            H.print();
        }

        else
        {
            break;
        }
    }

}
