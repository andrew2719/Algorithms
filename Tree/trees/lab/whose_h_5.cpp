#include<bits/stdc++.h>
using namespace std;
map<int,int> h;
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

void paths(Node* node,int path[],int len);
void print(int path[],int len);

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
int height(Node* root)
{

    if(root==NULL)
    return 0;
    int hl = height(root->left);
    int hr = height(root->right);
    h[root->data] = max(hl,hr);
    return max(hl,hr)+1;
}
void print_array(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}int main()
{
    /*int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }*/
    int a[] = {1,2,3,4,5,6};int n = sizeof(a)/sizeof(a[0]);
    Node *root = nullptr;
    root = insert(root,a[0]);
    for(int i=1;i<n;i++)
    insert(root,a[i]);
    
    height(root);
    /*for(auto it: h)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }*/
    bool flag = false;
    for(auto it: h)
    {
        if(it.second==5)
        {
            cout<<it.first<<endl;
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        cout<<"not found"<<endl;
    }
    
    
}