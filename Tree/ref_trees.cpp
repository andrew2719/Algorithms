#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};


Node* tree_insert(Node* root,int val)
{
    if(root==NULL)
    {
        return new Node(val);
    }
    if(val<root->data)
    {
        root->left = tree_insert(root->left,val);
    }
    else
    root->right = tree_insert(root->right,val);

    return root;
}

void inorder(Node* node)
{
    if(node==NULL)
    return ;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

void preorder(Node* node)
{
    if(node==NULL)
    return ;
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node* node)
{
    if(node==NULL)
    return ;
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}

int main()
{
    int n;
    int a[] = {8,2,7,5,6,9,3,4};
    n = sizeof(a)/sizeof(a[0]);
    Node* head  = tree_insert(NULL,a[0]);
    for(int i=1;i<n;i++)
    tree_insert(head,a[i]);
    inorder(head);
    cout<<endl;
    preorder(head);
    cout<<endl;
    postorder(head);
    cout<<endl;
    cout<<'\n';
}