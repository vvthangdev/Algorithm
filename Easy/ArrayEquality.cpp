//vvthangdev
/*

*/
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3+5;
int testNum, n, m;
int A[MAX], B[MAX];

void inp(){
    cin >> testNum >> n >> m;;
    
}

void solve(){
    for(int test = 1; test <= testNum; test++) {
        bool flag = true;
        cin >> n >> m;
        if(n != m) flag = false;
        for(int i = 1; i <= n; i++) {
        cin >> A[i];
        }
        for(int j = 1; j <= m; j++) {
            cin >> B[j];
            if(B[j] != A[j]) flag = false;
        }
    cout << flag << '\n';
    }
}

int main () {
    inp();
    solve();
    
    return 0;
}