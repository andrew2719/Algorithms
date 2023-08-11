#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node *left,*right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};


Node* insert(Node* root,int val)
{
    if(root==NULL)
    return new Node(val);
    else if(val<root->data)
    root->left = insert(root->left,val);
    else
    root->right = insert(root->right,val);

    return root;
}
Node* mini(Node* root)
{
    Node* curr = root;
    while(curr && curr!=NULL)
    curr= curr->left;
    return curr;
}

Node* delete_node(Node* root, int val)
{
    if(root==NULL)
    return root;
    else if(val<root->data)
    root->left = delete_node(root->left,val);
    else if(val>root->data)
    root->right = delete_node(root->right,val);
    else{
        if(root->left==NULL && root->right==NULL)
        {
            return NULL;
        }
        else if(root->right==NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        Node* temp = mini(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right,temp->data);
    }
}

void inorder(Node* root)
{
    if(root==NULL)
    return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main()
{
    int a[] = {50,30,20,40,70,60,80};int n = sizeof(a)/sizeof(a[0]);
    Node *root = nullptr;
    root = insert(root,a[0]);
    for(int i=1;i<n;i++)
    insert(root,a[i]);
    delete_node(root,20);
    //cout<<"found"<<endl;
    //else
    //cout<<"not found"<<endl;
    inorder(root);
}
