#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left,*right;
};

Node* newnode(int data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node *node,int val)//bst insertion
{
    if(node==NULL)
    return newnode(val);
    if(val<node->data)
        node->left = insert(node->left,val);
    else
        node->right = insert(node->right,val);
    return node;
}

vector<vector<int>> level_order_traverse(Node *root)
{
    vector<vector<int>> ans;
    if(root==NULL)
    return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        vector<int> row;
        for(int i=0;i<n;i++){
            Node *node = q.front();
            q.pop();
            if(node->left!=NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);
            row.push_back(node->data);
        }
        ans.push_back(row);
    }
    return ans;
}

void print_vector(vector<vector<int>> &a)
{
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
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
    vector<vector<int>> ans = level_order_traverse(root);
    print_vector(ans);
    
}

