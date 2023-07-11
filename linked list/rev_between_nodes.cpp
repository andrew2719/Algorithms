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

Node* reverse_list(Node* head)
{
    Node* prev;
    Node* curr;
    Node* nxt;
    curr = head;
    nxt = head;
    prev = NULL;

    while(nxt!=NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}


Node* rev_between_node(Node* head,int start,int end)
{
    Node *node_start=NULL,*node_end=NULL,*original_prev=NULL,*original_end=NULL
    ,*curr=head;
    int i = 1;
    
    while(i<=end && curr)
    {
        if(i<start)
        {
            original_prev = curr;
        }
        if(i==start)
        {
            node_start = curr;
        }
        if(i==end)
        {
            original_end = curr->next;
            node_end = curr;
        }
        i++;
        curr=curr->next;
    }

    node_end->next = NULL;
    node_end = reverse_list(node_start);
    if(original_prev){
    original_prev->next = node_end;
    }
    else
    head = node_end;
    node_start->next = original_end;
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
    //print(reverse_list(head));
    print(rev_between_node(head,2,5));


}