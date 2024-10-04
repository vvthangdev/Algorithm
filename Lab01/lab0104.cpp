//vvthangdev
/*

*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 1007
int n, m;
int a[MAX][MAX];
void inp() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    inp();

    
    return 0;
}