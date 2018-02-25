#include<bits/stdc++.h>
#include<string.h>
using namespace std;
struct tree
{
    tree *left,*right;
    char val[10];
}*root = NULL,*p = NULL;
struct tree* FindMin(tree *p)
{
  if(p==NULL)  return p;
  if(p->left != NULL)
    FindMin(p->left);
  return p;
}
void create(int n)
{
    char data[10];
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
                if(strcmp(data,p->val)<0)
                {
                    if(p->left == NULL)
                    {
                        p->left = new tree;
                        p = p->left;
                        strcpy(p->val,data);
                        p->left = NULL;
                        p->right = NULL;
                        break;
                    }
                    else if(p->left != NULL)
                    {
                        p = p->left;
                    }
                }
                else if(strcmp(data, p->val)>0)
                {
                    if(p->right == NULL)
                    {
                        p->right = new tree;
                        p = p->right;
                        strcpy(p->val,data);
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
void search(char s[],tree *p)
{
    if(strcmp(s,p->val)==0)
    {
        printf("Found\n");
        return;
    }
    if(p->left==NULL && p->right==NULL)
    {
        printf("Not Found\n");
        return;
    }

    if(strcmp(s,p->val)==1)
        search(s,p->right);
    else if(strcmp(s,p->val)==-1)
        search(s,p->left);
}
void delete_node(char s[],tree *p)
{
    if(p==NULL) return ;
    else if(strcmp(s,p->val)==-1) delete_node(s,p->left);
    else if(strcmp(s,p->val)==1) delete_node(s,p->right);
    else
    {
    if(p->left == NULL && p->right == NULL)
    {
        delete p ;
        p = NULL;
    }
    else if(p->left==NULL)
    {
        tree *temp = p;
        p = p->right;
        delete temp;
    }
    else if(p->right==NULL)
    {
        tree *temp = p;
        p = p->left;
        delete temp;
    }
    else
    {
        struct tree *temp = FindMin(p->right);
        p = temp;
        delete temp;

    }
    }
}
main()
{
    int n;
    char s[10],k[10];
    cin>>n;
    create(n);
    cout<<"Printing traversal in inorder:\n";
    inorder(root);
    cout<<"Printing traversal in preorder:\n";
    preorder(root);
    cout<<"Printing traversal in postorder:\n";
    postorder(root);
    cin>>s;
    search(s,root);
    cin>>k;
    delete_node(k,root);
    inorder(root);
}

