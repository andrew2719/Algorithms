// distance vector
#include<bits/stdc++.h>
using namespace std;

void print_table(vector<vector<int>> table){
    for(auto i:table){
        for(auto j:i){
            // cout<<j<<" ";
            if(j == INT_MAX)
                cout<<"INF ";
            else
                cout<<j<<" ";
        }
        cout<<endl;
    }
}

void distance_vector(vector<vector<int>> &table,int V){
    // vector<vector<int>> table(V,vector<int>(V,INT_MAX));

    vector<vector<int>> previous = table;
    int interation = 0;
    bool change = true;
    cout<<"Iteration: "<<interation<<endl;
    print_table(table);
    interation++;
    do{
        change = false;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                for(int k=0;k<V;k++){
                    if(table[i][j] > table[i][k]+table[k][j]){
                        table[i][j] = table[i][k]+table[k][j];
                        change = true;
                    }
                }
            }
        }
        cout<<"Iteration: "<<interation<<endl;
        print_table(table);
        interation++;
    }while(change);    
}


int main(){
    int V = 3;
    vector<vector<int>> adj(V,vector<int>(V,INT_MAX));

    adj[0][0] = 0;
    adj[0][1] = 1;
    adj[0][2] = 6;
    adj[1][0] = 1;
    adj[1][1] = 0;
    adj[1][2] = 3;
    adj[2][0] = 6;
    adj[2][1] = 3;
    adj[2][2] = 0;



    // for(int i=0;i<edges;i++){
    //     int a,b,weight;
    //     cin>>a>>b>>weight;
    //     adj[a][b] = weight;
    //     adj[b][a] = weight;
    // }

    // for(int i=0;i<V;i++){
    //     for(int j=0;j<V;j++){
    //         if (i==j)
    //         adj[i][j] = 0;
    //     }
    // }

    distance_vector(adj,V);

    // Print distance table
    cout<<"---------------------------------"<<endl;
    cout<<"Distance Table final table"<<endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << adj[i][j] << " ";
        }
        cout << "\n";
    }


}