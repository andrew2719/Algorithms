#include<bits/stdc++.h>
using namespace std;

class Item{
    public:
    int wt;
    int profit;
    Item(int wt,int profit){
        this->wt=wt;
        this->profit=profit;
    }
};


class cmp{
    public:
    bool operator()(Item a,Item b){
        return a.wt<b.wt;
    }
};


void knapsack(vector<Item> items,int w){
   vector<vector<int>> dp(items.size()+1,vector<int>(w+1,0));

   for(int i=1;i<=items.size();i++){
       for(int j=1;j<=w;j++){
           if(items[i-1].wt<=j){
               dp[i][j] = max(dp[i-1][j],items[i-1].profit+dp[i-1][j-items[i-1].wt]);
           }else{
               dp[i][j] = dp[i-1][j];
           }
       }
   }

   // pprint dp
    for(int i=0;i<=items.size();i++){
         for(int j=0;j<=w;j++){
              cout<<dp[i][j]<<" ";
         }
         cout<<endl;
    }

    int j = w;
    int x = dp[items.size()][w];
    //cout<<x<<endl;
    int arr[items.size()];
    
    for(int i=items.size();i>0;i--){
        if(x==dp[i-1][j]){
            arr[i-1] = 0;
        }else{
            arr[i-1] = 1;
            x = x-items[i-1].profit;
            j = j-items[i-1].wt;
        }
    }

    for(int i=0;i<items.size();i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n,w;
    //cin>>n>>w;
    n = 4;
    w = 8;
    vector<Item> items  = {Item(3,2),Item(4,3),Item(6,1),Item(5,4)};
    // for(int i=0;i<n;i++){
    //     int wt,profit;
    //     cin>>wt>>profit;
    //     Item item(wt,profit);
    //     items.push_back(item);
    // }
    sort(items.begin(),items.end(),cmp());

    // for(int i=0;i<n;i++){
    //     cout<<items[i].wt<<" "<<items[i].profit<<endl;
    // }

    knapsack(items,w);

    
}