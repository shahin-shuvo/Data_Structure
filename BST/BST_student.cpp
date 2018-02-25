#include<bits/stdc++.h>
using namespace std;

struct student
{
   char nam[100] ;
   int roll;
   int marks;
};
struct tree
{
    student s;
    tree *left;
    tree *right;
};
struct BST
{
    tree *root=NULL;
    tree *get(student st)
    {
        tree *p=(tree *)malloc(sizeof(tree));
        p->s = st;
        p->left = NULL;
        p->right = NULL;
        return p;
    }
    tree* getroot()
    {
        return root;
    }
    tree* insert_new(tree *p,student st)
    {

        if(root==NULL)
            root = get(st);
        else if(p==NULL)
            p = get(st);
        else if(strcmp(p->s.nam,st.nam)>0)
            p->left = insert_new(p->left,st);
        else if(strcmp(p->s.nam,st.nam)<0)
            p->right = insert_new(p->right,st);
        else if(strcmp(p->s.nam,st.nam)==0)
        {
            if(p->s.roll>st.roll)
            p->left = insert_new(p->left,st);
        else if(p->s.roll<st.roll)
            p->right = insert_new(p->right,st);
        }
        return p;
    }
    void inorder(tree *p)
    {
        if(p!=NULL)
        {
            inorder(p->left);
            cout<<p->s.nam<<" "<<p->s.roll<<" "<<p->s.marks<<endl;
            inorder(p->right);
        }
    }
    student getstd(char n[],int r,int m)
    {
        student st;
        strcpy(st.nam , n);
        st.roll = r;
        st.marks = m;
        return st;
    }
};
int main()
{
    BST b;
    student st;
    int c;
    char n[50];
    int r;
    int m;
    char s[100];
    cout<<"1 to insert\n3 to inorder\n6 to delete"<<endl;
    while(1)
    {
        cin>>c;

        if(c==1)
        {
            cin>>n;
            cin>>r;
            cin>>m;
            st = b.getstd(n,r,m);
            b.insert_new(b.getroot(), st);
        }

        else if(c==3)
        {
            b.inorder(b.getroot());
            cout<<endl;

        }

    }
    return 0;
}
