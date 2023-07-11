#include<bits/stdc++.h>
using namespace std;
//delete child node of a given node
map<int,int> child_parent;
map<int,set<int>> parent_child;
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
    if(val<node->data){
        Node* lchild = insert(node->left,val);
		node->left = lchild;
		child_parent[lchild->data] = node->data;
        parent_child[node->data].insert(lchild->data);
	}
    else{
        Node* rchild = insert(node->right,val);
		node->right = rchild;
		child_parent[rchild->data] = node->data;
        parent_child[node->data].insert(rchild->data);
	}
    return node;
}

Node* mini(Node* node)
{
    Node* current = node;
    while(current && current->left!=NULL)
    current = current->left;
    return current;
}

Node* delete_node(Node* root,int val)
{
    if(root==NULL)
    return root;
    if(val<root->data)
    root->left =  delete_node(root->left,val);
    else if(val>root->data)
    root->right =  delete_node(root->right,val);
    else{
        if(root->left==NULL && root->right==NULL)
        return NULL;
        else if(root->left==NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = mini(root->right);

        root->data = temp->data;
        
        root->right = delete_node(root->right,temp->data);
    }
    return root;
}
void posteorder(Node *node)
{
    if(node==NULL)
    return;
    posteorder(node->left);
    posteorder(node->right);
    cout<<node->data<<" ";
}
void print_array(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
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
    int a[] = {50,20};int n = sizeof(a)/sizeof(a[0]);
    Node *root = nullptr;
    root = insert(root,a[0]);
    for(int i=1;i<n;i++)
    insert(root,a[i]);
    print_array(a,n);
	/*for(auto it:child_parent)
	{
		cout<<it.first<<" "<<it.second<<endl;
	}*/
    /*for(auto it1:parent_child)
    {
        for(auto it2:it1.second)
        {
            cout<<it1.first<<" "<<it2<<endl;
        }
    }*/
	int x=30;
	cout<<"enter node : ";
	cin>>x;
	/*if(child_parent[x]){
	delete_node(root,child_parent[x]);
	inorder(root);
	}
	else
	cout<<"it is root"<<endl; */
    //cout<<*(parent_child[x].begin())<<endl;
    if(parent_child[x].size())
    {
        
        delete_node(root,*(parent_child[x].begin()));
        posteorder(root);
    } 
    else
    cout<<"it is leaf node";
}