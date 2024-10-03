//vvthangdev
/*

*/
#include <bits/stdc++.h>
using namespace std;
int n, m, r, c;
char a[1001][1001];
int d[1001][1001];
bool visited[1001][1001];

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

int bfs(int i, int j) {
    queue<pair<int, int>> q;
    visited[i][j] = true;
    q.push({i, j});
    // cout << i << " " << j << endl;
    // d[i][j] = 0;
    while(!q.empty()) {
        pair<int, int> top = q.front(); q.pop();
        for(int k = 0; k < 4; k++) {
            int i1 = top.first + di[k];
            int j1 = top.second + dj[k];
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited[i1][j1] && a[i1][j1] == '0') {
                // cout << i1 << " " << j1 << endl;
                d[i1][j1] = d[top.first][top.second] + 1;
                // cout << d[i1][j1] << endl;
                if (i1 == 1 || i1 == n || j1 == 1 || j1 == m) return d[i1][j1];
                q.push({i1, j1});
                visited[i1][j1] = true;
            }
        }
    }
    return -1;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> r >> c;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) {
            visited[i][j] = false;
        }
    }
    int res = bfs(r, c) + 1;
    if (res == 0) {
        cout << -1;
    }
    else cout << res;
    return 0;
}