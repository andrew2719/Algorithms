#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src;
    cin>>src;
    queue<int> q;
    vector<bool> visited(n+1,false);
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                q.push(it);
                visited[it]=true;
            }
        }
    }
    return 0;
}