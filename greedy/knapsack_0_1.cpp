// knapsack_0_1 greedy
#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
    double fraction;    
};

int main(){
    int n;
    cout<<"Enter number of items: ";
    cin>>n;
    Item items[n];
    cout<<"Enter value and weight of each item:\n";
    for(int i=0;i<n;i++){
        cin>>items[i].value>>items[i].weight;
        items[i].fraction = (double)items[i].value/items[i].weight;
    }
    int capacity;
    cout<<"Enter capacity of knapsack: ";
    cin>>capacity;
    sort(items,items+n,[](Item a,Item b){
        return a.fraction>b.fraction;
    });
    int profit = 0;
    for(int i=0;i<n;i++){
        if(capacity>=items[i].weight){
            profit += items[i].value;
            capacity -= items[i].weight;
        }
        else{
            profit += items[i].fraction*capacity;
            break;
        }
    }
    cout<<"Maximum profit: "<<profit<<endl;
    return 0;
}