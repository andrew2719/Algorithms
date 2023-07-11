#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int> adj[],int visited[],vector<int> &ls){
    ls.push_back(node);
    visited[node] = 1;
    for(auto it: adj[node]){
        if(!visited[it]){
            dfs(it,adj,visited,ls);
        }
    }
}

void addEdge(vector<int> adj[],int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

int main(){

    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    addEdge(adj,0, 1);
    addEdge(adj,0, 2);
    addEdge(adj,1, 2);
    addEdge(adj,2, 0);
    addEdge(adj,2, 3);
    addEdge(adj,3, 3);
    vector<int> ls;
    int visited[n+1]={0};
    dfs(1,adj,visited,ls);
    for(auto it:ls){
        cout<<it<<" ";
    }
}