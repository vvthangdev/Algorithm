//vvthangdev
/*
6 6
xxxooo
ooxooo
oxxxxo
ooooox
xxoxox
xoxxox
=>4
*/
#include <bits/stdc++.h>
using namespace std;
int n ,m;
char a[1001][1001];
bool visited[1001][1001];

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

void dfs(int i, int j) {
    visited[i][j] = true;
    for(int k = 0; k < 4; k++) {
        int i1 = i + di[k];
        int j1 = j + dj[k];
        if (i1 >= 1 && i1 <= n && j1 >=1 && j1 <= m && !visited[i1][j1] && a[i1][j1] == 'x') {
            dfs(i1, j1);
        }
    }
}

void bfs(int i, int j) {
    visited[i][j] = true;
    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()) {
        pair<int, int> top = q.front(); q.pop();
        for(int k = 0; k < 4; k++) {
            int i1 = top.first + di[k];
            int j1 = top.second + dj[k];
            if (i1 >= 1 && i1 <= n && j1 >=1 && j1 <= m && !visited[i1][j1] && a[i1][j1] == 'x') {
                q.push({i1, j1});
                visited[i1][j1] = true;
            }
        }
    }
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    // for(int i = 1; i <= n; i++) {
    //     fill(visited[i], visited[i] + m + 1, false);
    // }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) {
            visited[i][j] = false;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'x' && !visited[i][j]) {
                bfs(i, j);
                cnt++;
                cout << cnt << " " ;
            }
        }
    }
    
    // cout << cnt - 1;
    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= m; j++) {
    //         cout << visited[i][j] << endl;
    //     }
    // }
    return 0;
}