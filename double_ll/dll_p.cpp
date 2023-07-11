#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    char data;
    Node *prev,*next;
    Node(char val)
    {
        data = val;
        prev = next = NULL;
    }
};

Node* double_ll_insert(Node* head, char val)
{
    Node* temp = head;
    if(head==NULL)
    {
        return new Node(val);
    }
    else{
        temp->next = double_ll_insert(temp->next,val);
        temp->next->prev = head;
    }

    return head;
    
}

// void print(Node* head)
// {
//     Node* prev = head;
//     cout<<"\nfrom front\n";
//     while(head!=NULL)
//     {
//         cout<<head->data<<" ";
//         prev = head;
//         head = head->next;
//     }
//     cout<<"\nfrom back\n";
//     while (prev!=NULL)
//     {
//         cout<<prev->data<<" ";
//         prev = prev->prev;
//     }
    

// }

string remove_adj(Node* head){
	// this code removes adjacent duplicates using a stack
    // stack<char> st;
    // while(head!=NULL){
    //     if(st.empty() || st.top()!=head->data){
    //         st.push(head->data);
    //     }
    //     else{
    //         if(st.top()==head->data){
    //             st.pop();
    //             while(!st.empty() && st.top()==head->data){
    //                 st.pop();
    //             }
                
    //         }
    //         else{
    //             st.push(head->data);
    //         }
    //     }
    //     head = head->next;
    // }

    // while(!st.empty()){
    //     cout<<st.top()<<"<->";
    //     st.pop();
    // }

    stack<char> st;
     
    // Store the index of str
    int i = 0;
    string str1 = "";
    while(head!=NULL){
        str1 += head->data;
        head = head->next;
    }
    // azxxzy
    // Traverse the string str
    while (i < str1.length())
    {
         
        // Checks if stack is empty or top of the
        // stack is not equal to current character
        if (st.empty() || str1[i] != st.top())
        {
            st.push(str1[i]);
            //i++;
        }
             
        // If top element of the stack is
        // equal to the current character
        else
        {
            while (str1[i] == st.top()&& !st.empty())
            {
                st.pop();
                //i++;
            }
        }
            i++;
    }
     
    // If stack is empty
    if (st.empty())
    {
        return ("Empty String");
    }
         
    // If stack is not Empty
    else
    {
        string short_string = "";
        while (!st.empty())
        {
            short_string = st.top() +
                           short_string;
            st.pop();
        }
        return (short_string);
    }
}


int main(){
	string s;
	cin>>s;
	Node *head = double_ll_insert(nullptr,s[0]);
	for(int i=1;i<s.size();i++){
		double_ll_insert(head,s[i]);
	}
	//print(head);
	cout<<remove_adj(head);
}

// int main(){
// 	unordered_map<char,int> mp;
// 	string s;
// 	cin>>s;
// 	for(char x:s){
// 		mp[x]++;
// 	}
// 	vector<char> ch;
// 	for(auto it=mp.begin();it!=mp.end();it++){
// 		if(it->second==1)
// 			//cout<<it->first<<" ";
// 			ch.push_back(it->first);
// 	}

// 	for(auto it=ch.rbegin();it!=ch.rend();it++){
// 		cout<<*it<<"<->";
// 	}
// 	cout<<"NULL";
	
// }