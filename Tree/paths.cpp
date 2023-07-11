#include<bits/stdc++.h>
using namespace std;
 

vector<vector<int>> paths;
class Node
{
public:
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 

bool isLeaf(Node* node) {
    return (node->left == nullptr && node->right == nullptr);
}
 

void printRootToLeafPaths(Node* node, vector<int> &path)
{
    // base case
    if (node == nullptr) {
        return;
    }
 
    
    path.push_back(node->data);
 
    
    if (isLeaf(node))
    {
        vector<int> temp;
        for (int data: path) {
            temp.push_back(data);

        }
        paths.push_back(temp);
    }
 

    printRootToLeafPaths(node->left, path);
    printRootToLeafPaths(node->right, path);
 
    
    path.pop_back();
}
 

void printRootToLeafPaths(Node* node)
{
    
    vector<int> path;
 
    printRootToLeafPaths(node, path);
}
 
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
int main()
{
    int n;
    cin>>n;
    n = 9;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    Node* root = NULL;
    for(int i=0;i<n;i++)
    {
        root = tree_insert(root,a[i]);
    }

    printRootToLeafPaths(root);

    
    for(int i=0;i<paths.size();i++)
    {
        if(paths[i].size()>0)
        {
            
            for(int j=paths[i].size()-1;j>=1;j--)
            {
                cout<<paths[i][j]<<"->";
            }
            cout<<paths[i][0];
            cout<<endl;
        }
        
    }
    
}