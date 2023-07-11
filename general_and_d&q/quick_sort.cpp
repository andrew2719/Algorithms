// quick sort

#include <iostream>
using namespace std;
int swaps = 0;
void quick_sort(int a[], int l, int r) {
    if (l >= r) return;
    int i = l, j = r, x = a[(l+r)/2];
    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            swaps++;
            i++; j--;
        }
    }
    quick_sort(a, l, j);
    quick_sort(a, i, r);
}

int main() {
    int a[10] = {1, 3, 2, 5, 4, 7, 6, 9, 8, 0};
    quick_sort(a, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}