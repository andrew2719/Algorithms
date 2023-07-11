#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {5, 4, 3, 2, 1};
    int n = sizeof(a)/sizeof(a[0]);
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 && a[j-1]>a[j]){
            swap(a[j], a[j-1]);
            j--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}