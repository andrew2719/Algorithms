#include<bits/stdc++.h>
using namespace std;


class cmp{
    public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b. second;
    }
};

void dijktras(int V,vector<pair<int,int>> adj[],int src){
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    vector<int> source(V,-1);
    vector<int> distTo(V,INT_MAX);

    source[src] = src;
    distTo[src] = 0;

    pq.push({src,0});

    while(!pq.empty()){
        
        pair<int,int> top = pq.top();
        int parent = top.first;
        int distance_up_to_parent = top.second;
        pq.pop();

        for(auto it:adj[parent]){
            int adjacent_node = it.first;
            int distance_to_this_node = it.second;

            if(distance_up_to_parent+distance_to_this_node < distTo[adjacent_node]){
                source[adjacent_node] = parent;
                distTo[adjacent_node] = distance_to_this_node+distance_up_to_parent;
                pq.push({adjacent_node,(distance_to_this_node+distance_up_to_parent)});
            }
        }
    }

    // printing parents

    for(int i=0;i<source.size();i++){
        cout<<"node: "<<i<<" ,parent: "<<source[i]<<endl;
    }

    cout<<"---------------------------------"<<endl;
    // printing distances 
    for(int i=0;i<distTo.size();i++){
        cout<<"node: "<<i<<" ,distance from the source "<<source[i]<<": "<<abs(distTo[i]-distTo[source[i]])<<endl;
    }

}

int main(){
    int V = 3,E=6;
    vector<pair<int,int>> adj[V];

    pair<int,int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};

    // for(int i=0;i<E;i++){
    //     int src,dest,w;
    //     cin>>src>>dest>>w;
    //     adj[src].push_back(make_pair(dest,w));
    // }

    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    int src = 0;

    dijktras(V,adj,src);


}