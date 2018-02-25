#include<bits/stdc++.h>
using namespace std;
struct tree
{
    tree *left,*right;
    int val;
}*root = NULL,*p = NULL;
void create(int n)
{
    int data;
    while(n)
    {
        if(root == NULL)
        {
            root = new tree;
            cout<<"Enter value of root:";
            cin>>root->val;
            root->left = NULL;
            root->right = NULL;
        }
        else
        {
            p = root;
            cout<<"Enter value of node:";
            cin>>data;
            while(1)
            {
                if(data < p->val)
                {
                    if(p->left == NULL)
                    {
                        p->left = new tree;
                        p = p->left;
                        p->val = data;
                        p->left = NULL;
                        p->right = NULL;
                        break;
                    }
                    else if(p->left != NULL)
                    {
                        p = p->left;
                    }
                }
                else if(data > p->val)
                {
                    if(p->right == NULL)
                    {
                        p->right = new tree;
                        p = p->right;
                        p->val = data;
                        p->left = NULL;
                        p->right = NULL;
                        break;
                    }
                    else if(p->right != NULL)
                    {
                        p = p->right;
                    }
                }
            }
        }
       n--;
    }
}
void inorder(tree *p)
{
    if(p==NULL)
        return;
    inorder(p->left);
    cout<<p->val<<endl;
    inorder(p->right);
}
void postorder(tree *p)
{
    if(p==NULL)
        return;
    postorder(p->left);
    postorder(p->right);
    cout<<p->val<<endl;
}
void preorder(tree *p)
{
    if(p==NULL)
        return;
    cout<<p->val<<endl;
    preorder(p->left);
    preorder(p->right);
}

main()
{
    int n;
    cin>>n;
    create(n);
    cout<<"Printing traversal in inorder:\n";
    inorder(root);
    cout<<"Printing traversal in preorder:\n";
    preorder(root);
    cout<<"Printing traversal in postorder:\n";
    postorder(root);
}
