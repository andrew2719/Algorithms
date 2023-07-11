#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    map<int,int> mp;

    for(int i = 0; i < n; i++) {
        cin >> vec[i];
        mp[vec[i]] += 1;
    }
    
    int x;
    cin >> x;

    if(mp[x]!=0) {
        cout<<x<<endl;
    } else {
        int mini = INT_MAX;
        int value;
        for(int i=0;i<n;i++) {
            if(abs(vec[i]-x)<mini) {
                mini = abs(vec[i]-x);
                value = vec[i];
            }
        }
        cout<<value<<endl;
    }
}