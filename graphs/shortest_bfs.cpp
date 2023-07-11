#include<bits/stdc++.h>
using namespace std;

vector<int> shortest_paths(vector<int> &dist,vector<int> adj[],int src)
{
    queue<int> q;
    q.push(src);
    dist[src]=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(dist[node]+1<dist[it])
            {
                dist[it]=dist[node]+1;
                q.push(it);
            }
        }
    }
    return dist;
}


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
    int src = 1;
    vector<int> dist(n+1,INT_MAX);
    vector<int> ans=shortest_paths(dist,adj,src);
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
}