#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
    
    Node(int val){
        data = val;
        left = right = NULL;    
    }
};

//bottom view
void bottomview(map<int,int> &mp,Node* root,int h){

    if(root==NULL)
    return ;
    mp[h] = root->data;
    bottomview(mp,root->left,h-1);
    bottomview(mp,root->right,h+1);
}


//topview
void topview(map<int,int> &mp,Node* root,int h,map<int,int> &sum){

    if(root==NULL)
    return ;
    if(mp[h]!=0)
    mp[h] = root->data;
    sum[h] += root->data;
    topview(mp,root->left,h-1,sum);
    topview(mp,root->right,h+1,sum);
}



Node* insert(Node* root, int val){
    if(root==NULL)
    return new Node(val);
    
    if(val<root->data){
        root->left = insert(root->left,val);
    }
    else if(val>root->data){
        root->right = insert(root->right,val);
    }
    return root;
}

void inorder(Node* root){
    if(root==NULL)
    return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
int main(){

    int n;
    int a[] = {8,2,7,5,6,9,3,4};
    n = sizeof(a)/sizeof(a[0]);
    Node* head  = insert(NULL,a[0]);
    for(int i=1;i<n;i++)
    insert(head,a[i]);
    map<int,int> mp;
    inorder(head);
    cout<<"\n";
    map<int,int> sum;
    //bottomview(mp,head,0,sum);
    topview(mp,head,0,sum);
    // for(auto it:mp){
    //     cout<<it.second<<" ";
    // }
    for(auto it:sum){
        cout<<it.second<<" ";
    }

}