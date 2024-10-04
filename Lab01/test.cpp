#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005
int n;
int a[MAX];
int m;
int M[25][MAX];

// Function to calculate log base 2 of a number
int log_2(int k) {
    int i = 0;
    while ((1 << (i + 1)) <= k) i++;
    return i;
}

// Preprocessing function to build the sparse table
void preprocessing() {
    for (int i = 0; i < n; i++) {
        M[0][i] = i; // Initialize first row
    }
    int j_max = log_2(n); // Find max power of 2 less than or equal to n

    for (int j = 1; j <= j_max; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) { // Use correct bitwise shift
            if (a[M[j - 1][i]] < a[M[j - 1][i + (1 << (j - 1))]]) {
                M[j][i] = M[j - 1][i];
            } else {
                M[j][i] = M[j - 1][i + (1 << (j - 1))];
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Read input array
    }

    preprocessing(); // Build sparse table

    // Output first 5 rows of the sparse table for debugging
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    
    cin >> m; // Unused input, can be removed

    return 0;
}
