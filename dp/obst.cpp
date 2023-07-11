
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// Function to compute the values of w(i,j), c(i,j), and r(i,j)
void OBST(int n, vector<double> p, vector<double> q, vector<vector<double>>& w, vector<vector<double>>& c, vector<vector<int>>& r) {
    // Initialize w and c
    for (int i = 0; i <= n; i++) {
        w[i+1][i] = q[i];
        c[i+1][i] = 0;
    }

    // Compute the values of w and c using a bottom-up approach
    for (int l = 1; l <= n; l++) {
        for (int i = 1; i <= n-l+1; i++) {
            int j = i+l-1;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            c[i][j] = INT_MAX;
            for (int k = i; k <= j; k++) {
                double t = c[i][k-1] + c[k+1][j] + w[i][j];
                if (t < c[i][j]) {
                    c[i][j] = t;
                    r[i][j] = k;
                }
            }
        }
    }
}

int main() {
    // Number of identifiers
    int n = 4;

    // Identifier set
    vector<string> id = {"cout", "float", "if", "while"};

    // Probabilities
    vector<double> p = {0, 1.0/20, 1.0/5, 1.0/10, 1.0/20};
    vector<double> q = {1.0/5, 1.0/10, 1.0/5, 1.0/20, 1.0/20};

    // Arrays to store the values of w(i,j), c(i,j), and r(i,j)
    vector<vector<double>> w(n+2,vector<double>(n+1));
    vector<vector<double>> c(n+2,vector<double>(n+1));
    vector<vector<int>> r(n+2,vector<int>(n+1));

    // Compute the values of w(i,j), c(i,j), and r(i,j)
    OBST(n, p, q, w, c, r);

    // Print the values of w(i,j), c(i,j), and r(i,j)
    cout << "w(i,j):" << endl;
    for (int i = 1; i <= n+1; i++) {
        for (int j = 0; j <= n; j++) {
            cout << w[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "c(i,j):" << endl;
    for (int i = 1; i <= n+1; i++) {
        for (int j = 0; j <= n; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "r(i,j):" << endl;
    for (int i = 1; i <= n+1; i++) {
        for (int j = 0; j <= n; j++) {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
