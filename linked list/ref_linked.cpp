#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* insert(Node* head,int val)
{
    if(head==NULL)
    {
        return new Node(val);
    }
    else{
        Node* temp = head;
        temp->next = insert(temp->next,val);
    }
    return head;
}

void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main()
{
    int n;
    int a[] = {1,2,3,5,6};
    n = sizeof(a)/sizeof(a[0]);
    Node* head  = insert(NULL,a[0]);
    for(int i=1;i<n;i++)
    insert(head,a[i]);
    print(head);
    cout<<'\n';

    
}