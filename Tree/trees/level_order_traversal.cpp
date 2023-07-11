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

Node* insert(Node *node,int val)//bst insertion but as mentioed to reverse the constraints
{
    if(node==NULL)
    return newnode(val);
    if(val<node->data)
        node->right = insert(node->right,val);
    else
		node->left = insert(node->left,val);
    return node;
}

vector<vector<int>> level_order_traverse(Node *root,int n)
{
    vector<vector<int>> ans;
	vector<queue<Node*>> nodes;
	int c=0,j=0;
    if(root==NULL)
    return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        vector<int> row;
        for(int i=0;i<n;i++){
			nodes.push_back(q);
            Node *node = q.front();
            q.pop();
            if(node->left!=NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);
            row.push_back(node->data);
        }
		if(c==n)
		{
			int avg = accumulate(row.begin(),row.end(),0)/row.size();
			row.erase(find(row.begin(),row.end(),row.front()));
			row.front() = avg;
			row.erase(find(row.begin(),row.end(),row.back()));
			row.back() = avg;
		}
        ans.push_back(row);
		c++;
    }
    return ans;
}

void print_vector(vector<vector<int>> &a)
{
    for(int i=0;i<a.size();i++)
    {
		if(i%2){ // printing the odd rows
			for(int j=0;j<a[i].size();j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
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
    int a[] = {4 ,2 ,1 ,3 ,6 ,5 ,7};int n = sizeof(a)/sizeof(a[0]);
    Node *root = nullptr;
    root = insert(root,a[0]);
    for(int i=1;i<n;i++)
    insert(root,a[i]);
    vector<vector<int>> ans = level_order_traverse(root,3);
    print_vector(ans);
    
}

