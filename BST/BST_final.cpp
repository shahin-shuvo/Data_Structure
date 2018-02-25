#include<bits/stdc++.h>
using namespace std;

struct tree
{
    char str[100];
    tree *right;
    tree *left;
};
struct BSTree
{
    tree *root=NULL;

    tree* get(char s[])
    {
        tree *p=(tree *)malloc(sizeof(tree));
        strcpy(p->str,s);
        p->left = NULL;
        p->right = NULL;
        return p;
    }

    tree* getroot()
    {
        return root;
    }

    tree* insert_new(tree *p,char s[])
    {

        if(root==NULL)
            root = get(s);
        else if(p==NULL)
            p = get(s);
        else if(strcmp(p->str,s)>0)
            p->left = insert_new(p->left,s);
        else
            p->right = insert_new(p->right,s);
        return p;
    }
    tree *bst_search(tree *p,char s[])
    {
        if(p==NULL)
            return p;
        else if(strcmp(p->str,s)==0)
            return p;
        else if(strcmp(s,p->str)>0)
            return bst_search(p->right,s);
        else if((s,p->str)<0)
            return bst_search(p->left,s);
    }

    void inorder(tree *p)
    {
        if(p!=NULL)
        {
            inorder(p->left);
            cout<<p->str<<" ";
            inorder(p->right);
        }
    }
    void preorder(tree *p)
    {
        if(p!=NULL)
        {
            cout<<p->str<<" ";
            preorder(p->left);
            preorder(p->right);
        }
    }
    void postorder(tree *p)
    {
        if(p!=NULL)
        {
        postorder(p->left);
        postorder(p->right);
        cout<<p->str<<" ";
        }
    }

    tree *leftmost(tree *p)
    {
        if(p->left==NULL)
            return p;
        else
            return leftmost(p->left);
    }

    tree* del(tree *p,char s[])
    {
        if(p==NULL)
            return p;
        else if(strcmp(p->str,s)<0)
            p->right=del(p->right,s);
        else if(strcmp(p->str,s)>0)
            p->left=del(p->left,s);
        else
        {
            if(p->left==NULL && p->right==NULL)
                p=NULL;
            else if(p->left==NULL)
                p=p->right;
            else if(p->right==NULL)
                p=p->left;
            else
            {
                tree *temp=leftmost(p->right);
                strcpy(p->str,temp->str);
                p->right=del(p->right,temp->str);
            }
        }
        return p;
    }
    void cc(tree *p)
    {
        while(p!=NULL)
        {

        }
    }
    void counting(tree *p,char s[])
    {
        tree *curr = bst_search(p,s);
    }


};
int main()
{
    BSTree b;
    int c;
    char s[100];
    cout<<"1 to insert \n2 to search \n3 to inorder \n4 to preorder \n5 to postorder\n6 to delete"<<endl;
    while(1)
    {
        cin>>c;

        if(c==1)
        {
            cin>>s;
            b.insert_new(b.getroot(),s);
        }
        else if(c==2)
        {
            cin>>s;
            tree *temp=b.bst_search(b.getroot(),s);
            if(temp!=NULL)
                cout<<"Found\n";
            else
                cout<<"Not Found\n";
        }
        else if(c==3)
        {
            b.inorder(b.getroot());
            cout<<endl;

        }
        else if(c==4)
        {
            b.preorder(b.getroot());
            cout<<endl;
        }
        else if(c==5)
        {
            b.postorder(b.getroot());
            cout<<endl;
        }
        else if(c==6)
        {
            cin>>s;
            b.del(b.getroot(),s);
        }
    }
    return 0;
}
