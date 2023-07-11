#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1,2,3,4,5,6};
    a.erase(find(a.begin(),a.end(),a.front()));
    a.front() = 10;
    cout<<a[0];

    
    
}