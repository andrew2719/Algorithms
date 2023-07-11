#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left,*right;
};

Node* newnode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

Node* insert(int a[],int i,int n)
{
    Node *root = nullptr;
    if(i<n)
    {
        root = newnode(a[i]);
        root->left = insert(a,2*i+1,n);
        root->right = insert(a,2*i+2,n);
    }
    return root;
}

void inorder(Node *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

int main()
{
    int a[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };
    int n = sizeof(a)/sizeof(a[0]);
    Node *root = insert(a,0,n);
    inorder(root);
}
