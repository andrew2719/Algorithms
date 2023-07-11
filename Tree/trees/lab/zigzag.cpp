#include<bits/stdc++.h>
using namespace std;
struct Node //struct declaraton
{
    int data;
    Node *left,*right;
};

Node* newnode(int data)// creating the node
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
Node* insert(Node *node,int val) //  inserting the node
{
    if(node==NULL)
    return newnode(val);
    if(val<node->data)
        node->left = insert(node->left,val);
    else
        node->right = insert(node->right,val);
    return node;
}
void zigzag(Node* root,int l,int r,int h)
{
    if(root==NULL)
    return;
    if(l>r)
    {
        h++;
        cout<<root->data<<" ";
    }
    zigzag(root->left,l+1,r,h);
    zigzag(root->right,l,r+1,h);
}
int solve(Node* root)
{
    int h=0;
    zigzag(root,0,0,h);
    return h;
}
int main()
{
    /*int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }*/
    int a[] = {7,6,1,4,9,5};int n = sizeof(a)/sizeof(a[0]);
    Node *root = nullptr;
    root = insert(root,a[0]);
    for(int i=1;i<n;i++)
    insert(root,a[i]);
    
    
}