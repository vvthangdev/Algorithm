//vvthangdev
/*

*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005
int n;
int a[MAX];
int m;
int M[25][MAX];

int log_2(int k) {
    int i = 0;
    while (1 << (i + 1) <= k) i++;
    return i;
}

void preprocessing() {
    for(int i = 0; i < n; i++) {
        M[0][i] = i;
    }
    int j_max = log_2(n);

    for (int j = 1; j <= j_max; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            if (a[M[j - 1][i]] < a[M[j - 1][i + (1 << (j - 1))]]) {
                M[j][i] = M[j-1][i];
            }
            else {
                M[j][i] = M[j - 1][i + (1 << (j - 1))];
            }
        }
    }
}

int RMQ(const int &i,const int &j) {
    int k = log_2(j - i + 1);
    if(a[M[k][i]] <= a[M[k][j - (1 << k) + 1]]) {
        return a[M[k][i]];
    }
    else return a[M[k][j - (1 << k) + 1]];
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    preprocessing();
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << M[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    long long Q = 0;
    cin >> m;

    int a, b;
    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        // cout << RMQ(a, b) << "x" << endl;
        // cout << Q << " " << endl;
        Q += RMQ(a, b);
    }
    cout << Q << endl;

    
    return 0;
}