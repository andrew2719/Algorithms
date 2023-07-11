#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    // here we are finding the leastor(min index and swaping if arr[min] is greater than arr[j])
    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min])
            {
                min = j;
            }
            swap(arr[i], arr[min]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}