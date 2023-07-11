#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> outputs;
void s_subst(vector<int> a,int k,int sum,int i,vector<int> &x){
    if(sum==k){
        for(int j=0;j<x.size();j++){
            cout<<x[j]<<" ";
        }
        cout<<endl;
        return;
    }
    if(i==a.size()){
        return;
    }
    if(sum+a[i]<=k){
        x.push_back(a[i]);
        // print the x
        // for(int j=0;j<x.size();j++){
        //     cout<<x[j]<<" ";
        // }
        // cout<<endl;
        s_subst(a,k,sum+a[i],i+1,x);
        x.pop_back();
    }
    s_subst(a,k,sum,i+1,x);
}


int main(){
    int k;
    int n;
    cin>>n;
    cin>>k;
    vector<int> a(n);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    reverse(a.begin(),a.end());

    vector<int> x;
    s_subst(a,k,0,0,x);
    return 0;

}

// #include <stdio.h>
// int n;
// int m;
// int a[100];
// int track[100];
// int flag = 0;
// void backtrack(int a[], int n1, int sum1)
// {
//     int sum = sum1, i;
//     if (sum == m)
//     {
//         flag = 1;
//         for (i = 0; i < n; i++)
//             if (track[i] == 1)
//                 printf("%d ", a[i]);
//         printf("\n");
//         return;
//     }
//     if (sum > m)
//         return;
//     for (i = n1; i >= 0; i--)
//     {
//         sum = sum + a[i];
//         track[i] = 1;
//         backtrack(a, i - 1, sum);
//         sum = sum - a[i];
//         track[i] = 0;
//     }
// }
// int main()
// {
//     scanf("%d", &n);
//     scanf("%d", &m);
//     int i;
//     // 6
//     // 30
//     // 5 10 12 13 15 18
//     for (i = 0; i < n; i++)
//         scanf("%d", &a[i]);
//     for (i = 0; i < n; i++)
//         track[i] = 0;
//     backtrack(a, n - 1, 0);
//     if (flag == 0)
//         printf("No Solution");
// }