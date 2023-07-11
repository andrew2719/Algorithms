#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int tsp(int i, set<int> S, vector<vector<int>>& dist, map<pair<int, set<int>>, int>& memo, map<pair<int, set<int>>, int>& parent) {
    if (S.empty()) { // all cities have been visited
        return dist[i][0];
    }
    if (memo.find({i, S}) != memo.end()) { // memoization
        return memo[{i, S}];
    }
    int min_cost = INF;
    for (int j : S) {
        set<int> new_S = S;
        new_S.erase(j);
        int new_cost = dist[i][j] + tsp(j, new_S, dist, memo, parent);
        if (new_cost < min_cost) {
            min_cost = new_cost;
            parent[{i, S}] = j; // update parent
        }
    }
    memo[{i, S}] = min_cost; // memoize the result
    return min_cost;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }

    // initialize memo and parent tables
    map<pair<int, set<int>>, int> memo;
    map<pair<int, set<int>>, int> parent;

    // initialize visited set
    set<int> S;
    for (int i = 1; i < n; ++i) {
        S.insert(i);
    }

    // compute the shortest path
    int min_cost = tsp(0, S, dist, memo, parent);

    // reconstruct the path
    vector<int> path(n);
    int curr_city = 0;
    set<int> curr_S = S;
    path[0] = 0;
    for (int i = 1; i < n; ++i) {
        int next_city = parent[{curr_city, curr_S}];
        path[i] = next_city;
        curr_city = next_city;
        curr_S.erase(next_city);
    }

    map<int,char> alphabets;

    for(int i=0;i<n;i++)
    {
        alphabets[i] = 'A'+i;
    }
    

    // print the result
    cout << "Path: ";
    for (int i = 0; i < n; ++i) {
        cout << alphabets[path[i]] << "->";

    }
    cout << alphabets[0] << endl;
    cout << endl;
    cout << "Minimum cost: " << min_cost << endl;

    return 0;
}
// 4
// 0 10 15 20
// 10 0 35 25
// 15 35 0 30
// 20 25 30 0