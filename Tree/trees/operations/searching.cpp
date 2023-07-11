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
bool search(Node *root,int val)
{
    if(!root)
    return false;
    if(val==root->data)
    return true;
    if(val>root->data)
    return search(root->right,val);
    else
    return search(root->left,val);
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
    if(search(root,5))
    cout<<"found"<<endl;
    else
    cout<<"not found"<<endl;
    
}