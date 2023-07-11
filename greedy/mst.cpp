#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	vector<vector<int>> a;
	vector<vector<int>> result(n,vector<int>(n,0));

	for(int i=0;i<n;i++){
		vector<int> temp;
		for(int j=0;j<n;j++){
			int x;
			cin>>x;
			temp.push_back(x);
		}
		a.push_back(temp);
	}

	vector<pair<int,int>> adj[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]!=0)
			adj[i].push_back(make_pair(j,a[i][j]));
		}
	}

	int parent[n],key[n];
	bool mstset[n];

	for(int i=0;i<n;i++){
		key[i] = INT_MAX;mstset[i] = false;
	}

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

	key[0] = 0;
	parent[0] = -1;
	pq.push({0,0});

	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();

		mstset[u] = true;

		for(auto it:adj[u]){
			int v = it.first;
			int weight = it.second;
			if(mstset[v]==false && weight<key[v]){
				parent[v] = u;
				key[v] = weight;
				
				
				pq.push({key[v],v});
			}
		}
	}

	for(int i=1;i<n;i++){
		result[parent[i]][i] = key[i];
		result[i][parent[i]] = key[i]; 
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	int sum = 0;
	for(int i=0;i<n;i++){
		sum+=key[i];	
		}
	
	cout<<"Total cost of spanning tree="<<sum<<endl;

	// time complexity = O(ElogV)
	

}
// sample input
// 5
// 0 2 0 6 0
// 2 0 3 8 5
// 0 3 0 0 7
// 6 8 0 0 9
// 0 5 7 9 0
