#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair


// merge sort algorithm
int swaps = 0;
void merge(vector<int> &a, int l, int m, int r, int &count)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
            count ++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &a, int l, int r, int &count)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m, count);
        mergeSort(a, m + 1, r, count);
        merge(a, l, m, r, count);
    }
}

int main()
{
    //int n;
    //cin>>n;
    int n =0;
    vector<int> a;
    string line = "7 3 4 10";
    //getline(cin, line);
    string word;
    stringstream ss(line);
    while (ss >> word) {
      cout << word << endl;
      int x = stoi(word);
      a.push_back(x);
      n++;
    }
      cout<<n<<endl;
  
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    int count = 0;
    mergeSort(a, 0, n - 1, count);
    cout<<endl;
    cout << count << endl;
    return 0;

}