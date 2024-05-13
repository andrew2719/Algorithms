#include<bits/stdc++.h>
using namespace std;

class CompareWithFirstMin{
    public:
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.first>b.first;
    }
};


class Solution{
    public:
    vector<int> dijkstra(int V,vector<vector<int>> adj[],int src){
        priority_queue<pair<int,int>, vector<pair<int,int>>,CompareWithFirstMin> pq;
        vector<int> distTo(V,INT_MAX);
        vector<int> dest(V,-1);
        dest[src] = src;

        distTo[src] = 0;
        pq.push({0,src});

        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            for(auto it:adj[node]){
                int v = it[0];
                int w = it[1];

                if(dist+w < distTo[v]){
                    distTo[v] = dist + w;
                    dest[v] = node;
                    pq.push({dist+w,v});
                }
            }
        }

        return distTo;

    }

};

int main()
{
    // Driver code.
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    // vector<int> dest = obj.dijkstra.dest;
    // for (int i = 0; i < V; i++)
    // {
    //     cout << i << " ";
    // }
    return 0;
}