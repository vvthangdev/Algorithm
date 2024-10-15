//Vu Van Thang 20215643
//MSSV: 20215643
/*

*/

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3+5;

short n, K, Q;
short c[MAX][MAX];
short d[MAX];


void input() {
	cin >> n >> K >> Q;
	for (int i = 1; i < n; i++) {
		cin >> d[i];
	}
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			cin >> c[i][j];
		}
	}
}


void solve() {
	int f = 0;
	int F = INT_MAX;
	
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	solve();
	return 0;
}
